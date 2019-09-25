#include <stdio.h>

char* isheap(int a[],int n){
  int i=0,res=1;
  char y[3]="YES";
  int l=2*i+1,r=2*i+2;
  while(r<n){
    if(l<n && a[l]>a[i]){
      //printf("%d %d",a[l],a[i]);
      res=0;
      break;
    }
    if(r<n && a[i]<a[r]){
      //printf("%d %d",a[r],a[i]);
      res=0;
      break;
    }
    i+=1;
    l=2*i+1;r=2*i+2;
  }
  if(res==0){
    return "NO";
  }
  else{
    return "YES";
  }
}

int main(void) {
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("%s",isheap(a,n));
  return 0;
}