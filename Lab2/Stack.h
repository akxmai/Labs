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
        if (stack == nullptr) {
            stack = new StackNode;
            stack->data = a;
            stack->next = nullptr;
        }
        else
        {
            auto* tmp = new StackNode;
            tmp->data = a;
            tmp->next = nullptr;
            StackNode* temp = stack;

            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = tmp;
        }
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

