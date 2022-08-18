//https://leetcode.com/problems/two-sum/
//1)Brute(two loops)
//2)Map
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int>m;
//         m.insert({nums[0],0});
//         vector<int>v;
//         for(int i=1;i<nums.size();i++){
//             if(m.find(target-nums[i])!= m.end()){
//                auto it = m.find(target-nums[i]);
//                 v.push_back(it->second);
//                 v.push_back(i);
//             }
//             m.insert({nums[i],i});
//         }
//         return v;
//     }
// };
