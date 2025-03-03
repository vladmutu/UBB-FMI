namespace Lab11.Tests;

public class MessageTaskTest
{
    public static MessageTask?[] getMessageTasks()
    {
        MessageTask? task1 =
            new MessageTask("1", "Feedback", "Totul ok", "Gigel", "Mihai",
                DateTime.Parse("2020-10-10 10:10"));
        MessageTask? task2 =
            new MessageTask("2", "Greeting", "Ceau!!", "Maria", "Ionus",
                DateTime.Parse("2021-11-11 11:11"));
        MessageTask? task3 =
            new MessageTask("3", "Feedback", "Top", "Alex", "Ioana",
                DateTime.Parse("2022-3-3 3:33"));
        MessageTask? task4 =
            new MessageTask("4", "nuj", "Alo?", "Giani", "Elena",
                DateTime.Parse("2023-5-5 5:55"));
        MessageTask? task5 =
            new MessageTask("5", "hello", "hi", "Vlad", "Mutu",
                DateTime.Parse("2024-7-7 7:57"));

        return new MessageTask[] { task1, task2, task3, task4, task5 };
    }

    public static void testMessageTask()
    {
        MessageTask?[] messageTasks = getMessageTasks();
        for (int i = 0; i < messageTasks.Length; i++)
        {
            messageTasks[i].execute();
        }
    }
}