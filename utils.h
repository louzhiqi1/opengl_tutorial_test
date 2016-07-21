#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#define GLEW_STATIC
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;
// Window dimensions

extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUp;
extern GLfloat aspect;
extern GLfloat lastTime;
extern GLfloat deltaTime;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void initEnv();
bool initWindow(GLFWwindow* window);
void do_movement();

#endif