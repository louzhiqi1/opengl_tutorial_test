#include "Shader.h"
#include "utils.h"
#define GLEW_STATIC
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//
//static glm::vec3 cameraPos;
//static glm::vec3 cameraFront;
//static glm::vec3 cameraUp;
const GLuint WIDTH = 800, HEIGHT = 600;

int tutorial9()
{
	initEnv();

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

	if (!initWindow(window))
	{
		return 1;
	}

	// Build and compile our shader program
	Shader ourShader("shader.vs", "shader.frag");

	/*glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/
	return 0;
}