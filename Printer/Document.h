#pragma once
#include <string>

using namespace std;

enum Priority { CLERK, ACCOUNTANT, BOSS };

class Document
{
private:
	string name;
	int size;
	Priority priority;

public:
	Document();
	Document(string name, int size, Priority priority);
	string GetName();
	int GetSize();
	Priority GetPriority();
	void SetSize(int size);
	void SetName(string name);
	void SetPriority(Priority priority);
	bool operator <(const Document& right);
	bool operator >(const Document& right);
	bool operator <=(const Document& right);
	bool operator >=(const Document& right);
};