#include <iostream>
#pragma once
class Queue
{
private:
	int size;
	int t;
	char* QueueArr;
public:
	Queue(int _size = 100)
	{
		size = _size;
		t = size + 1;
		QueueArr = new char[size];
	}
	void Push(char a)
	{
		if (t < 0)
		{
			std::cout << "������� �����������!";
		}
		else
		{
			t--;
			QueueArr[t] = a;
		}
	}
	char Pop()
	{
		if (t > size) {
			std::cout << "������� �����!";
		}
		else
		{
			t++;
			return QueueArr[t - 1];
		}
	}
	char Top() {
		return QueueArr[t];
	}
	bool IsEmpty() {
		return (t == size + 1) ? true : false;
	}
};

