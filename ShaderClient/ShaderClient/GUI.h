#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "ShaderProgram.h"

class GUI {
public:
	void Init(GLFWwindow* window, const char* glsl_version);
	virtual void Update();
	void Render(GLFWwindow* window);
	void NewFrame();
	void Shutdown();
	void ShowDemo();
	void Input();
	void ShaderOutput(ShaderProgram* program);

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	float f = 0.0f;
	int counter = 0;
};