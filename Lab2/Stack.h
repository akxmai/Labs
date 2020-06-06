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
		auto* tmp = new StackNode;
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
		return 0;
	}
	char Top() {
		return stack->data;
	}
	bool IsEmpty() {
		return stack == nullptr;
	}
};