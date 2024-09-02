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

//prefix sum
vi productExceptSelf(vi& nums){ 
    int n = nums.size();
    vi res(n);

    res[0] = 1;
    res[n-1] = 1;
    
    for(int i = 1; i < n; i++){
       res[i] = nums[i-1] * res[i-1];
    }

    int product = 1;
    for(int i = 1; i < n; i++){
        product *= nums[n-i];
        res[n-i-1] *= product;
        
    }
    return res;
}

int main() {
    vi nums = {0,2,3,4};
    //vi nums = {1, 2, 3, 4};
    vi ans = productExceptSelf(nums);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}