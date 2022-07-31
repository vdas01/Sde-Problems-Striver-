//https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

#include <bits/stdc++.h>
using namespace std;
//Summation:--
void result(vector<int>&arr,int n){
    int s = (n*(n+1))/2;
    int doubleS = (n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        s -= arr[i];
        doubleS -= arr[i]*arr[i];
    }
    //s = x - y
    //s^2 = x^2 - y^2
    doubleS = doubleS / s;
    //doubleS = x+y
    //s = x - y
    int mis_num = (s + doubleS)/2;
    int repeating_num = abs(mis_num - s);
   cout<<mis_num<<" "<<repeating_num;
}
int main(){
       int n;
       cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    result(v,n);
}


//XOR approach:---
vector < int >Solution::repeatedNumber (const vector < int >&arr) {
    /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}

//Cyclic Sort:--
void swap(int arr[],int i,int j ){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
pair<int,int> cyclic_sort(int arr[], int n){
    int i=0;
    while(i<n){
        if(i+1 != arr[i]){
           int correct_index = arr[i]-1;
           if(arr[i] != arr[correct_index])
           swap(arr,i,correct_index);
           else return {arr[i],i+1};
        }else i++;
    }
    return {0,0};
}

//1)Sort and traverse
//2) Count array
//3) Xor
//4)Sumattion(S and S^2).
//5)Cyclic Sort
