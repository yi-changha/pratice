// Hello World
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("안녕 C#");
            Console.WriteLine("안녕하세요. "+ args[0]);

            Console.ReadKey();          // 키 하나를 받을 때까지 기다림.
        }
    }
}
