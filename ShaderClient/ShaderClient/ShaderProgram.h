#pragma once
#include <string>
#include <fstream>
#include "glad/glad.h"

#define SHADER_LOG_SIZE 512

class ShaderProgram {
public:
	void Init(const char* fsFilePath, const char* vsFilePath);
	void Activate();
	void Delete();
	void BindVAO();

private:
	GLuint program;
	std::string GetFileContents(const char* fn);
	GLuint InitShader(const char* filePath, GLuint type);
	float** VBOs;
	GLuint VAO;
	GLuint** EBOs;
};