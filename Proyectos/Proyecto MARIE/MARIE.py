from sys import stdin

def gcd(x,y,z):
    if x > y: 
        small = y
        if y > z:
            small = z
    else: 
        small = x
        if x > z:
            small = z
    for i in range(1, small+1): 
        if((x % i == 0) and (y % i == 0) and (z % i == 0)): 
            gcd = i
            
    return gcd 
  
def main():
    x,y,z = map(int, stdin.readline().split())
    n = int(stdin.readline())
    gcdd = gcd(x,y,z)
    a = x/gcdd
    b = y/gcdd
    c = z/gcdd
    suma = a + b + c
    total = int(suma*n)
    print(total)

main()
