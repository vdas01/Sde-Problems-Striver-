//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
//1) using Set:-
//Time:- O(2N)
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.length()<=1)
//             return s.length();
//         int len=INT_MIN;
//         int left=0;
//         set<char>ans;
//        for(int r=0;r<s.length();r++){
//            while(left<r && ans.find(s[r]) != ans.end()){
//                ans.erase(s[left]);
//                left++;
//            }
//            len = max(len,(r-left)+1);
//            ans.insert(s[r]);
//        }
//         return len;
//     }
// };

//2)Map:- O(N)
//class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int ansLen=0;
        int l=0;
        for(int r=0;r<s.length();r++){
            if(mp[s[r]]!=-1)
                l=max(mp[s[r]]+1,l);
            mp[s[r]]=r;
            ansLen=max(ansLen,r-l+1);
        }
        return ansLen;
    }
};