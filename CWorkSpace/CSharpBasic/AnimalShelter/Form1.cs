using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace AnimalShelter
{
    public partial class Form1 : Form
    {
        public List<Customer> Customers = new List<Customer>();

        public Form1()
        {
            InitializeComponent();
        }

        private void CusCreate_Click(object sender, EventArgs e)
        {
            Customer cus = new Customer(NewFirstName.Text, NewLastName.Text,
                DateTime.Parse(NewBirthday.Text));
            cus.Address = NewAddress.Text;
            cus.Description = NewDescription.Text;

            CusList.Rows.Add(cus.FirstName, cus.Age, cus.IsQualified);

            Customers.Add(cus);

            NewFirstName.Text = "";
            NewLastName.Text = "";
            NewBirthday.Text = "";
            NewAddress.Text = "";
            NewDescription.Text = "";
        }

        public void ShowDetails(Customer Cus)
        {
            CusFullName.Text = Cus.FullName;
            CusAge.Text = Cus.Age.ToString();
            CusAddress.Text = Cus.Address;
            CusDescription.Text = Cus.Description;
            CusQualified.Text = Cus.IsQualified.ToString();

            CusPetInfo.Text = "";
            foreach (Pet pet in Cus.MyPets)
            {
                CusPetInfo.Text += pet.Name + " : " + pet.MakeSound();

                if (pet is Cat)
                {
                    CusPetInfo.Text += " : " + (pet as Cat).Scratch();
                }
                else if (pet is Dog)
                {
                    CusPetInfo.Text += " : " + (pet as Dog).Bite();
                }

                CusPetInfo.Text += Environment.NewLine;
            }
        }

        private void CusList_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            string firstName = (string)CusList.Rows[e.RowIndex].Cells[0].Value;
            
            foreach (Customer cus in Customers)
            {
                ShowDetails(cus);
                break;
            }
            CusNewPanel.Hide();
            CusDetailPanel.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            CusListPanel.Dock = DockStyle.Fill;
            CusDetailPanel.Dock = DockStyle.Right;
            CusNewPanel.Dock = DockStyle.Right;


            Customer cus = new Customer("kim", "me", new DateTime(2000, 1, 2));
            Cat cat = new Cat(1, "cat", "White", "Male");
            cus.Adopt(cat);

            Cat cat2 = new Cat(3, "c", "blue", "Female");
            cus.Adopt(cat2);

            Dog dog = new Dog(2, "Happy", "Black", "Male", DogBreed.Husky);
            cus.Adopt(dog);

            Customers.Add(cus);
            CusList.Rows.Add(cus.FirstName, cus.Age, cus.IsQualified);


        }

        private void 새입양자ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CusNewPanel.Show();
            CusDetailPanel.Hide();
        }
    }
}
