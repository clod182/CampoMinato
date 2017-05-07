#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char** creaCampo(char** campo,int r,int c){
	int i,j;
	campo=(char**)malloc(r*sizeof(char*));
	for(i=0;i<r;i++){
		campo[i]=(char*)malloc(c*sizeof(char));
	}
	return campo;
}


char** riempiCampo(char** campo,int r, int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			campo[i][j]='0';
		}
	}	
	return campo;
}


void stampaCampo(char** campo,int r,int c){
	int i,j;
	printf("-----Il campo e questo-----\n");
	/*for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%c",campo[i][j]);
		}
		printf("\n");
	}*/
	for(j=0;j<c;j++){
		printf("%d  ",j+1);
	}
	printf("\n");
	for(j=0;j<c;j++){
		printf("-  ",j+1);
	}	
	printf("\n\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%c  ",campo[i][j]);
        }
    	printf("|%d ",i+1);
    	printf("\n");
    }
}


char** inserisciMine(char** campo,int r,int c,int m){
	int i,j,ran1,ran2,contm=0;
	srand(time(NULL));
	/*for(i=0;i<r && contm<=m;i++){
		for(j=0;j<c && contm<=m;j++){
			ran1=rand()%(r);
			ran2=rand()%(c);
			if(campo[ran1][ran2]!='*'){
				campo[ran1][ran2]='*';
				contm++;
			}							
		}
	}*/	
	while(contm<m){
		ran1=rand()%(r);
		ran2=rand()%(c);
		if(campo[ran1][ran2]!='*'){
			campo[ran1][ran2]='*';
			contm++;
		}		
	}
	return campo;
}


int main(){
	int scelta=0;
	char** CampoMain;
	printf("***---***CampoMinato***---***\n");
	printf("Cosa vuoi fare?\n1 - Generare schema tramite input\n2 - Generare schema tramite file\n3 - Uscita\n");
	scanf("%d",&scelta);
	if (scelta==1){
		int R,C,mine;
		do{
			printf("Dammi la dimensione del campo ((R C) > 0)\n");
			scanf("%d %d",&R, &C);
		}while(R<=0 || C<=0);		
		CampoMain=creaCampo(CampoMain,R,C);
		CampoMain=riempiCampo(CampoMain,R,C);				
		stampaCampo(CampoMain,R,C);
		do{
			printf("Dammi il numero di mine che vuoi inserire (0<n<dimensione campo -1)\n");
			scanf("%d",&mine);
		}while(mine<=0 || mine>(R*C)-1);
		CampoMain=inserisciMine(CampoMain,R,C,mine);
		stampaCampo(CampoMain,R,C);
	}
	return 0;
}
