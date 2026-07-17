#include <iostream>

// Minimal OpenGL example
// Creates a black window and finishes the application once its closed.

#include <GL/glew.h>     // interact with OpenGL
#include <GLFW/glfw3.h>  // create windows

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
  GLFWwindow *window;  // created window

  if (glfwInit() == 0) {
    std::cerr << "GLFW failed to initiate." << std::endl;
    return -1;
  }

  window = glfwCreateWindow(800, 600, "A normal window", nullptr, nullptr);

  // check if window was created successfully
  if (window == nullptr) {
    std::cerr << "GLFW failed to create window." << std::endl;
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  
  if (glewInit() != GLEW_OK) {
    std::cerr << "GLFW failed to create window." << std::endl;
    glfwTerminate();
    return -1;
  }

  //enable the 2D textures
  glEnable(GL_TEXTURE_2D);

  unsigned int textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);

  //load the texture
  int width, height, channels;
  unsigned char* pixels = stbi_load("texture1.png", &width, &height, &channels, 4);

  //get the image on OpneGL
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

  //set parameters for the texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

  while (glfwWindowShouldClose(window) == 0) {
    // clear the window
    glClear(GL_COLOR_BUFFER_BIT);

    //default color for background
    glClearColor(0.f, 0.f, 0.f, 1.f);

    //start drawing striped lines
    glBegin(GL_LINE_STRIP);

    //set the color of the lines
    glColor4f(1.f, 1.f, 1.f, 0.f);
    //three vertices for two lines
    glVertex3f(0.6f, -0.9f, 0.0f);
    glVertex3f(-0.7f, -0.2f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);

    //end drawing lines
    glEnd();

    //begin drawing striped triangles
    glBegin(GL_TRIANGLE_STRIP);

    //set the u and v
    glTexCoord2f(0, 0);
    //set the color of the vertex
    glColor4f(0.f, 0.f, 1.f, 0.f);
    //create the vertex
    glVertex3f(-0.5f, -0.5f, 0.0f);

    //set the u and v
    glTexCoord2f(2, 0);
    //set the color of the vertex
    glColor4f(0.f, 1.f, 1.f, 0.f);
    //create the vertex
    glVertex3f(0.5f, -0.5f, 0.0f);

    //set the u and v
    glTexCoord2f(0, 2);
    //set the color of the vertex
    glColor4f(1.f, 0.f, 1.f, 0.f);
    //create the vertex
    glVertex3f(-0.5f, 0.5f, 0.0f);

    //set the u and v
    glTexCoord2f(2, 2);
    //set the color of the vertex
    glColor4f(0.f, 1.f, 0.f, 0.f);
    //create the vertex
    glVertex3f(0.5f, 0.5f, 0.0f);

    //end drawing triangles
    glEnd();

    // swap buffer
    glfwSwapBuffers(window);

    // process user events
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
