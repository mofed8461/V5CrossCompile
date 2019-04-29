
#include "V5Compiler.h"
#include <dirent.h>

void V5Compiler::SetCommandLine(const string& cmdline)
{
    this->cmdline = cmdline;
}

string V5Compiler::GetCommandLine()
{
    return cmdline;
}

void V5Compiler::SetArgs(const string& args)
{
    this->args = args;
}

string V5Compiler::GetArgs()
{
    return args;
}

void V5Compiler::AddFile(const string& file)
{
    files.push_back(file);
}

void V5Compiler::AddFolder(const string& folder, const bool& recursive)
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

void V5Compiler::AddLibrary(const string& lib)
{
    libraries.push_back(lib);
}

void V5Compiler::SetOutputName(const string& name)
{
    outputName = name;
}

string V5Compiler::GetOutputName()
{
    return outputName;
}
