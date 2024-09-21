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

int lengthOfLongestSubstring(string s){
    int maxLength = 0;
    unordered_map<char,int> map;

    int n = s.size();
    //'jbpn'bwwd
    for(int start = 0, end = 0; end < n; end++){
        if(map.find(s[end]) != map.end()){
            //move start
            start = max(map[s[end]]+1, start);
        }
        map[s[end]] = end;
        maxLength = max(maxLength, end-start+1);
        
    }
    return maxLength;
}

int main() {
    //string s = "pwwkew";
    //string s = "aab";
    string s = "jbpnbwwd";
    int res = lengthOfLongestSubstring(s);

    cout << "Result: " << res << endl;
    return 0;
}