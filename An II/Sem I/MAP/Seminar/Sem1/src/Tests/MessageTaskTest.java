package Tests;

import Model.MessageTask;

import java.time.LocalDateTime;

public class MessageTaskTest {

    public static MessageTask[] getMessageTasks() {
        MessageTask task1 =
                new MessageTask("1", "Feedback", "Totul ok", "Gigel", "Mihai",
                        LocalDateTime.of(2019, 10, 7, 3, 45));
        MessageTask task2 =
                new MessageTask("2", "Greeting", "Ceau!!", "Maria", "Ionus",
                        LocalDateTime.of(2020, 4, 6, 14, 12));
        MessageTask task3 =
                new MessageTask("3", "Feedback", "Top", "Alex", "Ioana",
                        LocalDateTime.of(2020, 11, 28, 17, 34));
        MessageTask task4 =
                new MessageTask("4", "nuj", "Alo?", "Giani", "Elena",
                        LocalDateTime.of(2023, 4, 4, 4, 44));
        MessageTask task5 =
                new MessageTask("5", "hello", "hi", "Vlad", "Mutu",
                        LocalDateTime.of(2024, 10, 10, 11, 9));

        return new MessageTask[]{task1, task2, task3, task4, task5};
    }

    public static void testMessageTask() {
        MessageTask[] messageTasks = getMessageTasks();
        for (MessageTask messageTask : messageTasks) {
            messageTask.execute();
        }
    }

}