#include "SystemInfo.h"

SystemInfo ::SystemInfo() {
    model = modelRecovery();
    coresNumber = coresNumberRecovery();
    totalRAM = totalRamRecovery();
    totalRAMUsage = totalRamUsageRecovery();
    //cpuUsage.resize(ConvertData ::atoi(ConvertData ::systemCall("cat /proc/cpuinfo | grep processor | wc -l")));
    cpuUsage = cpuUsageRecovery();
}

const string &SystemInfo :: getModel() const {return model;}
int SystemInfo :: getCoresNumber() const {return coresNumber;}
int SystemInfo :: getTotalRam() const {return totalRAM;}
int SystemInfo :: getTotalRamUsage() const {return totalRAMUsage;}
int SystemInfo ::getSingleCoreCpuUsage(int ind) const {return cpuUsage[ind];}
vector<int> SystemInfo ::getCpuUsage() {return cpuUsage;}

void SystemInfo :: setModel(string str) {model = str;}
void SystemInfo :: setCoresNumber(int coresNumberSet) {coresNumber = coresNumberSet;}
void SystemInfo :: setTotalRam(int totalRAMSet) {totalRAM = totalRAMSet;}
void SystemInfo :: setTotalRamUsage(int totalRamUsageSet) {totalRAMUsage = totalRamUsageSet;}
void SystemInfo ::setCpuUsage(vector<int> vect) {cpuUsage = vect;}

string SystemInfo ::modelRecovery() {
    int i = 17;
    string str, modelName;
    str = ConvertData ::systemCall("cat /proc/cpuinfo | grep name ");
    for (int j = 13; j > 0; j--, i++){
        modelName += str[i];
    }
    return modelName;
}

int SystemInfo ::coresNumberRecovery() {
    return ConvertData ::atoi(ConvertData ::systemCall("cat /proc/cpuinfo | grep processor | wc -l"));
}

int SystemInfo ::totalRamRecovery() {
    string str, totalRAM;
    int i = 12;
    str = ConvertData ::systemCall("cat /proc/meminfo | grep MemTotal");
    while (str[i] != 'k' && str[i] != '\n') {
        if (str[i] != ' '){
            totalRAM += str[i];
        }
        i++;
    }
    return ConvertData ::atoi(totalRAM);
}

int SystemInfo ::totalRamUsageRecovery() {
    string str, totalramusage;
    int i = 0;
    str = ConvertData ::systemCall("free -m | grep Память:");
    while (str[i] != ' ') i++;
    while (str[i] == ' ') i++;
    while (str[i] != ' ') i++;
    while (str[i] == ' ') i++;

    while (str[i] != ' ') {
        totalramusage += str[i];
        i++;
    }
    return (ConvertData ::atoi(totalramusage)) * 1024;
}

vector<int> SystemInfo ::cpuUsageRecovery() {
    vector<int> CPUusage;
    string str;

    for (int i = 0; i < coresNumber; i++) {
        string core_cpu_usage = "";
        str = "mpstat -P ALL 1 1 | grep ";
        str += '\"';
        str += '\\';
        str += "Среднее:    ";
        str += ConvertData ::itoa(i);
        str += '\"';
        str = ConvertData ::systemCall(str.c_str());
        int j = 0;
        while (str[j] != ' ') j++;
        while (str[j] == ' ') j++;
        while (str[j] != ' ') j++;
        while (str[j] == ' ') j++;
        while (str[j] != ',') {
            if (str[j] != ' ') {
                core_cpu_usage += str[j];
                j++;
            }
        }
        CPUusage.push_back(ConvertData :: atoi(core_cpu_usage));
    }
    return CPUusage;
}

void SystemInfo ::updateInfo() {
    setTotalRam(totalRamRecovery());
    setTotalRamUsage(totalRamUsageRecovery());
    setCpuUsage(cpuUsageRecovery());
}

void SystemInfo ::outputInfo() {
    cout << "Processor model: "<< model << endl << "Number of cores: "
         << coresNumber  << endl << "RAM: " << totalRAM << endl << "Memory usage: " << 100 * totalRAMUsage / totalRAM << "%" << endl;
    for(int i = 0; i < coresNumber; i++) {
        cout << "CPU №" << i + 1 << " usage: " << cpuUsage[i] << "%" << endl;
    }
}
