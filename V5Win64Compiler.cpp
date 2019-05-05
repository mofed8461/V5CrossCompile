
#include "V5Win64Compiler.h"
#include <dirent.h>

V5Win64Compiler::V5Win64Compiler()
{
#if WIN32
    
#elif __APPLE__
    cmdline = "/usr/local/bin/x86_64-w64-mingw32-g++";
    args = "-static-libgcc -static-libstdc++ -static";
#else
    
#endif
}

void V5Win64Compiler::SetCommandLine(const string& cmdline)
{
    this->cmdline = cmdline;
}

string V5Win64Compiler::GetCommandLine()
{
    return cmdline;
}

void V5Win64Compiler::SetArgs(const string& args)
{
    this->args = args;
}

string V5Win64Compiler::GetArgs()
{
    return args;
}

void V5Win64Compiler::AddFile(const string& file)
{
    files.push_back(file);
}

void V5Win64Compiler::AddFolder(const string& folder, const bool& recursive)
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

void V5Win64Compiler::AddLibrary(const string& lib)
{
    libraries.push_back(lib);
}

void V5Win64Compiler::SetOutputName(const string& name)
{
    outputName = name;
}

string V5Win64Compiler::GetOutputName()
{
    return outputName;
}
