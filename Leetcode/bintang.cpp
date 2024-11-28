#include <iostream>
#include <vector>
using namespace std;


void star(vector<char>& arr, int size){
    int track = 0;
    bool pastOne = false;
    for(int i = 1; i < size; i++){
        if(track == 1 && !pastOne){
            pastOne = true;
            arr[i-1] = '*';
            track = 0;
        }
        else if(track == 2){
            pastOne = false;
            arr[i-1] = '*';
            track = 0;
        }
        else{
            arr[i-1] = '0' + (i % 10);
            track++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<char> arr(n); 
    star(arr, n);

    cout << "Result: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}