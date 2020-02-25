#include <iostream>
#pragma once
class Queue
{
private:
	struct QueueNode
	{
		char data;
		QueueNode* next;
	};
	QueueNode* queue;
public:
	Queue() : queue (nullptr)
	{
	}
	void Enqueue(char a)
	{
		if (queue == nullptr) {
			queue = new QueueNode;
			queue->data = a;
			queue->next = nullptr;
		}
		else 
		{
			QueueNode* tmp = new QueueNode;
			tmp->data = a;
			tmp->next = nullptr;
			QueueNode* temp = queue;

			while (temp->next != nullptr)
				temp = temp->next;
			temp->next = tmp;
		}
	}
	char Dequeue()
	{
		if (queue != nullptr)
		{
			char value = queue->data;
			QueueNode* tmp = queue;
			queue = queue->next;
			delete tmp;
			return value;
		}
		throw std::exception("");
	}
	char Top() {
		return queue->data;
	}
	bool IsEmpty() {
		return queue == nullptr;
	}
};

