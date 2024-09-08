#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <limits>
//#include <cctype> 
#include <stack>
// Include any other headers you need
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;

bool isValid(string s){
    //use stack (LAST IN FIRST OUT)
    stack<char> stk;
    
    for(int i = 1; i < s.size(); i++){
        if(!stk.empty() && ((stk.top() == '[' && s[i] == ']') || (stk.top() == '{' && s[i] == '}') || (stk.top() == '(' && s[i] == ')'))){
            stk.pop();
        }
        else{
            stk.push(s[i]);
        };
    }
    

    if(stk.empty()){
        return true;
    }else{
        return false;
    }


}

int main() {

    string s = "()[]{}";
    //string s = "([])";
   // string s = "(]";

   bool result = isValid(s);
   cout << result << endl;
    return 0;
}