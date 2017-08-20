#include "sillyrabbit/utils/Log.hpp"

namespace sr { namespace utils {

void Log::error(const char* text)
{
    std::cerr << RED << "[Error] " << text << RESET << std::endl;
}

void Log::warning(const char* text)
{
    std::cerr << YELLOW << text << RESET << std::endl;
}

void Log::info(const char* text)
{
    std::cerr << text << std::endl;
}

void Log::glerror(const char* text)
{
    std::cerr << RED << "[OpenGL Error] " << text << RESET << std::endl;
}

} }
