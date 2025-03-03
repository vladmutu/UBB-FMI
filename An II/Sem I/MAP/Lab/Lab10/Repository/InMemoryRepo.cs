using Lab10.Domain;

namespace Lab10.Repository
{
    internal class InMemoryRepo<E> : IRepository<int, E> where E : Entity<int>, new()
    {
        private Dictionary<int, E> entities;

        public InMemoryRepo() => entities = new Dictionary<int, E>();

        public IEnumerable<E> FindAll() => entities.Values;


        public E FindOne(int id)
        {
            return entities[id];
        }

        public E Save(E entity)
        {
            entities[entity.Id] = entity;
            return entity;
        }

        public bool Delete(int id)
        {
            return entities.Remove(id);
        }
    }
}