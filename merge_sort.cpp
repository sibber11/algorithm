#include <iostream>
#include "print_array.hpp"
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int left_size = mid - low + 1;
    int right_size = high - mid;
    int left_array[left_size];
    int right_array[right_size];

    for (int i = 0; i < left_size; i++)
        left_array[i] = arr[low + i];
    for (int i = 0; i < left_size; i++)
        right_array[i] = arr[mid + i + 1];
    
    int i = 0, j = 0, k = low;
    while (i < left_size && j < right_size)
    {
        if (left_array[i] <= right_array[j])
            arr[k++] = left_array[i++];
        else
            arr[k++] = right_array[j++];
    }

    while (i < left_size)
        arr[k++] = left_array[i++];
    while (j < left_size)
        arr[k++] = right_array[j++];
}

void merge_sort(int arr[], int low, int high)
{
    if (high <= low)
        return;

    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
    print_array(arr, 9);
}

int main()
{
    int arr[] = {2, 1, 5, 9, 3, 7, 8, 6, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, len);
    cout << endl;
    merge_sort(arr, 0, len - 1);
    cout << endl;
    print_array(arr, len);
}