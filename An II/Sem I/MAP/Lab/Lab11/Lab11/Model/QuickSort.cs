namespace Lab11;

public class QuickSort : AbstractSorter
{
    private int partition(int[] elements, int left, int right)
    {
        var pivot = elements[right];
        var i = left - 1;
        for (var j = left; j < right; j++)
        {
            if (elements[j] >= pivot) continue;
            i++;
            (elements[i], elements[j]) = (elements[j], elements[i]);
        }
        (elements[i + 1], elements[right]) = (elements[right], elements[i + 1]);
        return i + 1;
    }
    
    private void quickSort(int[] elements, int left, int right)
    {
        if (left >= right) return;
        var pivot = partition(elements, left, right);
        quickSort(elements, left, pivot - 1);
        quickSort(elements, pivot + 1, right);
    }
    public override void sort(int[] array)
    {
        quickSort(array, 0, array.Length - 1);
    }
}