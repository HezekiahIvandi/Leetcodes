// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string input){
    int left = 0;
    int right = input.size() - 1;
    
    while(left < right){
        if(input[left] != input[right]){
            cout << input << " bukan palindrome" << endl;
            return false;
        }
        left++;
        right--;
    }
    
    cout << input << " adalah palindrome" << endl;
    return true;
}

int main() {
    // Write C++ code here
    bool total = isPalindrome("lksakl");
    cout << total << endl;
    return 0;
}