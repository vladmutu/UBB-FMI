using Lab11.Enums;

namespace Lab11;

public class SortingTask : Task
{
    private AbstractSorter AbstractSorter { get; set; }
    private SortStrategy sortStrategy { get; set; }
    private int[] elements { get; set; }
    
    public SortingTask(String taskID, String descriere, SortStrategy sortStrategy, int[] elements) : base(taskID, descriere)
    {
        this.sortStrategy = sortStrategy;
        this.elements = elements;
        switch (sortStrategy)
        {
            case SortStrategy.BUBBLESORT:
                this.AbstractSorter = new BubbleSort();
                break;
            case SortStrategy.QUICKSORT:
                this.AbstractSorter = new QuickSort();
                break;
        }
    }
    
    
    public override void execute()
    {
        AbstractSorter.sort(elements);
        Console.WriteLine("Sorted elements: " + string.Join(", ", elements));
    }
}