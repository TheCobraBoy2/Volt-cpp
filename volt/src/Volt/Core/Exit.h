#pragma once
#include <cstdlib>
#include "Log.h"
#include "ExitCodes.h"

namespace Volt::Backend
{
    inline void close(unsigned int code, std::string msg)
    {
        VT_CORE_ERROR("({0}) {1}", code, msg);
        VT_CORE_FLUSH();
        std::exit(code);
    }

    inline void closeSuccess()
    {
        VT_CORE_INFO("{0}", "Exiting by user request");
        VT_CORE_FLUSH();
        std::exit(VOLT::SUCCESS);
    }
}