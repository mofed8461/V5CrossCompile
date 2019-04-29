#pragma once


#include <iostream>
#include <string>
#include <vector>
#include "V5ICompiler.h"

using namespace std;

class V5CrossCompile
{
private:
    const static int32_t compilersCapacity = 32;
    V5ICompiler* compilers[compilersCapacity];
    string log;
    string outputName;

public:
    V5CrossCompile();
    virtual bool Compile();
    virtual void MakeV5Library();
    virtual V5ICompiler* GetWindows32Compiler();
    virtual V5ICompiler* GetWindows64Compiler();
    virtual V5ICompiler* GetLinux32Compiler();
    virtual V5ICompiler* GetLinux64Compiler();
    virtual V5ICompiler* GetARM32Compiler();
    virtual V5ICompiler* GetARM64Compiler();
    virtual V5ICompiler* GetMac32Compiler();
    virtual V5ICompiler* GetMac64Compiler();
    virtual string GetLog();
    virtual void ClearLog();


    virtual void AddFile(const string& file);
    virtual void AddFolder(const string& folder, const bool& recursive = true);
    virtual void AddLibrary(const string& lib);

    virtual void SetOutputName(const string& name);
    virtual string GetOutputName();
};