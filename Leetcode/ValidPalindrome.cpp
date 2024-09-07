#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <limits>
#include <cctype> 
// Include any other headers you need
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;

bool isPalindrome(string s){
    int pStart = 0;
    int pEnd = s.size() - 1;

    while(pStart < pEnd){
        while(!isalnum(s[pStart])){
            pStart++;
        }
        while(!isalnum(s[pEnd])){
            pEnd--;
        }
        if(tolower(s[pStart]) != tolower(s[pEnd])){
            return false;
        }
        pStart++;
        pEnd--;
    }

    return true;
}

int main() {
    string a = "abccba";
    string s = "A man, a plan, a canal: Panama";
    int res = isPalindrome(s);

    cout << "Result: " << res << endl;
    return 0; 
}