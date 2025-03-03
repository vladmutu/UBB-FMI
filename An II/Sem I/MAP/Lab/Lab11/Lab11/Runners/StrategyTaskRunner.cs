using Lab11.Enums;
using Lab11.Factory;
using Lab11.Container;

namespace Lab11.Runners;

public class StrategyTaskRunner : TaskRunner
{
    
    private Container.Container container;

    public StrategyTaskRunner(Strategy strategy)
    {
        container = TaskContainerFactory.getInstance.createContainer(strategy);
    }
    
    public void executeOneTask()
    {
        if (!hasTask()) return;
        Task? task = container.remove();
        task.execute();
    }

    public void executeAll()
    {
        while (hasTask())
        {
            executeOneTask();
        }
    }
    
    public bool hasTask()
    {
        return !container.isEmpty();
    }
    
    public void addTask(Task? t)
    {
        container.add(t);
    }
}