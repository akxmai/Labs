#include <iostream>
#include <string>
#include <fstream>
#include "Queue.h"

using namespace std;

void Dist(string path, Queue &evenQ, Queue &oddQ, int length = 20)
{
	char* buff = new char(length + 1);
	ifstream fs;
	fs.open(path);
	while(fs.eof() == false) 
	{
		fs.getline(buff, length, ' ');
		if (atoi(buff) % 2 == 0)
			evenQ.Push(atoi(buff));
		else
			oddQ.Push(atoi(buff));
	}
	fs.close();
}
void Output(Queue q1, Queue q2) {
	cout << "Четная очередь: ";
	while (q1.IsEmpty() == false) 
	{
		cout << q1.Pop() << " ";
	}
	cout << "\nНечетная очередь: ";
	while (q2.IsEmpty() == false) 
	{
		cout << q2.Pop() << " ";
	}
}
int main()
{
	system("chcp 1251");
	system("cls");
	Queue evenQueue;
	Queue oddQueue;
	const string path = "file.txt"; // путь к файлу
	Dist(path, evenQueue, oddQueue);
	Output(evenQueue, oddQueue);
}