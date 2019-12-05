// Считайте строку текста, помещая каждый непустой символ и в очередь, и в стек. Проверьте, не является ли текст
// палидромом. Пример палиндрома: "А роза упала на лапу Азора".
// Для реализации АТД Стек и Очередь использовать динамическое распределение памяти.

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;

char* Read(string path, int length = 20)
{	
	char* line = new char(length + 1);
	ifstream fs;
	fs.open(path);
	fs.getline(line, length, '\n');
	fs.close();
	return line;
}
int main()
{
	bool palindrome = true;
	string path = "file.txt";
	const int length = 30; //длина строки
	Queue queue(length);
	Stack stack(length);
	char* string;
	string = Read(path, length);
	for (int i = 0; i < strlen(string); i++) 
	{
		if (string[i] != ' ' && string[i] != '\0' && string[i] != '\n')
		{
			queue.Push(string[i]);
			stack.Push(string[i]);
		}
	}
	//while (queue.IsEmpty() == false) 
	//{
	//	if (queue.Pop() != stack.Pop()) palindrome = false;

	//}
	while (queue.IsEmpty() == false)
	{
		cout << queue.Pop();
	}
	cout << endl;
	while (stack.IsEmpty() == false)
	{
		cout << stack.Pop();
	}
	return 0;
}
