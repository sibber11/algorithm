#include <iostream>
#include "print_array.hpp"
using namespace std;
int count = 0;
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int j = low;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            if (i !=j)
            {
                swap(arr[j], arr[i]);
                // print_array(arr, low, high);
            }
            
            j++;
        }   
    }
    swap(arr[j], arr[high]);
    // print_array(arr, low, high);
    return j;
}

void quick_sort(int arr[],int low, int high){
    if (high < low)
    {
        return;
    }
    
    int pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);

}

int main(){
    int arr[] = {2,1,5,9,3,7,8,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, len);
    cout << endl;
    quick_sort(arr, 0, len-1);
    cout << endl;
    print_array(arr, len);
}