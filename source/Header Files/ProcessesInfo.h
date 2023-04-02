#ifndef PROCESSESINFO_H
#define PROCESSESINFO_H
#include <iostream>
#include <string>
#include <signal.h>
#include "ConvertData.h"


using namespace std;

class ProcessesInfo {                                   //класс, содержащий в своих полях информацию о процессах системы
protected:
    string commandLine;                                 //команда, запустившая процесс
    string processName;                                 //имя процесса
    string user;                                        //имя пользователя, запустившего процесс
    int threads;                                        //количество дочерних потоков
    int pid;                                            //идентификатор процесса в системе 
    int memory;                                         //занимаемая процессом память
    double cpuPercent;                                  //занимаемые ресурсы процессора

public:
    ProcessesInfo();
    ProcessesInfo(int pid);

    void setCommandLine(string str);                   //setters
    void setProcessName(string str);
    void setUser(string str);
    void setPid(int);
    void setThreads(int );
    void setMemory(int);                              //

    const string &getCommandLine() const;             //getters
    const string &getProcessName() const;
    const string &getUser() const;
    int getThreads() const;
    int getPid() const;
    int getMemory() const;                           //

    string processNameRecovery();                      //метод получения имени процесса
    string userRecovery();                             //метод получения имени пользователя
    string commandLineRecovery();                      //метод получения команды запуска
    int memoryRecovery();                              //метод получения занимаемой памяти
    int threadsRecovery();                             //метод получения количества дочерних потоков
    void infoOutput();                                 //метод вывод всей информации

    ~ProcessesInfo();


};

int deleteProcess(int pid);                            //функция остановки процесса
#endif // PROCESSESINFO_H
