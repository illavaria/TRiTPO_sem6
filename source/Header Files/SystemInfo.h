#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H
#include "ProcessVectorTreatment.h"
#include <string>

class SystemInfo {
protected:
    string model;
    int coresNumber;
    int totalRAM;
    int totalRAMUsage;
    vector<int> cpuUsage;
public:
    SystemInfo();

    const string &getModel() const;
    int getCoresNumber() const;
    int getTotalRam() const;
    int getTotalRamUsage() const;
    int getSingleCoreCpuUsage(int) const;
    vector<int> getCpuUsage();

    void setModel(string);
    void setCoresNumber(int);
    void setTotalRam(int);
    void setTotalRamUsage(int);
    void setCpuUsage(vector<int>);

    string modelRecovery();
    int coresNumberRecovery();
    int totalRamRecovery();
    int totalRamUsageRecovery();
    //int singleCoreCpuUsageRecovery(int);
    vector<int> cpuUsageRecovery();
    void updateInfo();
    void outputInfo();
};
#endif // SYSTEMINFO_H
