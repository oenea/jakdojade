#pragma once

using namespace std;

template <typename T> 
class vector 
{
public:
	vector();
	vector(int newSize);
	vector(const vector& other);
    ~vector();
	vector<T>& operator=(const vector<T>& other);
	
	bool empty() const;
	int size() const;
	void push_back(const T& item);
	void pop_back();

	T& operator[](int i);
	const T& operator[](int i) const;
private:
    T* arr;
	int	length;
	int	volume;
};

template <typename T>
vector<T>::vector() {
    length = 0;
    volume = 0;
    arr = new T[0];
}

template <typename T>
vector<T>::vector(int newSize) {
    length = newSize;
    volume = newSize;
    arr = new T[newSize];
}

template <typename T>
vector<T>::vector(const vector& other) {
    length = other.length;
    volume = other.length;
    arr = new T[other.length];

	for (int i = 0; i < other.length; i++) {
		arr[i] = other.arr[i];
	}
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
	if (this == &other) {
		return *this;
	}

	T* tempArr = new T[other.length];

	for (int i = 0; i < other.length; i++) {
		tempArr[i] = other.arr[i];
	}

	delete[] arr;
	length = other.length;
	volume = other.length;
	arr = tempArr;
	return *this;
}

template <typename T>
vector<T>::~vector() {
	delete[] arr;
}

template <typename T>
bool vector<T>::empty() const {
	return length == 0;
}

template <typename T>
int vector<T>::size() const {
	return length;
}

template <typename T>
void vector<T>::push_back(const T& item) {
	if ( (volume == 0) || (volume == 1) ) {
        volume++;
        T* tempArr = new T[volume];
		
		for (int i = 0; i < length; i++) 
        {
			tempArr[i] = arr[i];
		}
		delete[] arr;
		arr = tempArr;
    } 
    if (length == volume) {
		volume = 2 * volume;
        T* tempArr = new T[volume];
		
		for (int i = 0; i < length; i++) {
			tempArr[i] = arr[i];
		}
		delete[] arr;
		arr = tempArr;
	}
	arr[length] = item;
	length++;
}

template <typename T>
T& vector<T>::operator[](int i) {
	return arr[i];
}

template <typename T>
const T& vector<T>::operator[](int i) const {
	return arr[i];
}

template <typename T>
void vector<T>::pop_back() {
	if (length > 0) {
		length--;
	}
}
