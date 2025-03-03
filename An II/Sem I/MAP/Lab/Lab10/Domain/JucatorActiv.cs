namespace Lab10.Domain
{
    enum Tip
    {
        REZERVA,
        JUCATOR
    }
    internal class JucatorActiv : Entity<int>
    {
        public JucatorActiv() { }

        private int idJucator;
        
        public int IdJucator 
        { 
            get { return idJucator; }
            set { idJucator = value; }
        }

        private int idMeci;
        public int IdMeci
        { 
            get { return idMeci; } 
            set { idMeci = value; } 
        }

        private int nrPuncteInscrise;

        public int NrPuncteInscrise
        {
            get { return nrPuncteInscrise;  }
            set { nrPuncteInscrise = value;}
        }

        private Tip tip;
        public Tip Tip
        { 
            get { return tip; }
            set { tip = value; } 
        }

        public JucatorActiv(int id, int idJucator, int idMeci, int nrPuncteInscrise, Tip tip) : base(id) 
        {
            this.idJucator = idJucator;
            this.idMeci = idMeci;
            this.nrPuncteInscrise = nrPuncteInscrise;
            this.tip = tip;
        }
    }
}