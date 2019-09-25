#include <stdio.h>

void printArray(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}

int check(int a[],int n,int i){
  int res=1,l=2*i+1,r=2*i+2,j=i;
  while(i<n){
    if(l<n && a[j]<a[l]){
      res=0;
      break;
    }
    if(r<n && a[j]<a[r]){
      res=0;
      break;
    }
    j+=1;
    l=2*j+1;r=2*j+2;
  }
  return res;
}

void fix(int a[],int n,int i){
  if(check(a,n,i)==0){
  int temp=a[i];
  if(a[2*i+1]<a[2*i+2]){
    a[i]=a[2*i+2];
    a[2*i+2]=temp;
  }
  else{
    a[i]=a[2*i+1];
    a[2*i+1]=temp;
  }
  while(check(a,n,2*i+1)==0){
    fix(a,n,2*i+1);
  }
  while(check(a,n,2*i+2)==0){
    fix(a,n,2*i+2);
  }
  }
}

int main(void) {
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