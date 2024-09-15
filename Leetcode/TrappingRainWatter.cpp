#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
//#include <sstream>
//#include <string>
#include <algorithm>
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

int trap(vector<int>& height){
    int total = 0;
    int n = height.size();
    int fromLeft[n]; int fromRight[n];
    int maxFromLeft = 0; int maxFromRight = 0;
    
   for(int i = 0; i < height.size(); i++){
      maxFromLeft = max(maxFromLeft, height[i]);
      fromLeft[i] = maxFromLeft;

      maxFromRight = max(maxFromRight, height[n-i-1]);
      fromRight[n-i-1] = maxFromRight;
   }

   for(int i = 0; i < height.size(); i++){
      total  += min(fromLeft[i], fromRight[i]) - height[i];
   }
        
    return total;
    
}

int main() {
   //vector<int> height = {4,2,3};
   //vector<int> height = {0,7,1,4,6};
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    //vector<int> height = {0,7,1,4,6};
    int res = trap(height);

    cout << "result: " << res << endl;
    return 0;
}