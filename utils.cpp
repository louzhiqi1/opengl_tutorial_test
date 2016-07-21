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

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
const GLuint WIDTH = 800, HEIGHT = 600;
bool keys[1024];

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

GLfloat lastX = 400, lastY = 300;

GLfloat pitch = 0.0f;
GLfloat yaw = 0.0f;
bool firstMouse = true;
GLfloat aspect = 45.0f;
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	GLfloat cameraSpeed = 0.05f;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;

		return;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	GLfloat sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.9f)
		pitch = 89.9f;
	if (pitch < -89.9f)
		pitch = -89.9f;

	if (yaw > 89.9f)
		yaw = 89.9f;
	if (yaw < -89.9f)
		yaw = -89.9f;

	glm::vec3 front;
	front.x = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = cos(glm::radians(pitch)) * cos(glm::radians(yaw));

	cameraFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	cout << yoffset << endl;
	if (aspect >= 1.0f && aspect <= 45.0f)
		aspect -= yoffset;
	if (aspect <= 1.0f)
		aspect = 1.0f;
	if (aspect >= 45.0f)
		aspect = 45.0f;
}

void do_movement()
{
	GLfloat cameraSpeed = 5.0f *deltaTime;

	if (keys[GLFW_KEY_W])
			cameraPos += cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_S])
		cameraPos -= cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_A])
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (keys[GLFW_KEY_D])
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;	
}

void initEnv()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glewExperimental = GL_TRUE;
}

bool initWindow(GLFWwindow* window)
{
	// Create a GLFWwindow object that we can use for GLFW's functions

	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions

	// Initialize GLEW to setup the OpenGL Function pointers

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		cout << "Error: %s\n" << glewGetErrorString(err) << endl;

		return false;
	}
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	return true;
}
