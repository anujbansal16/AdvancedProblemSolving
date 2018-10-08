#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the arraySplitting function below.
 */
int arraySplitting(int arr[], int low, int high) {
    long long sum=0;
    if(high==low){
        return 0;
    }
    for(int i=low;i<=high;i++){
        sum+=arr[i];
    }
    if(sum%2){
        return 0;
    }
    long long curr=0,index;
    for(int i=low;i<=high;i++){
        curr+=arr[i];
        if(curr==sum/2){
            index=i;   
            return 1+max(arraySplitting(arr,low,index),arraySplitting(arr,index+1,high));
        }
    }
    return 0;    
    
}

int main()
{
   int t,n;
    cin>>t;
    
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int result = arraySplitting(arr,0,n-1);
        cout<<result<<"\n";          
    }

    return 0;
}

