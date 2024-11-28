#include <iostream>
#include <string>
#include <vector>
using namespace std;


    int convert(char c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        if(c == 'M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int prev = convert(s[0]);
        int sum = prev;

        for(int i = 1; i < s.size(); i++){
            int current = convert(s[i]);
            if(current > prev) sum = sum + current - (prev * 2);
            else sum  = sum + current;
            prev = current;
        }   
          
        return sum;
    }


int main(){
    return 0;
}