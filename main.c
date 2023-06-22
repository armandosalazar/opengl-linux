#include <GLFW/glfw3.h>
#include <stdio.h>

void draw() {
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
}

int main(void) {
	if (!glfwInit()) {
		printf("Error: glfwInit failed\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window) {
		printf("Error: glfwCreateWindow failed\n");
		return 1;
	}

	glfwMakeContextCurrent(window);

	// Render loop
	while (!glfwWindowShouldClose(window)) {
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
