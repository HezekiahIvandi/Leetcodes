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

void sortVvi(vvi& intervals){
    sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return lhs[0] < rhs[0];
    });
}

vvi merge(vvi& intervals){
    if(intervals.size() <= 1) return intervals;

    vector<vector<int>> res;
    
    sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return lhs[0] < rhs[0];
    });
    res.reserve(intervals.size());

    int minLeft = intervals[0][0];
    int maxRight = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++){
        //overlap
        if(maxRight >= intervals[i][0]){
            minLeft = min(intervals[i][0], minLeft);
            maxRight = max(intervals[i][1], maxRight);
        }
        else{
            //not overlapped
            res.push_back({minLeft, maxRight});
            minLeft = intervals[i][0];
            maxRight = intervals[i][1];
        }
            
    }
    res.push_back({minLeft, maxRight});
    return res;
} 

int main() {
    vvi intervals = {{1,3},{2,6},{8,10},{15,18}};
    vvi res = merge(intervals);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}