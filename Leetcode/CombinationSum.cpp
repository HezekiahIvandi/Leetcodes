#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <limits>
// Include any other headers you need
#include <numeric>
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_map<int, int> umap;


void recursion(const vi& candidates, int target, int root, vvi& res, vi& path){

    if(target < 0){
        return;
    }
    if(target == 0){
        res.push_back(path);
        return;
    }
    for(int i = root; i < candidates.size(); i++){
        path.push_back(candidates[i]);
        cout << "path: + " << candidates[i] << endl;
        recursion(candidates, target-candidates[i], i, res, path);
        path.pop_back();
    }
    

}

vvi combinationSum(vi& candidates, int target){
    vvi res;
    vi path;
    recursion(candidates,target, 0, res, path);


    // Use binary_search to check if the target is in the vector
    // bool found = binary_search(candidates.begin(), candidates.end(), target);

    // if(found){
    //     res.push_back({target});
    // }
    return res;
}

int main() {
    // vi candidates = {2,3,6,7};
    // int target = 7;
    vi candidates = {3,5,8};
    int target = 11;

    vvi res = combinationSum(candidates, target);

    cout << "RESULTS: " << endl;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}