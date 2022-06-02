using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WeightConvertor
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

        }

        private void btnConvert_Click(object sender, EventArgs e)
        {
            try
            {
                double value = Convert.ToDouble(InputText.Text);
                mgBox.Text = kgToMg(value).ToString();
                gramBox.Text = kgToGram(value).ToString();
                kgBox.Text = value.ToString();
                tonBox.Text = kgToTon(value).ToString();
            }
            catch
            {
                InputText.Text = "잘못 입력하였습니다.";
            }
        }

        public double kgToMg(double kg)
        {
            double mg = kg * 1000000;
            return mg;
        }
        public double kgToGram(double kg)
        {
            double gram = kg * 1000;
            return gram;
        }
        public double kgToTon(double kg)
        {
            double ton = kg * 0.001;
            return ton;
        }
        
    }
}
