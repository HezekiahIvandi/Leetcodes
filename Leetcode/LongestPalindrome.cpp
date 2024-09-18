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

int longestPalindrome(string s){
    int total = 0;
    unordered_map<char, pair<int, int>> map;

    for(int i = 0; i < s.size(); i++){
        map[s[i]].first++;
    }

    for(const auto& pair : map){
        char key = pair.first;
        cout << key << " Key : freq " << pair.second.first << " second: " << pair.second.second << endl;
        total += ((pair.second.first+pair.second.second)/2) * 2;
        
    }

    if(total % 2 == 0 && total < s.size()){
        total += 1;
    }
    
    return total;
}

int main() {
    string s = "abccccdd";
    int res = longestPalindrome(s);

    cout << "RESULT: " << res << endl;
    return 0;
}