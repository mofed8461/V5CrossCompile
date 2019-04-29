#pragma once


#include <iostream>
#include <string>
#include <vector>
#include "V5ICompiler.h"

using namespace std;

class V5Compiler : public V5ICompiler
{
private:
    string cmdline;
    string args;
    string outputName;
    vector<string> files;
    vector<string> libraries;

public:
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