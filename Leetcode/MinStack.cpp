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
// Include any other headers you need
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;

class MinStack{
    vector<pair<int,int>> stk;
    int min;
    public:
    MinStack(){

    }  
    void push(int val) {
        if(stk.empty()){
            min = val;
        }else{
            if(min > val){
                min = val;
            }
        }
        stk.push_back({val, min});
    }
    
    void pop() {
        stk.pop_back();
        min = stk.back().second;
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

int main() {
    return 0;
}