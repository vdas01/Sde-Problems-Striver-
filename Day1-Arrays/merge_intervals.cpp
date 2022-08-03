//https://leetcode.com/problems/merge-intervals/submissions/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>>result;
         sort(intervals.begin(),intervals.end());
        vector<int>ans = intervals[0];
       
        for(auto it : intervals){
            if(it[0] <=ans[1])
                ans[1] = max(it[1],ans[1]);
            else{
                result.push_back(ans);
                ans = it;
            }
        }
        result.push_back(ans);
        return result;
    }
};
