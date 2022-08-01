#include <bits/stdc++.h>
using namespace std;
// void sorted(int arr1[],int arr2[],int n,int m){
//     int i = 0;
//     while(i<n){
//         if(arr2[0]<arr1[i]){
//             int temp = arr2[0];
//             arr2[0] = arr1[i];
//             arr1[i] = temp;
//            sort(arr2.begin(),arr2.end());
//         }
//          else i++;
//     }
// }
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void gap(int arr1[],int arr2[],int n,int m){
    int gap = ceil((n+m)/2);
    int i=0, j = ((gap+i)%gap)-1;
    while(gap >= 1){
       if(j<n){
           if(arr1[i] > arr1[j]){
               swap(arr1,i,j);
           }
            i++;
            j++;
       }
       else if(j<m){
           if(i<n){
               if(arr1[i] > arr2[j]){
                   int temp = arr2[j];
                   arr2[j] = arr1[i];
                   arr1[i] = temp;
               }
           }
           else{
               if(arr2[i] > arr2[j]){
                   swap(arr2,i,j);
               }
          }
          i++;
          j++;
       }
       else{
           gap = gap/2;
           i=0;
           j= gap+i;
       }
    }

}

int main() {
    int m,n;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)
    cin>>arr1[i];
    for(int j=0;j<m;j++)
    cin>>arr2[m];
  gap(arr1,arr2,n,m);
  for(int i=0;i<n;i++)
  cout<<arr1[i]<<" ";
//   cout<<"\n";
//   for(int j=0;j<m;j++)
//   cout<<arr2[j]<<" ";
}


//Sort:- put all in 3rd array then sort it

//Two pointer:- two pointer in 1st and 2nd array , if arr1[i] < arr2[j] then arr3[k] = arr1[i] and i++;

//Two pointer without 3rd array :-- if arr[i] < arr[j] then swap and i++ then sort or arrange from next element
// the 2nd array and repeat the same process

//GAP method:-- 
//while(gap>=1)
//gap1 = (arr1.size() + arr2.size())/2
// if size is odd then take ceil
//Now start from arr1 1st element one pointer and another pointer at a gap of 
//now traverse and if arr1[i] > arr1[j] then swap and move else move
//if j or i reaches end of array 1 then go to array 2
//if j reaches out of array2 then again do gap = gap/2;
//when gap =1 then after this it will be sorted.