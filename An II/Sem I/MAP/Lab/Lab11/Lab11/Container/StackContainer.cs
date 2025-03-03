namespace Lab11.Container;

public class StackContainer : AbstractContainer
{
    public StackContainer()
    {
        this.tasks = new Task[10];
        this.sz = 0;
    }

    public override Task? remove()
    {
        if (isEmpty()) return null;
        --this.sz;
        return tasks[this.sz];
    }
}