#pragma once


#include <iostream>
#include <string>

using namespace std;

class V5ICompiler
{
public:
    virtual void SetCommandLine(const string& cmdline) = 0;
    virtual string GetCommandLine() = 0;

    virtual void SetArgs(const string& args) = 0;
    virtual string GetArgs() = 0;

    virtual void AddFile(const string& file) = 0;
    virtual void AddFolder(const string& folder, const bool& recursive = true) = 0;
    virtual void AddLibrary(const string& lib) = 0;

    virtual void SetOutputName(const string& name) = 0;
    virtual string GetOutputName() = 0;
};