#include <iostream>
using namespace std;

int factorial(int input){
    if(input == 0) return 1;
    return input * factorial(input - 1);
}

int main(){
    int result = factorial(4);
    cout << "Result: " << result;
    return 0;
}