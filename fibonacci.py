def fib(n):
    L=[]
    l=1
    m=0
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
    return L
print(fib(10))