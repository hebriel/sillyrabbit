#include <sillyrabbit/utils/FileUtils.hpp>
#include <sillyrabbit/utils/Log.hpp>

#include <cstdio>

namespace sr { namespace utils {


std::string readFile(const char* filepath)
{
    FILE* file = fopen(filepath, "rt");
    fseek(file, 0, SEEK_END);
    unsigned long length = ftell(file);
    char* data = new char[length + 1];
    memset(data, 0, length + 1);
    fseek(file, 0, SEEK_SET);
    if(fread(data, 1, length, file)) Log::error("Error reading a file");
    fclose(file);

    std::string result(data);
    delete[] data;
    return result;
}

}}
