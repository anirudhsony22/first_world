#include <stdio.h>
void printArray(int a[],int s,int e){
  for(int i=s;i<=e;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void merge(int L[], int R[], int E[],int l,int r,int e,int a[]){
  int i=0;
  while(i!=l){
    a[i]=L[i];
    i+=1;
  }
  while(i!=l+e){
    a[i]=E[i-l];
    i+=1;
  }
  while(i!=l+e+r){
    a[i]=R[i-l-e];
    i+=1;
  }
  //printf("After merge");
  printArray(a,0,l+e+r-1);
  //printf("\n");
}

void qs(int a[],int n){
  int l=0,r=0,e=1,R[n],L[n],E[n];
  E[0]=a[0];
  for(int i=1;i<n;i++){
    if(a[i]<a[0]){
      L[l]=a[i];
      l+=1;
    }
    else if(a[i]>a[0]){
      R[r]=a[i];
      r+=1;
    }
    else{
      E[e]=a[i];
      e+=1;
    }
  }
  //printArray(a,0,n-1);
  //printf(" L = ");
  //printArray(L,0,l-1);
  //printf(" E = ");
  //printArray(E,0,e-1);
  //printf(" R = ");
  //printArray(R,0,r-1);
  if(l>1){
    qs(L,l);
  }
  if(r>1){
    qs(R,r);
  }
  merge(L,R,E,l,r,e,a);
}

int main(void) {
  int n,j=0,k=0,i=0;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qs(a,n);
  //printArray(a,0,n-1);
  return 0;
}