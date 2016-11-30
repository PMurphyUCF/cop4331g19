import org.lwjgl.*;
import org.lwjgl.glfw.*;
import org.lwjgl.opengl.*;

import static org.lwjgl.glfw.Callbacks.*;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.system.MemoryUtil.*;
import java.util.Random;

public class GLLoader implements Runnable{

	// The window handle
	private long window;
	private int windowW;
	private int windowH;

	public int width = 0, height = 0;
	public boolean fullscreen = false;
	public void run() {
		runLoader(width, height, fullscreen);
	}

	public void runLoader(int width, int height, boolean fullscreen) {
		System.out.println("Hello LWJGL " + Version.getVersion() + "!");
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
		while ( !glfwWindowShouldClose(window) ) {
			draw();	
			sync(5);
		}
	}
	
	private void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		int SIZE=16; 
		int PADDING_HALF=2;	
		//setColor(material);	
		int x=0;
		int y=0;	
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		Random Random = new Random() ; 
		for(int i=0;i<64;i++){
			x++;
			y=0;
			for(int k=0;k<32;k++){
				y++;
				float rn = Random.nextFloat();
				float rn1 = Random.nextFloat();
				float rn2 = Random.nextFloat();
				glBegin(GL_QUADS);
				glColor3f(rn,rn1,rn2);
		        glVertex2i(SIZE*(x-1) + PADDING_HALF, SIZE*(y-1) + PADDING_HALF); //bottom-left vertex
		      //  glColor3f(rn,rn1,rn2);
		        glVertex2i(SIZE*x     - PADDING_HALF, SIZE*(y-1) + PADDING_HALF); //bottom-right vertex
		      //  glColor3f(rn,rn1,rn2);
		        glVertex2i(SIZE*x     - PADDING_HALF, SIZE*y     - PADDING_HALF); //top-right vertex
		        //glColor3f(rn,rn1,rn2);
		        glVertex2i(SIZE*(x-1) + PADDING_HALF, SIZE*y     - PADDING_HALF); //top-left vertex
		        glEnd();
			}
		}
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glfwSwapBuffers(window);
		glfwPollEvents();
			
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
    
	
	/*public static void main(String[] args) {
		new GLLoader().run(1280,720,true);
	}*/
	
}