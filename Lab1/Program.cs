using System;
using System.IO;

namespace Lab1
{
    //13. Используя очередь, решить следующую задачу:
    //Написать программу, которая читает из файла последовательность целых чисел, и помещает все четные числа
    //в одну очередь, а нечетные - в другую. Содержимое каждой очереди вывести на экран.
    //Для реализации АТД Очередь использовать массив.

    class Program
    {
        static void Main(string[] args)
        {
            string path = @"D:\Files\Coding\SiAODvEVM\Labs\Lab1\file.txt";
            string[] numStr = new string[20];
            int[] numInt;
            int i = 0;
            Queue q1 = new Queue();
            Queue q2 = new Queue();
            try
            {
                using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
                {
                    string line;
                    line = sr.ReadLine();
                    numStr = line.Split(' ');
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            numInt = new int[numStr.Length];
            for (i = 0; i < numStr.Length; i++)
            {
                if (numStr[i] != "") { numInt[i] = Convert.ToInt32(numStr[i]); }
            }
            for (i = 0; i < numInt.Length; i++)
            {
                if (numInt[i] % 2 == 0)
                {
                    q1.Push(numInt[i]);
                }
                else
                {
                    q2.Push(numInt[i]);
                }
            }
            Console.WriteLine("Первая очередь:");
            while (!q1.IsEmpty())
            {
                Console.Write(q1.Pop() + " ");
            }
            Console.WriteLine("\nВторая очередь:");
            while (!q2.IsEmpty())
            {
                Console.Write(q2.Pop() + " ");
            }
            Console.ReadKey();
        }
    }
} 
