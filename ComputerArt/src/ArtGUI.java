import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.*;

public class ArtGUI extends JApplet implements ActionListener {

	//false when not recording, true when recording
	boolean recordState;
	JButton recordInput, saveImage;
	JSlider slider;
	
	public void init(){
		recordState = false;
	
		//setDefaultCloseOperation(JApplet.EXIT_ON_CLOSE);
		setSize(770,550);
		
		createMenu();
		
		
		
		createSouthPanel();
		
		
		createEastPanel();
		
		createWestPanel();
		
	
	}
	
	private void createWestPanel(){
		JPanel westPanel = new JPanel();
		westPanel.setLayout(new BoxLayout(westPanel,BoxLayout.Y_AXIS));
        westPanel.setBorder(BorderFactory.createTitledBorder("Select Style"));
        add(westPanel,BorderLayout.WEST);
        
        ButtonGroup algorithmOption = new ButtonGroup();
        JRadioButton algo1 = new JRadioButton("Algorithm 1");
        algo1.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        JRadioButton algo2 = new JRadioButton("Algorithm 2");
        algo2.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        JRadioButton algo3 = new JRadioButton("Algorithm 3");
        algo3.setFont(new Font(Font.DIALOG,Font.PLAIN,24));
        JRadioButton algo4 = new JRadioButton("Algorithm 4");
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
		//eastPanel.setLayout(new BoxLayout(eastPanel,BoxLayout.Y_AXIS));
        //add(eastPanel,BorderLayout.EAST);
        
        eastPanel.setBorder(BorderFactory.createTitledBorder("Image Output"));
        add(eastPanel,BorderLayout.CENTER);
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
        
        ButtonGroup modeOption = new ButtonGroup();
        JRadioButton staticImage = new JRadioButton("Static Image");
        JRadioButton realImage = new JRadioButton("Real Time Image");
        modeOption.add(staticImage);
        modeOption.add(realImage);

		top.add(staticImage);
		top.add(realImage);
        
        saveImage = new JButton("Save Image");
        saveImage.setPreferredSize(new Dimension(170, 60));
        saveImage.setMinimumSize(new Dimension(170, 60));
        saveImage.setMaximumSize(new Dimension(170, 60));
		saveImage.setActionCommand("saveImage");
		saveImage.addActionListener(this);
		top.add(saveImage);

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
		
		//menu for modes
		JMenu modeOptions = new JMenu("Mode");
		modeOptions.setMnemonic('M');
		menuBar.add(modeOptions);
		
		setJMenuBar(menuBar);
		
		//menuitems for File
		JMenuItem saveOption = new JMenuItem("Save Image",KeyEvent.VK_S);
		fileOptions.add(saveOption);
		JMenuItem exitOption = new JMenuItem("Exit",KeyEvent.VK_E);
		exitOption.addActionListener(new ExitListener());
		fileOptions.add(exitOption);
		
		//menuitems for Mode
		JMenuItem selectMode = new JMenuItem("Select Operation Mode...",KeyEvent.VK_S);
		modeOptions.add(selectMode);
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch (e.getActionCommand()) {
			case "recordInput":
				recordState = !recordState;

				if (recordState) {
					recordInput.setText("Stop Recording");
					//start the recording
					//need to get chosen algorithm
					int chosenAlgo = 1;
					AudioModule module = new AudioModule(chosenAlgo);
					//need to get slider position
					int sliderPos = 4;
					try {
						module.runAudioModule(sliderPos);
					} catch (Exception e1) {
						e1.printStackTrace();
					}
				}
				else {
					recordInput.setText("Record Input");
					//stop the recording
				}
				break;
			case "saveImage":
				//save the image
				System.out.println("Saving...");
				break;
			default:
				System.out.println(e.getActionCommand());
		}
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
