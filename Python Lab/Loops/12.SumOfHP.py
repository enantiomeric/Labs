#Aditya Aparadh     22610082    S3
#Program to calculate sum of inverse of first n natural numbers

n = int(input())
i=1
sum=0
while(i<=n):
    sum+= (1/i)
    i+=1
print("Sum of inverse of first",n,"numbers is:",sum)