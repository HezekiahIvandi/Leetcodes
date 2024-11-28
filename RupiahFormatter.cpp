#include <iostream>
#include <string>
#include <vector>
using namespace std;

string format(string input){
    string result = "Rp. " + input;
    int size = input.size()-1;
    int track = 0;

    for(int i = size; i > 0; i--){
        track = track + 1;
        if(track == 3){
            result.insert(i+4, 1, '.');
            track = 0;
        }
    }
    result = result + ",00";
    return result;
}

int main(){
    string res = format("1000000000000");
    cout << res << endl;
    return 0;
}