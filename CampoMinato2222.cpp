#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(){
	int scelta=0;
	int** CampoMain;
	int i,j;
	printf("***---***CampoMinato***---***\n");
	printf("Cosa vuoi fare?\n1 - Generare schema tramite input\n2 - Generare schema tramite file\n3 - Uscita\n");
	scanf("%d",&scelta);
	if (scelta==1){
		int R,C;
		printf("Dammi la dimensione del campo ((R C) > 0)\n");
		scanf("%d %d",&R, &C);
		//creaCampo(CampoMain,R,C);
		CampoMain=(int**)malloc(R*sizeof(int*));
		for(i=0;i<R;i++){
			CampoMain[i]=(int*)malloc(C*sizeof(int));
		}
		//riempiCampo(CampoMain,R,C);		
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				CampoMain[i][j]=0;
			}
		}
		//stampaCampo(CampoMain,R,C);		
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				printf("%d",CampoMain[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
