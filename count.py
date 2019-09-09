num=int(input())

def fb(n):
    L=[]
    m=0
    l=1
    i=0
    while(i!=n):
       L.append(m%10)
       l=m+l
       m=l-m
       i+=1
    while(len(L)!=1):
        m=[]
        for i in range(1,len(L),2):
            m.append(L[i])
        L=m
    return L[0]
output=[]
for i in range(num):
    output.append(int(input()))
for i in range(num):
    print(fb(output[i]))