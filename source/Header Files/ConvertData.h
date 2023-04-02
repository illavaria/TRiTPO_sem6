#ifndef CONVERTDATA_H
#define CONVERTDATA_H
#include <string>
#include <iostream>
#include <array>
#include <memory>

using namespace std;

class ConvertData {                                                     //класс содержит методы для преобразования одних типов данных в другие
                                                                        //с целью упрощения работы с ними
public:
    ConvertData();
    static string itoa(int data);                                      //метод преобразования int в string
    static int atoi(string buf);                                       //метод преобразования string в int
    static string dtoa(double data, int fractional_part);              //метод преобразования double в string 
    static string convertMemory(int data);                             //метод конвертации объёма памяти из байт в единицы измерения высших порядков(KB, MB, GB)
    static string systemCall(const char* command);                     //метод для получения информации, возвращаемой системным вызовом, в формате string

};
#endif // CONVERTDATA_H
