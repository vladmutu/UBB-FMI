using Lab10.Domain;

namespace Lab10.Repository.FileRepo
{
    internal abstract class FileRepo<E> : InMemoryRepo<E>
        where E : Entity<int>, new()
    {
        protected FileRepo() { }
        public FileRepo(string fileName)
        {
            readFromFile(fileName);
        }

        protected void readFromFile(string fileName)
        {
            StreamReader streamReaderreader = new StreamReader(fileName);
            string data;
            while(true)
            {
                data = streamReaderreader.ReadLine();
                if (data == null)
                    break;

                Save(entityFromString(data));

            }
        }

        protected abstract E entityFromString(string data);
    }
}