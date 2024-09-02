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
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_map<int, int> umap;

//Two pointer solution
vvi threeSum(vi& nums){
    vvi res;
    sort(nums.begin(), nums.end());
    int current;

    for(int i = 0; i < nums.size(); i++){
        
        current = nums[i];
        int sum;
        int pLeft = i+1;
        int pRight = nums.size()-1;
        cout << "current: " << current << " : " << nums[i+1] << " left: " << pLeft << " right: " << pRight << endl;

        if(i > 0 && current == nums[i-1]){
                continue;
        }

        while(pLeft < pRight){
            int sum = current + nums[pLeft] + nums[pRight];
            cout << "sum: " << sum << " left: " << pLeft << " right: " << pRight <<endl;
            if(sum > 0){
                pRight--;
            }
            else if(sum < 0){
                pLeft++;
            }
            else{
                res.push_back({current, nums[pLeft], nums[pRight]});
                pLeft++;
                pRight--;
            }
        }
        
      
        cout << endl;
    }
    return res;
}

int main() {
    //vi nums = {-1,0,1,2,-1,-4 };
    vi nums = {0,0,0};
    vvi res = threeSum(nums);

    cout << "RESULT: " << endl;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}