#include "myString.h"

String::String() {
    for (int i = 0; i < S_SIZE; i++) {
        arr[i] = 0;
    }
}

String::String(const char* str) {
    int i;
    for (i = 0; i < S_SIZE - 1 && str[i] != '\0'; i++) {
        arr[i] = str[i];
    }
    arr[i] = '\0';
}

String::~String() {}

int String::length() const {
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    return len;
}

void String::push_back(String str) {
    int len = length();
    int i;
    for (i = 0; i < S_SIZE - len - 1 && str.arr[i] != '\0'; i++) {
        arr[len + i] = str.arr[i];
    }
    arr[len + i] = '\0';
}

bool String::operator==(const String& other) const {
    int i = 0;
    while (arr[i] != '\0' && other.arr[i] != '\0')
    {
        if (arr[i] != other.arr[i]) {
            return false;
        }
        i++;
    }
    return arr[i] == other.arr[i];
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

String& String::operator=(const String& other) {
    for (int i = 0; i < S_SIZE; i++) {
        arr[i] = other.arr[i];
    }
    return *this;
}

String& String::operator=(const char* other) {
    for (int i = 0; i < (int)strlen(other); i++) {
        arr[i] = other[i];
    }
    arr[strlen(other)] = '\0';
    return *this;
}

String& String::operator+=(const String& other)
{
    push_back(other);
    return *this;
}

void String::push_back(char c) {
    arr[strlen(arr)] = c;
    arr[strlen(arr)+1] = '\0';
}

void String::clear() {
    for (int i = 0; i < S_SIZE; i++) {
        arr[i] = 0;
    }
}

char& String::operator[](int i) {
    return arr[i];
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.arr;
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    is >> str.arr;
    return is;
}

/*
//http://www.cse.yorku.ca/~oz/hash.html
unsigned int hashing(char* str) {
    unsigned long hash = 5381;
    int c;
    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }
    return (hash % H_SIZE);
}
*/