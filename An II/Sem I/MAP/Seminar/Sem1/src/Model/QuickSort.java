package Model;

public class QuickSort extends AbstractSorter{

    @Override
    public void sort(int[] numbers) {
        quicksort(numbers, 0, numbers.length -1);
    }

    public void quicksort(int[] array, int begin, int end) {
        if(begin < end) {
            int partitionIndex = partition(array, begin, end);
            quicksort(array, begin, partitionIndex - 1);
            quicksort(array, partitionIndex + 1, end);
        }
    }

    private int partition(int[] array, int begin, int end) {
        int pivot = array[end];
        int i = begin - 1;
        for(int j = begin; j < end; j++) {
            if(array[j] <= pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[end];
        array[end] = temp;

        return i + 1;
    }
}
