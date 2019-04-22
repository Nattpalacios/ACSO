#include <stdio.h>
#include <math.h>
#include <string.h>

char listado[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int numValido(char numVal[8], int baseOrigen){
	int flag = 1;
	int a = 0; int x = 0;
	int len = strlen(numVal);
	while(x < len){
		a = numVal[x];
		if(numVal[x] > 57){
			a = numVal[x] - 7;
		}
		a -= 48;
		if(a >= baseOrigen){
			flag = 0;
			break; 
		}
		x++;
	}
	return flag;
}

long long aBaseDecimal(char numero[8], int baseOrigen){
    long long numeroDecimal = 0;
    int potencia = strlen(numero) - 1;
    
    char temp[8];
    int i = 0; int a = 0;
    while(i < 8){
    	a = numero[i];
    	if(a > 57){
    		a -= 7;
		}
		a -= 48;
		temp[i] = a;
    	i++;
	}
    
    i = 0;
    while(potencia >= 0){
        numeroDecimal += temp[i] * (pow(baseOrigen,potencia));
        i++; potencia--;
    }
    return numeroDecimal;
}

void deBaseDecimal(long long numero, int baseDestino){
	int n = 0;
	char casi[100] = {'\0'};
	int x = 0;
	if(numero == 0){
		casi[x] = 0;
	}
	while(numero != 0){
		n = numero % baseDestino;
		numero = (long long) numero/baseDestino;
		casi[x] = listado[n];
		x++;
	}
	
	char final[100] = {'\0'};
	int len = strlen(casi);
	x = 0;
	while(x < len){
		len --;
		final[x] = casi[len];
		x ++;
	}
	printf("%s \n", final);
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
		if(baseOrigen < 2 || baseOrigen > 36){
			printf("Error base origen \n");
		}else{
			int numVal = numValido(numeroOriginal, baseOrigen);
			if(numVal == 0){
				printf("Error numero \n");
			}else{
				if(baseDestino < 2 || baseDestino > 36){
					printf("Error base destino \n");
				}else{
					if(baseOrigen == baseDestino){
						printf("%s \n", numeroOriginal);			
					}else{
						long long temp = aBaseDecimal(numeroOriginal,baseOrigen);
						if (baseDestino == 10){
							printf("%lld \n", temp);
						}else {
							if(temp == 0){
								printf("%lld \n",temp);
							}else{
								deBaseDecimal(temp,baseDestino);
							}
							
						}
					}
				}
			}
			
		}
		casos--;
	}
}
