#pragma once

#include "Ferret/Renderer/GraphicsContext.h"

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <optional>

namespace Ferret
{
    class VulkanContext : public GraphicsContext
    {
    public:
        VulkanContext(GLFWwindow* windowHandle);
        virtual void Init() override;
        virtual void SwapBuffers() override;
        virtual void Shutdown() override;

    private:
        void CreateInstance();
        void SetupDebugMessenger();

        void CreateLogicalDevice();
        void PickPhysicalDevice();
        
    private:
    
        struct QueueFamilyIndices
        {
            std::optional<uint32_t> GraphicsFamily;

            bool IsComplete() { return GraphicsFamily.has_value(); }
        };

        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
        bool IsDeviceSuitable(VkPhysicalDevice device);

    private:
        GLFWwindow* m_Window;
        VkInstance m_Instance;

        VkDebugUtilsMessengerEXT m_DebugMessenger;

        VkDevice m_Device;
        
        // Destoyed with the VkInstance
        VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;

        static bool s_EnableValidationLayers;

    };
}
