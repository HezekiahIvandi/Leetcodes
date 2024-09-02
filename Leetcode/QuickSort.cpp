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

void QuickSort(vi& nums, int lastPivot = 0){
    int pivot = nums[lastPivot];
    int pivotIndex = lastPivot;
    int n = nums.size();

    for(int i = 1; i < n; i++){
        int toMove = nums[i];
        if(nums[i] < pivot){;
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin(), toMove);
            pivotIndex++;
        }
        else{
            nums.erase(nums.begin() + i);
            nums.push_back(toMove);
            i--;
            n--;
        }
    }
    cout << "Pivot index: " << pivotIndex << endl;
}

int main() {
    vi nums = {4,9,2,5,7,1,6,8,3};
    QuickSort(nums);

    cout << "Result: " << endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }

    return 0;
}