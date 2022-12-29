import random
import math
n = int(input())
N = int(input())
s = 0
a = 1
while a < n:
    k = random.randint(0, N)
    fact = math.factorial(k)
    b = pow(a, fact) - 1
    b = b % n
    if math.gcd(b, n)!= 1 and math.gcd(b,n)!=n:
        s = 1
        a = n
        print(b)
    a += 1
if ~s:
    print(1)