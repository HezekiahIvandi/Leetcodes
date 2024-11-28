#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
        int first = 0;
        int second = 1;

       for(int i = 0; i < n; i++){
        int temp = first;
        first = second;
        second = second + temp;
       }

       return first;
    }

int main(){
    return 0;
}