#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        vector<string> inCommon;
        string result;
        if(strs[0].size() == 0) return result;
        
        

        int len = 0;
        while(len < strs[0].size()){
            char prev = strs[0][len];
            for(int i = 1; i < strs.size(); i++){
                if(len < strs[i].size() && prev == strs[i][len]) continue;
                return result;
            }
            result.push_back(prev);
            len++;
        }

        return result;
       
    }

int main(){
  
    return 0;
}