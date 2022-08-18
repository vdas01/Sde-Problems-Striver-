//https://www.geeksforgeeks.org/count-number-subarrays-given-xor/
//1)Brute(Two loops):- O(N^2):-
long long subarrayXor(int arr[], int n, int m){
    long long  ans =0;
    for(int i=0;i<n;i++){
        int xor = 0;
        for(int j=i;j<n;j++){
            xor = xor ^ arr[j];
            if(xor == m)
            ans++;
        }
    }
    return ans;
}
//2)Optimised:- O(nlogn)
long long subarrayXor(int arr[],int n,int k){
    map<int,int>m;
    int xr=0,count=0;
    for(int i=0;i<arr.size();i++){
        xr = xr ^k;
        if(xr == k)
        count++;
        long long y = xr ^ k;
        if(m.find(y) != m.end())
        count+=m[y];
        m[xr]++;
    }
    return count;
}


