namespace Lab11.Runners;

public interface TaskRunner
{
    void executeOneTask();
    void executeAll();
    void addTask(Task? t);
    bool hasTask();
}