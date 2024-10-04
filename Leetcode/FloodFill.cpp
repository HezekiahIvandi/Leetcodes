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


void flood(vector<vector<int>>& image, int sr, int sc, int color){
    int target = image[sr][sc];
    image[sr][sc] *= color;
    
    //top
    if(sr-1 >= 0 && image[sr-1][sc] == target){
        flood(image, sr-1, sc, color);
    }
    //right  
    if(sc+1 < image.size() && image[sr][sc+1] == target){
        flood(image, sr, sc-1, color);
    }
    //left
     if(sc-1 >= 0 && image[sr][sc-1] == target){
        flood(image, sr, sc+1, color);
    }
    //bottom
     if(sr+1 < image.size() && image[sr+1][sc] == target){
        flood(image, sr+1, sc, color);
    }
}

vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int color){
    flood(image, sr , sc, color);
    return image;
}
int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};

    vector<vector<int>> res = floodfill(image, 1, 1, 2);

    cout <<endl<< " [";
    for(int i = 0; i < res.size(); i++){
        cout << "[";
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << " ]";
    return 0;
}