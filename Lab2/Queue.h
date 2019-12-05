#include <iostream>
#pragma once
class Queue
{
private:
	int size;
	int start;
	int end;
	char* QueueArr;
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
		if (end = 0) end = size;
		else end--;
		QueueArr[end] = a;
	}
	char Pop()
	{
		if (start == end) {
			std::cout << "Очередь пуста!";
		}
		else
		{
			if (start = 0) start = end;
			else start--;
			return QueueArr[start - 1];
		}
	}
	char Front() {
		return QueueArr[start];
	}
	bool IsEmpty() {
		return (start == end) ? true : false;
	}
};

