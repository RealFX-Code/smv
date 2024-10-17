#include <iostream>

#include "spdlog/spdlog.h"

// Including source files feels so wrong
#include "MainApplication.cpp"

#define PROJECT_NAME "SimpleMusicVisualizer"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

int main(int argc, char **argv) {

    spdlog::info("Starting {}!",PROJECT_NAME);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    spdlog::info("{} vulkan extensions supported.", extensionCount);

    MainApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        spdlog::critical("%s\n",e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
