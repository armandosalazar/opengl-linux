#include <GLFW/glfw3.h>
#include <stdio.h>
#include <arpa/inet.h>

#include "keys.h"

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

int run_socker()
{
	int server_fd, new_socket, valread;

	sockaddr_in address;

	int addrlen = sizeof(address);

	char buffer[BUFFER_SIZE] = {0};
	printf("%s\n", buffer);

	const char hello[] = "Hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		printf("Error: socket failed\n");
		return 1;
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (sockaddr *)&address, sizeof(address)) < 0)
	{
		printf("Error: bind failed\n");
		return 1;
	}

	if (listen(server_fd, 3) < 0)
	{
		printf("Error: listen failed\n");
		return 1;
	}

	if ((new_socket = accept(server_fd, (sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		printf("Error: accept failed\n");
		return 1;
	}

	valread = read(new_socket, buffer, BUFFER_SIZE);
	printf("%s\n", buffer);

	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent\n");
}

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
