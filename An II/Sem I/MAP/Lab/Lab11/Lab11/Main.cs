using Lab11.Enums;
using Lab11.Tests;

namespace Lab11;

public class Main
{
        public void main(String[] args)
        {
            Console.WriteLine("Test task - BUBBLESORT");
            SortingTask task1 = new SortingTask("1", "Hello", SortStrategy.BUBBLESORT, new int[]{4, 3, 2, 1});
            task1.execute();

            Console.WriteLine("Test task - QUICKSORT");
            SortingTask task2 = new SortingTask("2", "Hello", SortStrategy.QUICKSORT, new int[]{4, 3, 2, 1});
            task2.execute();

            int[] n1 = {4, 3, 2, 1};

            BubbleSort bubbleSort = new BubbleSort();
            bubbleSort.sort(n1);

            for (int j = 0; j < n1.Length; j++) {
                Console.WriteLine(n1[j] + " ");
            }
            Console.WriteLine("\n");

            int[] n2 = {4, 3, 2, 1};

            QuickSort quickSort = new QuickSort();
            quickSort.sort(n2);

            for (int j = 0; j<n2.Length; j++) {
                Console.WriteLine(n2[j] + " ");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Test task-uri\n");
            MessageTaskTest.testMessageTask();
            Console.WriteLine("\n");


            String containerStrategy = args[0];
            switch (containerStrategy) {
                case "FIFO" : {
                    Console.WriteLine("Test StrategyTaskRunner\n");
                    Console.WriteLine("FIFO");
                    StrategyTaskRunnerTest.strategyTaskRunnerTest(Strategy.FIFO, MessageTaskTest.getMessageTasks());
                    Console.WriteLine('\n');
                    Console.WriteLine("Test PrinterTaskRunner\n");
                    PrinterTaskRunnerTest.printerTaskRunnerTest(Strategy.FIFO, MessageTaskTest.getMessageTasks());
                    Console.WriteLine("\n");
                    Console.WriteLine("Test DelayTaskRunner\n");
                    DelayTaskRunnerTest.delayTaskRunnerTest(Strategy.FIFO, MessageTaskTest.getMessageTasks());
                    Console.WriteLine("\n");
                    break;
                }
                case "LIFO"  : {
                    Console.WriteLine("Test StrategyTaskRunner\n");
                    Console.WriteLine("LIFO");
                    StrategyTaskRunnerTest.strategyTaskRunnerTest(Strategy.LIFO, MessageTaskTest.getMessageTasks());
                    Console.WriteLine('\n');
                    Console.WriteLine("Test PrinterTaskRunner\n");
                    PrinterTaskRunnerTest.printerTaskRunnerTest(Strategy.LIFO, MessageTaskTest.getMessageTasks());
                    Console.WriteLine("\n");
                    Console.WriteLine("Test DelayTaskRunner\n");
                    DelayTaskRunnerTest.delayTaskRunnerTest(Strategy.LIFO, MessageTaskTest.getMessageTasks());
                    Console.WriteLine("\n");
                    break;
                }
            }
        }
}