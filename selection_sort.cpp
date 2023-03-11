#include <iostream>
using namespace std;

void selection_sort(int arr[], int len){
    for (int i = 0; i < len; i++)
    {
        int minimum = i;
        for (int j = i+1; j < len; j++)
        {
            
            if (arr[j] < arr[minimum])
            {
                minimum = j;
            }
            
        }
        swap(arr[minimum], arr[i]);
    }
}

void print_array(int arr[], int len){
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}


int main(){
    int arr[] = {20,11,53,9,32,21,47,9,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, len);
    selection_sort(arr, len);
    print_array(arr,len);
}