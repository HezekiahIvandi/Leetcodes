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

int maxArea(vector<int>& height){
    int currentMaxArea = 0;
    int pStart = 0;
    int pEnd = height.size() - 1;

    while(pStart < pEnd){
        if(height[pStart] >= height[pEnd]){
            //START BIGGER THAN END
            int area = height[pEnd] * (pEnd-pStart);
            currentMaxArea = max(currentMaxArea, area); 
            pEnd--;

        }
        else if (height[pStart] < height[pEnd]){
            //  END BIGGER THAN START
            int area = height[pStart] * (pEnd-pStart);
            currentMaxArea = max(currentMaxArea, area);
            pStart++;
        }
    }
    return currentMaxArea; 
}

int main() {
    vi height = {1,8,6,2,5,4,8,3,7};

    int res = maxArea(height);

    cout << "Res: " << res << endl;
    return 0;
}