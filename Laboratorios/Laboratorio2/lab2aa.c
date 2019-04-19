#include <stdio.h>
#include <math.h>

char listadoLet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int listadoNum[26] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

char* mapearNumeroInicial(char *numero, int baseOrigen){
	char numReal[100];	
    int n = 0;
    while(n < 100){
        numReal[n] = '*';
        n++;
    }
    char *numeroReal = numReal;
    n = 0;
    int len = 0;
    while(numero[n] != '*' && n < 100){
        len++;
        n++;
    }
    int x = 0;
    while(len > x){
        int pos = -1;
        int y = 0;
        while(y < (baseOrigen - 9)){
            if(numero[x] == listadoLet[y]){
                pos = y;
            }
            y++;
        }
        if(pos != -1){
            numeroReal[x] = listadoNum[pos];
        }else{
            numeroReal[x] = atoi(numero[x]);
        }
        x++;
    }
    printf("%c",numeroReal[0]);
    return numeroReal;
}

void mapeoFinal(char *numero, int baseDestino){
    char numeroFinal[100];
    int n = 0;
    while(n < 100){
        numeroFinal[n] = '*';
        n++;
    }
    n = 0;
    int len = 0;
    while(numero[n] != '*' && n < 100){
        len++;
        n++;
    }
    int x = 0;
    while(len > x){
        int pos = -1;
        int y = 0;
        while(y < baseDestino - 9){
            if(numero[x] == listadoNum[y]){
                pos = y;
            }
            y++;
        }
        if(pos != -1){
            numeroFinal[x] = listadoLet[pos];
        }else{
            numeroFinal[x] = atoi(numero[x]);
        }
        x++;
    }
    int i = 0;
    while(numeroFinal[i] != '*'){
        printf("%c",numeroFinal[i]);
    }
}

char* aBaseDecimal(char *numero, int baseOrigen){
    char *numeroDecimal;
    int n = 0;
    while(n < 100){
        numeroDecimal[n] = '*';
        n++;
    }
    n = 0;
    int potencia = 0;
    while(numero[n] != '*' && n < 100){
        potencia++;
        n++;
    }
    int i = 0;
    while(potencia >= 0){
        potencia--;
        numeroDecimal[i] = numero[i] * (pow(baseOrigen,potencia));
        i++;
    }
    return numeroDecimal;
}

char* deBaseDecimal(char *numero, int baseDestino){
	int dividendo = 0; int cociente = -1;
	char *numeroFinal;
	//lleno de * el arreglo
	int n = 0;
	while(n < 100){
		numeroFinal[n] = '*';
		n++;
	}
	n = 0;
	int len = 0;
	while(numero[n] != '*' && n < 100){
		len++;
		n++;
	}
	int i = 0;
	while(len >= 0){
		len--;
		dividendo += numero[i] * (pow(10,len));
		i++;
	}
	int completo = 0; int residuo = 0;
	while(cociente != 0 && len >= 0){
	
	    len--;
		completo = dividendo/baseDestino;
		cociente = atoi(completo);;
		residuo = dividendo % baseDestino;
		numeroFinal[len] = residuo;
		dividendo = cociente;
	}
	return numeroFinal;
}

void main(){
	int casos;
	scanf("%d", &casos);
	while(casos > 0){
		int baseOrigen;
		int baseDestino;
		char numeroOriginal[8];
		scanf("%d", &baseOrigen);
		scanf("%s", &numeroOriginal);
		scanf("%d", &baseDestino);
		char *numeroFinal;
		char *numero = mapearNumeroInicial(numeroOriginal,baseOrigen);
		int flag = 0;
		int n = 0;
		while(n < 100 && numeroFinal[n] != '*'){
			if(numero[n] >= baseOrigen){
				flag = 1;
			}
			n++;
		}
		if(baseOrigen < 2 || baseOrigen > 36){
			printf("Error base origen");
		}else if(flag == 1){
			printf("Error numero");
		}else if(baseDestino < 2 || baseDestino > 36){
			printf("Error base destino");		
		}else if(baseOrigen == baseDestino){
			printf("%s", numeroOriginal);			
		}else{
			if(baseOrigen == 10){
				numeroFinal = deBaseDecimal(numero,baseDestino);				
			}else if(baseOrigen != 10 && baseDestino != 10){
				char *temp;
				temp = aBaseDecimal(numero,baseOrigen);
				char l[1];
				int a = 0; int c = 0;
				while((temp [c] != '*') && c < 100){
					a += temp[c];
					c++;
				}l[0] = a;
				numeroFinal = deBaseDecimal(l,baseDestino);
			}
			else{
				numeroFinal = aBaseDecimal(numero,baseOrigen);
			}
			mapeoFinal(numeroFinal,baseDestino);
		}
		
		casos--;
	}
}
