#include "GUI.h"


void GUI::Init(GLFWwindow* window, const char* glsl_version){
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();
}

void GUI::NewFrame(){
	// Gives input to imgui and starts a new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void GUI::Update() {
	Input();
}

void GUI::Input() {
	static char input[256] = "Input";
	ImGui::Begin("Input");
	ImGui::InputTextMultiline("Input", input, IM_ARRAYSIZE(input));
	ImGui::End();
}

void GUI::ShaderOutput(ShaderProgram* program) {

}



void GUI::Render(GLFWwindow* window){
	
	ImGui::Render();
	int sWidth, sHeight;
	glfwGetFramebufferSize(window, &sWidth, &sHeight);
	glViewport(0, 0, sWidth, sHeight);
	glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::Shutdown(){
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
