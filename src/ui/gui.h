#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <thread>
#include <stdexcept>
#include <iostream>
class GUI
{
    public: 
            GUI();
            void run();
            void initThread();
                
    private:
            void InitGlfw();
            void CreateWindowGlfw();
            void destruct();

            GLFWwindow* window;    

    };