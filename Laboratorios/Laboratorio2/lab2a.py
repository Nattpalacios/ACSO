from sys import stdin

listadoLet = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
listadoNum = [10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36]

def mapearNumeroInicial(numero,baseOrigen):
    numeroReal = []
    for x in range(len(numero)):
        pos = -1
        for y in range(0,baseOrigen-9):
            if(numero[x] == listadoLet[y]):
                pos = y
        if(pos != -1):
            numeroReal.append(listadoNum[pos])
        else:
            numeroReal.append(int(numero[x]))
    return numeroReal

def mapeoFinal(numero, baseDestino):
    numeroFinal = ""
    for x in range(len(numero)):
        pos = -1
        for y in range(0,baseDestino-9):
            if(numero[x] == listadoNum[y]):
                pos = y
        if(pos != -1):
            numeroFinal += listadoLet[pos]
        else:
            numeroFinal += str(numero[x])

    print(numeroFinal)

def aBaseDecimal(numero,baseOrigen):
    potencia = len(numero)
    numeroDecimal = []
    for i in range(len(numero)):
        potencia -= 1
        numeroDecimal.append(numero[i] * (baseOrigen**potencia))
    return numeroDecimal

def deBaseDecimal(numero,baseDestino):
    dividendo = 0
    x = len(numero)
    for i in range(len(numero)):
        x -= 1
        dividendo += numero[i] * (10**x)
    numeroFinal = []
    cociente = -1
    while(cociente != 0):
        completo = dividendo/baseDestino
        cociente = int(completo)
        residuo = dividendo % baseDestino
        numeroFinal.append(residuo)
        dividendo = cociente
    numeroFinal.reverse()
    return numeroFinal

def main():
    casos = int(stdin.readline())
    for x in range(casos):
        conver = stdin.readline().strip().split()
        baseOrigen = int(conver[0])
        baseDestino = int(conver[2])
        numeroOriginal = conver[1]
        numeroFinal = []
        numero = mapearNumeroInicial(numeroOriginal,baseOrigen)
        flag = False
        for i in range(len(numero)):
            if(numero[i] >= baseOrigen):
                flag = True
        if(baseOrigen < 2 or baseOrigen > 36):
            print("Error base origen")
        elif(flag):
            print("Error numero")
        elif(baseDestino < 2 or baseDestino > 36):
            print("Error base destino")
        elif(baseOrigen == baseDestino):
            print(numeroOriginal)
        else:
            if(baseOrigen == 10):
                numeroFinal = deBaseDecimal(numero,baseDestino)
            elif(baseOrigen != 10 and baseDestino != 10):
                temp = aBaseDecimal(numero,baseOrigen)
                l = []
                a = 0
                for z in range(len(temp)):
                    a += temp[z]
                l.append(a)
                numeroFinal = deBaseDecimal(l,baseDestino)
            else:
                numeroFinal = aBaseDecimal(numero,baseOrigen)
            mapeoFinal(numeroFinal, baseDestino)


main()
