#pragma once


#include <iostream>
#include <string>
#include <vector>
#include "V5Compiler.h"

using namespace std;

class V5Win32Compiler : public V5Compiler
{
public:
    V5Win32Compiler();
    virtual void SetCommandLine(const string& cmdline);
    virtual string GetCommandLine();

    virtual void SetArgs(const string& args);
    virtual string GetArgs();

    virtual void AddFile(const string& file);
    virtual void AddFolder(const string& folder, const bool& recursive = true);
    virtual void AddLibrary(const string& lib);

    virtual void SetOutputName(const string& name);
    virtual string GetOutputName();
};
