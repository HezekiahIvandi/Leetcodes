#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

///PROBLEM TYPE : ARRAY AND DYNAMIC PROGRAMMING
//Kadane's Algorithm
//Kadane's Algorithm is a dynamic programming technique used to find the maximum subarray sum in an array of numbers. 
//The algorithm maintains two variables: max_current represents the maximum sum ending at the current position, 
//and max_global represents the maximum subarray sum encountered so far. At each iteration, it updates max_current to include 
//the current element or start a new subarray if the current element is larger than the accumulated sum. The max_global is updated 
//if max_current surpasses its value.
int maxProfit(vector<int>& prices){
    int len = prices.size();

    if(len == 1){
        return 0;
    }

    int pointed = prices[0];
    int maxSelisih = 0;

    for(int i = 1; i < len; i++){
        int selisih = pointed - prices[i];

        if(selisih >= 0){//jika depan lebih kecil
        
            pointed = prices[i];
        }
        else{
            //jika depan lebih besar
            
            maxSelisih = max(maxSelisih, abs(selisih));
            cout << "selisih " << i << " " << abs(selisih) << endl;
        }
    }
    return maxSelisih;

}

int main() {
    vi prices = {9,2,8,1,0,6,9};
    int res = maxProfit(prices);

    cout << res << endl;
    return 0;
}