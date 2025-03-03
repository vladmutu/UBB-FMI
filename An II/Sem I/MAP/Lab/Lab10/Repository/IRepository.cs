using Lab10.Domain;

namespace Lab10.Repository
{
    internal interface IRepository<ID, E> where E : Entity<ID>
    {
        E FindOne(ID id);

        IEnumerable<E> FindAll();

        E Save(E entity);

        bool Delete(ID id);
    }
}