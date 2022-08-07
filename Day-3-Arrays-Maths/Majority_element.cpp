  //1) Moore voting algo:-
  int majorityElement(vector<int>& nums) {
        int count = 0,element=0;
        for(int i=0;i<nums.size();i++){
            if(count ==0){
                count++;
                element= nums[i];
            }
            else{
                if(element == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return element;
    }

2)Map
3)Sort and count
4)Brute force (two loops and check for freq of n/2 + 1)