#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <limits>
// Include any other headers you need
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;

bool containsDuplicate(vector<int>& nums){
    umap map;
    map[nums[0]] = 0;
    for(int i = 1; i < nums.size(); i++){
        if(map.find(nums[i]) != map.end()){
            return true;
        }
        else{
            map[nums[i]] = i;
        }
    }
    return false;
}

int main() {
    vi nums = {1,2,3,1};
    bool res = containsDuplicate(nums);

    cout << "RESULT: " << res << endl;
    return 0;
}