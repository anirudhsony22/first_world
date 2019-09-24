#include <stdio.h>
#include <stdlib.h>

void printArray(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void rd(int a[],int n){
  for(int i=0;i<n;i++){
    if(a[i]==a[i+1]){
      int j=i;
      while(a[j]==a[j+1] && j<n-1){
        j+=1;
      }
      for(int p=i;p<j;p++){
        a[p]=a[j+1];
      }
    }
  }
}
void sort(int A[],int n){
  int temp=0;
  for(int i=0;i<n-1;i++){
    if(A[i]>A[i+1]){
      temp=A[i+1];
      int j=i;
      while(A[j]>=temp){
        A[j+1]=A[j];
        j-=1;
      }
      A[j+1]=temp;
    }
  }
}
int main(void) {
  int n[5],total=0;
  for(int i=0;i<5;i++){
    scanf("%d",&n[i]);
    total+=n[i];
  }


  int *a0 = (int*)malloc(n[0]+1 * sizeof(int));
  int *a1 = (int*)malloc(n[1]+1 * sizeof(int));
  int *a2 = (int*)malloc(n[2]+1 * sizeof(int));
  int *a3 = (int*)malloc(n[3]+1 * sizeof(int));
  int *a4 = (int*)malloc(n[4]+1 * sizeof(int));
  int ma=0;
  for(int i=0;i<n[0];i++){
    scanf("%d",&a0[i]);
    if(ma<a0[i]){
      ma=a0[i];
    }
  }
  for(int i=0;i<n[1];i++){
    scanf("%d",&a1[i]);
    if(ma<a1[i]){
      ma=a1[i];
    }
  }
  for(int i=0;i<n[2];i++){
    scanf("%d",&a2[i]);
    if(ma<a2[i]){
      ma=a2[i];
    }
  }
  for(int i=0;i<n[3];i++){
    scanf("%d",&a3[i]);
    if(ma<a3[i]){
      ma=a3[i];
    }
  }
  for(int i=0;i<n[4];i++){
    scanf("%d",&a4[i]);
    if(ma<a4[i]){
      ma=a4[i];
    }
  }
  a0[n[0]]=ma;
  a1[n[1]]=ma;
  a2[n[2]]=ma;
  a3[n[3]]=ma;
  a4[n[4]]=ma;
  sort(a0,n[0]);
  sort(a1,n[1]);
  sort(a2,n[2]);
  sort(a3,n[3]);
  sort(a4,n[4]);
  /*printArray(a0,n[0]);
  printf("\n");
  printArray(a1,n[1]);
    printf("\n");
  printArray(a2,n[2]);
    printf("\n");
  printArray(a3,n[3]);
    printf("\n");
  printArray(a4,n[4]);
  */int max[5];
  int i0=0,i1=0,i2=0,i3=0,i4=0,c=0,F[total];
  while(c!=total){
    max[0]=a0[i0];
    max[1]=a1[i1];
    max[2]=a2[i2];
    max[3]=a3[i3];
    max[4]=a4[i4];
    int m=max[0],ind=0;
    for(int i=0;i<5;i++){
      if(max[i]<m){
        m=max[i];ind=i;
      }
    }
    F[c]=m;
    if(ind==0){
      i0+=1;
    }
    if(ind==1){
      i1+=1;
    }
    if(ind==2){
      i2+=1;
    }
    if(ind==3){
      i3+=1;
    }
    if(ind==4){
      i4+=1;
    }
    c+=1;
  }
  int count=0,temp=1,i=0;
  //printArray(F,total);
  //printf("\n");
  while(i!=total-1){
    if(F[i+1]==F[i]){
      temp+=1;
    }
    else{
      temp=1;
    }
    if(temp>2){
      while(i!=total-2 && F[i+1]==F[i]){
        i+=1;
      }
      count+=1;
      temp=1;
      //printf("%d ",F[i]);
    }
    i+=1;
  }
  //printf("\n");
  printf("%d",count);
}