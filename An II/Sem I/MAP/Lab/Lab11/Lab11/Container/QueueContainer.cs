using System.Collections;

namespace Lab11.Container;

public class QueueContainer : AbstractContainer
{
    public QueueContainer()
    {
        this.tasks = new Task[10];
        this.sz = 0;
    }

    public override Task? remove()
    {
        if (isEmpty()) return null;
        Task? task = tasks[0];
        Task?[] newTasks = new Task[tasks.Length];
        System.Array.Copy(tasks, 1, newTasks, 0, tasks.Length - 1);
        tasks = newTasks;
        sz--;
        return task;

    }
}