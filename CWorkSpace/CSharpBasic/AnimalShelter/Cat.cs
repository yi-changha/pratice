using System;
using System.Collections.Generic;
using System.Text;

namespace AnimalShelter
{
    public class Cat : Pet
    {
        public Cat(int petID, string name, string color, string gender)
            : base(petID, name, color, gender)
        {
            PetID = petID;
            Name = name;
            Color = color;
            Gender = gender;
        }

        public override string MakeSound()
        {
            return "야옹";
        }

        public string Scratch()
        {
            return "할퀴기";
        }
    }
}
