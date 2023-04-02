#ifndef KURS_PROJECT_PROCESSVECTORTREATMENT_H
#define KURS_PROJECT_PROCESSVECTORTREATMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "ProcessesInfo.h"


using namespace std;

class ProcessVectorTreatment {                                                  //класс, содержащий методы для взаимодействия со списком всех процессов
protected:
    vector<ProcessesInfo> processVector;                                        //вектор всех процессов
public:
    ProcessVectorTreatment();
    void update_information();                                                  //метод перезаполнения вектора актуальной информацией
    void delete_process_vector();                                               //метод удаления вектора
    void output_vector();                                                       //вывод вектора

    void setProcessVector(vector<ProcessesInfo> setVect);                       
    vector<ProcessesInfo> getProcessVector();
    vector<ProcessesInfo> findByName(string str);

    void sortByName();                                                          //сортировки вектора по параметрам
    void sortByPid();
    void sortByUser();
    void sortByThreadNumber();
    void sortByMemory();                                                        //

    friend bool pidComparator(ProcessesInfo obj1, ProcessesInfo obj2);         //компараторы для сортировок
    friend bool nameComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool userComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool threadsComparator(ProcessesInfo obj1, ProcessesInfo obj2);
    friend bool memoryComparator (ProcessesInfo obj1, ProcessesInfo obj2);     //
};



#endif //KURSUPDATE_PROCESSVECTORTREATMENT_H
