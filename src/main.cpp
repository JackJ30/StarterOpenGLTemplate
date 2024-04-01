#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    // Set up GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 800, "Hello Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    // Load OpenGL and configure
    gladLoadGL();

    int w,h;
	glfwGetFramebufferSize(window, &w, &h); // get size
    glViewport(0,0,w,h); // tell OpenGL size

    glClearColor(0.9f, 0.6f, 0.85f, 1.0f);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}