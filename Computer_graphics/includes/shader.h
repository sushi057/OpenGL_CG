#ifndef SHADER_H
#define SHADER_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<string>
#include<iostream>
#include<fstream>
#include<map>
#include"matrix.h"

class Shader
{
public:
	unsigned int ID;
	//constructor generates shader as needed
	Shader(const char* vertexPath, const char* fragmentPath)
	{
		//get the vertex and fragment path from the filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();


		//compile shaders
		unsigned int vertex, fragment;

		//vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		//checkCompileErrors(vertex, "VERTEX");

		// fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		//checkCompileErrors(fragment, "FRAGMENT");

		//shaderProgram
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		/*//check link status
		int program_linked;

		GLCall(glGetProgramiv(ID, GL_LINK_STATUS, &program_linked));
		std::cout << "Program link status: " << program_linked << std::endl;
		if (program_linked != GL_TRUE)
		{
			GLsizei log_length = 0;
			GLchar message[1024];
			GLCall(glGetProgramInfoLog(ID, 1024, &log_length, message));
			std::cout << "Failed to link program" << std::endl;
			std::cout << message << std::endl;
		}

		GLCall(glValidateProgram(ID));*/

		//delete shaders after compiled
		glDeleteShader(vertex);
		glDeleteShader(fragment);

	}

	// activate the shader
	void use()
	{
		glUseProgram(ID);
	}
	// utility uniform functions
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

};
#endif