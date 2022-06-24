#include "GUI.h"
#include <stdlib.h>
#include <fstream>

/*
	TO DO
1. Refactor Main Function to be cleaner
	> Utilize Shader Program
2. Create UI linked to shader input variables


*/



int main()
{
	//setup window
	if (!glfwInit()) {
		return 1;
	}

	// set GL+GLSL versions
	//GL 3.2 + GLSL 150
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//Create window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Shader Client", NULL, NULL);
	if (window == NULL) {
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	//Load OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw("Unable to context to OpenGL");
	}

	int sWidth, sHeight;
	glfwGetFramebufferSize(window, &sWidth, &sHeight);
	glViewport(0, 0, sWidth, sHeight);
	
	
	GUI gui;
	gui.Init(window, glsl_version);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
				
		gui.NewFrame();
		gui.Update();
		gui.Render(window);
		
		glfwSwapBuffers(window);
	}
	gui.Shutdown();

	return 0;
}


