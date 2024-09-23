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

int search(vector<int>& nums, int target){
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end){
        int mid = start + (end-start) / 2;        
        cout << "start: " << start <<" end: " << end <<" mid: " << mid<< endl;
        
        if(nums[mid] == target){ //found
            return mid;
        }
        else if(nums[mid] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    //target: 9, 2=
    vi nums = {-1,0,3,5,9,12};
    //start: 0:-1, 1:0
    //end: 5:12, 2:3,
    //mid: 2:3, 1:0, 
    int res = search(nums, 2);
    cout << "Res: " << res << endl;
    return 0;
} 