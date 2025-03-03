namespace Lab11.Runners;

public class PrinterTaskRunner : AbstractTaskRunner
{
    private static readonly String formatter = "HH:mm";

    public PrinterTaskRunner(TaskRunner taskRunner) : base(taskRunner)
    {
    }

    public void executeOneTask()
    {
        base.executeOneTask();
        Console.WriteLine( "Execute one task: " + DateTime.Now.ToString(formatter));
    }
}