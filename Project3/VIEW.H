#ifndef VIEW
#define VIEW

#include "SDL.h"
#include "Model.h"
#include "glew.h"
#include "Camera.h"
#include <fstream>
#include <string>
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class View {
private:
	GLuint mvp_uniform_attribute;

	GLuint triangle_settings;
	GLuint triangle_buffer;
	GLuint color_buffer;
	GLuint shader_program;
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint element_buffer;
	
	Model& model;

	class SceneLoader {
	private:
		View& view;
		std::vector<float> rectangle_data_vector;
		void loadAllRectangles();
		void loadBlock(const Block& block);
		void loadRectangle(const Rectangle& rectangle);
		void loadRectangleVertex(const int& vertex_number, const Rectangle& rectangle, const glm::vec3& vertex_normal);
	public:
		GLuint number_of_verticies_in_scene;
		SceneLoader(View& view);
	};
	SceneLoader* scene_loader;
public:
	Camera& camera;
	View(Model& model, Camera& camera);
	void render(SDL_Window* window);
	~View();
private:
	GLuint light_position_uniform_attribute;
	GLuint camera_position_uniform_attribute;
public:
	glm::vec3 light_position = glm::vec3(250.0f, 250.0f, 250.0f);
};

//Utilities
//Shader object creation function. compiles both vertex and fragment shaders
GLuint LoadShader(std::string shader_file_name, GLenum shader_type);
//Help function to check if shader program successfully linked vertex and fragment shaders
void CheckLinkStatus(GLuint& shader_program);

#endif