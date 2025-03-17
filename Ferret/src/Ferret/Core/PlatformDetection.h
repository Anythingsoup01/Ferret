#pragma once

#ifdef _WIN32
/* Windows x64/x86 */
#	ifdef _WIN64
/* Windows x64  */
#		define FE_PLATFORM_WINDOWS
#	else
/* Windows x86 */
#	error "x86 Builds are not supported!"
#	endif
#elif defined(__APPLE__) || defined(__MACH__)
#	include <TargetConditionals.h>
/* TARGET_OS_MAC exists on all the platforms
 * so we must check all of them (in this order)
 * to ensure that we're running on MAC
 * and not some other Apple platform */
#	if TARGET_IPHONE_SIMULATOR == 1
#		error "IOS simulator is not supported!"
#	elif TARGET_OS_IPHONE == 1
#		define FE_PLATFORM_IOS
#		error "IOS is not supported!"
#	elif TARGET_OS_MAC == 1
#		define FE_PLATFORM_MACOS
#		error "MacOS is not supported!"
#	else
#	error "Unknown Apple platform!"
#endif
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
#	define CE_PLATFORM_ANDROID
#	error "Android is not supported!"
#elif defined(__linux__)
#	define FE_PLATFORM_LINUX
#else
/* Unknown compiler/platform */
#	error "Unknown platform!"
#endif // End of platform detection


#ifdef CE_PLATFORM_WINDOWS
#	if CE_DYNAMIC_LINK
#		ifdef CE_BUILD_DLL
#			define CE_API __declspec(dllexport)
#		else
#			define CE_API __declspec(dllimport)
#		endif
#	else
#		define CE_API
#	endif
#elif defined(FE_PLATFORM_LINUX)

#endif

namespace Ferret
{
    enum class PlatformAPI
    {
        NONE = 0,
        WINDOWS,
        LINUX,
    };

    class PlatformDetection
    {
    public:
        static void Init();
        static PlatformAPI GetPlatform() { return s_PlatformAPI; }

    private:
        static PlatformAPI s_PlatformAPI;
    };
}
