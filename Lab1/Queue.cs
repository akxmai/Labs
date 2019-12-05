using System;

namespace Lab1
{
    class Queue
    {
        private int[] queue = new int[20];
        private int t;
        public Queue()
        {
            t = queue.Length;
        }
        public void Push(int a)
        {
            if (t < 0)
            {
                throw new OverflowException("Queue Overflow");
            }
            else
            {
                t--;
                queue[t] = a;
            }
        }
        public int Pop()
        {
            if (t > queue.Length)
            {
                throw new System.ArgumentException("Queue Empty");
            }
            else
            {
                int a = queue[t];
                t++;
                return a;
            }
        }
        public int Top()
        {
            return queue[t];
        }
        public bool IsEmpty()
        {
            if (t == queue.Length) 
            {
                return true;
            } 
            else 
            {
                return false;
            }
        }
    }
}
