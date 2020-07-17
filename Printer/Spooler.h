#pragma once

using namespace std;

template <typename T>
class Spooler
{
private:
	T* p;
	int count;
	bool isSorted;

public:
	Spooler();

	Spooler(const Spooler& obj);

	void Push(T item);

	T Pop();

	Spooler& operator=(const Spooler& obj);

	~Spooler();

	T GetItem();
	void Clear();

	bool IsEmpty();

	int GetN();

	void Print();

	void Sort();
};