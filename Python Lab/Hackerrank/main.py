if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    i=0
    j=0
    k=0
    arr =[]
    while(i<=x):
        j=0
        while(j<=y):
            k=0
            while(k<=z):
                if(i+j+k != n):
                    a = [i,j,k]
                    arr.append(a)
                k+=1
            j+=1
        i+=1
    
    print(arr)