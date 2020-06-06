// Считайте строку текста, помещая каждый непустой символ и в очередь, и в стек. 
// Проверьте, не является ли текст палидромом. Пример палиндрома: "А роза упала на лапу Азора".
// Для реализации АТД Стек и Очередь использовать динамическое распределение памяти.

#include <iostream>
#include <fstream>
#include <cstring>
#include "Queue.h"
#include "Stack.h"

using namespace std;

char* Read(const string& path, const int length = 20)
{
	char* line = new char;
	ifstream fs;
	fs.open(path);
	fs.getline(line, length, '\n');
	fs.close();
	return line;
}
void Write(Queue* &q, Stack* &s, char* line){
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] != ' ' && line[i] != '\0' && line[i] != '\n')
        {
            q->Enqueue(line[i]);
            s->Push(line[i]);
        }
    }
}
void Output(Queue* q, Stack* s, const string& path, char* line)
{
	bool palindrome = true;
	cout << "Cтрока \"" << line << "\" из файла " << path;
	while (!q->IsEmpty())
	{
		if (q->Dequeue() != s->Pop())
		{
			palindrome = false;
			break;
		}
	}
	if (!palindrome) cout << " не";
	cout << " является палиндромом";
}
int main()
{
	system("chcp 1251");
	system("cls");
	string path = "file.txt"; // название файла со строкой
	const int length = 100; // длина строки
	auto* queue = new Queue();
	auto* stack = new Stack();
    char* line;
	line = Read(path, length);
	Write(queue, stack, line);
	Output(queue, stack, path, line);
	return 0;
}
