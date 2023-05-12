/*ProcessesInfo Class
Header: #include<ProcessesInfo.h>
Properties:
commandLine: string                              
processName: string                              
user: string                                         
threads: int                                    
pid: int                                          
memory: int                                          
cpuPercent: double    


Public Functions
                        ProcessesInfo()
                        ProcessesInfo(int pid)
                        ~ProcessesInfo();
string                  processNameRecovery()
string                  userRecovery()
string                  commandLineRecovery()
int                     memoryRecovery()
int                     threadsRecovery()
void                    infoOutput() 


Member Type Documentation

commandLine:string
-------------------------------------------
Поле содержит команду, с помощью которой был запущен процесс

processName:string
-------------------------------------------
Поле содержит имя процесса

user:string
-------------------------------------------
Поле содержит имя пользователя, запустившего процесс

threads:int
-------------------------------------------
Поле количество дочерних потоков процесса

pid:int
-------------------------------------------
Поле содержит parend id процесса

memory:int
-------------------------------------------
Поле содержит объем памяти, занимаемый процессом

cpuPercent:double
-------------------------------------------
Поле содержит процент занимаемых ресурсов процессора


Member Function Documentation

ProcessesInfo::ProcessesInfo()
-------------------------------------------
Конструктор создает объект типа ProcessesInfo с пустыми полями

ProcessesInfo::ProcessesInfo(int pid)
-------------------------------------------
Конструктор создает объект типа ProcessesInfo и при помощи pid процесса, который передается в конструктор заполняет его поля информацией,
которую получает при помощи методов threadsRecovery(), memoryRecovery(), commandLineRecovery(), userRecovery(), processNameRecovery() 

ProcessesInfo::~ProcessesInfo()
-------------------------------------------
Деструктор для уничтожения объекта типа ProcessesInfo

string ProcessesInfo::processNameRecovery()
-------------------------------------------
Метод, используя значение поля pid, получает имя процесса и заносит его в поле processName

string ProcessesInfo::userRecovery()
-------------------------------------------
Метод, используя значение поля pid, получает имя пользователя запустившего процесс и заносит его в поле user

string ProcessesInfo::commandLineRecovery()
-------------------------------------------
Метод, используя значение поля pid, получает команду, при помощи которой, 
был запущен процесс и заносит его в поле commandLine

int ProcessesInfo::memoryRecovery()
-------------------------------------------
Метод, используя значение поля pid, получает объем памяти, потребляемой процессом, и заносит его в поле memory

int ProcessesInfo::threadsRecovery()
-------------------------------------------
Метод, используя значение поля pid, получает количество дочерних потоков процесс и заносит его в поле threads

void ProcessesInfo::infoOutput()
-------------------------------------------
Метод выводит значения всех полей процесса
*/

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
