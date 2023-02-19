#include "ProcessVectorTreatment.h"

ProcessVectorTreatment ::ProcessVectorTreatment() {
    update_information();
}

vector<ProcessesInfo> ProcessVectorTreatment ::getProcessVector() {
    return processVector;
}

void ProcessVectorTreatment ::setProcessVector(vector<ProcessesInfo> setVect) {
    processVector = setVect;
}

void ProcessVectorTreatment ::update_information() {
    string str;
    int i = 0, pid = 0;
    str = ConvertData ::systemCall("ls /proc");

    while ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
            pid *= 10;
            pid += str[i] - 48;
        }
        if (str[i] == '\n'){
            ProcessesInfo tmp(pid);
            processVector.push_back(tmp);
            pid = 0;
        }
        i++;
    }
}

void ProcessVectorTreatment :: delete_process_vector() {
    for (int i = processVector.size(); i > 0; i--) {
        processVector.pop_back();
    }
}

void ProcessVectorTreatment ::output_vector() {
    for (int i = 0; i < processVector.size(); i++) {
        processVector[i].infoOutput();
    }
}

vector<ProcessesInfo> ProcessVectorTreatment :: findByName(string str) {
    vector<ProcessesInfo> foundVector;
    for (int i = 0; i < processVector.size(); i++) {
        if (str == processVector[i].getProcessName()) {
            foundVector.push_back(processVector[i]);
        }
    }
    return foundVector;
}

bool pidComparator (ProcessesInfo obj1, ProcessesInfo obj2) {
    return (obj1.getPid() < obj2.getPid());
}

bool nameComparator (ProcessesInfo obj1, ProcessesInfo obj2) {
    return (obj1.getProcessName() < obj2.getProcessName());
}

bool userComparator (ProcessesInfo obj1, ProcessesInfo obj2) {
    return (obj1.getUser() < obj2.getUser());
}

bool threadsComparator (ProcessesInfo obj1, ProcessesInfo obj2) {
    return (obj1.getThreads() < obj2.getThreads());
}

bool memoryComparator (ProcessesInfo obj1, ProcessesInfo obj2) {
    return (obj1.getMemory() < obj2.getMemory());
}

void ProcessVectorTreatment :: sortByPid() {
    sort(processVector.begin(), processVector.end(), pidComparator);
}

void ProcessVectorTreatment :: sortByUser() {
    sort(processVector.begin(), processVector.end(), userComparator);
}

void ProcessVectorTreatment ::sortByName() {
    sort(processVector.begin(), processVector.end(), nameComparator);
}

void ProcessVectorTreatment ::sortByThreadNumber() {
    sort(processVector.begin(), processVector.end(), threadsComparator);
}

void ProcessVectorTreatment ::sortByMemory() {
    sort(processVector.begin(), processVector.end(), memoryComparator);
}




