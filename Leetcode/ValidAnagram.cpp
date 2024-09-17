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

bool isAnagram(string s, string t){
    unordered_map<char, int> map;
    unordered_map<char, int> map2;

    if(s.size() != t.size()) return false;

    for(int i = 0; i < s.size(); i++){
        map[s[i]]++;
        map2[t[i]]++;
    }

    for (const auto& pair : map) {
        char key = pair.first;  
        int v = pair.second;
        if(map2.find(key) == map2.end() ||!(v == map2[key])) return false; 
      
    }

    return true;
}

int main() {
    string s = "aacc"; string t =  "ccac";
    bool res = isAnagram(s,t);
    cout << "Res: " << res << endl;
    return 0;
}