#include <iostream>
#include <string>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        int p1 = i-1;
        int p2 = i;

        while(!(p1 < 0) && arr[p1] > arr[p2]){
            int temp = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = temp;
            p2 = p2 - 1;
            p1 = p1 - 1;
        }
    }
}

int main(){
    vector<int> arr = {3, 1, 5, 3, 1, 22, 2, 4};

    insertionSort(arr);
    cout << "After insertion sort: " << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}