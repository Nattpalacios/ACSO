#include <stdio.h>
#include <math.h>

char listadoLet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int listadoNum[26] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

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
		char numeroFinal[100];
		//inicio mapearNumeroInicial		
		//numeroReal : importante
		char numReal[100];	
	    int n = 0;
	    while(n < 100){
	        numReal[n] = '*';
	        n++;
	    }
		char numeroReal[100];
		int r = 100;
		while(r > 0){
			numeroReal[r] = numReal[r];
			r--;
		}
		n = 0;
	    int len = 0;
	    while(numeroOriginal[n] != '*' && n < 100){
	        len++;
	        n++;
	    }
		int x = 0;
	    while(len > x){
	        int pos = -1;
	        int y = 0;
	        while(y < (baseOrigen - 9)){
	            if(numeroOriginal[x] == listadoLet[y]){
	                pos = y;
	            }
	            y++;
	        }
	        if(pos != -1){
	            numeroReal[x] = listadoNum[pos];
	        }else{
	            numeroReal[x] = atoi(numeroOriginal[x]);
	        }
	        x++;
	    }
		//final mapearNumeroInicial		
		
		int flag = 0;
		int b = 0;
		while(b < 100 && numeroFinal[b] != '*'){
			if(numeroReal[b] >= baseOrigen){
				flag = 1;
			}
			b++;
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
				//inicio deBaseDecimal
				int dividendo = 0; int cociente = -1;
				int h = 0;
				while(h < 100){
					numeroFinal[h] = '*';
					h++;
				}
				h = 0;
				int len = 0;
				while(numeroReal[h] != '*' && h < 100){
					len++;
					h++;
				}
				int i = 0;
				while(len >= 0){
					len--;
					dividendo += numeroReal[i] * (pow(10,len));
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
				//final deBaseDecimal		
			}else if(baseOrigen != 10 && baseDestino != 10){
				char temp[100];
				//inicio aBaseDecimal
				int h = 0;
			    while(h < 100){
			        temp[h] = '*';
			        h++;
			    }
			    h = 0;
			    int potencia = 0;
			    while(numeroReal[h] != '*' && h < 100){
			        potencia++;
			        h++;
			    }
			    int i = 0;
			    while(potencia >= 0){
			        potencia--;
			        temp[i] = numeroReal[i] * (pow(baseOrigen,potencia));
			        i++;
			    }
				//final aBaseDecimal
				char l[1];
				int a = 0; int c = 0;
				while((temp [c] != '*') && c < 100){
					a += temp[c];
					c++;
				}l[0] = a;
				//inicio deBaseDecimal
				int dividendo = 0; int cociente = -1;
				int s = 0;
				while(s < 100){
					numeroFinal[s] = '*';
					s++;
				}
				s = 0;
				int len = 0;
				while(l[s] != '*' && s < 100){
					len++;
					s++;
				}
				int g = 0;
				while(len >= 0){
					len--;
					dividendo += l[g] * (pow(10,len));
					g++;
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
				//final deBaseDecimal
			}
			else{
				//inicio aBaseDecimal
				int h = 0;
			    while(h < 100){
			        numeroFinal[h] = '*';
			        h++;
			    }
			    h = 0;
			    int potencia = 0;
			    while(numeroReal[h] != '*' && h < 100){
			        potencia++;
			        h++;
			    }
			    int i = 0;
			    while(potencia >= 0){
			        potencia--;
			        numeroFinal[i] = numeroReal[i] * (pow(baseOrigen,potencia));
			        i++;
			    }
				//final aBaseDecimal
			}
			//inicio mapeoFinal
			//mapeoFinal(numeroFinal,baseDestino);
			char numeroFinall[100];
		    int z = 0;
		    while(z < 100){
		        numeroFinall[z] = '*';
		        z++;
		    }
		    z = 0;
		    int len = 0;
		    while(numeroFinal[z] != '*' && z < 100){
		        len++;
		        z++;
		    }
		    int x = 0;
		    while(len > x){
		        int pos = -1;
		        int y = 0;
		        while(y < baseDestino - 9){
		            if(numeroFinal[x] == listadoNum[y]){
		                pos = y;
		            }
		            y++;
		        }
		        if(pos != -1){
		            numeroFinall[x] = listadoLet[pos];
		        }else{
		            numeroFinall[x] = atoi(numeroFinal[x]);
		        }
		        x++;
		    }
		    int i = 0;
		    while(numeroFinall[i] != '*'){
		        printf("%c",numeroFinall[i]);
		    }
			//final mapeoFinal
		}
		
		casos--;
	}
}
