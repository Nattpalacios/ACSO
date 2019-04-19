#include <stdio.h>
#include <string.h>
#include <math.h>

char uwu[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

long long pasarbase10(int bi, char num[10]){
	long long b = 0;
	int el = strlen(num)-1;
	int i = 0;
	while (el>=0){
		int temp = num[i];
		//printf("%d \n",temp);
		if(temp>57){
			temp-=7;
		}
		temp-=48;
		b += (temp*pow(bi,el));
		i++;
		el--;
	}
	//printf("rta = %lld \n",b);
	return b;
}

void invertir(char rta[100]){
	char sol[100] = {'\0'}; 
	int i=strlen(rta)-1;
	//printf("%d \n", i);
	int j=0;
	while(j<strlen(rta)){
		//printf("%s \n",sol);
		sol[j] = rta[i];
		//printf("%d %d \n",i,j);
		i--;
		j++;
	}
	printf("%s \n",sol); 
	
	
}


void pasarbasen(long long num, int bf){
	int r;
	char rta[100] = {'\0'};
	int i=0;
	if(num==0){
		rta[i]= 0;
	}
	while (num!=0){
		//printf("%lld %d %d \n",num,bf,i);
		r = num%bf;
		//printf("%d \n",r);
		num = (long long) num/bf;
		rta[i] = uwu[r];
		//printf("cadena %s \n",rta);
		i++;
	}
	invertir(rta);	
}

int comprobar(char num[10], int bi){
	int rta = 1;
	int i=0;
	int lo = strlen(num);
	for(i=0; i<lo; i++){
		char t = num[i];
		if(t>57){
			t-=7;
		}
		t-=48;
		if(t>=bi){
			rta = 0;
			break;
		}
	}
	return rta;
}


int main(){
	int casos;
	scanf("%d",&casos);
	while(casos!=0){
		int bini;
		int bfin;
		char esp;
		char num[10];
		scanf("%d",&bini);
		//printf("%d \n",bini);
		scanf("%c",&esp);
		scanf("%s",&num);
		//printf("%s \n",num);
		scanf("%c",&esp);
		scanf("%d",&bfin);
		//printf("%d \n",bfin);
		if (bini<2 || bini>36){
			printf("Error base origen \n");
		}
		else{
			int pru = comprobar(num, bini);
			if (pru!=1){
				printf("Error numero \n");
			}
			else{
				if (bfin<2 || bfin>36){
					printf("Error base destino \n");
				}
				else{
					//printf("puede calcularse uwu \n");
					if(bini==bfin){
						printf("%s \n",num);
					}
					else{
						long long nu = pasarbase10(bini, num);
						//printf("%lld",nu);
						if(nu==0){
							printf("0 \n");
						}
						else{
							pasarbasen(nu, bfin);
						}
					}
				
				}
			}
		}	
		
		
		
		//printf("%d \n",casos);
		casos--;
	}
	
	
	
	
	
}
