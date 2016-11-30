import org.jtransforms.fft.DoubleFFT_1D;

import javax.sound.sampled.*;
import java.io.ByteArrayOutputStream;
import java.nio.ByteBuffer;


public class AudioModule implements Runnable {

    int modeOfOp, duration;
    boolean recording = false;

    AudioModule(int modeOfOp, int duration) {
        //sets the mode of operation, either static or real time
        //1 for static, 2 for real time
        this.modeOfOp = modeOfOp;
        this.duration = duration;
        this.recording = false;
    }

    @Override
    public void run() {
        //run it based on the algorithm number (algoNum)

        int limit;
        short[] shorts;
        //limit = 8192;
        limit = 32768;

        double[] processedAudio = new double[2 * limit];
        DoubleFFT_1D dfft = new DoubleFFT_1D(limit);
        //getting the audio input in the form of a byte array
        byte[] audioInputBytes = getAudio(duration);

        //converting the byte array to a short array
        //converting it straight to a double array would not give correct data
        shorts = shortMe(audioInputBytes);

        //converting the short array to a double array
        for (int i = 0; i<shorts.length; i++) {
            processedAudio[i] = shorts[i];
        }
        //getting the fft data from the imported JTransforms library
        dfft.realForward(processedAudio);
        int cntr = 0;
        //printing fft data to transform
        for (double dub : processedAudio) {
            System.out.println(dub);
            cntr++;
        }
        System.out.println(cntr + " total data points");
    }

    public byte[] getAudio(int duration) {
        //int duration = 5; // sample for 5 seconds
        byte[] output = null;

        try {
            TargetDataLine line = null;
            // find a DataLine that can be read
            // (maybe hardcode this if you have multiple microphones)
            Mixer.Info[] mixerInfo = AudioSystem.getMixerInfo();
            for (int i = 0; i < mixerInfo.length; i++) {
                Mixer mixer = AudioSystem.getMixer(mixerInfo[i]);
                Line.Info[] targetLineInfo = mixer.getTargetLineInfo();
                if (targetLineInfo.length > 0) {
                    line = (TargetDataLine) mixer.getLine(targetLineInfo[0]);
                    break;
                }
            }
            if (line == null)
                throw new UnsupportedOperationException("No recording device found");
            AudioFormat af = new AudioFormat(11000, 8, 1, true, false);
            line.open(af);
            line.start();
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            byte[] buf = new byte[(int) af.getSampleRate() * af.getFrameSize()];
            long end;
            int len;
            recording = true;
            if (modeOfOp == 1) {
                end = System.currentTimeMillis() + 1000 * duration;
                ArtGUI.recordInput.setEnabled(false);
                ArtGUI.slider.setEnabled(false);
                while (System.currentTimeMillis() < end && ((len = line.read(buf, 0, buf.length)) != -1)) {
                    baos.write(buf, 0, len);
                }
                ArtGUI.recordInput.setEnabled(true);
                ArtGUI.slider.setEnabled(true);
                recording = false;
            }
            else {
                duration = 10;
                end = System.currentTimeMillis() + 1000 * duration;
                ArtGUI.slider.setEnabled(false);
                while (recording && System.currentTimeMillis() < end && ((len = line.read(buf, 0, buf.length)) != -1)) {
                    baos.write(buf, 0, len);
                }
                if (System.currentTimeMillis() >= end) {
                    ArtGUI.recordInput.doClick();
                    ArtGUI.infoBox("The max duration has been reached", "Recording Stopped");
                }
                ArtGUI.slider.setEnabled(true);
                recording = false;
            }
            line.stop();
            line.close();

            baos.flush();
            output = baos.toByteArray();
            baos.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }

        return output;
    }

    public double[] toDoubleArray(byte[] byteArray){
        int times = Double.SIZE / Byte.SIZE;
        double[] doubles = new double[byteArray.length / times];
        for(int i=0;i<doubles.length;i++){
            doubles[i] = ByteBuffer.wrap(byteArray, i*times, times).getDouble();
        }
        return doubles;
    }

    public short[] shortMe(byte[] bytes) {
        short[] out = new short[bytes.length / 2]; // will drop last byte if odd number
        ByteBuffer bb = ByteBuffer.wrap(bytes);
        for (int i = 0; i < out.length; i++) {
            out[i] = bb.getShort();
        }
        return out;
    }

}
