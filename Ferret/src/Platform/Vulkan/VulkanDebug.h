#pragma once

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace Ferret
{
    class VKDebugUtils
    {
    public:
        static bool CheckValidationLayerSupport();
        static std::vector<const char*> GetRequiredExtensions();

        static uint32_t GetValidationLayerCount() { return static_cast<uint32_t>(m_ValidationLayers.size()); }
        static const char** GetValidationLayers() { return m_ValidationLayers.data(); }

        static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
                                VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                VkDebugUtilsMessageTypeFlagsEXT messageType,
                                const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                void* pUserData);

        static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
        static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
        static void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        
    private:

        static inline std::vector<const char*> m_ValidationLayers =
        {
            "VK_LAYER_KHRONOS_validation",
        };

    };
}
