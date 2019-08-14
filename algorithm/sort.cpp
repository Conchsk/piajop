#include <iostream>
using namespace std;

// Selection Sort
template <typename T>
void selectionSort(T array[], int length, bool (*cmp)(T a, T b))
{
    for (int i = 0; i < length - 1; ++i)
    {
        int target = i;
        for (int j = i + 1; j < length; ++j)
            if (!cmp(array[target], array[j]))
                target = j;
        swap(array[i], array[target]);
    }
}

// Bubble Sort
template <typename T>
void bubbleSort(T array[], int length, bool (*cmp)(T a, T b))
{
    for (int i = 0; i < length - 1; ++i)
    {
        bool hasSwap = false;
        for (int j = length - 1; j > i; --j)
            if (cmp(array[j], array[j - 1]))
            {
                swap(array[j], array[j - 1]);
                hasSwap = true;
            }
        if (!hasSwap)
            break;
    }
}

// Insertion Sort
template <typename T>
void insertionSort(T array[], int length, bool (*cmp)(T a, T b))
{
    for (int j = 1; j < length; ++j)
    {
        T key = array[j];
        int i = j - 1;
        while (i >= 0 && !cmp(array[i], key))
        {
            array[i + 1] = array[i];
            --i;
        }
        array[i + 1] = key;
    }
}

// Merge Sort
template <typename T>
void mergeSort(T array[], int length, bool (*cmp)(T a, T b))
{
    if (length > 1)
    {
        int mid = length / 2;
        mergeSort(array, mid, cmp);
        mergeSort(array + mid, length - mid, cmp);
        T *left = new T[mid];
        T *right = new T[length - mid];
        for (int i = 0; i < mid; ++i)
            left[i] = array[i];
        for (int i = 0; i < length - mid; ++i)
            right[i] = array[mid + i];
        int i = 0;
        int j = 0;
        int k = 0;
        while (k < length)
        {
            if (i >= mid)
                array[k++] = right[j++];
            else if (j >= length - mid)
                array[k++] = left[i++];
            else
                array[k++] = cmp(left[i], right[j]) ? left[i++] : right[j++];
        }
        delete[] right;
        delete[] left;
    }
}

// Quicksort
template <typename T>
void quicksort(T array[], int length, bool (*cmp)(T a, T b))
{
    if (length > 1)
    {
        T pivot = array[length - 1];
        int i = 0;
        for (int j = 0; j < length - 1; ++j)
            if (!cmp(pivot, array[j]))
                swap(array[i++], array[j]);
        swap(array[i++], array[length - 1]);
        quicksort(array, i - 1, cmp);
        quicksort(array + i, length - i, cmp);
    }
}
