using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab10.Domain
{
    internal class Echipa : Entity<int>
    {
        public Echipa() { }
        public Echipa(int id, string name) : base(id)
        {
            this.name = name;
        }

        private string name;
        
        public string Name
        { 
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
    }
}