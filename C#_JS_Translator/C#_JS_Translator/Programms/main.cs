using System;

namespace Program
{
    public class Program 
    {
        public static void Main(string[] args)
        {
            double a, b;
            a = 5;
            b = -6.34;

            if (a * b > 0)
            {
                a -= b;
            } else
            {
                b -= a;
            }
        }
    }
}