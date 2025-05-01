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
        
        void CreateSurface();
        
        void CreateLogicalDevice();
        void PickPhysicalDevice();

        void CreateSwapChain();
        void CreateImageViews();

        void CreateGraphicsPipeline();

    private:

        struct SwapChainSupportDetails
        {
            VkSurfaceCapabilitiesKHR Capabilites;
            std::vector<VkSurfaceFormatKHR> Formats;
            std::vector<VkPresentModeKHR> PresentModes;
        };

        SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);

        struct QueueFamilyIndices
        {
            std::optional<uint32_t> GraphicsFamily;
            std::optional<uint32_t> PresentFamily;

            bool IsComplete() { return GraphicsFamily.has_value() && PresentFamily.has_value(); }
        };

        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

        bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
        bool IsDeviceSuitable(VkPhysicalDevice device);

        VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    private:
        GLFWwindow* m_Window;
        VkInstance m_Instance;

        const std::vector<const char*> m_DeviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME,
        };

        VkDebugUtilsMessengerEXT m_DebugMessenger;

        // Destoyed with the VkInstance
        VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
        VkDevice m_Device;

        VkSurfaceKHR m_Surface;

        VkQueue m_GraphicsQueue;
        VkQueue m_PresentQueue;

        VkSwapchainKHR m_SwapChain;
        std::vector<VkImage> m_SwapChainImages;
        VkFormat m_SwapChainImageFormat;
        VkExtent2D m_SwapChainExtent;
        std::vector<VkImageView> m_SwapChainImageViews;

        static bool s_EnableValidationLayers;

    };
}
