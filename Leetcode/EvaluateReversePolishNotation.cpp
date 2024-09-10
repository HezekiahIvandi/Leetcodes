#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
#include <string>
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

int evalRPN(vector<string>& tokens){
    stack<int> stk;
    for(int i = 0; i < tokens.size(); i++){
        
            if(tokens[i] == "+"){
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1+n2);
            }
            else if(tokens[i] == "-"){
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1-n2);
            }
            else if(tokens[i] == "*"){
                  int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1*n2);
            }
            else if(tokens[i] == "/"){
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1/n2);
            }
        
        else{
            stk.push(stoi(tokens[i]));
        }
    }
    return stk.top();
}

int main() {
    //vector<string> tokens = {"2","1","+","3","*"};
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int res = evalRPN(tokens);

    cout << res << endl;
    return 0;
}