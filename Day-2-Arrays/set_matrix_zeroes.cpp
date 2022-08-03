//https://leetcode.com/problems/set-matrix-zeroes/
//1) Map:- 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0)
                    m[j].push_back(i);
            }
        }
        for(auto it:m){
            for(int i = 0;i<n;i++){
                matrix[i][it.first] = 0;
            }
            vector<int>v = it.second;
            for(int i=0;i<v.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    matrix[v[i]][j]=0;
                }
            }
        }
    }
};
