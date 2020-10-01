#include<bits/stdc++.h>
using namespace std;

int main(){

int n=A.size();

    int msum=INT_MIN; //Max sum
    int sumh=0;       //max sum till current
    
    for(int i=0;i<n;i++){
        sumh+=A[i];
        if(msum<sumh) msum=sumh;
        if(sumh<0) sumh=0;
    }
    cout<<msum;
}
