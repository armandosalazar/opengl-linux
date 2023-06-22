#include <GLFW/glfw3.h>
#include <stdio.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    printf("key: %d, scancode: %d, action: %d, mods: %d\n", key, scancode, action, mods);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}