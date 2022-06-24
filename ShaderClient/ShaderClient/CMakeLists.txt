
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CMakeProject1 "ShaderClient.cpp"  "GUI.h" "GUI.cpp" "ShaderProgram.h" "ShaderProgram.cpp" "ObjectModel.h")
find_package(glad CONFIG REQUIRED)
target_link_libraries(CMakeProject1 PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(CMakeProject1 PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(CMakeProject1 PRIVATE imgui::imgui)
