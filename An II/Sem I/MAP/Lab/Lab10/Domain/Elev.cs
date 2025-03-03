namespace Lab10.Domain
{
    internal class Elev : Entity<int>
    {
        public Elev() { }
        public Elev(int id, string name, string school) : base(id)
        {
            this.name = name;
            this.school = school;
        }

        private string name;
        
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private string school;
        public string School
        {
            get { return school; }
            set { school = value; }
        }

        public override string ToString()
        {
            return Id.ToString() + ";" + Name + ";" + School;
        }
    }
}