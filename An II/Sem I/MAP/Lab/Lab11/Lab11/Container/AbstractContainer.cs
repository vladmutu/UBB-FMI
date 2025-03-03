using System.Security.Cryptography;

namespace Lab11.Container;

public abstract class AbstractContainer : Container
{
    protected Task?[] tasks;
    protected int sz;


    public abstract Task? remove();

    public void add(Task? task)
    {
        if (tasks.Length == sz)
        {
            Task?[] newTasks = new Task[tasks.Length * 2];
            System.Array.Copy(tasks, 0, newTasks, 0, newTasks.Length);
            tasks = newTasks;
        }
        tasks[sz++] = task;
    }

    public int size()
    {
        return this.sz;
    }

    public bool isEmpty()
    {
        return sz == 0;
    }
}