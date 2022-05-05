using System;
using System.Collections.Generic;
using System.Text;

namespace AnimalShelter
{
    public class Customer
    {
        public string FirstName;
        public string LastName;
        private DateTime _Birthday;
        private bool _IsQualified;
        public string Address;
        public string Description;

        private List<Pet> _MyPets = new List<Pet>();
        public List<Pet> MyPets
        {
            get { return _MyPets; }
        }

        public Customer(string firstName, string lastName, DateTime birthday)
        {
            this.FirstName = firstName;
            this.LastName = lastName;
            this._Birthday = birthday;

            this._IsQualified = DateTime.Now.Year - birthday.Year >= 18;
        }

        public DateTime Birthday
        {
            get { return _Birthday; }
            set
            {
                _Birthday = value;
                _IsQualified = Age >= 18;
            }
        }

        public int Age
        {
            get { return DateTime.Now.Year - _Birthday.Year; }
        }

        public bool IsQualified
        {
            get
            {
                return _IsQualified;
            }
        }

        public string FullName
        {
            get
            {
                return FirstName + " " + LastName;
            }
        }

        public bool Adopt(Pet pet)
        {
            if (_IsQualified)
            {
                _MyPets.Add(pet);
                return true;
            }
            else
                return false;
        }
    }
}
