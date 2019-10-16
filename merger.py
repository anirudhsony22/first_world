def merge(a,b):
    a[1]=b[1];
    return a
def merger(a,b):
    if(a[1]>b[0]):
        return True
    else:
        return False
n=int(input())
a=[]
for i in range(n):
    a.append(input().split())
    a[i][0]=int(a[i][0])
    a[i][1]=int(a[i][1])
b=[a[0]]
j=0
for i in range(n-1):
    if(merger(a[i],a[i+1])):
        b[j][1]=a[i+1][1]
    else:
        j+=1
        b.append(a[i+1])
for i in range(j+1):
    print(b[i][0],b[i][1])