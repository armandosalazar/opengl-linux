#include <GLFW/glfw3.h>
#include <stdio.h>

int main(void) {
	GLFWwindow* window;
	// importante iniciar como NULL
	GLFWwindow* w = NULL;

	printf("%p\n", window);
	printf("%p\n", w);

	if (w == NULL)
		printf("%s\n", "is null");

	if (window == NULL)
		printf("%s\n",  "null");

	printf("%d\n", sizeof(window));
	printf("%d\n", sizeof(w));

	return 0;
}
