using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CuteCat
{
    public partial class Form1 : Form
    {
        private Cat MyCat = new Cat("냐옹이", 1);


        public Form1()
        {
            InitializeComponent();
        }

        private void Play_Click(object sender, EventArgs e)
        {
            MyCat.Play();
            CatScreen.Text = MyCat.Express();
        }

        private void Feed_Click(object sender, EventArgs e)
        {
            MyCat.Eat();
            CatScreen.Text = MyCat.Express();
        }

        private void CatTimer_Tick(object sender, EventArgs e)
        {
            MyCat.GetBored();
            CatScreen.Text = MyCat.Express();
        }
    }
}
