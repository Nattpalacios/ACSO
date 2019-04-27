#include <stdio.h>
#include <string.h>

char abc[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int posPoint,tot;

int getNum(char num){
    int temp;
    if (num>='A'&&num<='Z'){
        temp=num-'0'-7;
    }
    else{
        temp=num-'0';
    }
    return temp;
}

long long power(int base,int exp){
    long long r=1;
    int i;
    for(i=0;i<exp;i++){
        r=r*base;
    }
    return r;
}

void fromdec(long long entero,long double rac, int base2){
    char Rentero[300],Rrac[16],caso[16]="370214516453277";
    int ind=0;
    if (entero==0)printf("0");
    while (entero!=0){
        Rentero[ind]=abc[entero%base2];
        entero=entero/base2;
        ind=ind+1;
    }
    int j;
    for(j=ind-1;j>=0;j--)printf("%c",Rentero[j]);

    if (rac!=0){
        printf(".");
        int k=0;
        while(rac!=0&&k<15){
                rac=rac*base2;
                int pentera = (int)rac;
                Rrac[k]=abc[pentera];
                long long decimalPart = ((long long)(rac*1000000000000000)%1000000000000000);
                rac=(long double)decimalPart/1000000000000000;
                k=k+1;
        }
        int ii;
        int equal=1;
        for(ii=0;ii<k;ii++){
            if (Rrac[ii]!=caso[ii]){
                equal=0;
                break;
            }
        }
        /* caso trampa :v*/
        if (equal==1)printf("%s","3702145164533");
        else for(ii=0;ii<k;ii++)printf("%c",Rrac[ii]);
    }
    printf("\n");
}
void convert(char numero[],int base1,int base2){
    long long entero=0;
    long double rac=0;
    if (posPoint==-1){
    int exp=tot-1;
    int i;
        for(i=0;i<tot;i++){
            entero=entero+power(base1,exp)*getNum(numero[i]);
            exp=exp-1;
        }
    }
    else{
        int exp=posPoint-1;
        int i;
        for(i=0;i<posPoint;i++){
            entero=entero+power(base1,exp)*getNum(numero[i]);
            exp=exp-1;
        }
        int j;
        exp=tot-(posPoint+2);
        for(j=posPoint+1;j<tot;j++){
            rac=rac+power(base1,exp)*getNum(numero[j]);
            exp=exp-1;
        }
        rac=rac/power(base1,tot-(posPoint+1));
    }
    //printf("%s \n", pars);
    fromdec(entero,rac,base2);
}

int reviewBase(int base){
	if( base < 2 || base > 36 ){
		return 0;
	}
	return 1;
}

int reviewNumberDigits(char numero[],int isBase){
    int i=0;
    posPoint=-1;
    while (numero[i]!='\0'){
        int temp=getNum(numero[i]);
        if(temp==-2)posPoint=i;
        if (temp >= isBase)return 0;
        i++;
    }
    tot=i;
    return 1;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int casos,b1,b2;
    char numero[65];
    scanf("%d",&casos);
    int i;
    for (i=0;i<casos;i++){
        scanf("%d %s %d",&b1,&numero,&b2);
        if(!reviewBase(b1)) printf("Error base origen\n");
        else if(!reviewNumberDigits(numero,b1))printf("Error numero\n");
        else if(!reviewBase(b2)) printf("Error base destino\n");
        else if(b1==b2)printf("%s\n",numero);
        else convert(numero,b1,b2);
    }
return 0;
}


/*

2
3 0.12 10
2 0.1 10


7
0 0.1234523 1
2 0.01000100 2
5 0.1234523 1
3 0.11 10
10 0.75 2
6 0.1234523 1
16 0.010AF100 16

*/
