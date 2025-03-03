namespace Lab11.Container;

public interface Container
{
    Task? remove();
    void add(Task? task);
    int size();
    bool isEmpty();

}