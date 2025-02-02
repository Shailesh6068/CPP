void QuickSort(vector<int> &s,int first,int last)
{
    if (first >= last)
    {
        return;
    }
    int pi = partition(s,first,last);  
    QuickSort(s,first,pi-1);
    QuickSort(s,pi+1,last);
}