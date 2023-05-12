/*ProcessVectorTreatment Class
Header: #include<ProcessVectorTreatment.h>

Public Functions
                        ProcessVectorTreatment()
void                    update_information()
void                    delete_process_vector()
void                    output_vector()
void                    setProcessVector(vector<ProcessesInfo> setVect)
vector<ProcessesInfo>   getProcessVector()
vector<ProcessesInfo>   findByName(string str)

void                    sortByName()
void                    sortByPid()
void                    sortByUser()
void                    sortByThreadNumber()
void                    sortByMemory()

bool                    pidComparator(ProcessesInfo obj1, ProcessesInfo obj2)           friend
bool                    nameComparator(ProcessesInfo obj1, ProcessesInfo obj2)          friend
bool                    userComparator(ProcessesInfo obj1, ProcessesInfo obj2)          friend
bool                    threadsComparator(ProcessesInfo obj1, ProcessesInfo obj2)       friend
bool                    memoryComparator (ProcessesInfo obj1, ProcessesInfo obj2)       friend


ProcessVectorTreatment::ProcessVectorTreatment()
-------------------------------------------
Метод создает объект типа ProcessVectorTreatment и заполняет поле vector<ProcessInfo> processVector

void ProcessVectorTreatment::update_information()
-------------------------------------------
Метод перезаполнет поле vector<ProcessInfo> processVector актуальной информацией

void ProcessVectorTreatment::delete_process_vector()
-------------------------------------------
Метод очищает поле vector<ProcessInfo> processVector

void ProcessVectorTreatment::output_vector()
-------------------------------------------
Метод выводит содержимое поля vector<ProcessInfo> processVector

void ProcessVectorTreatment::setProcessVector(vector<ProcessesInfo> setVect)
-------------------------------------------
Метод заполняет поле vector<ProcessInfo> processVector переданным в метод вектором vector<ProcessesInfo> setVect

vector<ProcessesInfo>   ProcessVectorTreatment::getProcessVector()
-------------------------------------------
Метод возвращает содержимое поля vector<ProcessInfo> processVector в векторе типа vector<ProcessInfo>

vector<ProcessesInfo>   ProcessVectorTreatment::findByName(string str)
-------------------------------------------
Метод возвращает в векторе типа vector<ProcessInfo> объекты, в которых поле processName совпадает с переданным полем str

vector<ProcessesInfo>   ProcessVectorTreatment::findByName(string str)
-------------------------------------------
Метод возвращает в векторе типа vector<ProcessInfo> объекты, в которых поле processName совпадает с переданным полем str

void   ProcessVectorTreatment::sortByName()
-------------------------------------------
Метод сортирует поле vector<ProcessInfo> processVector по полю processName объектов типа ProcessInfo находящихся в векторе processVector 

void   ProcessVectorTreatment::sortByPid()
-------------------------------------------
Метод сортирует поле vector<ProcessInfo> processVector по полю pid объектов типа ProcessInfo находящихся в векторе processVector 

void   ProcessVectorTreatment::sortByUser()
-------------------------------------------
Метод сортирует поле vector<ProcessInfo> processVector по полю user объектов типа ProcessInfo находящихся в векторе processVector 

void   ProcessVectorTreatment::sortByTreadNumber()
-------------------------------------------
Метод сортирует поле vector<ProcessInfo> processVector по полю threads объектов типа ProcessInfo находящихся в векторе processVector 

void   ProcessVectorTreatment::sortByMemory()
-------------------------------------------
Метод сортирует поле vector<ProcessInfo> processVector по полю memory объектов типа ProcessInfo находящихся в векторе processVector 

bool   ProcessVectorTreatment::pidComparator()                  [friend]
-------------------------------------------
Метод компаратора, использующийся в методе sortByPid

bool   ProcessVectorTreatment::nameComparator()                 [friend]
-------------------------------------------
Метод компаратора, использующийся в методе sortByName

bool   ProcessVectorTreatment::userComparator()                 [friend]
-------------------------------------------
Метод компаратора, использующийся в методе sortByUser

bool   ProcessVectorTreatment::threadsComparator()              [friend]
-------------------------------------------
Метод компаратора, использующийся в методе sortByThreadNumber

bool   ProcessVectorTreatment::memoryComparator()               [friend]
-------------------------------------------
Метод компаратора, использующийся в методе sortByMemory
*/

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
