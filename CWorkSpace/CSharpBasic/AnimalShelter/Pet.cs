using System;
using System.Collections.Generic;
using System.Text;

namespace AnimalShelter
{
    public class Pet
    {
        public int PetID;
        public string Name;
        public string Color;
        public string Gender;
        public string Description;

        public Pet(int petID, string name, string color, string gender)
        {
            PetID = petID;
            Name = name;
            Color = color;
            Gender = gender;
        }

        public virtual string MakeSound()
        {
            return "";
        }
    }
}
