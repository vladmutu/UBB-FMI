package Model;

import java.util.Arrays;
import Enums.SortStrategy;

public class SortingTask extends Task{
    private AbstractSorter abstractSorter;
    private final int[] numbers;
    private final SortStrategy sortStrategy;

    public SortingTask(String taskID, String descriere, int[] numbers, SortStrategy sortStrategy) {
        super(taskID, descriere);
        this.numbers = numbers;
        this.sortStrategy = sortStrategy;
        switch (this.sortStrategy) {
            case SortStrategy.BUBBLESORT -> {
                abstractSorter = new BubbleSort();
            }
            case SortStrategy.QUICKSORT -> {
                abstractSorter = new QuickSort();
            }
        }
    }

    @Override
    public void execute() {
        abstractSorter.sort(numbers);
        System.out.println(Arrays.toString(numbers) + '\n');
    }
}
