import random
import math
  
primes31 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127]
a = pow(2, 123)
b = pow(2, 128)
k=random.randint(0,15) + 5
print("k = {}".format(k))
p = []
p.append(2)
print("p[0] = {}".format(p[0]))
flag = [0]*32
flag[0] = 1

i = 1
while i <= k - 1:
    j = random.randint(0,30)
    if ~flag[j]:
        p.append(primes31[j])
        flag[j] = 1
        print("p[{}] = {}".format(i, p[i]))
        i += 1
    
n = 1
for i in range (0,k):
    n *= p[i]
while n < a - 1:
    i = random.randint(0, k - 1)
    n *= p[i]
n += 1
t = 0
L = int(math.log2(n))
for a in range (2, L + 1):
    for i in range (0, k):
        if pow(a, int((n - 1)/p[i]), n) != 1 and pow(a, int(n - 1), n) == 1:
            t = 1       
if ~t:
    print("Composite Number n = {}".format(n))
else:
    print("Not Composite Number Try Again")