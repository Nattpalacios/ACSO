from sys import stdin

def gcd(x,y):
    while y != 0:
        temp = y
        y = x % y
        x = temp
    return x
  
def main():
    x,y,z = map(int, stdin.readline().split())
    n = int(stdin.readline())
    gcdd = gcd(x,y)
    print(gcdd)
    gcdd2 = gcd(gcdd,z)
    print(gcdd2)
    a = x/gcdd2
    print(a)
    b = y/gcdd2
    print(b)
    c = z/gcdd2
    print(c)
    suma = a + b + c
    print(suma)
    total = int(suma*n)
    print(total)

main()
