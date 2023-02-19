#include "ConvertData.h"

ConvertData :: ConvertData() {}

string ConvertData :: itoa(int data) {
    string buf;
    int divider = 1;
    int result = data / divider;
    while (result > 9){
        divider *= 10;
        result = data / divider;
    }
    while (divider != 0) {
        buf += (data / divider) + 48;
        data %= divider;
        divider /= 10;
    }
    return buf;
}

int ConvertData ::atoi(string buf) {
    int num = 0;
    for (int i = 0; i < buf.size(); i++) {
        if (buf[i] == '\n' || buf[i] == '\0') {
            return num;
        }
        num *= 10;
        num += buf[i] - 48;
    }
    return num;
}

string ConvertData ::dtoa(double data, int fractional_part) {
    int number = data;
    int afterdot;
    data -= number;
    string buf;
    buf = itoa(number);
    if(fractional_part > 0){
        buf += ".";
        for (int i = 0; i < fractional_part; i++) {
            data *= 10;
            afterdot = data + 48;
            buf += afterdot;
            number = data;
            data -= number;
        }
    }
    return buf;
}

string ConvertData ::convertMemory(int data) {
    double num = data;
    int numbers_after_dot = 0;
    string buf;
    string measure_units = " KB";

    if (num < 0) {
        return "Error: Incorrect memory";
    }
    if (num > 1024) {
        num /= 1024;
        numbers_after_dot++;
        measure_units = " MB";
    }
    if (num > 1024) {
        num /= 1024;
        numbers_after_dot ++;
        measure_units = " GB";
    }

    buf += dtoa(num, numbers_after_dot);
    buf += measure_units;
    return buf;
}

string ConvertData ::systemCall(const char *command) {
    array<char, 128> buf;
    string  call;
    shared_ptr <FILE> pipe(popen(command, "r"), pclose);
    if (!pipe) {
        throw runtime_error("Error in systemCall");
    }
    while (!feof(pipe.get())) {
        if(fgets(buf.data(), 128, pipe.get()) != NULL) {
            call += buf.data();
        }
    }
    return call;
}
