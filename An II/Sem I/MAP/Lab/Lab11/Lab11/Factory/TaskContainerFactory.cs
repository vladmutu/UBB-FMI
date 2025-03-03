using Lab11.Enums;
using Lab11.Container;
namespace Lab11.Factory;

public class TaskContainerFactory : Factory
{
    private TaskContainerFactory()
    {
        
    }

    private static readonly TaskContainerFactory instance = new TaskContainerFactory();

    public static TaskContainerFactory getInstance => instance;
    
    public Container.Container createContainer(Strategy containerStrategy)
    {
        return containerStrategy switch
        {
            Strategy.FIFO => new Container.QueueContainer(),
            Strategy.LIFO => new Container.StackContainer(),
            _ => throw new ArgumentOutOfRangeException(nameof(containerStrategy), containerStrategy, null)
        };
    }
}