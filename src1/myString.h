#pragma once

#include "string.h"
#include <iostream>

using namespace std;

const int S_SIZE = 9;

class String
{
public:
    String();
    String(const char* str);
    ~String();
    int length() const;
    void push_back(String str);
    void push_back(char c);
    void clear();
                                   
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;

    String& operator=(const String& other);
    String& operator=(const char* other);
    String& operator+=(const String& other);
    char& operator[](int i);

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
private:
    char arr[S_SIZE];
};

