//include glew
#include <GL/glew.h>

//inlcude glfw
#include <GLFW/glfw3.h>

#include <iostream>


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        //getchar();
        return -1;
    }

    //width and height of the window
    const int width = 1920, height = 1400;
    
    //aspect ratio of the window
    float aspectratio = float(width) / float(height);

    // Create a windowed mode window and its OpenGL context 
    window = glfwCreateWindow(width, height, "Computer Grpahics Project", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
       // this is  a comment to check smth
    std::cout << "Hello" << std::endl;
    /* Opengl settings and Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout << "Using GL Version: " << glGetString(GL_VERSION) << std::endl;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}