import org.lwjgl.*;
import org.lwjgl.glfw.*;
import org.lwjgl.opengl.*;

import static org.lwjgl.glfw.Callbacks.*;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.system.MemoryUtil.*;


public class GLLoader {

	// The window handle
	private long window;

	public void run() {
		System.out.println("Hello LWJGL " + Version.getVersion() + "!");

		try {
			init();
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

	private void init() {
		// Setup an error callback. The default implementation
		// will print the error message in System.err.
		GLFWErrorCallback.createPrint(System.err).set();

		// Initialize GLFW. Most GLFW functions will not work before doing this.
		if ( !glfwInit() )
			throw new IllegalStateException("Unable to initialize GLFW");

		// Configure our window
		glfwDefaultWindowHints(); // optional, the current window hints are already the default
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // the window will stay hidden after creation
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); // the window will be resizable

		int WIDTH = 800;
		int HEIGHT = 600;

		// Create the window
		window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World!", NULL, NULL);
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
		glOrtho(0, 800, 0, 600, 1, -1);
		glMatrixMode(GL_MODELVIEW);
		//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );   wireframemode
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		// the window or has pressed the ESCAPE key.
		while ( !glfwWindowShouldClose(window) ) {
			draw();	
		}
	}
	
	private void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		int SIZE=32; 
		int PADDING_HALF=1;	
		//setColor(material);	
		int x=0;
		int y=0;	
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		for(int i=0;i<32;i++){
			x++;
			y=0;
			for(int k=0;k<32;k++){
				y++;
				glColor3f(1.0f,1.0f, 1.0f);
				glBegin(GL_QUADS);
		        glVertex2i(SIZE*(x-1) + PADDING_HALF, SIZE*(y-1) + PADDING_HALF); //bottom-left vertex
		        glVertex2i(SIZE*x     - PADDING_HALF, SIZE*(y-1) + PADDING_HALF); //bottom-right vertex
		        glVertex2i(SIZE*x     - PADDING_HALF, SIZE*y     - PADDING_HALF); //top-right vertex
		        glVertex2i(SIZE*(x-1) + PADDING_HALF, SIZE*y     - PADDING_HALF); //top-left vertex
		        glEnd();
			}
		}
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glfwSwapBuffers(window);
		glfwPollEvents();
			
	}
		
	
	public static void main(String[] args) {
		new GLLoader().run();
	}
	
}