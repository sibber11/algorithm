#include <iostream>
using namespace std;

int get_min(int arr[], int len){
    if (len == 1)
        return arr[0];
    return min(arr[len], get_min(arr, len-1));
}

int get_max(int arr[], int len){
    if (len == 1)
        return arr[0];
    return max(arr[len], get_max(arr, len-1));
}

int main(){
    int arr[] = {3,61,34,42,57,68,71,82,95,100};
    cout << get_min(arr, 9);
    cout << endl;
    cout << get_max(arr, 9);
}