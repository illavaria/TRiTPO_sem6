#ifndef PROCESSESINFO_H
#define PROCESSESINFO_H
#include <iostream>
#include <string>
#include <signal.h>
#include "ConvertData.h"


using namespace std;

class ProcessesInfo {
protected:
    string commandLine;
    string processName;
    string user;
    int threads;
    int pid;
    int memory;
    double cpuPercent;

public:
    ProcessesInfo();
    ProcessesInfo(int pid);

    void setCommandLine(string str);
    void setProcessName(string str);
    void setUser(string str);
    void setPid(int);
    void setThreads(int );
    void setMemory(int);

    const string &getCommandLine() const;
    const string &getProcessName() const;
    const string &getUser() const;
    int getThreads() const;
    int getPid() const;
    int getMemory() const;

    string processNameRecovery();
    string userRecovery();
    string commandLineRecovery();
    int memoryRecovery();
    int threadsRecovery();
    void infoOutput();

    ~ProcessesInfo();


};

int deleteProcess(int pid);
#endif // PROCESSESINFO_H
