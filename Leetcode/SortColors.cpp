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
   int pEnd = nums.size() -1;

   while(pMiddle < pEnd && pStart < pEnd){
    if(nums[pStart] == 2 || nums[pEnd] == 0){
        //swap
        int temp = nums[pStart];
        nums[pStart] = nums[pEnd];
        nums[pEnd] = temp;

        if(nums[pStart] == 0) pStart++;
        if(nums[pEnd] == 2) pEnd--;
    }
    else if(nums[pStart] == 0 || nums[pEnd] == 2){
        //skip
        if(nums[pStart] == 0) pStart++;
        if(nums[pEnd] == 2) pEnd--;
    }
    else{
        pMiddle = pStart + 1;
        while(nums[pMiddle] == 1 && pMiddle < pEnd){
            pMiddle++;
        }

        if(nums[pMiddle] == 0){
            //swap to start
            nums[pMiddle] = 1;
            nums[pStart] = 0;


        }
        if(nums[pMiddle] == 2){
            //swap to end
            nums[pMiddle] = 1;
            nums[pEnd] = 2;
        }
    }
   }
}

int main() {
    vi nums = {2,0,1};
    sortColors(nums);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }
    return 0;
}