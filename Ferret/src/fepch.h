#pragma once

#include "Ferret/Core/PlatformDetection.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#if defined(FE_PLATFORM_WINDOWS)
#   include <Windows.h>
#elif defined (FE_PLATFORM_LINUX)
#   include <signal.h>
#endif


#include "Ferret/Core/Core.h"
#include "Ferret/Core/Log.h"
