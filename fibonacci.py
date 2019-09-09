def fib(n):
    L=[]
    l=1
    m=0
    i=0
    while(i!=n):
        k=m+l
        L.append(m)
        m=l
        l=k
        i+=1
    return L
print(fib(10))