namespace Lab11;

public class MessageTask : Task
{
    private String mesaj { get; set; }
    private String from { get; set; }
    private String to { get; set; }
    private DateTime date { get; set; }
    
    public MessageTask(string taskID, string descriere, string mesaj, string from, string to, DateTime date) : base(taskID, descriere)
    {
        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    public override void execute()
    {
        Console.WriteLine(this.mesaj + " " + this.date.ToString());
    }
}