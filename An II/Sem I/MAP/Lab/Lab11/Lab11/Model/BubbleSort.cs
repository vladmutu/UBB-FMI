namespace Lab11;

public class BubbleSort : AbstractSorter
{
    public override void sort(int[] elements)
    {
        for (var i = 0; i < elements.Length - 1; i++)
        {
            for (var j = 0; j < elements.Length - i - 1; j++)
            {
                if (elements[j] <= elements[j + 1]) continue;
                (elements[j], elements[j + 1]) = (elements[j + 1], elements[j]);
            }
        }
    }
}