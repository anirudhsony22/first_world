def bny(n):
    m=[]
    while n!=0:
        m.append(n%2)
        n=n//2
    return m
def band(a,b):
    if(a>b):
        return band(b,a)
    else:
        i=bny(a)
        j=bny(b)
        sum=0
        while(len(i)!=len(j)):
            i.append(0)
        for l in range(len(i)):
            sum+=(2**l)*(i[l]*j[l])
        return sum
print(band(6,1))