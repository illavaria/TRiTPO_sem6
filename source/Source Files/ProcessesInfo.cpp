#include "ProcessesInfo.h"


ProcessesInfo ::ProcessesInfo() {
    commandLine = "";
    processName = "";
    user = "";
    threads = 0;
    pid = 0;
    memory = 0;
    cpuPercent = 0;
}

ProcessesInfo :: ProcessesInfo(int get_pid) {
    pid = get_pid;
    processName = processNameRecovery();
    user = userRecovery();
    commandLine = commandLineRecovery();
    memory = memoryRecovery();
    threads = threadsRecovery();
}

ProcessesInfo :: ~ProcessesInfo() {}

void ProcessesInfo :: setProcessName(string str) { processName = str;}
void ProcessesInfo :: setUser(string str) { user = str;}
void ProcessesInfo :: setCommandLine(string str) { commandLine = str;}
void ProcessesInfo :: setMemory(int set_memory) { memory = set_memory;}
void ProcessesInfo :: setThreads(int set_threads) { threads = set_threads;}
void ProcessesInfo ::setPid(int set_pid) { pid = set_pid;}

const string &ProcessesInfo::getCommandLine() const {return commandLine;}
const string &ProcessesInfo::getProcessName() const {return processName;}
const string &ProcessesInfo::getUser() const {return user;}
int ProcessesInfo::getThreads() const {return threads;}
int ProcessesInfo::getPid() const {return pid;}
int ProcessesInfo::getMemory() const {return memory;}

string ProcessesInfo ::processNameRecovery() {
    string str = "cat /proc/";
    str += ConvertData ::itoa(pid);
    str += "/comm 2> /dev/null";
    const char* buf = str.c_str();
    str = ConvertData ::systemCall(buf);
    if(str.size()){
        str.resize(str.size() - 1);
    }
    else return "Unnamed";
    //if (str == "TaskManager") return "TaskManager";
    return str;
}

string ProcessesInfo ::userRecovery() {
    string str = "id -nu 2> /dev/null </proc/";
    str += ConvertData ::itoa(pid);
    str += "/loginuid ";
    const char* buf = str.c_str();
    str = ConvertData ::systemCall(buf);
    if (str.size() != 0) {
        str.resize(str.size() - 1);
    }
    else return "Unknown";
    return str;
}

string ProcessesInfo ::commandLineRecovery() {
    string str = "cat /proc/";
    str += ConvertData ::itoa(pid);
    str += "/cmdline 2> /dev/null";
    const char* buf = str.c_str();
    str = ConvertData ::systemCall(buf);
    if (!str.size()) {
        return "Command line not found";
    }
    return str;
}

int ProcessesInfo ::memoryRecovery() {
    int i = 9;
    string memory;
    string str = "cat /proc/";
    str += ConvertData :: itoa(pid);
    str += "/status 2> /dev/null | grep RssAnon";
    const char* buf = str.c_str();
    str = ConvertData ::systemCall(buf);
    if(!str.size()){
        //cout << "Memory recovery error" << endl;
        return 0;
    }
    while (str[i] != 'k' && str[i] != '\n') {
        if(str[i] != ' '){
            memory += str[i];
        }
        i++;
    }
    return ConvertData ::atoi(memory);
}

int ProcessesInfo ::threadsRecovery() {
    int i = 9;
    string threads;

    string str = "cat /proc/";
    str += ConvertData ::itoa(pid);
    str += "/status 2> /dev/null | grep Threads";
    const char* buf = str.c_str();
    str = ConvertData ::systemCall(buf);
    if (str == "") {
        //cout << "Threads recovery error" << endl;
        return 0;
    }
    while (str[i] != '\n') {
        if(str[i] != ' ') {
            threads += str[i];
        }
        i++;
    }
    return ConvertData ::atoi(threads);
}

void ProcessesInfo ::infoOutput() {
    cout << "----------------" << endl << "Process Name: " << processName << endl
         << "Memory: " << ConvertData :: convertMemory(memory) << endl << "Pid: " << pid << endl << "User: " << user << endl
         << "Threads: " << threads << endl << "Command: " << commandLine << endl << "Cpu_percent: " << cpuPercent << endl;
}


int deleteProcess(int pid){
   int returnSig = kill(pid, 9);
   return returnSig;
}
