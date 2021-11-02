#include "input.h"
#include <stdio.h>

static void error_callback(int error, const char* desc) {
	printf("%i\n%s", error, desc);
}

static void windowClose_callback(GLFWwindow* window, int shouldClose) {
	if (shouldClose) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

static void key_callback(GLFWwindow* window, int key) {
	handleInput(window,key);
}

void setCallbacks(GLFWwindow* window) {
	glfwSetErrorCallback(error_callback);
	glfwSetWindowCloseCallback(window, windowClose_callback);
	glfwSetKeyCallback(window, key_callback);

}

void gameLoop(GLFWwindow* window) {
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int main() {
	if (!glfwInit()) {
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "leaf2", NULL, NULL);
	setCallbacks(window);
	
	if (!window){
		return 1;
	}
	glfwMakeContextCurrent(window);

	gameLoop(window);

	

	glfwDestroyWindow(window);
}