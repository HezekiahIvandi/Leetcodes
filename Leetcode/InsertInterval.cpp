#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
//\#include <algorithm>
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

vvi insert(vvi& intervals, vi newInterval){
    vvi res;
    int left = newInterval[0];
    int right = newInterval[1];

    if(intervals.size() == 0){
        //Jika intervals kosong
        res.push_back(newInterval);
        return res;
    }

    for(int i = 0; i < intervals.size(); i++){
        if(right < intervals[i][0]){
            //no more overlapped intervals
            res.push_back({left, right});

            while(i < intervals.size()){
                //insert remaining intervals
                res.push_back(intervals[i]);
                i++;
            }
            cout << "new Interval: " << left << " | " << right << endl;
            return res;
        }
        else if(left > intervals[i][1]){
            //not overlapped
            res.push_back(intervals[i]);
        }
        else{
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
        }
       
    }
    res.push_back({left, right});
    return res;
}

int main() {
    vvi intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vi newInterval = {4,8};
    vvi res = insert(intervals, newInterval);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}