//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int>&nums, int n){   
    int sum =0,maxL = INT_MIN;
    map<int,int>m;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum == 0)
        maxL = max(maxL,i+1);
        else{
            if(m.find(sum) != m.end()){
                maxL = max(maxL,(i-m[sum]));
            }
            else m[sum] = i;
        }
    }
    return maxL;
}

