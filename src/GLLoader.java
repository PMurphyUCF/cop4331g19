import org.lwjgl.*;
import org.lwjgl.glfw.*;
import org.lwjgl.opengl.*;


import static org.lwjgl.glfw.Callbacks.*;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.system.MemoryUtil.*;

import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.Random;

import javax.imageio.ImageIO;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;

public class GLLoader implements Runnable{

	// The window handle
	private long window;
	private int windowW;
	private int windowH;
	private int xArrayVal =64;
	private int yArrayVal =32;
	
	public int width = 0, height = 0, algo = 0, mode = 0;
	public boolean fullscreen = false, takeScreenshot = false;
	private volatile boolean running = true;
	private quaddata storage[][];
	private float alphaChannels[][] = new float[xArrayVal][yArrayVal];
	private colorquad colorChannels[][] = new colorquad[xArrayVal][yArrayVal];
	private colorquad colorChannelsActive[][] = new colorquad[xArrayVal][yArrayVal];
	private static final int[] xmove = {0,1,0,-1};
	private static final int[] ymove = {-1,0,1,0};
	private int[] AudioData = new int[512];
	private point pointMapper[];
	
	public void run() {
		running = true;
		runLoader(width, height, fullscreen, algo);
	}

	private class point{
		int x;
		int y;
	}
	
	private class quaddata{
        point bl; //bottom-left vertex
        point br; //bottom-right vertex
        point tr; //top-right vertex
        point tl; //top-left vertex
        quaddata(){
        	bl = new point();
        	br = new point();
        	tr = new point();
        	tl = new point();
        }
	}
	
	private class colorquad{
        float r;
        float g;
        float b;
	}
	
	public void terminate() {
		running = false;
	}

	public void runLoader(int width, int height, boolean fullscreen, int algoC) {
		System.out.println("Hello LWJGL " + Version.getVersion() + "!");
		arrayFiller();
		algo = algoC;
		arrayFiller();
		vertexArrayFillerInit();
		try {
			init(width, height, fullscreen);
			loop();
			// Free the window callbacks and destroy the window
			glfwFreeCallbacks(window);
			glfwDestroyWindow(window);
		} finally {
			// Terminate GLFW and free the error callback
			glfwTerminate();
			glfwSetErrorCallback(null).free();
		}
	}
	
	public long windowReturn(){
		return window;
	}
	
	private void init(int WIDTH, int HEIGHT, boolean FULLSCREEN) {
		// Setup an error callback. The default implementation
		// will print the error message in System.err.
		GLFWErrorCallback.createPrint(System.err).set();

		// Initialize GLFW. Most GLFW functions will not work before doing this.
		if ( !glfwInit() )
			throw new IllegalStateException("Unable to initialize GLFW");

		// Configure our window
		glfwDefaultWindowHints(); // optional, the current window hints are already the default
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // the window will stay hidden after creation
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // the window will be resizable

		// Create the window
		if(FULLSCREEN==false){
		window = glfwCreateWindow(WIDTH, HEIGHT, "Visualizer Output", NULL, NULL);
		}
		else{
		window = glfwCreateWindow(WIDTH, HEIGHT, "Visualizer Output", glfwGetPrimaryMonitor(), NULL);
		}
		if ( window == NULL )
			throw new RuntimeException("Failed to create the GLFW window");

		// Setup a key callback. It will be called every time a key is pressed, repeated or released.
		glfwSetKeyCallback(window, (window, key, scancode, action, mods) -> {
			if ( key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE )
				glfwSetWindowShouldClose(window, true); // We will detect this in our rendering loop
		});

		// Get the resolution of the primary monitor
		GLFWVidMode vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		// Center our window
		glfwSetWindowPos(
			window,
			(vidmode.width() - WIDTH) / 2,
			(vidmode.height() - HEIGHT) / 2
		);
		windowW=vidmode.width();
		windowH=vidmode.height();
		// Make the OpenGL context current
		glfwMakeContextCurrent(window);
		// Enable v-sync
		glfwSwapInterval(1);

		// Make the window visible
		glfwShowWindow(window);
	}

	private void loop() {
		// This line is critical for LWJGL's interoperation with GLFW's
		// OpenGL context, or any context that is managed externally.
		// LWJGL detects the context that is current in the current thread,
		// creates the GLCapabilities instance and makes the OpenGL
		// bindings available for use.
		GL.createCapabilities();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 640, 0, 640*windowH/windowW, 1, -1);
		glMatrixMode(GL_MODELVIEW);
		//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );   wireframemode
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		// the window or has pressed the ESCAPE key.
		int frame =0;
		while ( !glfwWindowShouldClose(window) ) {
			audioProc();
			draw();	
			frame++;
			if(frame%2==0){
				alphaFiller();
			}
			if(frame%3==0){
				if(algo!=0){
					fadeout();
				}
			}
			if(frame==30){
				frame=0;
			}
			sync(30);
			if (takeScreenshot) {
				saveImage();
			}
		}
	}
	
	private void draw() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		//setColor(material);	
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		double[] tmp;
		if (mode == 1) {
			tmp = AudioModule.staticData;
		}
		else {
			tmp = AudioModule.relData;
		}
 
		switch (algo){
			case 0:
			for(int i=0;i<xArrayVal;i++){
				for(int k=0;k<yArrayVal;k++){
					float rn = (float) tmp[(i + k*64) % 512];
					float rn1 = (float) tmp[(i + k*64) % 512];
					float rn2 = (float) tmp[(i + k*64) % 512];
	                System.out.printf("vals %d, %f\n", (i + k*64) % 512, tmp[(i + k*64) % 512]);
					glBegin(GL_QUADS);
					glColor3f(rn,rn1,rn2);
			        glVertex2i(storage[i][k].bl.x,storage[i][k].bl.y); //bottom-left vertex
			      //  glColor3f(rn,rn1,rn2);
			        glVertex2i(storage[i][k].br.x, storage[i][k].br.y); //bottom-right vertex
			      //  glColor3f(rn,rn1,rn2);
			        glVertex2i(storage[i][k].tr.x, storage[i][k].tr.y); //top-right vertex
			        //glColor3f(rn,rn1,rn2);
			        glVertex2i(storage[i][k].tl.x, storage[i][k].tl.y); //top-left vertex
			        glEnd();
				}
			}
			break;
			case 1:
			int pointerA;
			int rand;
			for(int a=0;a<512;a++){
				if(AudioData[a]!=0){
					rand = (int) Math.floor(Math.random() * 2) -1;
					pointerA = a*4 + rand;
					if(pointerA>=xArrayVal*yArrayVal){
						pointerA=xArrayVal*yArrayVal-1;
					}
					colorCrawler(pointMapper[pointerA].x,pointMapper[pointerA].y,AudioData[a],colorChannels[pointMapper[pointerA].x][pointMapper[pointerA].y]);
				}
			}
			for(int i=0;i<xArrayVal;i++){
				for(int k=0;k<yArrayVal;k++){
					glBegin(GL_QUADS);
					glColor4f(colorChannelsActive[i][k].r,colorChannelsActive[i][k].g,colorChannelsActive[i][k].b,alphaChannels[i][k]);
			        glVertex2i(storage[i][k].bl.x,storage[i][k].bl.y); //bottom-left vertex
			        glVertex2i(storage[i][k].br.x, storage[i][k].br.y); //bottom-right vertex
			        glVertex2i(storage[i][k].tr.x, storage[i][k].tr.y); //top-right vertex
			        glVertex2i(storage[i][k].tl.x, storage[i][k].tl.y); //top-left vertex
			        glEnd();
				}
			}
			break;
			
			
			
			
		}

		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		glfwSwapBuffers(window);
		glfwPollEvents();	
	}
	
	private void arrayFiller(){
		storage = new quaddata[xArrayVal][yArrayVal];
		pointMapper = new point[xArrayVal*yArrayVal];
		int SIZE=16; 
		int PADDING_HALF=2;	
		int x=0;
		int y=0;
		int tracker=0;
		for(int i=0;i<xArrayVal;i++){
			x++;
			y=0;
			for(int k=0;k<yArrayVal;k++){
				y++;
				point cur = new point();
				cur.x=i;
				cur.y=k;
				pointMapper[tracker]=cur;
				tracker++;
				storage[i][k] = new quaddata();
		        storage[i][k].bl.x = SIZE*(x-1) + PADDING_HALF;
		        storage[i][k].bl.y = SIZE*(y-1) + PADDING_HALF;
		       
		        storage[i][k].br.x = SIZE*x - PADDING_HALF;
		        storage[i][k].br.y = SIZE*(y-1) + PADDING_HALF;
		        
		        storage[i][k].tr.x = SIZE*x - PADDING_HALF;
		        storage[i][k].tr.y = SIZE*y - PADDING_HALF;
		        
		        storage[i][k].tl.x = SIZE*(x-1) + PADDING_HALF;
		        storage[i][k].tl.y = SIZE*y - PADDING_HALF;
		      
			}
		}
	}
	
	private void colorCrawler (int x, int y, int Magnitude, colorquad Color){
		if(Magnitude <=0){
			return;
		}
		int ytemp;
		int xtemp;
		for(int i=0; i<4; i++)
		{	
			xtemp = x+xmove[i];
			ytemp = y+ymove[i];
			if (!((xtemp <0) || (xtemp>(xArrayVal-1)) || (ytemp <0) || (ytemp>(yArrayVal-1))))
			{		
				colorChannelsActive[x][y].r = (colorChannelsActive[x][y].r + Color.r)/2;
				colorCrawler(xtemp, ytemp, Magnitude--, Color);
			}
		}
	}
	
	private void fadeout(){
		for(int i=0;i<xArrayVal;i++){
			for(int k=0;k<yArrayVal;k++){
				colorChannelsActive[i][k].r = colorChannelsActive[i][k].r - 0.05f;
				if(colorChannelsActive[i][k].r<0.0f){
					colorChannelsActive[i][k].r=0.0f;
				}
				colorChannelsActive[i][k].g = colorChannelsActive[i][k].g - 0.05f;
				if(colorChannelsActive[i][k].g<0.0f){
					colorChannelsActive[i][k].g=0.0f;
				}
				colorChannelsActive[i][k].b = colorChannelsActive[i][k].b - 0.05f;
				if(colorChannelsActive[i][k].b<0.0f){
					colorChannelsActive[i][k].b=0.0f;
				}
			}
		}
	}
	
	private void audioProc(){
		for(int i=0; i<512 ; i++){
				if(AudioModule.relData[i] <= 0.05d){
					AudioData[i] =0;	
				}
				else{
					if(AudioModule.relData[i] > 0.05d){
						AudioData[i] =1;	
					}
					if(AudioModule.relData[i] >= 0.4d){
						AudioData[i] =2;	
					}
					if(AudioModule.relData[i] >= 0.6d){
						AudioData[i] =3;	
					}	

					if(AudioModule.relData[i] >= 0.9d){
						AudioData[i] =4;	
					}
					
					
				}
		//	AudioData[i] = (float) AudioModule.relData[i];
		}		
	}
	
	private void vertexArrayFillerInit(){
		float theta;
		for(int i =0; i<xArrayVal; i++){
			for(int k=0; k<yArrayVal;k++){
				alphaChannels[i][k]=1.0f;
				colorquad colors = new colorquad();
				colorquad colorsActive = new colorquad();
				theta = (float) i * k;
			    while (theta < 0){
			    	theta += 360;
			    }	        			 
			    while (theta >= 360){
			    	theta -= 360;
			    }			   	 
			    if (theta < 120) {
			    	colors.g = theta / 120;
			        colors.r = 1 - colors.g;
			        colors.b = 0;
			    } else if (theta < 240) {    
			    	colors.b = (theta - 120) / 120;
			        colors.g = 1 - colors.b;
			        colors.r = 0;
			    } else {
			    	colors.r = (theta - 240) / 120;
			    	colors.b = 1 - colors.r;
			        colors.g = 0;
			    }
			    colorsActive.r = 0.0f;
		    	colorsActive.b = 0.0f;
		        colorsActive.g = 0.0f;
				colorChannels[i][k]=colors;
				colorChannelsActive[i][k]=colorsActive;
			}
		}
	}
	
	private void alphaFiller(){
		float alpha;
		Random Random = new Random() ;
		for(int i =0; i<xArrayVal; i++){
			for(int k=0; k<yArrayVal;k++){
				int seed = Random.nextInt(1000);
				alpha = alphaChannels[i][k]  + noise.noise(i+seed,k+seed)/8;
				if(alpha >= 1.0f || alpha <= 0.0f ){
					alphaChannels[i][k] = 1.0f;
				}
				else{
					alphaChannels[i][k]=alpha;
				}		
			}
		}
	}
	
	
    private long variableYieldTime, lastTime;
    
    /**
     * An accurate sync method that adapts automatically
     * to the system it runs on to provide reliable results.
     * 
     * @param fps The desired frame rate, in frames per second
     * @author kappa (On the LWJGL Forums)
     */
    
    private void sync(int fps) {
        if (fps <= 0) return;
          
        long sleepTime = 1000000000 / fps; // nanoseconds to sleep this frame
        // yieldTime + remainder micro & nano seconds if smaller than sleepTime
        long yieldTime = Math.min(sleepTime, variableYieldTime + sleepTime % (1000*1000));
        long overSleep = 0; // time the sync goes over by
          
        try {
            while (true) {
                long t = System.nanoTime() - lastTime;
                  
                if (t < sleepTime - yieldTime) {
                    Thread.sleep(1);
                }else if (t < sleepTime) {
                    // burn the last few CPU cycles to ensure accuracy
                    Thread.yield();
                }else {
                    overSleep = t - sleepTime;
                    break; // exit while loop
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }finally{
            lastTime = System.nanoTime() - Math.min(overSleep, sleepTime);
             
            // auto tune the time sync should yield
            if (overSleep > variableYieldTime) {
                // increase by 200 microseconds (1/5 a ms)
                variableYieldTime = Math.min(variableYieldTime + 200*1000, sleepTime);
            }
            else if (overSleep < variableYieldTime - 200*1000) {
                // decrease by 2 microseconds
                variableYieldTime = Math.max(variableYieldTime - 2*1000, 0);
            }
        }
    }

	public void destroyWindow(){
		try {
			Robot robot = new Robot();

			// Simulate a mouse click
			robot.mousePress(InputEvent.BUTTON1_MASK);
			robot.mouseRelease(InputEvent.BUTTON1_MASK);

			robot.delay(50);

			// Simulate a key press
			robot.keyPress(KeyEvent.VK_ALT);
			robot.keyPress(KeyEvent.VK_TAB);
			robot.delay(20);
			robot.keyRelease(KeyEvent.VK_ALT);
			robot.keyRelease(KeyEvent.VK_TAB);

			robot.delay(50);

			robot.keyPress(KeyEvent.VK_ESCAPE);
			robot.keyRelease(KeyEvent.VK_ESCAPE);

		} catch (AWTException e) {
			e.printStackTrace();
		}
	}

    private void saveImage() {
		glReadBuffer(GL_FRONT);
		int bpp = 4;
		ByteBuffer buffer = BufferUtils.createByteBuffer(width * height * bpp);
		GL11.glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

		String dir = System.getProperty("user.home");
		dir += "\\Pictures\\SoundVisualizer";

		File directory = new File(dir);

		if (!directory.exists()) {
			try {
				directory.mkdir();
			}
			catch (SecurityException se) {
				se.printStackTrace();
			}
		}

		dir += "\\ScreenCapture-" + System.currentTimeMillis() + ".png";
		File file = new File(dir);
		String format = "PNG";
		BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				int i = (x + (width * y)) * bpp;
				int r = buffer.get(i) & 0xFF;
				int g = buffer.get(i+1) & 0xFF;
				int b = buffer.get(i+2) & 0xFF;
				image.setRGB(x, height - (y+1), (0xFF << 24) | (r << 16) | (g << 8) | b);
			}
		}

		try {
			ImageIO.write(image, format, file);
		}
		catch (IOException e) {
			e.printStackTrace();
		}

		takeScreenshot = false;
	}
	
	/*public static void main(String[] args) {
		new GLLoader().run(1280,720,true);
	}*/
	
}