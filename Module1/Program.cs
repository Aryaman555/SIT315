using System;
using System.Diagnostics;

namespace ParallelVectorSum
{
    class Program
    {
        static void RandomVector(int[] vector, int size)
        {
            Random rand = new Random();
            for (int i = 0; i < size; i++)
            {
                vector[i] = rand.Next(100);
            }
        }

        static void Main(string[] args)
        {
            int size = 100000000;
            int[] v1 = new int[size];
            int[] v2 = new int[size];
            int[] v3 = new int[size];
            Random rand = new Random();
            Stopwatch stopwatch = new Stopwatch();

            stopwatch.Start();
            RandomVector(v1, size);
            RandomVector(v2, size);

            for (int i = 0; i < size; i++)
            {
                v3[i] = v1[i] + v2[i];
            }

            stopwatch.Stop();
            Console.WriteLine("Time taken by function: " + stopwatch.ElapsedMilliseconds + " milliseconds");
        }
    }
}
