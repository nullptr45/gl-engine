#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

static constexpr int WIDTH = 1280;
static constexpr int HEIGHT = 720;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "gl-engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to load OpenGL extensions" << std::endl;
        return -1;
    }

    glClearColor(0.392, 0.584, 0.929, 1.0);
    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    return 0;
}
