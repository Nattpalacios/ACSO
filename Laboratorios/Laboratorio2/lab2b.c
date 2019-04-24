#include <stdio.h>
#include <math.h>
#include <string.h>

char listado[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int numValido(char numVal[11], int baseOrigen){
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

long long poww(int baseOrigen, int potencia){
	long long pot = 1;
	long long baseO = (long long) baseOrigen;
	int x = 0;
	while(x < potencia){
		pot = pot * baseO; 
		x++;
	}
	//printf("%lld \n", pot);
	return pot;
}

long double aBaseDecimal(char numero[11], int baseOrigen){
	//printf("%s \n", numero);
	long double numeroDecimal = 0;
    int potencia = 1; 
    //printf("%d \n", potencia);
    char temp[11];
    int i = 0; int a = 0;
    //printf("%s \n", numero[0]);
    while(i < 11){ 
    	//printf("%s \n", numero[i]);
    	a = numero[i];
    	if(a > 57){
    		a -= 7;
		}
		a -= 48;
		temp[i] = a;
    	i++;
	}
    i = 2;
    
    int limite = (strlen(numero) - 1);
    while(potencia < limite){
    	//printf("%s \n", "Hola");
    	//long double caste = (long double) temp[i];
    	//printf("%lld \n", caste);
    	//long long potenciaaaa = poww(baseOrigen,potencia);
    	//printf("%lld \n", potenciaaaa);
    	//printf("%lld \n", poww(10,15));
    	//printf("%lf \n", 1.000000000000000 / 1.000000000000000);
    	long double tempi = ((long double)temp[i] /(long double)poww(baseOrigen,potencia));
    	//printf("%lf \n",tempi);
    	long long tempi2 = (long long) (tempi * 1000000000000000)%1000000000000000;
    	printf("%lld \n",tempi2);
    	tempi = (long double)tempi2 / 1000000000000000;
    	//printf("%lf \n",tempi);
        numeroDecimal += tempi;
        
        //printf("%lf \n",(double)temp[i] /(double)poww(baseOrigen,potencia));
        //long long potenciaaaa = poww(baseOrigen,potencia);
        //printf("%lf \n",numeroDecimal);
        //printf("%lf \n", pow(baseOrigen,potencia));
        i++; potencia++;
    }
    //printf("%s \n", "Hola");
    //printf("%lf \n", numeroDecimal);
    //numeroDecimal = numeroDecimal * poww(10,15);
    //numeroDecimal = numeroDecimal / poww(10,15);
    return numeroDecimal;
}

void deBaseDecimal(double numero, int baseDestino){
	double n = 0;
	char casi[100] = {'\0'};
	int x = 0;
	if(numero == 0){
		casi[x] = 0;
	}
	while(numero != 0){
		n = fmod(numero,(double)baseDestino);
		numero = (double) numero/baseDestino;
		casi[x] = listado[(int)n];
		x++;
	}
	
	char final[100] = {'\0'};
	int len = strlen(casi) - 1;
	x = 0;
	while(x < strlen(casi)){
		final[x] = casi[len];
		len --;
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
		char numeroOriginal[11];
		scanf("%d", &baseOrigen);
		scanf("%s", &numeroOriginal);
		scanf("%d", &baseDestino);
		//printf("%s \n", numeroOriginal);
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
						//printf("%s \n", numeroOriginal);
						double temp = aBaseDecimal(numeroOriginal,baseOrigen);
						if (baseDestino == 10){
							printf("%lf \n", temp);
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
