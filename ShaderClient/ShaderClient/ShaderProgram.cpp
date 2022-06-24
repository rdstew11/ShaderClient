#include "ShaderProgram.h"

void ShaderProgram::Init(const char* fsFilePath, const char* vsFilePath) {
	program = glCreateProgram();
	GLuint fragShader = InitShader(fsFilePath, GL_FRAGMENT_SHADER);
	GLuint vertShader = InitShader(vsFilePath, GL_VERTEX_SHADER);
	glAttachShader(program, fragShader);
	glAttachShader(program, vertShader);
	glLinkProgram(program);
	GLint result;
	char strInfoLog[SHADER_LOG_SIZE];
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(program, SHADER_LOG_SIZE, NULL, strInfoLog);
		throw(strInfoLog);
	}
	glDeleteShader(fragShader);
	glDeleteShader(vertShader);
}

GLuint ShaderProgram::InitShader(const char* filePath, GLuint type) {

	std::string code = GetFileContents(filePath);
	const char* source = code.c_str();

	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	char strInfoLog[SHADER_LOG_SIZE];
	if (result == GL_FALSE) {
		glGetShaderInfoLog(shader, SHADER_LOG_SIZE, NULL, strInfoLog);
		throw(strInfoLog);
	}

	return shader;
}


void ShaderProgram::Activate() {
	glUseProgram(program);
}

void ShaderProgram::Delete() {
	glDeleteProgram(program);
}

// Returns content from a given file 
std::string ShaderProgram::GetFileContents(const char* fn) {
	std::ifstream in(fn, std::ios::binary);
	if (in) {
		std::string contents;

		//	getting file size and resizing string
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);


		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}