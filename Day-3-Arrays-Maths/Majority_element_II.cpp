  //https://leetcode.com/problems/majority-element-ii/
  //1) Moore voting algo:-
    class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1,num2 = -2,c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1) c1++;
            else if(nums[i] == num2) c2++;
            else if(c1 == 0){
                num1 = nums[i];
                c1++;
            }
            else if(c2 == 0){
                num2 = nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int>v;
        c1 =0;
        c2=0;
        for(int i=0;i<nums.size();i++){
            if(num1 == nums[i])
                c1++;
            if(num2 == nums[i])
                c2++;
        }
        if(c1 > nums.size()/3)
            v.push_back(num1);
       if(c2> nums.size()/3)
            v.push_back(num2);
        return v;
    }
};

//2)Map(ologn + n , o(logN))
//3)Brute force