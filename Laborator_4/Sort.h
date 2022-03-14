class Sort
{
    int* v;
    int size;
public:
    Sort(int n, int min, int max);
    Sort();
    Sort(int v2[],  int n);
    Sort(int n, ...);
    Sort(char v2[]);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    friend void QuickRecurs(int v[], int st, int dr, bool ascendent);
    friend int Partitie(int v[], int st, int dr, bool ascendent);
};