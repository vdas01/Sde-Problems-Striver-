//1)can use binary search for n logn
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                for(int j=0;j<m;j++){
                    if(matrix[i][j] == target)
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};
//2)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
       int i = 0,j = n-1;
        while(i< n && j>=0){
            if(matrix[i][j] == target)
                return true;
            else{
                if(matrix[i][j] > target)
                    j--;
                else
                    i++;
            }
        }
        return false;
        
    }
    
};
//3)Optimal:- when element of first column is greater than last element of previous row.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
      int l = 0, h = (m*n)-1;
    while(l<=h){
        int mid = l+((h-l)/2);
        int row= mid/m,col = mid%m;
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] > target)
            h = mid-1;
        else
            l=mid+1;
    }
        return false;
    }
};