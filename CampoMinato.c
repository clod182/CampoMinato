#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void creaCampo(int** campo,int r,int c){
	int i,j;
	campo=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++){
		campo[r]=(int*)malloc(c*sizeof(int));
	}
}

void riempiCampo(int** campo,int r, int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			campo[i][j]='*';
		}
	}
}

void stampaCampo(int** campo,int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d",campo[i][j]);
		}
	}
}
int main(){
	int scelta=0;
	int** CampoMain;
	printf("***---***CampoMinato***---***\n");
	printf("Cosa vuoi fare?\n1 - Generare schema tramite input\n2 - Generare schema tramite file\n3 - Uscita\n");
	scanf("%d",&scelta);
	if (scelta==1){
		int R,C;
		printf("Dammi la dimensione del campo ((r c) > 0)\n");
		scanf("%d %d",R, C);
		creaCampo(CampoMain,R,C);
		riempiCampo(CampoMain,R,C);
		stampaCampo(CampoMain,R,C);
	}
	return 0;
}
