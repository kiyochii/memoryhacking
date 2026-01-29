cmake_minimum_required(VERSION 3.10)
project(ImguiApp)

set(CMAKE_CXX_STANDARD 17)
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

add_executable(imgui_app src/main.cpp ${IMGUI_SOURCES})

target_include_directories(imgui_app PRIVATE ${IMGUI_DIR} ${IMGUI_DIR}/backends)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(imgui_app glfw OpenGL::GL)