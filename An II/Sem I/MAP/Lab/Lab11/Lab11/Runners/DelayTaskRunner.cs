using System.ComponentModel;
using System.Globalization;
using System.Runtime.Serialization;

namespace Lab11.Runners;

public class DelayTaskRunner : AbstractTaskRunner
{
    public DelayTaskRunner(TaskRunner taskRunner) : base(taskRunner)
    {
    }
    
    private static readonly String formatter = "HH:mm";

    public override void executeOneTask()
    {
        try
        {
            Thread.Sleep(1000);
        }
        catch (ThreadInterruptedException e)
        {
            Console.WriteLine(e);
        }
        base.executeOneTask();
    }
}