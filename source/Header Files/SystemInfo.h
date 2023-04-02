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
