#ifndef CONVERTDATA_H
#define CONVERTDATA_H
#include <string>
#include <iostream>
#include <array>
#include <memory>

using namespace std;

class ConvertData {
public:
    ConvertData();
    static string itoa(int data);
    static int atoi(string buf);
    static string dtoa(double data, int fractional_part);
    static string convertMemory(int data);
    static string systemCall(const char* command);

};
#endif // CONVERTDATA_H
