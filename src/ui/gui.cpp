#include "gui.h"
GUI::GUI()
{
    try{
         CreateWindowGlfw();
         InitGlfw();
     }
     catch(const std::runtime_error& e){
           std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
void GUI::run()
{

    while (!glfwWindowShouldClose(window)) {
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::ShowStyleEditor();
    
    ImGui::End();

    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_MULTISAMPLE);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    }
    destruct();
}
 void GUI::destruct()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}
void GUI::CreateWindowGlfw(){
        if (!glfwInit())
        throw std::runtime_error("glfwInit error");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);      
        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_SAMPLES, 9); // 4x Anti-aliasing
        window = glfwCreateWindow(1280, 800, "UI", nullptr, nullptr);
        glfwMakeContextCurrent(window); 
        if (!window)
            throw std::runtime_error("glfwCreateWindow error");
        
        glfwSwapInterval(1);
}
void GUI::InitGlfw(){

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");
    
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;
        float xscale, yscale;
        glfwGetWindowContentScale(window, &xscale, &yscale);
        float baseFontSize = 20.0f;
        std::string fontPath = "misc/Inter/Inter.ttf";
        
        ImFont* font = io.Fonts->AddFontFromFileTTF(fontPath.c_str(), baseFontSize * xscale);

        if (font == nullptr) {
            std::cerr << "Failed to load Inter font! Using default." << std::endl;
            io.Fonts->AddFontDefault();
        }
}


void GUI::initThread(){
    std::thread guiThread(&GUI::run, this);
    guiThread.detach();
}