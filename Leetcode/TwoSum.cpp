#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Typedefs
typedef vector<int> vi;
typedef unordered_map<int, int> umap;

///PROBLEM TYPE : HASHMAP 
vi twoSum(vector<int>& nums, int target){
    umap visited;
    vi res(2);

    visited[target-nums[0]] = 0;

    for(int i = 1; i < nums.size(); i++){
        if(visited.find(nums[i]) != visited.end()){
            res[1] = i;
            res[0] = visited.at(nums[i]);
            return res;
        }
        visited[target-nums[i]] = i;
        cout << "insert: " << nums[i]-target << endl;
    }

    return res;
}

int main() {
    vi nums = {3,2,4};
    int target = 6;
    vi res = twoSum(nums, target);

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}

