using System;
using System.Collections.Generic;
using System.Text;

namespace AnimalShelter
{
    public enum DogBreed { Mixed, Shiba, Jindo, Husky}
    public class Dog : Pet
    {
        public DogBreed Breed;

        public Dog(int petID, string name, string color, string gender, DogBreed breed)
            : base(petID, name, color, gender)
        { 
            Breed = breed;
        }

        public override string MakeSound()
        {
            return "멍멍";
        }

        public string Bite()
        {
            return "물기";
        }
    }
}
