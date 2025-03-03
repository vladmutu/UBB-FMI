using Lab10.Domain;

namespace Lab10.Repository.FileRepo
{
    internal class EchipaFile : FileRepo<Echipa>
    {
        public EchipaFile(string fileName) : base(fileName) { }

        protected override Echipa entityFromString(string data)
        {
            string[] properties = data.Split(';');
            return new Echipa(int.Parse(properties[0]), properties[1]);
        }
    }
}