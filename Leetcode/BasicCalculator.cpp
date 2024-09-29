#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
#include <string>
#include <stack>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <limits>
//#include <cctype> 
// Include any other headers you need
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;


void evalString(stack<int>& number, string s, int& recIndex, bool bracketUnary){
    bool lastCharIsUnary = false;
      for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            continue;
        }
        else if(s[i] == '(' || s[i] == ')'){
            if(s[i] == ')'){
                recIndex = i + 1;
                cout << "done ) : RI " << recIndex << " : char " << s[recIndex]  << endl;
                break;
            }
        
                cout << "enter bracket for: " << s.substr(i+1) << endl;
           
                evalString(number, s.substr(i+1), recIndex, (bracketUnary ^ lastCharIsUnary));
                lastCharIsUnary = false;
                cout << "recIndex: " << recIndex << endl;
                i += recIndex; 
          
            continue;
        }
        else if(s[i] =='+' || s[i] =='-'){
            if(s[i] == '-'){
                //unary number
                lastCharIsUnary = true;
                continue;
            }
            lastCharIsUnary = false;
        }
        else{
            string nums;
            nums.push_back(s[i]);

            while(i+1 < s.size() && (s[1+i] != '+' && s[1+i] != '-' && s[1+i] != '(' && s[i+1] != ')')){
                i++;
                nums.push_back(s[i]); 
                cout << "whiled char: " << s[i] << endl;
            }
            cout << lastCharIsUnary << " lastCharIsUnary || bracketUnary " <<  bracketUnary << endl;
            if(lastCharIsUnary || bracketUnary){
                //unary number
                int res = stoi(nums) * -1;
                cout << i << " index : num " <<  res << endl;
                
                
                if(lastCharIsUnary && bracketUnary) res = res * -1;
                number.push(res);
                lastCharIsUnary = false;
                continue;
            }
            cout << i << " index : num " <<  (stoi(nums)) << endl;
            number.push((stoi(nums)));
        }
    }
    cout << "out of loop" << endl;
}

int calculate(string s){
    int recIndex = 0;
    stack<int> number;
    
    evalString(number, s, recIndex, false);


   //clarified the stack and get THE SUM
    int total = 0;
    while(!number.empty()){
        total += number.top();
        number.pop();
   
    }
    return total;
}


int main() {
    string s = "(3-(2-(5-(9-(4)))))";
    int result = calculate(s);

    cout << "Result: " << result << endl;
    return 0;
}