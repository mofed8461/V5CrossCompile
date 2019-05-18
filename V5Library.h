#pragma once



#if defined _WIN32 || defined __CYGWIN__
  #ifdef WIN_EXPORT
    // Exporting...
    #ifdef __GNUC__
      #define EXPORTED __attribute__ ((dllexport))
    #else
      #define EXPORTED __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define EXPORTED __attribute__ ((dllimport))
    #else
      #define EXPORTED __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define NOT_EXPORTED
#else
  #if __GNUC__ >= 4
    #define EXPORTED __attribute__ ((visibility ("default")))
    #define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
  #else
    #define EXPORTED
    #define NOT_EXPORTED
  #endif
#endif


#include <iostream>

#if defined _WIN32
#include <windows.h>
class V5Library
{
private:
    HINSTANCE handle;
    bool loaded;
    string fileName;
    bool loadFailed;
public:
    const static int32_t MODE_LAZY;
    const static int32_t MODE_NOW;
    V5Library(const std::string& file, const int32_t& mode = MODE_NOW);
    bool LoadFailed();
    void* GetFunction(const std::string& name);
    virtual ~V5Library();
};
#else
#include <dlfcn.h>
class V5Library
{
private:
    void* handle;
    bool loadFailed;
public:
    const static int32_t MODE_LAZY;
    const static int32_t MODE_NOW;
    V5Library(const std::string& file, const int32_t& mode = MODE_NOW);
    bool LoadFailed();
    void* GetFunction(const std::string& name);
    virtual ~V5Library();
};
#endif
