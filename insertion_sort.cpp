#include <iostream>

using namespace std;

void print_array(int *arr, const int len){
	for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // array of size 10 with random int values
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4, 9, 10};
	// lenght of the array
    int len = sizeof(arr) / sizeof(arr[0]);

    // print unsorted array
    cout << "Unsorted array: ";
    print_array(arr, len);

    // insertion sort
    for (int i = 1; i < len; i++)
    {
    	/*
    	// visualize which element is worked on.
        for (int l = 0; l < len; l++)
	    {
	    	if(i == l) cout << "(";
	        cout << arr[l];
	        if(i == l) cout << ") ";
	        else cout << " ";
	    }
    	cout << endl;
    	*/
        int k = i;
        for (int j = k-1; j >= 0; j--)
        {
            if (arr[k] < arr[j]){
                swap(arr[j], arr[k]);
                swap(j, k);
            }
        }

    }

    // print sorted array
    cout << "Sorted array: ";
    print_array(arr, len);
}
