using Lab10.Domain;

namespace Lab10.Repository.FileRepo
{
    internal class MeciFile : FileRepo<Meci>
    {
        IRepository<int, Echipa> echipe;
        public MeciFile(IRepository<int, Echipa> echipe ,string fileName)
        {
            this.echipe = echipe;
            readFromFile(fileName);
        }

        protected override Meci entityFromString(string data)
        {
            string[] properties = data.Split(';');
            int idEchipa1 = int.Parse(properties[1]);
            int idEchipa2 = int.Parse(properties[2]);

            return new Meci(int.Parse(properties[0]), echipe.FindOne(idEchipa1), echipe.FindOne(idEchipa2), DateTime.Parse(properties[3]));
        }
    }
}