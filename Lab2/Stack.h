#include <iostream>
#pragma once
class Stack
{
private:
	int size;
	int t;
	char* StackArr;
public:
	Stack(int _size = 100)
	{
		size = _size;
		t = -1;
		StackArr = new char[size];
	}
	void Push(char a)
	{
		if(t > size)
		{
			std::cout << "���� ����������!";
		}
		else
		{
			t++;
			StackArr[t] = a;
		}
	}
	char Pop()
	{
		if (t < 0) {
			std::cout << "���� ����!";
		}
		else 
		{
			t--;
			return StackArr[t + 1];
		}
	}
	char Top() {
		return StackArr[t];
	}
	bool IsEmpty() {
		return (t == -1) ? true : false;
	}
};

