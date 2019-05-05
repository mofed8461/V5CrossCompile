
#include "V5Win32Compiler.h"
#include <dirent.h>

V5Win32Compiler::V5Win32Compiler()
{
#if WIN32
    
#elif __APPLE__
    cmdline = "/usr/local/bin/i686-w64-mingw32-g++";
    args = "-m32 -static-libgcc -static-libstdc++ -static";
#else
    
#endif
}

void V5Win32Compiler::SetCommandLine(const string& cmdline)
{
    this->cmdline = cmdline;
}

string V5Win32Compiler::GetCommandLine()
{
    return cmdline;
}

void V5Win32Compiler::SetArgs(const string& args)
{
    this->args = args;
}

string V5Win32Compiler::GetArgs()
{
    return args;
}

void V5Win32Compiler::AddFile(const string& file)
{
    files.push_back(file);
}

void V5Win32Compiler::AddFolder(const string& folder, const bool& recursive)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(folder.c_str())) != NULL) 
    {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL) 
        {
            string fn(ent->d_name);
            if ((ent->d_type == DT_DIR || ent->d_type == DT_LNK))
            {
                if (recursive)
                {
                    AddFolder(folder + fn);
                }
            }
            else
            {
                files.push_back(folder + fn);
            }
        }
        closedir(dir);
    }
}

void V5Win32Compiler::AddLibrary(const string& lib)
{
    libraries.push_back(lib);
}

void V5Win32Compiler::SetOutputName(const string& name)
{
    outputName = name;
}

string V5Win32Compiler::GetOutputName()
{
    return outputName;
}
