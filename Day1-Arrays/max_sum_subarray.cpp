#include <bits/stdc++.h>
using namespace std;
int maxsubArray(vector<int>&nums){
    int ans = INT_MIN,sum = nums[0];
    for(int i=1;i<nums.size();i++){
           if(sum<0){
               ans=max(ans,sum);
               sum+=nums[i];
           }
           else{
               if(nums[i] < 0)
                  ans = max(ans,sum);
                sum+=nums[i];
           }
    }
    ans=max(sum,ans);
    return ans;
}
int main() {
     int n;
     cin>>n;
     vector<int>arr(n);
     for(int i=0;i<n;i++)
      cin>>arr[i];
    cout<<maxsubArray(arr);
}
