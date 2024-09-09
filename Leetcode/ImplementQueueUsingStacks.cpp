#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
//#include <sstream>
//#include <string>
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

class MyQueue{
    public:
        stack<int> stk;
        stack<int> stk2;
        int front;

        MyQueue(){

        }

        void push(int x){
            if(stk.empty()){
                front = x;
            }
            stk.push(x);
        }

        int pop(){
            if(stk2.empty()){
                while(!stk.empty()){
                    stk2.push(stk.top());
                    stk.pop();
                }
            }
            
            int top = stk2.top();
            stk2.pop();
            return top;
        }   

        int peek(){ 
            if(!stk2.empty()){
                return stk2.top();
            }
            return front;
        }

        bool empty(){
            return (stk.empty() && stk2.empty());
        }
};

int main() {
    MyQueue q;
    // q.push(1);
    // q.push(2);

    // cout << q.peek() <<endl;
    // cout << q.pop() << endl;
    // cout << q.peek() << endl;

    q.push(1);
    q.push(2);
    cout << q.pop() << endl;
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    cout << q.peek() << endl;
    return 0;
}