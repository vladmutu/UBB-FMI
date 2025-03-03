namespace Lab10.Domain
{
    internal class Jucator : Elev
    {
        public Jucator() { }
        public Jucator(int id, string name, string school, Echipa echipa) : base(id, name, school)
        {
            this.echipa = echipa;
        }

        private Echipa echipa;
        
        public Echipa Echipa 
        { 
            get
            {
                return this.echipa;
            }
            set
            {
                this.echipa = value;
            }
        }
    }
}