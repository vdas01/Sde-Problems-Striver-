//https://leetcode.com/problems/longest-consecutive-sequence/submissions/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
       map<int,int>m;
        int len=1,maxL = 0;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto it:m){
            if(m.find(it.first - 1) != m.end())
                len++;
            else{
                maxL = max(maxL,len);
                len=1;
            }
        }
        maxL = max(maxL,len);
        return maxL;
    }
};