import Enums.Strategy;
import Enums.SortStrategy;
import Model.BubbleSort;
import Model.QuickSort;
import Model.SortingTask;
import Runners.StrategyTaskRunner;
import Tests.DelayTaskRunnerTest;
import Tests.MessageTaskTest;
import Tests.PrinterTaskRunnerTest;
import Tests.StrategyTaskRunnerTest;

public class Main {
    public static void main(String[] args) {
        System.out.println("Test task - BUBBLESORT");
        SortingTask task1 = new SortingTask("1", "Hello", new int[]{1, 4, 3}, SortStrategy.BUBBLESORT);
        task1.execute();

        System.out.println("Test task - QUICKSORT");
        SortingTask task2 = new SortingTask("2", "Hello", new int[]{4, 3, 2, 1}, SortStrategy.QUICKSORT);
        task2.execute();

        int[] n1 = {4, 3, 2, 1};

        BubbleSort bubbleSort = new BubbleSort();
        bubbleSort.sort(n1);

        for (int j : n1) {
            System.out.print(j + " ");
        }
        System.out.println("\n");

        int[] n2 = {4, 3, 2, 1};

        QuickSort quickSort = new QuickSort();
        quickSort.sort(n2);

        for (int j : n2) {
            System.out.print(j + " ");
        }
        System.out.println("\n");

        System.out.println("Test task-uri\n");
        MessageTaskTest.testMessageTask();
        System.out.println("\n");


        String containerStrategy = args[0];
        switch (containerStrategy) {
            case ("FIFO") -> {
                System.out.println("Test StrategyTaskRunner\n");
                System.out.println("FIFO");
                StrategyTaskRunnerTest.strategyTaskRunnerTest(Strategy.FIFO, MessageTaskTest.getMessageTasks());
                System.out.println('\n');
                System.out.println("Test PrinterTaskRunner\n");
                PrinterTaskRunnerTest.printerTaskRunnerTest(Strategy.FIFO, MessageTaskTest.getMessageTasks());
                System.out.println("\n");
                System.out.println("Test DelayTaskRunner\n");
                DelayTaskRunnerTest.delayTaskRunnerTest(Strategy.FIFO, MessageTaskTest.getMessageTasks());
                System.out.println("\n");
            }
            case("LIFO") -> {
                System.out.println("Test StrategyTaskRunner\n");
                System.out.println("LIFO");
                StrategyTaskRunnerTest.strategyTaskRunnerTest(Strategy.LIFO, MessageTaskTest.getMessageTasks());
                System.out.println('\n');
                System.out.println("Test PrinterTaskRunner\n");
                PrinterTaskRunnerTest.printerTaskRunnerTest(Strategy.LIFO, MessageTaskTest.getMessageTasks());
                System.out.println("\n");
                System.out.println("Test DelayTaskRunner\n");
                DelayTaskRunnerTest.delayTaskRunnerTest(Strategy.LIFO, MessageTaskTest.getMessageTasks());
                System.out.println("\n");
            }
        }
    }
}