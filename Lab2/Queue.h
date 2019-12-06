#include <iostream>
#pragma once
class Queue
{
private:
	int size;
	int start;
	int end;
	char *QueueArr;
public:
	Queue(int _size = 100)
	{
		size = _size;
		start = size;
		end = start;
		QueueArr = new char[size];
	}
	void Push(char a)
	{
		if (end == start + 1) start--;
		QueueArr[end] = a;
		if (end < 1) end = size;
		else end--;
	}
	char Pop()
	{
		if (start == end) {
			std::cout << "Очередь пуста!";
		}
		else
		{
			char buff = QueueArr[start];
			if (start < 1) start = size;
			else start--;
			return buff;
		}
	}
	char Front() {
		return QueueArr[start];
	}
	bool IsEmpty() {
		return (start == end) ? true : false;
	}
};

