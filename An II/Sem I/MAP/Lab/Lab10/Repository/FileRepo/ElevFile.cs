using Lab10.Domain;

namespace Lab10.Repository.FileRepo
{
    internal class ElevFile : FileRepo<Elev>
    {
        public ElevFile(string fileName) : base(fileName) { }

        protected override Elev entityFromString(string data)
        {
            string[] properties = data.Split(';');
            return new Elev(int.Parse(properties[0]), properties[1], properties[2]);
        }
    }
}