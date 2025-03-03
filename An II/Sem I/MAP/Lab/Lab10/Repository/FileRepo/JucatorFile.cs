using Lab10.Domain;

namespace Lab10.Repository.FileRepo
{
    internal class JucatorFile : FileRepo<Jucator>
    {
        IRepository<int, Echipa> echipe;
        public JucatorFile(IRepository<int, Echipa> echipe, string fileName) 
        {
            this.echipe = echipe;
            readFromFile(fileName);
        }

        protected override Jucator entityFromString(string data)
        {
            string[] properties = data.Split(';');
            int idEchipa = int.Parse(properties[3]);

            return new Jucator(int.Parse(properties[0]), properties[1], properties[2], echipe.FindOne(idEchipa));
        }
    }
}