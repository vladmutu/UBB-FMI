namespace Lab10.Domain
{
    internal class Entity<ID>
    {
        public Entity() { }
        public Entity(ID id) 
        { 
            this.id = id;   
        }

        private ID id;
        
        public ID Id 
        { 
            get
            {
                return id;
            }
            set
            {
                id = value;
            } 
        }
    }
}