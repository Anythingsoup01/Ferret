#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Ferret
{
    class Log
    {
    public:
        static void Init();

        static inline Ref<spdlog::logger>& GetAPILogger() { return s_APILogger; }
        static inline Ref<spdlog::logger>& GetCLILogger() { return s_CLILogger; }
    private:
        static Ref<spdlog::logger> s_APILogger;
        static Ref<spdlog::logger> s_CLILogger;
    };
}

#if defined(FE_DEBUG)
/*------ API RELATED LOG CALLS - TO BE USED ONLY IN FERRET! ------*/
#define FE_API_CRITICAL(...)  ::Ferret::Log::GetAPILogger()->critical(__VA_ARGS__)
#define FE_API_ERROR(...)     ::Ferret::Log::GetAPILogger()->error(__VA_ARGS__)
#define FE_API_WARN(...)      ::Ferret::Log::GetAPILogger()->warn(__VA_ARGS__)
#define FE_API_INFO(...)      ::Ferret::Log::GetAPILogger()->info(__VA_ARGS__)
#define FE_API_TRACE(...)     ::Ferret::Log::GetAPILogger()->trace(__VA_ARGS__)

/*--- CLI RELATED LOG CALLS - TO BE USED IN FERRET BUILT APPS! ---*/
#define FE_CLI_CRITICAL(...)  ::Ferret::Log::GetCLILogger()->critical(__VA_ARGS__)
#define FE_CLI_ERROR(...)     ::Ferret::Log::GetCLILogger()->error(__VA_ARGS__)
#define FE_CLI_WARN(...)      ::Ferret::Log::GetCLILogger()->warn(__VA_ARGS__)
#define FE_CLI_INFO(...)      ::Ferret::Log::GetCLILogger()->info(__VA_ARGS__)
#define FE_CLI_TRACE(...)     ::Ferret::Log::GetCLILogger()->trace(__VA_ARGS__)

#elif defined(FE_RELEASE)

/*------ API RELATED LOG CALLS - TO BE USED ONLY IN FERRET! ------*/
#define FE_API_CRITICAL(...)
#define FE_API_ERROR(...)
#define FE_API_WARN(...)
#define FE_API_INFO(...)
#define FE_API_TRACE(...)

/*--- CLI RELATED LOG CALLS - TO BE USED IN FERRET BUILT APPS! ---*/
#define FE_CLI_CRITICAL(...)  ::Ferret::Log::GetCLILogger()->critical(__VA_ARGS__)
#define FE_CLI_ERROR(...)     ::Ferret::Log::GetCLILogger()->error(__VA_ARGS__)
#define FE_CLI_WARN(...)      ::Ferret::Log::GetCLILogger()->warn(__VA_ARGS__)
#define FE_CLI_INFO(...)      ::Ferret::Log::GetCLILogger()->info(__VA_ARGS__)
#define FE_CLI_TRACE(...)     ::Ferret::Log::GetCLILogger()->trace(__VA_ARGS__)
#endif
