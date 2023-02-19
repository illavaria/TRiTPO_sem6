#ifndef KURS_PROJECT_PROCESSVECTORTREATMENT_H
#define KURS_PROJECT_PROCESSVECTORTREATMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "ProcessesInfo.h"


using namespace std;

class ProcessVectorTreatment {
protected:
    vector<ProcessesInfo> processVector;
public:
    ProcessVectorTreatment();
    void update_information();
    void delete_process_vector();
    void output_vector();

    void setProcessVector(vector<ProcessesInfo> setVect);
    vector<ProcessesInfo> getProcessVector();
    vector<ProcessesInfo> findByName(string str);

    void sortByName();
    void sortByPid();
    void sortByUser();
    void sortByThreadNumber();
    void sortByMemory();

    friend bool pidComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool nameComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool userComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool threadsComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool memoryComparator (ProcessesInfo obj1, ProcessesInfo obj2);
};



#endif //KURSUPDATE_PROCESSVECTORTREATMENT_H
