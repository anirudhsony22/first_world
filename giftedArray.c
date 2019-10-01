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

void sort(int a[], int n){
  for(int i=0;i<n-1;i++){
    heapify(a,n,i);
  }
}

void sums(int a[],int b[], int n, int curr, int e,int m){ //In b, sum of all possib subsets
  if(e<n){
    b[b[m]]=curr+a[e];
    b[m]+=1;
    e+=1;
    sums(a,b,n,curr,e,m);
    sums(a,b,n,curr+a[e-1],e,m);
  }
}

int element(int a[], int b[], int m){
  int i=0,j=b[0];
  while(b[i]==a[i] && i<m){
    i+=1;
  }
  j=a[i];
  return j;
}

int ex(int n){
  int m=1;
  for(int i=0;i<n;i++){
    m=m*2;
  }
  return m;
}

void final(int a[], int n){
  int k=ex(n);
  sort(a,k);
  printArray(a,k);
  int gift[n];
  gift[0]=a[0];
  gift[1]=a[1];

  for(int i=2;i<n;i++){
    int m=ex(i);
    int b[m+1];
    b[m+1]=0;
    sums(a,b,i,0,0,m);
    gift[i]=element(a,b,m);
  }
  printArray(gift,n);
}

int main(void) {
  int n;
  scanf("%d",&n);
  int a[n];
  int mM=ex(n);
  for(int i=0;i<mM;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<mM;i++){
    heapify(a,mM,i);
    printArray(a,mM);
  }
  //final(a,n);
}