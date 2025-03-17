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
#endif

#include "Ferret/Core/Log.h"
#include "Ferret/Core/Core.h"
