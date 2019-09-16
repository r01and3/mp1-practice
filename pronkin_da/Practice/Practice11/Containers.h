#pragma once

template <typename T, int maxsize>
class Container<T*, maxsize> {
	T** arr;
	int n;
public:
	Container();
	Container(const Container&);
	~Container();
	bool isFull() const;
	bool isEmpty() const;
	int Find(const T* a) const;
	void Add(const T* a);
	void Delete(const T* a);
	T& operator[](int _n) const;
};

template <typename T, int maxsize>
Container<T*, maxsize>::Container() {
	n = 0;
	arr = new T*[maxsize];
}

template <typename T, int maxsize>
Container<T*, maxsize>::Container(const Container<T*, maxsize> &c) {
	n = c.n;
	arr = new T*[n];
	for (int i = 0; i < n; i++) arr[i] = new T(*(c.arr[i]));
}

template <typename T, int maxsize>
Container<T*, maxsize>::~Container() {
	for (int i = 0; i < n; i++) delete arr[i];
	n = 0;
	delete[]arr;
}

template <typename T, int maxsize>
bool Container<T*, maxsize>::isFull() const {
	return n == maxsize;
}

template <typename T, int maxsize>
bool Container<T*, maxsize>::isEmpty() const {
	return n == 0;
}

template <typename T, int maxsize>
int Container<T*, maxsize>::Find(const T* a) const {
	for (int i = 0; i < n; i++) if (*(arr[i]) == *a) return i;
	return -1;
}

template <typename T, int maxsize>
void Container<T*, maxsize>::Add(const T* a) {
	if (isFull()) throw "Array overflow";
	arr[n] = new T; ///////////////////////////////////
	arr[n] = new T(*a);
	n++;
}

template <typename T, int maxsize>
void Container<T*, maxsize>::Delete(const T* a) {
	if (isEmpty()) throw "Array is empty";
	int k = -1;
	for (int i = 0; i < n; i++) if (*(arr[i]) == *a) k = i;
	if (k == -1) throw "Item not found";
	delete arr[k];
	arr[k] = arr[n - 1];
	n--;
}

template <typename T, int maxsize>
T& Container<T*, maxsize>::operator[](int _n) const {
	if (_n > n) throw "Item can not be found";
	return *arr[_n];
}

