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
typedef unordered_map<int, pair<int,int>> pmap;
int majorityElement(vector<int>& nums){
    pair<int,int> res = {0,0};//index, amount
    umap map;

    for(int i = 0; i < nums.size(); i++){

            //nums[i] ada di map
            int amount = map[nums[i]] + 1;
            map[nums[i]] = amount;
            
            //track
            if(amount > res.second){
                res.first = i;
                res.second = amount;
            }
     
    }
    return nums[res.first];
}

int main() {
    vi nums = {2,2,1,1,1,2,2};
    int modus = majorityElement(nums);
    cout << "modus: " << modus << endl;
    return 0;
};