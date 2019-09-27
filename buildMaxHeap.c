#include <stdio.h>

void printArray(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}

int check(int a[],int n,int i){
  int largest=i,res=1;
  if(2*i+1<n && a[i]<a[2*i+1]){
    res=0;
  }
  if(2*i+2<n && a[i]<a[2*i+2]){
    res=0;
  }
  return res;
}

int wc(int a[], int n, int i){
  int res=1,j=2*i+1,k=2*i+2;
  if(check(a,n,j)==0 || check(a,n,k)==0){
    res=0;
  }
  else if(j<n){
    if(wc(a,n,j)==0){
      res=0;
    }
    if(wc(a,n,k)==0){
      res=0;
    }
  }
  return res;
}

void fix(int a[],int n,int i){
  if(check(a,n,i)==0){
    int temp=a[i];
    if(a[2*i+1]<a[2*i+2] && 2*i+2<n){
      a[i]=a[2*i+2];
      a[2*i+2]=temp;
    }
    else if(2*i+1<n){
      a[i]=a[2*i+1];
      a[2*i+1]=temp;
    }
    if(check(a,n,2*i+1)==0){
      fix(a,n,2*i+1);
    }
    if(check(a,n,2*i+2)==0){
      fix(a,n,2*i+2);
    }
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=n-1;i>=0;i--){
    fix(a,n,i);
  }
  printArray(a,n);
  return 0;
}