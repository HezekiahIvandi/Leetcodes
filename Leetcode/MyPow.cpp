

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

double myPow(double x, int n) {
    double res = 1;
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        res = 1/(x * myPow(x, (n*-1)-1));
    }
    else{
        int mid = n/2; if (mid == 0) return x;
        res = x * myPow(x, mid-1);
        res = res * res;
        if(n % 2 == 1) res = res * x;
    }
    return res;
}
int main() {
    double x = 1;
    int n = -2147483648;
    double res = myPow(x, n);

    cout <<endl<< "Res: " << res << endl;
    return 0;
}