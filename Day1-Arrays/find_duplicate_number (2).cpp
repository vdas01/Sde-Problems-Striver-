//https://leetcode.com/problems/find-the-duplicate-number/
//using cyclic sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(i+1 != nums[i]){
                int correct_index = nums[i]-1;
                if(nums[correct_index] != nums[i]){
                    int temp = nums[correct_index];
                    nums[correct_index] = nums[i];
                    nums[i] = temp;
                }
                else
                    return nums[i];
            }
            else
                i++;
        }
        return 0;
    }
};
//using tortoise method;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0],fast=nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
//using map:-
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it = m.begin();it!=m.end();it++){
            if(it->second > 1)
                return it->first;
        }
        return 0;
    }
};
//count array:-
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       vector<int>v(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]-1]++;
        }
        for(int i=0;i<nums.size();i++){
            if(v[i] > 1)
                return i+1;
        }
        return 0;
    }
};