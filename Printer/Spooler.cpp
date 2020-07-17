#include <iostream>
#include "Spooler.h"

template <class T>
Spooler<T>::Spooler()
{
	count = 0;
	isSorted = false;
}

template <class T>
Spooler<T>::Spooler(const Spooler& obj)
{
	count = obj.count;
	p = new T[count];
	for (int i = 0; i < count; i++)
		p[i] = obj.p[i];
	isSorted = false;
}

template <class T>
void Spooler<T>::Push(T item)
{
	T* p2;
	p2 = p;
	p = new T[count + 1];

	for (int i = 0; i < count; i++)
		p[i] = p2[i];

	p[count] = item;

	count++;

	if (count > 1)
		delete[] p2;
}

template <class T>
T Spooler<T>::Pop()
{
	if (count == 0)
		return 0;

	T item;
	item = p[0];
	T* p2;
	p2 = new T[count - 1];
	count--;

	for (int i = 0; i < count; i++)
		p2[i] = p[i + 1];

	if (!IsEmpty())
		delete[] p;

	p = p2;
	return item;
}

template <class T>
Spooler& Spooler<T>::operator=(const Spooler& obj)  // PROBLEM
{
	T* p2;
	p2 = new T[obj.count];

	if (!IsEmpty())
		delete[] p;

	p = p2;
	count = obj.count;

	for (int i = 0; i < count; i++)
		p[i] = obj.p[i];

	return *this;
}

template <class T>
Spooler<T>::~Spooler()
{
	if (!IsEmpty())
		delete[] p;
}

template <class T>
T Spooler<T>::GetItem()
{
	if (!IsEmpty())
		return p[0];
}

template <class T>
void Spooler<T>::Clear()
{
	if (!IsEmpty())
	{
		delete[] p;
		count = 0;
	}
}

template <class T>
bool Spooler<T>::IsEmpty()
{
	return count == 0;
}

template <class T>
int Spooler<T>::GetN()
{
	return count;
}

template <class T>
void Spooler<T>::Print()
{
	for (int i = 0; i < count; i++)
		cout << p[i] << "\t";
	cout << endl;
}

template <class T>
void Spooler<T>::Sort()
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
			if (p[i] < p[j])
				swap(p[i], p[j]);
	}
	isSorted = true;
}