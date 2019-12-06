// Считайте строку текста, помещая каждый непустой символ и в очередь, и в стек. 
// Проверьте, не является ли текст палидромом. Пример палиндрома: "А роза упала на лапу Азора".
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
void Output(Queue q, Stack s, string path, char* line)
{
	bool palindrome = true;
	cout << "Cтрока \"" << line << "\" из файла " << path;
	while (q.IsEmpty() == false)
	{
		if (q.Pop() != s.Pop())
		{
			palindrome = false;
			break;
		}
	}
	if (palindrome == false) cout << " не";
	cout << " является палиндромом";
}
int main()
{
	system("chcp 1251");
	system("cls");
	string path = "file.txt"; // название файла со строкой
	const int length = 50; // длина строки
	Queue queue(length);
	Stack stack(length);
	char* line;
	line = Read(path, length);
	for (int i = 0; i < strlen(line); i++)
	{
		if (line[i] != ' ' && line[i] != '\0' && line[i] != '\n')
		{
			queue.Push(line[i]);
			stack.Push(line[i]);
		}
	}
	Output(queue, stack, path, line);
	return 0;
}
