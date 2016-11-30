import org.jtransforms.fft.DoubleFFT_1D;

import javax.sound.sampled.*;

import static org.lwjgl.glfw.Callbacks.glfwFreeCallbacks;
import static org.lwjgl.glfw.GLFW.glfwDestroyWindow;
import static org.lwjgl.glfw.GLFW.glfwSetErrorCallback;
import static org.lwjgl.glfw.GLFW.glfwTerminate;

import java.io.ByteArrayOutputStream;
import java.nio.ByteBuffer;


public class AudioModule implements Runnable {
	private static AudioModule LastDec; 
    int modeOfOp, duration, width, height, algo;
    int max = 1000000;
    boolean recording = false, fullscreen = false;
    private long window;
    public static double[] rtData = new double[512];
    public static double[] staticData = new double[512];
    private GLLoader loader;
    Thread loaderThread;
    //used to check if there's a static window already open
    public boolean alreadyRan = false;

    AudioModule() {

        this.recording = false;
        AudioModule.LastDec = this;
    }

    @Override
    public void run() {
        //run it based on the algorithm number (algoNum)

        if (modeOfOp == 2 && alreadyRan && loaderThread != null) {
            loader.destroyWindow();
            loader.terminate();
            try {
                loaderThread.join();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
            alreadyRan = false;
        }

        loader = new GLLoader();

        int limit;
        short[] shorts;
        //limit = 8192;
        limit = 32768;

        double[] processedAudio = new double[2 * limit];
        DoubleFFT_1D dfft = new DoubleFFT_1D(limit);

        for(int i = 0; i < 512; i++) {
            staticData[i] = 0;
        }
        //getting the audio input in the form of a byte array
        byte[] audioInputBytes = getAudio(duration);

        alreadyRan = (modeOfOp == 1);


        if (modeOfOp == 1) {
            ArtGUI.recordState = false;
            //converting the byte array to a short array
            //converting it straight to a double array would not give correct data
            shorts = shortMe(audioInputBytes);

            //converting the short array to a double array
            for (int i = 0; i<shorts.length; i++) {
                processedAudio[i] = shorts[i];
            }
            //getting the fft data from the imported JTransforms library
            dfft.realForward(processedAudio);
            long cntr = 0;
            int index = 0;

            for (double dub : processedAudio) {
                if (dub < max && dub > -max && dub != 0.0) {
                    cntr++;
                }
            }

            double[] finalAudio = new double[(int) cntr];

            for (double dub : processedAudio) {
                if (dub < max && dub > -max && dub != 0.0) {
                    finalAudio[index] = dub;
                    index++;
                }
            }

            int div = finalAudio.length/512;
            //printing fft data to transform

            cntr = 0;
            index = 0;

            for (double dub : finalAudio) {
                if (dub < 0) {
                    dub *= -1;
                }
                cntr++;
                if (cntr % div == 0 && index < 512) {
                    staticData[index++] = dub/max;
                    //System.out.println(dub/max);
                }
            }
            System.out.println(index + " static data points");

            //send on over the staticData array to be used to make purrty visual stuff
        }
    }
    
    public static double[] getAudioS(int duration) {
    	return toDoubleArray(AudioModule.LastDec.getAudio(duration));
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
            byte[] rtBuf = new byte[512];
            long end;
            int len;
            recording = true;
            disableButtons();
            ArtGUI.slider.setEnabled(false);

            //starting another thread for the loader...
            loader.width = width;
            loader.height = height;
            loader.fullscreen = fullscreen;
            loader.mode = modeOfOp;
            loader.algo = algo;

            if (!alreadyRan) {
                loaderThread = new Thread(loader);
                loaderThread.start();
            }

            //for static mode...
            if (modeOfOp == 1) {
                end = System.currentTimeMillis() + 1000 * duration;
                ArtGUI.recordInput.setEnabled(false);
                while (System.currentTimeMillis() < end && ((len = line.read(buf, 0, buf.length)) != -1)) {
                    baos.write(buf, 0, len);
                }
                ArtGUI.recordInput.setEnabled(true);
                recording = false;
            }
            //for real time mode...
            else {

                for(int i = 0; i < 512; i++) {
                	rtData[i] = 0;
                }

                DoubleFFT_1D dfft = new DoubleFFT_1D(512);
                while (recording && ((len = line.read(rtBuf, 0, rtBuf.length)) != -1)) {
                    //this while loop creates a buf array of 5500 elements every second.
                    //need to send 512 data points 30 times a second somehow...
                    short[] s = shortMe(rtBuf);
                    for (int i = 0; i<s.length; i++) {
                        rtData[i] = s[i];
                    }
                    dfft.realForward(rtData);

                    for (int index=0; index<rtData.length; index++) {
                        rtData[index] = Math.abs(rtData[index]/20000);
                        if (rtData[index] > 1.0) {
                            rtData[index] = 1.0;
                        }
                        //System.out.println(rtData[index]);
                    }
                }
                /*
                if (System.currentTimeMillis() >= end) {
                    ArtGUI.recordInput.doClick();
                    ArtGUI.infoBox("The max duration has been reached", "Recording Stopped");
                }
                */

                loader.destroyWindow();
                loader.terminate();
                loaderThread.join();

                ArtGUI.recordState = false;
                ArtGUI.recordInput.setText("Record Input");
            }
            //no more mode-specific stuff
            enableButtons();
            ArtGUI.slider.setEnabled(true);

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

    private void disableButtons() {
        ArtGUI.algo1.setEnabled(false);
        ArtGUI.algo2.setEnabled(false);
        ArtGUI.algo3.setEnabled(false);
        ArtGUI.algo4.setEnabled(false);

        ArtGUI.reso1.setEnabled(false);
        ArtGUI.reso2.setEnabled(false);
        ArtGUI.reso3.setEnabled(false);
        ArtGUI.reso4.setEnabled(false);
    }

    private void enableButtons() {
        ArtGUI.algo1.setEnabled(true);
        ArtGUI.algo2.setEnabled(true);
        ArtGUI.algo3.setEnabled(true);
        ArtGUI.algo4.setEnabled(true);

        ArtGUI.reso1.setEnabled(true);
        ArtGUI.reso2.setEnabled(true);
        ArtGUI.reso3.setEnabled(true);
        ArtGUI.reso4.setEnabled(true);
    }

    public static double[] toDoubleArray(byte[] byteArray){
        int times = Double.SIZE / Byte.SIZE;
        double[] doubles = new double[byteArray.length / times];
        for(int i=0;i<doubles.length;i++){
            doubles[i] = ByteBuffer.wrap(byteArray, i*times, times).getDouble();
        }
        return doubles;
    }

    public static short[] shortMe(byte[] bytes) {
        short[] out = new short[bytes.length / 2]; // will drop last byte if odd number
        ByteBuffer bb = ByteBuffer.wrap(bytes);
        for (int i = 0; i < out.length; i++) {
            out[i] = bb.getShort();
        }
        return out;
    }
    
}
