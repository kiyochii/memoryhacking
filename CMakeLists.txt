cmake_minimum_required(VERSION 3.10)
project(ImguiApp)

set(CMAKE_CXX_STANDARD 17)

# 1. Collect all your project source files from src/
file(GLOB_RECURSE PROJECT_SOURCES 
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
)

# 2. Define ImGui directory and core files
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# 3. Create the executable using both your sources and ImGui
add_executable(imgui_app ${PROJECT_SOURCES} ${IMGUI_SOURCES})

# 4. Include paths
target_include_directories(imgui_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src 
    ${IMGUI_DIR} 
    ${IMGUI_DIR}/backends
)

# 5. Link Libraries
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(imgui_app PRIVATE glfw OpenGL::GL)

# 6. Copy fonts to build directory
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/misc" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")