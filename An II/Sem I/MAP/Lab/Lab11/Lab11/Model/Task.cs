namespace Lab11;

public abstract class Task
{
    private String taskID { get; set; }
    private String descriere { get; set; }
    
    public abstract void execute();
    
    public String ToString()
    {
        return taskID + " " + descriere;
    }
    
    public Boolean Equals(Task task)
    {
        return taskID == task.taskID;
    }
    
    public Task(String taskID, String descriere)
    {
        this.taskID = taskID;
        this.descriere = descriere;
    }
    
    public int HashCode()
    {
        return taskID.GetHashCode();
    }
    
}