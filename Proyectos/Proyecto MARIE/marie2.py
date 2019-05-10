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
    gcdd2 = gcd(gcdd,z)
    a = x/gcdd2
    b = y/gcdd2
    c = z/gcdd2
    suma = a + b + c
    total = int(suma*n)
    print(total)

main()
