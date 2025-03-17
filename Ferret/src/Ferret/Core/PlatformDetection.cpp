#include "fepch.h"
#include "PlatformDetection.h"

namespace Ferret
{
    PlatformAPI PlatformDetection::s_PlatformAPI;

    void PlatformDetection::Init()
    {
#       if defined(FE_PLATFORM_WINDOWS)
            s_PlatformAPI = PlatformAPI::WINDOWS;
#       elif defined(FE_PLATFORM_LINUX)
            s_PlatformAPI = PlatformAPI::LINUX;
#       else
            s_PlatformAPI = PlatformAPI::NONE;
#       endif

    }
}
