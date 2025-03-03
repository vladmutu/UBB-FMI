namespace Lab11.Runners;

public class AbstractTaskRunner : TaskRunner
{
    private TaskRunner taskRunner;

    public AbstractTaskRunner(TaskRunner taskRunner)
    {
        this.taskRunner = taskRunner;
    }
    
    public virtual void executeOneTask()
    {
        taskRunner.executeOneTask();
    }

    public void executeAll()
    {
        while (hasTask())
        {
            executeOneTask();
        }
    }

    public void addTask(Task? t)
    {
        taskRunner.addTask(t);
    }

    public bool hasTask()
    {
        return taskRunner.hasTask();
    }
}