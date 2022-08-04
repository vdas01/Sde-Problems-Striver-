//https://leetcode.com/problems/rotate-image/
//1) Take extra matrix and store first row in last column,  second row in second last column 
//Time:- O(N^2) + O(N^2), Space:- O(N^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>>ans(n,vector<int>(matrix[0].size()));
        int m = matrix[0].size()-1;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<matrix[i].size();j++){
                ans[k][m] = matrix[i][j];
                k++;
            }
            m--;
        }
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};
//2) Transpose the matrix and then reverse every row.
//class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>>ans(n,vector<int>(matrix[0].size()));
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<i;j++){
               int temp = matrix[i][j];
               matrix[i][j] = matrix[j][i];
               matrix[j][i] = temp;
           }
       }
       for(int i=0;i<n;i++)
           reverse(matrix[i].begin(),matrix[i].end());
    }
};



