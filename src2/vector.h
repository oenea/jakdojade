#ifndef vector_H
#define vector_H

//#include <vector>

#define MY_VECTOR
#ifdef MY_VECTOR
#include <cstddef>
#include <stdint.h>

typedef uint32_t size_type;

template <typename T> 
class vector {
public:
	vector();
	explicit vector(size_type s);
	vector(const vector& v);
	vector<T>& operator=(const vector<T>& v);
	~vector();

	class iterator;
	iterator begin();
	iterator end();	
	const iterator begin() const;
	const iterator end() const;
	const iterator cbegin() const;
	const iterator cend() const;

	bool empty() const;
	size_type capacity() const;
	void reserve(size_type newalloc);
	void resize(size_type newsize);

	size_type size() const;
	//size_type max_size() const;

	void shrink_to_fit();
	void clear();
	void push_back(const T& e);
	void pop_back();

	T& at(size_type n);
	T& operator[](size_type i);

	const T& at(size_type n) const;
	const T& operator[](size_type i) const;

	T& front();
	T& back();
	T* data();

	const T& front() const;
	const T& back() const;	
	const T* data() const;
private:
	size_type	_size;		// number of elements
	size_type	_capacity;	// capacity
	T*			_elements;	// elements
};


template <typename T> 
class vector<T>::iterator {
public:
	explicit iterator(T* p) : _current(p){}

	iterator& operator++() {
		_current++;
		return *this;
	}

	iterator& operator--() {
		_current--;
		return *this;
	}

	T& operator*() {
		return *_current;
	}

	bool operator==(const iterator& b) const {
		return *_current == *b._current;
	}

	bool operator!=(const iterator& b) const {
		return *_current != *b._current;
	}
private:
	T* _current;
};

template <typename T>
vector<T>::vector() : _size(0), _capacity(0), _elements(0){}

template <typename T>
vector<T>::vector(size_type s) : _size(s), _capacity(s), _elements(new T[s]) {
	for (size_type i = 0; i < _size; i++) {
		_elements[i] = T();
	}
}

template <typename T>
vector<T>::vector(const vector& v) : _size(v._size), _capacity(v._size), _elements(new T[v._size]) {
	for (size_type i = 0; i < v._size; i++) {
		_elements[i] = v._elements[i];
	}
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& v) {
	if (this == &v) {
		return *this;
	}
	/*if (_capacity >= v._size) {
		for (size_type index = 0; index < v._size; index++) {
			_elements[index] = v._elements[index];
			_size = v._size;
			return *this;
		}
	}*/

	T* p = new T[v._size];

	for (size_type i = 0; i < v._size; i++) {
		p[i] = v._elements[i];
	}

	delete[] _elements;
	_size = v._size;
	_capacity = v._size;
	_elements = p;
	return *this;
}

template <typename T>
vector<T>::~vector() {
	delete[] _elements;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {	
	return vector<T>::iterator(&_elements[0]);
}

template <typename T>
typename vector<T>::iterator const vector<T>::begin() const {
	return vector<T>::iterator(&_elements[0]);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
	return vector<T>::iterator(&_elements[_size]);
}

template <typename T>
typename vector<T>::iterator const vector<T>::end() const {
	return vector<T>::iterator(&_elements[_size]);
}

template <typename T>
typename vector<T>::iterator const vector<T>::cbegin() const {
	return vector<T>::iterator(&_elements[0]);
}

template <typename T>
typename vector<T>::iterator const vector<T>::cend() const {
	return vector<T>::iterator(&_elements[_size]);
}

template <typename T>
bool vector<T>::empty() const {
	return (_size == 0);
}

template <typename T>
size_type vector<T>::capacity() const {
	return _capacity;
}

template <typename T>
void vector<T>::reserve(size_type newalloc) {
	if (newalloc > _capacity) {
		T* p = new T[newalloc];
		
		for (size_type i = 0; i < _size; i++) {
			p[i] = _elements[i];
		}

		delete[] _elements;
		_elements = p;
		_capacity = newalloc;
	}
}

template <typename T>
void vector<T>::resize(size_type newsize) {
	reserve(newsize);

	//for (size_type i = _size; i < newsize; i++) {
	//	_elements[i] = v;
	//}
	_size = newsize;
}

template <typename T>
size_type vector<T>::size() const {
	return _size;
}

template <typename T>
void vector<T>::push_back(const T& e) {
	if (_capacity == 0) {
		reserve(1);
	}else if(_capacity == 1) {
		reserve(2);
	}
	else if (_size == _capacity) {
		reserve(size_type(_capacity + size_type(_capacity/2)));
	}
	_elements[_size] = e;
	_size += 1;
}

template <typename T>
T & vector<T>::at(size_type n) {
	//if (n < 0 || _size <= n) throw out_of_range();
	return _elements[n];
}

template <typename T>
const T & vector<T>::at(size_type n) const {
	//if (n < 0 || _size <= n) throw out_of_range();
	return _elements[n];
}

template <typename T>
T & vector<T>::operator[](size_type i) {
	return _elements[i];
}

template <typename T>
const T & vector<T>::operator[](size_type i) const {
	return _elements[i];
}

template <typename T>
T& vector<T>::front() {
	return _elements[0];
}

template <typename T>
const T& vector<T>::front() const {
	return _elements[0];
}

template <typename T>
T& vector<T>::back() {
	return _elements[_size - 1];
}

template <typename T>
const T& vector<T>::back() const {
	return _elements[_size - 1];
}

template <typename T>
T* vector<T>::data() {
	return _elements;
}

template <typename T>
const T* vector<T>::data() const {
	return _elements;
}

template <typename T>
void vector<T>::pop_back() {
	if (_size > 0) {
		_size -= 1;
	}
}

template <typename T>
void vector<T>::shrink_to_fit() {
	if (_capacity > _size) {
		T* p = new T[_size];
		for (size_type i = 0; i < _size; i++) {
			p[i] = _elements[i];
		}
		delete[] _elements;
		_elements = p;
		_capacity = _size;
	}
}

#endif /* MY_VECTOR */
#endif /* VECTOR_H */