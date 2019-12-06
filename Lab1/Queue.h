#include <iostream>
#pragma once
class Queue
{
private:
	int size;
	int start;
	int end;
	int* QueueArr;
public:
	Queue(int _size = 100)
	{
		size = _size;
		start = size;
		end = start;
		QueueArr = new int[size];
	}
	void Push(int a)
	{
		if (end == start + 1) start--;
		QueueArr[end] = a;
		if (end < 1) end = size;
		else end--;
	}
	int Pop()
	{
		if (start == end) {
			std::cout << "Очередь пуста!";
		}
		else
		{
			int buff = QueueArr[start];
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
