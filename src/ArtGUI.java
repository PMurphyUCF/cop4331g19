import java.awt.*;
import java.awt.event.*;
import java.util.Enumeration;

import javax.swing.*;

public class ArtGUI extends JApplet implements ActionListener, WindowListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = -1348153619396853235L;
	//false when not recording, true when recording
	public static boolean recordState = false;
	public static JButton recordInput, savePngImage, saveJpgImage;
	public static JSlider slider;
	private ButtonGroup algorithmOption, modeOption, resolutionOption;
	static JRadioButton staticImage, realImage, algo1, algo2, algo3, algo4, reso1, reso2, reso3, reso4;
	private AudioModule module;
	private Thread audioThread;
	private JPanel centerPanel;
	public static Frame frame = null;
	
	public static void main(String[] args) {
		frame = new Frame("SoundVisualizer");
		ArtGUI app = new ArtGUI();
		frame.add(app);	
		app.init();
		app.start();
		frame.pack();
		frame.setLocation(100,100);
		frame.setSize(770,560);
		frame.setVisible(true);
		
	}
	public void windowClosing(WindowEvent e)
	{
		frame.dispose();
		System.exit(0);
	}
	public void windowOpened(WindowEvent e)
	{ }
	public void windowIconified(WindowEvent e)
	{ }
	public void windowClosed(WindowEvent e)
	{ }
	public void windowDeiconified(WindowEvent e)
	{ }
	public void windowActivated(WindowEvent e)
	{ }
	public void windowDeactivated(WindowEvent e)
	{ }

	public void init(){
		frame.addWindowListener(this);
		recordState = false;
		module = new AudioModule();

		//setDefaultCloseOperation(JApplet.EXIT_ON_CLOSE);
		setSize(770,550);
		centerPanel = new JPanel(new GridLayout(1, 1));
		add(centerPanel, BorderLayout.CENTER);

		createMenu();

		createWestPanel();
		createEastPanel();
		createSouthPanel();

	}
	
	private void createWestPanel(){
		JPanel westPanel = new JPanel();
		westPanel.setLayout(new BoxLayout(westPanel,BoxLayout.Y_AXIS));
        westPanel.setBorder(BorderFactory.createTitledBorder("Select Style"));
        centerPanel.add(westPanel);
        
        algorithmOption = new ButtonGroup();
        algo1 = new JRadioButton("Algorithm 1");
        algo1.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        algo2 = new JRadioButton("Algorithm 2");
        algo2.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        algo3 = new JRadioButton("Algorithm 3");
        algo3.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        algo4 = new JRadioButton("Algorithm 4");
        algo4.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        
        algorithmOption.add(algo1);
        algorithmOption.add(algo2);
        algorithmOption.add(algo3);
        algorithmOption.add(algo4);
        
        westPanel.add(algo1);
        westPanel.add(algo2);
        westPanel.add(algo3);
        westPanel.add(algo4);
	}
	
	
	
	private void createEastPanel(){
		JPanel eastPanel = new JPanel();
		eastPanel.setLayout(new BoxLayout(eastPanel,BoxLayout.Y_AXIS));
		eastPanel.setBorder(BorderFactory.createTitledBorder("Resolution"));
        centerPanel.add(eastPanel);

		resolutionOption = new ButtonGroup();
		reso1 = new JRadioButton("640x480");
		reso1.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
		reso2 = new JRadioButton("1280x720");
		reso2.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
		reso3 = new JRadioButton("1920x1080");
		reso3.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
		reso4 = new JRadioButton("Fullscreen");
		reso4.setFont(new Font(Font.DIALOG,Font.PLAIN,24));

		resolutionOption.add(reso1);
		resolutionOption.add(reso2);
		resolutionOption.add(reso3);
		resolutionOption.add(reso4);

		eastPanel.add(reso1);
		eastPanel.add(reso2);
		eastPanel.add(reso3);
		eastPanel.add(reso4);
	}
	
	private void createSouthPanel(){

		JPanel southPanel = new JPanel(new GridLayout(3, 1));
		JPanel top = new JPanel();
		JPanel mid = new JPanel();
		JPanel bottom = new JPanel();
        add(southPanel,BorderLayout.SOUTH);

        recordInput = new JButton("Record Input");
        recordInput.setPreferredSize(new Dimension(170, 60));
        recordInput.setMinimumSize(new Dimension(170, 60));
        recordInput.setMaximumSize(new Dimension(170, 60));
		recordInput.setActionCommand("recordInput");
		recordInput.addActionListener(this);
		top.add(recordInput);

        modeOption = new ButtonGroup();
        staticImage = new JRadioButton("Static Image");
        realImage = new JRadioButton("Real Time Image");
        modeOption.add(staticImage);
        modeOption.add(realImage);

		top.add(staticImage);
		top.add(realImage);

		savePngImage = new JButton("<html><center>"+"Save"+"<br>"+"PNG"+"<br>"+"Image"+"</center></html>");
		savePngImage.setPreferredSize(new Dimension(80, 60));
		savePngImage.setMinimumSize(new Dimension(80, 60));
		savePngImage.setMaximumSize(new Dimension(80, 60));
		savePngImage.setActionCommand("savePngImage");
		savePngImage.addActionListener(this);
		top.add(savePngImage);

		saveJpgImage = new JButton("<html><center>"+"Save"+"<br>"+"JPG"+"<br>"+"Image"+"</center></html>");
		saveJpgImage.setPreferredSize(new Dimension(80, 60));
		saveJpgImage.setMinimumSize(new Dimension(80, 60));
		saveJpgImage.setMaximumSize(new Dimension(80, 60));
		saveJpgImage.setActionCommand("saveJpgImage");
		saveJpgImage.addActionListener(this);
		top.add(saveJpgImage);

		slider = new JSlider(JSlider.HORIZONTAL, 1, 10, 5);
		//slider.setMinorTickSpacing(2);
		slider.setMajorTickSpacing(1);
		slider.setPaintTicks(true);
		slider.setPaintLabels(true);
		slider.setLabelTable(slider.createStandardLabels(1));
		bottom.add(slider);

		JLabel inputLabel = new JLabel("Input Duration");
		mid.add(inputLabel);

		southPanel.add(top);
		southPanel.add(mid);
		southPanel.add(bottom);
	}
	
	private void createMenu(){
		JMenuBar menuBar =  new JMenuBar();
		
		//Menu for file options
		JMenu fileOptions = new JMenu("File");
		fileOptions.setMnemonic('F');
		menuBar.add(fileOptions);
		
		
		setJMenuBar(menuBar);
		
		//menuitems for File
		JMenuItem saveOption = new JMenuItem("Save Image",KeyEvent.VK_S);
		fileOptions.add(saveOption);
		JMenuItem exitOption = new JMenuItem("Exit",KeyEvent.VK_E);
		exitOption.addActionListener(new ExitListener());
		fileOptions.add(exitOption);
		
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch (e.getActionCommand()) {
			case "recordInput":
				int mode;
				if (!recordState) {

					if (getSelectedButtonText(algorithmOption).equals("")) {
						infoBox("Please select an Algorithm", "Unable to Proceed");
						return;
					}

					if (getSelectedButtonText(resolutionOption).equals("")) {
						infoBox("Please select a Resolution", "Unable to Proceed");
						return;
					}

					switch(getSelectedButtonText(modeOption)) {
						case "Real Time Image":
							recordInput.setText("Stop Recording");
							mode = 2;
							break;
						case "Static Image":
							mode = 1;
							break;
						default:
							infoBox("Please select a mode of operation", "Unable to Proceed");
							return;
					}

					try {
						//need to get slider position
						//start the recording
						module.modeOfOp = mode;
						module.duration = slider.getValue();

						switch (getSelectedButtonText(resolutionOption)) {
							case "640x480":
								module.width = 640;
								module.height = 480;
								module.fullscreen = false;
								break;
							case "1280x720":
								module.width = 1280;
								module.height = 720;
								module.fullscreen = false;
								break;
							case "1920x1080":
								module.width = 1920;
								module.height = 1080;
								module.fullscreen = false;
								break;
							case "Fullscreen":
								module.width = 0;
								module.height = 0;
								module.fullscreen = true;
								break;
							default:
								return;
						}

						switch (getSelectedButtonText(algorithmOption)) {
							case "Algorithm 1":
								module.algo = 0;
								break;
							case "Algorithm 2":
								module.algo = 1;
								break;
							case "Algorithm 3":
								module.algo = 2;
								break;
							case "Algorithm 4":
								module.algo = 3;
								break;
							default:
								return;
						}

						audioThread = new Thread(module);
						audioThread.start();
						recordState = true;
					} catch (Exception e1) {
						e1.printStackTrace();
					}

				}
				else {
					//stop the recording
					module.recording = false;
				}
				break;
			case "savePngImage":
				//save the image
				module.saveImage("png");
				infoBox("Image saved to your Pictures directory", "Saved Image");
				break;
			case "saveJpgImage":
				//save the image
				module.saveImage("jpg");
				infoBox("Image saved to your Pictures directory", "Saved Image");
				break;
			default:
				System.out.println(e.getActionCommand());
		}
	}

	private String getSelectedButtonText(ButtonGroup buttonGroup) {
		for (Enumeration<AbstractButton> buttons = buttonGroup.getElements(); buttons.hasMoreElements();) {
			AbstractButton button = buttons.nextElement();

			if (button.isSelected()) {
				return button.getText();
			}
		}

		return "";
	}

	public static void infoBox(String infoMessage, String titleBar)
	{
		JOptionPane.showMessageDialog(null, infoMessage, titleBar, JOptionPane.INFORMATION_MESSAGE);
	}


	private class ExitListener implements ActionListener{
	        
	        public void actionPerformed(ActionEvent e){
	            int response = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit?", 
	                    "Exit?", JOptionPane.YES_NO_OPTION);
	            
	            if (response == JOptionPane.YES_OPTION)
	                System.exit(0);	
	        }	
	            
	    }
	
	
}
