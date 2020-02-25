#include <iostream>
#pragma once
class Stack
{
private:
	struct StackNode 
	{
		char data;
		StackNode* next;
	};
	StackNode* stack;
public:
	Stack() 
	{
		stack = nullptr;
	}
	void Push(char a)
	{
		StackNode* tmp = new StackNode;
		tmp->data = a;
		tmp->next = stack;
		stack = tmp;
	}
	int Pop()
	{
		if (stack != nullptr)
		{
			char value = stack->data;
			StackNode* tmp = stack;
			stack = stack->next;
			delete tmp;
			return value;
		}
		throw std::exception("");
	}
	char Top() {
		return stack->data;
	}
	bool IsEmpty() {
		return stack == nullptr;
	}
};

