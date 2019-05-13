from sys import stdin

def main():
    while True:
        x1, y1, x2, y2, x3, y3 = map(int, stdin.readline().split())
        area = (x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2)
        if area < 0:
            area = -1 * area
        elif area == 0:
            print("No es un triangulo")
        else:
            A2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
            B2=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)
            C2=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)
            print("area", area >> 1)

            if A2 == B2 and B2 == C2:
                print("Triangulo Equilatero")
            elif A2 != B2 and B2 != C2 and C2 != A2:
                print("Triangulo Escaleno")
            else:
                print("Triangulo Isosceles")
            piv = 0
            p1 = 0
            p2 = 0
            if A2 > B2 and A2 > C2:
                piv = A2
                p1 = B2
                p2 = C2
            elif B2 > C2 and B2 > A2:
                piv = B2
                p1 = A2
                p2 = C2
            else:
                piv = C2
                p1 = A2
                p2 = B2

            if piv == p1 + p2:
                print("El triangulo es rectangulo")
            elif piv > p1 + p2:
                print("El triangulo es obtusangulo")
            else:
                print("El triangulo es acutangulo")
main()
