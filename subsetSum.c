#include <stdio.h>

void printArray(int a[], int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}

void sums(int a[],int b[], int n, int curr, int e,int m){
  if(e<n){
    b[b[m]]=curr+a[e];
    b[m]+=1;
    e+=1;
    sums(a,b,n,curr,e,m);
    sums(a,b,n,curr+a[e-1],e,m);
  }
}

int main(void) {
  int n,m=1;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    m=m*2;
  }
  int a[n];
  int b[m+1];
  b[m]=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int i=0;
  sums(a,b,n,0,0,m);
  printArray(b,m);
}