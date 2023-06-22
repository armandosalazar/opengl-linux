#include <GLFW/glfw3.h>
#include <stdio.h>
#include "keys.h"

// #include <arpa/inet.h>

// #define PORT 8080
// #define BUFFER_SIZE 1024

// typedef struct sockaddr_in sockaddr_in;

// void run_socker() {
// 	sockaddr_in address;
// 	const char hello[] = "Hello from server";
// }

void draw()
{
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
}

int main(void)
{
	if (!glfwInit())
	{
		printf("Error: glfwInit failed\n");
		return 1;
	}

	GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	// Check if window was created
	if (!window)
	{
		printf("Error: glfwCreateWindow failed\n");
		glfwTerminate();
		return 1;
	}

	// Register callback key
	glfwSetKeyCallback(window, key_callback);

	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		// Draw
		display();

		// Intercahnge buffers and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
