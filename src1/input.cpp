#include "input.h"
#include <iostream>

void inputString(String& arr) {
    arr.clear();
    char c = (char)getchar();
    while (c <= ' ') {
        c = (char)getchar();
    }
    int i = 0;
    while (c > ' ') {
        arr[i] = c;
        c = (char)getchar();
        i++;
    }
    arr[i] = '\0';
}

bool inputBool() {
    char c = (char)getchar();
    if (c > ' ') {
        return (bool)(c - '0');
    }
    while (c <= ' ') {
        c = (char)getchar();
    }
    while (c > ' ') {
        c = (char)getchar();
    };

    return (bool)(c - '0');
}

int inputInt() {
    char c;
    c = (char)getchar();
    while (c <= ' ') {
        c = (char)getchar();
    }
    int output = 0;
    while (c  > ' ') {
        if ( (c >= '0') && (c <= '9') ) {
            output *= 10;
            output += (c - '0');
        }  
        c = (char)getchar();
    }
    return output;
}