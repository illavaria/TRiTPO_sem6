/*ConvertData Class
Header: #include<ConvertData.h>

Public Functions
string          itoa(int data)                          static
int             atoi(string buf)                        static
string          dtoa(double data, int fractional_part)  static
string          convertMemory(int data)                 static
string          systemCall(const char* command)         static



string ConvertData::itoa(int data) [static]
-------------------------------------------
Метод преобразует входящее в него значение типа int в объект string


int ConvertData::atoi(string buf) [static]
-------------------------------------------
Метод преобразует входящий в него объект типа string в значение типа int


string ConvertData::dtoa(double data, int fractional_part) [static]
-------------------------------------------
Метод преобразует входящее в него значение типа double и размер его дробной части в объект string


string ConvertData::convertMemory(int data) [static]
-------------------------------------------
Метод преобразует входящее в него значение типа int, 
в котором заключен объем памяти в байтах, в объект string при этом конвертируя объем памяти из байт
в единицы измерения высших порядков(KB, MB, GB)


string ConvertData::systemCall(const char* command) [static]
-------------------------------------------
Метод принимает системную команду в виде указателя на начало строки и 
возвращает результат вывода этой команды в объекте типа string  
*/

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
    static string itoa(int data);                                      //метод преобразования int в string
    static int atoi(string buf);                                       //метод преобразования string в int
    static string dtoa(double data, int fractional_part);              //метод преобразования double в string 
    static string convertMemory(int data);                             //метод конвертации объёма памяти из байт в единицы измерения высших порядков(KB, MB, GB)
    static string systemCall(const char* command);                     //метод для получения информации, возвращаемой системным вызовом, в формате string

};
#endif // CONVERTDATA_H
