/*SystemInfo Class
Header: #include<SystemInfo.h>
Properties:
model: string                                                                   
coresNumber: int                                    
totalRAM: int                                          
totalRAMUsage: int                                          
cpuUsage: vector<int>  


Public Functions
                        SystemInfo()
string                  modelRecovery()
int                     coresNumberRecovery()
int                     totalRamRecovery()
int                     totalRamUsageRecovery()
vector<int>             cpuUsageRecovery()
void                    updateInfo()
void                    outputInfo() 


Member Type Documentation

model:string
-------------------------------------------
Поле содержит наименование модели процессора

coresNumber:int
-------------------------------------------
Поле содержит количество ядер процессора

totalRAM:int
-------------------------------------------
Поле общий объем оперативной памяти

totalRAMUsage:int
-------------------------------------------
Поле содержит объем памяти, занимаемый процессором

cpuUsage:vector<int>
-------------------------------------------
Поле содержит вектор занимаемых ресурсов каждого ядра процессора


Member Function Documentation

SystemInfo::SystemInfo()
-------------------------------------------
Конструктор создает объект типа SystemInfo и заполняет его поля информацией,
которую получает при помощи методов modelRecovery(), coresNumberRecovery(), totalRamRecovery(), totalRamUsageRecovery(), cpuUsageRecovery() 

int SystemInfo::modelRecovery()
-------------------------------------------
Метод наименование процессора и заносит его в поле model

int SystemInfo::coresNumberRecovery()
-------------------------------------------
Метод получает количество ядер процессора и заносит его в поле coresNumber

int SystemInfo::totalRamRecovery()
-------------------------------------------
Метод получает общий объем оперативной памяти и заносит его в поле totalRAM

int SystemInfo::totalRamUsageRecovery()
-------------------------------------------
Метод получает занимаемый процессором объем оперативной памяти и заносит его в поле totalRAMUsage

vector<int> SystemInfo::cpuUsageRecovery()
-------------------------------------------
Метод получает процент занимаемых ресурсов каждого ядра процессора и заносит его в поле cpuUsage

void SystemInfo::updateInfo()
-------------------------------------------
Метод актуализирует значения всех полей объекта

void SystemInfo::infoOutput()
-------------------------------------------
Метод выводит значения всех полей объекта
*/
#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H
#include "ProcessVectorTreatment.h"
#include <string>

class SystemInfo {                                  //класс, в полях которого хранится общая информация о системе
protected:
    string model;                                   //модель процессора
    int coresNumber;                                //количество ядер процессора
    int totalRAM;                                   //общий объём ОЗУ
    int totalRAMUsage;                              //используемый объём ОЗУ
    vector<int> cpuUsage;                           //потребление ресурсов ЦПУ
public:
    SystemInfo();

    const string &getModel() const;                 //getters
    int getCoresNumber() const;
    int getTotalRam() const;
    int getTotalRamUsage() const;
    int getSingleCoreCpuUsage(int) const;
    vector<int> getCpuUsage();                      //

    void setModel(string);                          //setters
    void setCoresNumber(int);
    void setTotalRam(int);
    void setTotalRamUsage(int);
    void setCpuUsage(vector<int>);                  //

    string modelRecovery();                         //получение модели процессора
    int coresNumberRecovery();                      //получения количества ядер ЦПУ
    int totalRamRecovery();                         //получение общего объёма ОЗУ  
    int totalRamUsageRecovery();                    //получение потребляемого объёма ОЗУ
    //int singleCoreCpuUsageRecovery(int); 
    vector<int> cpuUsageRecovery();                 //получение потребляемых ресурсов ЦПУ
    void updateInfo();                              //метод актуализации информации в полях класса
    void outputInfo();
};
#endif // SYSTEMINFO_H
