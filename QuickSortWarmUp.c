#include <stdio.h>
#include <stdlib.h>

void qs(int arr[],int n){
    int L[n],E[n],R[n],l=0,e=0,r=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[0]){
            R[r]=arr[i];
            r+=1;
        }
        if(arr[i]==arr[0]){
            E[e]=arr[i];
            e+=1;
        }
        if(arr[i]<arr[0]){
            R[r]=arr[i];
        }
    }
    for(int i=0;i<=l;i++){
        arr[i]=L[i];
    }
    for(int i=0;i<=e;i++){
        arr[i+l]=E[e];
    }
    for(int i=0;i<=r;i++){
        arr[i+l+e]=R[r];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *p = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&p[i])
    }
    qs(p,n);
    for(int i=0;i<n;i++){
        printf("%d",p[i]);
    }
}