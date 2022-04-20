using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public enum Operators { Add, Sub, Mul, Div, Equ }

    public partial class Calculator : Form
    {
        public double Result = 0.0f;
        public bool isNewNum = true;
        public Operators Opt = Operators.Add;

        public Calculator()
        {
            InitializeComponent();
        }

        public double Add(double number1, double number2)
        {
            double sum = number1 + number2;
            return sum;
        }

        public double Sub(double number1, double number2)
        {
            double sub = number1 - number2;
            return sub;
        }

        public double Equ(double number1, double number2)
        {
            if (number1 == 0)
                return number2;
            else
                return number1;
        }

        public double Mul(double number1, double number2)
        {
            double mul = number1 * number2;
            return mul;
        }

        public double Div(double number1, double number2)
        {
            double div = number1 / number2;
            return div;
        }

        public void SetNum(string num)
        {
            if (isNewNum == true)
            {
                NumScreen.Text = num;
                isNewNum = false;
            }
            else if (NumScreen.Text == "0")
                    NumScreen.Text = num;
            else
                NumScreen.Text = NumScreen.Text + num;
        }

        private void NumButton_Click(object sender, EventArgs e)
        {
            Button numButton = (Button)sender;  // object 클래스를 Button class로 형변환
            SetNum(numButton.Text);             // Button의 text (string)을 SetNum()의 매개변수로 사용
        }

        private void OperatorButton_Click(object sender, EventArgs e)
        {
            if (isNewNum == false)
            {
                double num = double.Parse(NumScreen.Text);    // string을 double로 형변환
                if (Opt == Operators.Add)
                    Result = Add(Result, num);
                else if (Opt == Operators.Sub)
                    Result = Sub(Result, num);
                else if (Opt == Operators.Equ)
                    Result = Equ(Result, num);
                else if (Opt == Operators.Mul)
                    Result = Mul(Result, num);
                else if (Opt == Operators.Div)
                    Result = Div(Result, num);

                NumScreen.Text = Result.ToString(); // double을 string으로 형변환
                isNewNum = true;
            }

            Button optButton = (Button)sender;
            if (optButton.Text == "+")
                Opt = Operators.Add;
            else if (optButton.Text == "-")
                Opt = Operators.Sub;
            else if (optButton.Text == "=")
                Opt = Operators.Equ;
            else if (optButton.Text == "x")
                Opt = Operators.Mul;
            else if (optButton.Text == "/")
                Opt = Operators.Div;
        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            Result = 0;
            isNewNum = true;
            Opt = Operators.Add;

            NumScreen.Text = "0";
        }
    }
}
