using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace TrafficLight
{
    class CSignal
    {
        const bool ON = true;
        const bool OFF = false;
        void SetColor(ConsoleColor forground, ConsoleColor background)
        {
            Console.ForegroundColor = forground;
            Console.BackgroundColor = background;
        }

        public CSignal()
        {
            Console.WriteLine("******************");
            Console.WriteLine("프로그램을 시작합니다.");
            Console.WriteLine("******************");
        }

        void Lamp(ConsoleColor color, bool power)
        {
            if (power == ON)
            {
                SetColor(color, color);
            }
            else
            {
                SetColor(ConsoleColor.Gray, ConsoleColor.Gray);
            }
            Console.WriteLine("           ");
            Console.WriteLine("           ");
            Console.WriteLine("           ");
            Console.WriteLine("           ");
            Console.WriteLine("           ");
            SetColor(ConsoleColor.White, ConsoleColor.Black);
        }

        void RedLampOn()
        {
            Console.Clear();
            Lamp(ConsoleColor.Red, ON);
            Lamp(ConsoleColor.Yellow, OFF);
            Lamp(ConsoleColor.Green, OFF);
            Console.WriteLine("적색등이 켜졌습니다.");
        }

        void YellowLampOn()
        {
            Console.Clear();
            Lamp(ConsoleColor.Red, OFF);
            Lamp(ConsoleColor.Yellow, ON);
            Lamp(ConsoleColor.Green, OFF);
            Console.WriteLine("황색등이 켜졌습니다.");
        }

        void GreenLampOn()
        {
            Console.Clear();
            Lamp(ConsoleColor.Red, OFF);
            Lamp(ConsoleColor.Yellow, OFF);
            Lamp(ConsoleColor.Green, ON);
            Console.WriteLine("청색등이 켜졌습니다.");
        }

        int nStep;
        int nCount;
        public bool loop()
        {
            switch(nStep)
            {
                case 0:     // 초기화
                    nStep = 100;
                    nCount = 0;
                    RedLampOn();
                    break;

                case 100:   // 적색등 ON
                    if (nCount < 5)
                    {
                        nCount++;
                    }
                    else
                    {
                        nCount = 0;
                        nStep = 200;
                        YellowLampOn();
                    }
                    break;

                case 200:   // 황색등 ON
                    if (nCount < 5)
                    {
                        nCount++;
                    }
                    else
                    {
                        nCount = 0;
                        nStep = 300;
                        GreenLampOn();
                    }
                    break;

                case 300:   // 청색등 ON
                    if (nCount < 3)
                    {
                        nCount++;
                    }
                    else
                    {
                        nCount = 0;
                        nStep = 0;
                    }
                    break;

                default:
                    nStep = 0;
                    break;
            }

            Thread.Sleep(1000);
            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            CSignal sig = new CSignal();
            while (sig.loop()) ;
        }
    }
}
