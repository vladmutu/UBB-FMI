using Lab10.Domain;

namespace Lab10.Repository.FileRepo
{
    internal class JucatorActivFile : FileRepo<JucatorActiv>
    {
        public JucatorActivFile(string fileName) : base(fileName) { }

        protected override JucatorActiv entityFromString(string data)
        {
            string[] properties = data.Split(';');
            return new JucatorActiv(int.Parse(properties[0]), int.Parse(properties[1]), int.Parse(properties[2]), int.Parse(properties[3]), Tip.REZERVA);
        }
    }
}