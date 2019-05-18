
#include "V5CrossCompile.h"
#include "V5Win32Compiler.h"
#include "V5Win64Compiler.h"

#define WIN32 0
#define WIN64 1
#define LINUX32 2
#define LINUX64 3
#define MAC32 4
#define MAC64 5
#define ARM32 6
#define ARM64 7
#define COMPILERS_COUNT 8



V5CrossCompile::V5CrossCompile()
{
    ClearLog();
    for (int32_t i = 0; i < compilersCapacity; ++i)
    {
        compilers[i] = NULL;
    }
    compilers[WIN32] = new V5Win32Compiler;
    compilers[WIN64] = new V5Win64Compiler;
}

bool V5CrossCompile::Compile()
{
    if (compilers[WIN32] == NULL || system((compilers[WIN32]->GetCommandLine() + " --help").c_str()) != 0)
    {
#if WIN32
#elif __APPLE__
        log += "/usr/local/bin/i686-w64-mingw32-g++ not found, please run the following commands to install minGW:\nbrew install FiloSottile/musl-cross/musl-cross\nbrew install mingw-w64\n";
        return false;
#else
        
#endif
    }
    if (compilers[WIN64] == NULL || system((compilers[WIN64]->GetCommandLine() + " --help").c_str()) != 0)
    {
#if WIN32
#elif __APPLE__
        log += "/usr/local/bin/x86_64-w64-mingw32-g++ not found, please run the following commands to install minGW:\nbrew install FiloSottile/musl-cross/musl-cross\nbrew install mingw-w64\n";
        return false;
#else
        
#endif
    }
    
    //check cmake
    //check for compilers
    //compile check for errors

    return true;
}

void V5CrossCompile::MakeV5Library()
{

}

V5ICompiler* V5CrossCompile::GetWindows32Compiler()
{
    return compilers[WIN32];
}

V5ICompiler* V5CrossCompile::GetWindows64Compiler()
{
    return compilers[WIN64];
}

V5ICompiler* V5CrossCompile::GetLinux32Compiler()
{
    return compilers[LINUX32];
}

V5ICompiler* V5CrossCompile::GetLinux64Compiler()
{
    return compilers[LINUX64];
}

V5ICompiler* V5CrossCompile::GetARM32Compiler()
{
    return compilers[ARM32];
}

V5ICompiler* V5CrossCompile::GetARM64Compiler()
{
    return compilers[ARM64];
}

V5ICompiler* V5CrossCompile::GetMac32Compiler()
{
    return compilers[MAC32];
}

V5ICompiler* V5CrossCompile::GetMac64Compiler()
{
    return compilers[MAC64];
}

string V5CrossCompile::GetLog()
{
    return log;
}

void V5CrossCompile::ClearLog()
{
    log = "";
}

void V5CrossCompile::AddFile(const string& file)
{
    for (int32_t i = 0; i < COMPILERS_COUNT; ++i)
    {
        compilers[i]->AddFile(file);
    }
}

void V5CrossCompile::AddFolder(const string& folder, const bool& recursive)
{
for (int32_t i = 0; i < COMPILERS_COUNT; ++i)
    {
        compilers[i]->AddFolder(folder, recursive);
    }
}

void V5CrossCompile::AddLibrary(const string& lib)
{
    for (int32_t i = 0; i < COMPILERS_COUNT; ++i)
    {
        compilers[i]->AddLibrary(lib);
    }
}

void V5CrossCompile::SetOutputName(const string& name)
{
    for (int32_t i = 0; i < COMPILERS_COUNT; ++i)
    {
        compilers[i]->SetOutputName(name);
    }
    outputName = name;
}

string V5CrossCompile::GetOutputName()
{
    return outputName;
}


#include <xlocale.h>

int main()
{
    V5CrossCompile cc;
    if (!cc.Compile())
    {
        cout << cc.GetLog() << endl;
    }
    
    return 0;
}
