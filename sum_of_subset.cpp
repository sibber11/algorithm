#include <iostream>
#include <numeric>

using namespace std;

int sum_of_subset(int arr[], int len, int m, int d, int w, int r)
{
    r -= arr[d];
    int current_weight = arr[d] + w;
    cout << d << ": ";
    cout << "[" << current_weight << "," << r << "]" << endl;
    if (current_weight == m){
        cout << "found with: " << arr[d] << endl;
        return true;
    }
    if (current_weight > m || d > len)
    {
        return false;
    }
    else
    {
        if (sum_of_subset(arr, len, m, d + 1, current_weight, r))
        {
            cout << "found with: " << arr[d] << endl;
            //return true;
        }else if (sum_of_subset(arr, len, m, d + 1, w, r))
        {
            cout << "found without: " << arr[d] << endl;
            //return true;
        }else
            return false;
    }

    return false;
}

int main()
{
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    // int arr[] = { 1, 5, 3, 7, 4 };
    int len = sizeof arr / sizeof arr[0];
    int m = 12, r = 0;
    r = accumulate(arr, arr + len, r);
    if (!sum_of_subset(arr, len, m, 0, arr[0], r))
    {
        sum_of_subset(arr, len, m, 0, 0, r);
    }else
    {
        cout << "found with: " << arr[0] << endl;
    }
    
    // sum_of_subset(arr, len, m, 0, 0, r); 
}