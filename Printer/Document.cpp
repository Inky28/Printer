#include <iostream>
#include "Document.h"
#define SIZE_RAND 100000

Document::Document()
{
	string name = "Document";
	name += rand() % 50;
	SetSize(rand() % SIZE_RAND);
	SetName(name);
	SetPriority(Priority(rand() % 3));
}

Document::Document(string name, int size, Priority priority)
{
	SetName(name);
	SetSize(size);
}

string Document::GetName()
{
	return name;
}

int Document::GetSize()
{
	return size;
}

Priority Document::GetPriority()
{
	return priority;
}

void Document::SetSize(int size)
{
	if (size > 0 && size < SIZE_RAND)
		this->size = size;
}

void Document::SetName(string name)
{
	if (!name.empty())
		this->name = name;
}

void Document::SetPriority(Priority priority)
{
	this->priority = priority;
}

bool Document:: operator <(const Document& right)
{
	return this->priority < right.priority;
}

bool Document:: operator >(const Document& right)
{
	return this->priority > right.priority;
}

bool Document:: operator <=(const Document& right)
{
	return this->priority <= right.priority;
}

bool Document:: operator >=(const Document& right)
{
	return this->priority >= right.priority;
}