#include "fepch.h"
#include <vulkan/vulkan_core.h>
#include "VulkanContext.h"

#include "VulkanDebug.h"

namespace VKUtils
{
    void test()
    {

    }
}

namespace Ferret
{

#   if defined(FE_DEBUG)
    bool VulkanContext::s_EnableValidationLayers = true;
#   else
    bool VulkanContext::s_EnableValidationLayers = false;
#   endif

    VulkanContext::VulkanContext(GLFWwindow* windowHandle)
        : m_Window(windowHandle)
    {
        FE_API_ASSERT(m_Window, "Window handle is null!");
    }
    
    void VulkanContext::Init()
    {
        CreateInstance();
        SetupDebugMessenger();
        PickPhysicalDevice();
        CreateLogicalDevice();
    }

    void VulkanContext::SwapBuffers()
    {
        
    }

    void VulkanContext::Shutdown()
    {
        if (s_EnableValidationLayers)
            VKDebugUtils::DestroyDebugUtilsMessengerEXT(m_Instance, m_DebugMessenger, nullptr);


        vkDestroyInstance(m_Instance, nullptr);
    }

    void VulkanContext::CreateInstance()
    {
        if (s_EnableValidationLayers && !VKDebugUtils::CheckValidationLayerSupport())
            FE_API_ASSERT(false, "Validation layers requested, but not available!");

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "FerretApplication";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "FerretFramework";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 1);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        auto extensions = VKDebugUtils::GetRequiredExtensions();
        
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();
        
        VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};

        if (s_EnableValidationLayers)
        {
            createInfo.enabledLayerCount = VKDebugUtils::GetValidationLayerCount();
            createInfo.ppEnabledLayerNames = VKDebugUtils::GetValidationLayers();

            VKDebugUtils::PopulateDebugMessengerCreateInfo(debugCreateInfo);
            createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
        }
        else
        {
            createInfo.enabledLayerCount = 0;
            createInfo.pNext = nullptr;
        }

        if (vkCreateInstance(&createInfo, nullptr, &m_Instance) != VK_SUCCESS)
            FE_API_ASSERT(false, "FAILED TO CREATE VULKAN INSTANCE!");
    }

    void VulkanContext::SetupDebugMessenger()
    {
        if (!s_EnableValidationLayers) return;

        VkDebugUtilsMessengerCreateInfoEXT createInfo{};
        VKDebugUtils::PopulateDebugMessengerCreateInfo(createInfo);
        if (VKDebugUtils::CreateDebugUtilsMessengerEXT(m_Instance, &createInfo, nullptr, &m_DebugMessenger) != VK_SUCCESS)
            FE_API_ASSERT(false, "Failed to set up debug messenger!");
    }

    bool VulkanContext::IsDeviceSuitable(VkPhysicalDevice device)
    {
        QueueFamilyIndices indices = FindQueueFamilies(device);

        return indices.IsComplete();
    }
    
    void VulkanContext::PickPhysicalDevice()
    {
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(m_Instance, &deviceCount, nullptr);

        if (deviceCount == 0)
            FE_API_ASSERT(false, "Failed to find GPUs with Vulkan supoort!");

        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(m_Instance, &deviceCount, devices.data());
        
        

        for (const auto& device : devices)
        {
            if (IsDeviceSuitable(device))
            {
                m_PhysicalDevice = device;
                break;
            }
        }

        if (m_PhysicalDevice == VK_NULL_HANDLE)
            FE_API_ASSERT(false, "Failed to find suitable GPU!");
    }

    VulkanContext::QueueFamilyIndices VulkanContext::FindQueueFamilies(VkPhysicalDevice device)
    {
        QueueFamilyIndices indices;
        
        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

        int i = 0;
        for (const auto& queueFamily : queueFamilies)
        {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
                indices.GraphicsFamily = i;

            if (indices.IsComplete())
                break;

            i++;
        }


        return indices;
    }
}
