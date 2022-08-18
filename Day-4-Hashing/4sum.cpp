//https://leetcode.com/problems/4sum/
//1) sort and three loop i,j,k and then binary search:-- O(N^3 logN)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            long long target2 = target - nums[i];
            for(int j=i+1;j<n-;j++){
               long long target3 = target2 - nums[j];
               for(int k=j+1;k<n;k++){
                   long long target4 = target3 - nums[k];
                   int low = k+1,high = n-1;
                   while(low <= high){
                       long long mid = high + ((high-low)/2);
                       if(nums[mid] < target4)
                           low = mid+1;
                       else if(nums[mid] > target4)
                           high = mid-1;
                       else{
                           vector<int>v;
                           v[0] = nums[i];
                           v[1] = nums[j];
                           v[2] = nums[k];
                           v[3] = nums[mid];
                           res.push_back(v);
                       }
                   }
               }
                while(j+1 < n && nums[j+1] == nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};
//2)sort and two loop and left and right pointer then if(target-two loop > left + right ->then left +1 else right -1);
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            long long target2 = target - nums[i];
            for(int j=i+1;j<n;j++){
               long long target3 = target2 - nums[j];
                int left = j+1,right = n-1;
                while(left < right){
                    int two_sum = nums[left] + nums[right];
                    if(two_sum < target3) left++;
                    else if(two_sum > target3) right--;
                    else{
                        vector<int>ans(4,0);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2]= nums[left];
                        ans[3] = nums[right];
                        res.push_back(ans);
                        //skipping left
                        while(left < right && nums[left] == ans[2]) left++;
                        //skipping right
                        while(left < right && nums[right] == ans[3]) right--;
                    }
                }
                //skipping j:-
                while(j+1 < n && nums[j+1] == nums[j]) j++;
            }
            //skipping i:-
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};