#include "V5Library.h"

#if defined _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

const int32_t V5Library::MODE_LAZY = 0;
const int32_t V5Library::MODE_NOW = 1;

V5Library::V5Library(const std::string& file, const int32_t& mode)
{
#if defined _WIN32
    loadFailed = false;
    loaded = (mode == MODE_NOW);
    fileName = file;
    if (mode == MODE_NOW)
    {
        handle = LoadLibrary(file.c_str());
        loadFailed = (handle == NULL);
    }
    if (loadFailed)
    {
        size_t found = file.find(".dll"); 
        if (found != string::npos)
        {
            if (mode == MODE_NOW)
            {
                handle = LoadLibrary((file + ".dll").c_str());
                loadFailed = (handle == NULL);
            }
        }
    }
#else
    handle = dlopen(file.c_str(), mode == MODE_LAZY ? RTLD_LAZY : RTLD_NOW);
    loadFailed = (handle == NULL);
    if (loadFailed)
    {
#if __APPLE__
        handle = dlopen((file + ".dylib").c_str(), mode == MODE_LAZY ? RTLD_LAZY : RTLD_NOW);
#else
        handle = dlopen((file + ".so").c_str(), mode == MODE_LAZY ? RTLD_LAZY : RTLD_NOW);
#endif

        loadFailed = (handle == NULL);
    }
#endif
}

bool V5Library::LoadFailed()
{
#if defined _WIN32
    if (!loaded)
    {
        handle = LoadLibrary(fileName.c_str());
        loadFailed = (handle == NULL);
        loaded = true;
        if (loadFailed)
        {
            size_t found = fileName.find(".dll"); 
            if (found != string::npos)
            {
                if (mode == MODE_NOW)
                {
                    handle = LoadLibrary((fileName + ".dll").c_str());
                    loadFailed = (handle == NULL);
                }
            }
        }
    }
#endif
    return loadFailed;
}


void* V5Library::GetFunction(const std::string& name)
{
#if defined _WIN32
    if (!loaded)
    {
        handle = LoadLibrary(fileName.c_str());
        loadFailed = (handle == NULL);
        loaded = true;
        if (loadFailed)
        {
            size_t found = fileName.find(".dll"); 
            if (found != string::npos)
            {
                if (mode == MODE_NOW)
                {
                    handle = LoadLibrary((fileName + ".dll").c_str());
                    loadFailed = (handle == NULL);
                }
            }
        }
    }

    if (loadFailed)
    {
        return NULL;
    }

    return GetProcAddress(handle, name.c_str());
#else

    if (loadFailed)
    {
        return NULL;
    }

    return dlsym(handle, name.c_str());
#endif
}

V5Library::~V5Library()
{
#if defined _WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
}
