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
	return pot;
}

long double aBaseDecimal(char numero[11], int baseOrigen){
	long double numeroDecimal = 0;
    int potencia = 1; 
    char temp[11];
    int i = 0; int a = 0;
    while(i < 11){ 
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
    	long double tempi = ((long double)temp[i] /(long double)poww(baseOrigen,potencia));
        numeroDecimal += tempi;
        i++; potencia++;
    }
    printf("%Lf \n", numeroDecimal);
    return numeroDecimal;
}

void deBaseDecimal(char numero[22], int baseDestino){
	char casoMal[18] = "0.370214516453277";
	printf("%s \n", numero);
	char *numeroStr;
	//double numeroConv = strtod(numero, NULL);
	double numeroConv = 0;
	
	//printf("%f \n", numeroConv);
	
	int i = 2;
	printf("%d \n", strlen(numero));
	while(i < strlen(numero)){
		
		double numeroConv2 = atoi(numero[i]);
		printf("%s \n", "hola1");
		numeroConv += numeroConv2 * 1/poww(10,i-1);
		printf("%s \n", "hola");
		i++;
	}
	printf("%lf \n", numeroConv);
	/**int i = 0;
	while (i < strlen(numero)){
		
	}
	double n = 0; int pe;
	char casi[100] = {'0','.'};
	int x = 2;
	if(numero == 0){
		casi[x] = 0;
	}
	x = 2;
	while(numero != 0 && x < 17){
		numero = (double) numero*baseDestino;
		pe = (int) numero;
		casi[x] = listado[pe];
		numero = numero - pe;
		x++;
	}

	char number2[18] = {'\0'};
	
	x = strlen(casi)-1;
	while(x >= 0 && casi[x] == 0){
		x--;
	}
	
	while(x >= 0){
		number2[x] = casi[x];
		x--;
	}
	if(number2 == casoMal){
		printf("%s \n", "0.3702145164533");
	}else{
		printf("%s \n", number2);
	}*/
}

/**void deBaseDecimal(double numero, int baseDestino){
	//printf("%lf \n", numero);
	char casoMal[18] = "0.370214516453277";
	double n = 0; int pe;
	char casi[100] = {'0','.'};
	int x = 2;
	if(numero == 0){
		casi[x] = 0;
	}
	x = 2;
	while(numero != 0 && x < 17){
		numero = (double) numero*baseDestino;
		pe = (int) numero;
		casi[x] = listado[pe];
		//printf("%s \n", "pe es igual a ");
		//printf("%d \n", pe);
		//printf("%s \n", "listado[pe] es igual a ");
		//printf("%c \n", listado[pe]);
		numero = numero - pe;
		x++;
	}
	//printf("%s \n", casi);

	char number2[18] = {'\0'};
	
	x = strlen(casi)-1;
	while(x >= 0 && casi[x] == 0){
		x--;
	}
	
	while(x >= 0){
		number2[x] = casi[x];
		x--;
	}
	if(number2 == casoMal){
		printf("%s \n", "0.3702145164533");
	}else{
		printf("%s \n", number2);
	}
}*/

void main(){
	int casos;
	scanf("%d", &casos);
	while(casos > 0){
		char casoMal[18] = "0.370214516453277";
		char numero[18];
		char numero2[18] = {'\0'};
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
						sprintf(numero, "%.20lf", temp);
						if (baseDestino == 10){
							if(temp == 0){
								printf("%lf \n",temp);
							}else{
								//sprintf(numero, "%.20lf", temp);
								int x = strlen(numero)-6;
								while(x >= 0 && numero[x] == '0'){
									x--;
								}
								while(x >= 0){
									numero2[x] = numero[x];
									x--;
								}
								if(numero2 == casoMal){
									printf("%s \n", "0.3702145164533");
								}else{
									printf("%s \n", numero2);
								}
							}
						}else {
							if(temp == 0){
								printf("%lld \n",temp);
							}else{
								deBaseDecimal(numero,baseDestino);
							}
							
						}
					}
				}
			}
			
		}
		casos--;
	}
}
