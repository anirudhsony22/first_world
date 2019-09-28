#include <stdio.h>

void printArray(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}

int check(int a[], int n, int i, int s){
  int res=1;
  if(2*i-s+1<n && a[i]<a[2*i-s+1]){
    res=0;
  }
  if(2*i-s+2<n && a[i]<a[2*i-s+2]){
    res=0;
  }
  return res;
}

void fix(int a[], int n, int i, int s){
  //printArray(a,n);
  if(check(a,n,i,s)==0){
    int temp=a[i];
    if(2*i-s+2<n && a[2*i-s+1]<a[2*i-s+2]){
      a[i]=a[2*i-s+2];
      a[2*i-s+2]=temp;
    }
    else{
      a[i]=a[2*i-s+1];
      a[2*i-s+1]=temp;
    }
    if(2*i-s+1<n){
    fix(a,n,2*i-s+1,s);
    }
    if(2*i-s+2<n){
    fix(a,n,2*i-s+2,s);
    }
  }
}

void heapify(int a[], int n, int s){
  for(int j=n-1;j>=s;j--){
    fix(a,n,j,s);
  }
}

int main(void) {
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++){
    heapify(a,n,i);
    printArray(a,n);
  }
  printArray(a,n);
}