#include <iostream>

#include "log.h"

// Including source files feels so wrong
#include "MainApplication.cpp"

#define PROJECT_NAME "SimpleMusicVisualizer"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

int main(int argc, char **argv) {
    char StartingMsg[100];
    sprintf_s(StartingMsg, sizeof(StartingMsg), "Starting %s!", PROJECT_NAME);
    std::string StartingMsg_s(StartingMsg);
    Log(INFO, StartingMsg_s);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

// Log
    char ExtentionCountMsg[100];
    sprintf_s(ExtentionCountMsg, sizeof(ExtentionCountMsg), "%u extensions supported!", extensionCount);
    std::string ExtentionCountMsg_s(ExtentionCountMsg);
    Log(INFO, ExtentionCountMsg_s);

    MainApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        Log(FATAL, e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
