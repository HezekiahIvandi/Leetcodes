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

void sortColors(vector<int>& nums){
    int pStart = 0;
    int pMiddle = 0;
    int pEnd = nums.size()-1;
    while(pStart != pStart){
        ///
        if(nums[pStart] == 0){
            pStart++;
        }
        if(nums[pEnd] == 2){
            pEnd--;
        }

        ///
        if(nums[pStart] == 2 || nums[pEnd] == 0){
            //swap start and end
            int temp = nums[pStart];
            
            nums.insert(nums.begin()+pStart, nums[pEnd]);
            nums.erase(nums.begin()+pStart);

            nums.insert(nums.begin()+pStart, nums[pEnd] );
            nums.erase(nums.begin()+pEnd);
        }

    }
    
}

int main() {
    vi nums = {2,0,2,1,1,0};
    sortColors(nums);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }
    return 0;
}