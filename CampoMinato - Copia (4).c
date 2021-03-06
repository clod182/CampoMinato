#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MINA '*'
#define VUOTO '0'
#define BANDIERINA '?'
#define COPERTO 'X'
#define SCOPERTO 'O'
#define LINEAOUT "----->>>>>"

char** creaCampo(char** campo,int r,int c){
	int i,j;
	campo=(char**)malloc(r*sizeof(char*));
	for(i=0;i<r;i++){
		campo[i]=(char*)malloc(c*sizeof(char));
	}
	return campo;
}


char** riempiCampo(char** campo,int r, int c, char carattere){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			campo[i][j]=carattere;
		}
	}
	return campo;
}


void aggiungiNumeri(char** campo,int r, int c){
	int i,j,k,kk;
	char conta='0';
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			conta='0';
			if(i==0 && j==0){ /*Gestisco il caso particolare della cella nord-ovest*/
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){
					for(k=0;k<2;k++){
						for(kk=0;kk<2;kk++){
							if(campo[k][kk]==MINA){
								conta++;						
							}	
						}
					}				
					if(conta!='0'){
							campo[i][j]=conta;					
					}
				}				
			}
			else if(i==r-1 && j==c-1){ /*Gestisco il caso particolare della cella sud-est*/
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){
					for(k=r-1;k>r-3;k--){
						for(kk=c-1;kk>c-3;kk--){
							if(campo[k][kk]==MINA){
								conta++;						
							}	
						}
					}				
					if(conta!='0'){
							campo[i][j]=conta;					
					}
				}
			}
			else if(i==0 && j==c-1){ /*Gestisco il caso particolare della cella nord-est*/
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){
					for(k=0;k<2;k++){
						for(kk=c-1;kk>c-3;kk--){
							if(campo[k][kk]==MINA){
								conta++;						
							}	
						}
					}				
					if(conta!='0'){
							campo[i][j]=conta;					
					}
				}
			}
			else if(i==r-1 && j==0){ /*Gestisco il caso particolare della cella sud-ovest*/
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){
					for(k=r-1;k>r-3;k--){
						for(kk=0;kk<2;kk++){
							if(campo[k][kk]==MINA){
								conta++;						
							}	
						}
					}				
					if(conta!='0'){
							campo[i][j]=conta;					
					}
				}
			}
			else if(i==0){
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){ /*Gestisco il caso particolare del lato nord*/
					for(k=i;k<(i+2);k++){
						for(kk=(j-1);kk<(j+2);kk++){
							if(campo[k][kk]==MINA){
								conta++;
							}
						}
					}
					if(conta!='0'){
						campo[i][j]=conta;					
					}
				}
			}
			else if(j==0){
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){ /*Gestisco il caso particolare del lato ovest*/
					for(k=i-1;k<(i+2);k++){
						for(kk=(j);kk<(j+2);kk++){
							if(campo[k][kk]==MINA){
								conta++;
							}
						}
					}
					if(conta!='0'){
						campo[i][j]=conta;					
					}
				}
			}
			else if(i==r-1){
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){ /*Gestisco il caso particolare del lato sud*/
					for(k=r-1;k>r-3;k--){
						for(kk=(j-1);kk<(j+2);kk++){
							if(campo[k][kk]==MINA){
								conta++;
							}
						}
					}
					if(conta!='0'){
						campo[i][j]=conta;					
					}
				}
			}
			else if(j==c-1){
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){ /*Gestisco il caso particolare del lato est*/
					for(k=(i-1);k<(i+2);k++){
						for(kk=c-1;kk>c-3;kk--){
							if(campo[k][kk]==MINA){
								conta++;
							}
						}
					}
					if(conta!='0'){
						campo[i][j]=conta;					
					}
				}
			}			
			else{ /*Gestisco tutti gli altri casi (tutta la parte della matrice senza i bordi)*/
				if(campo[i][j]!=MINA && campo[i][j]==VUOTO){
					for(k=(i-1);k<(i+2);k++){
						for(kk=(j-1);kk<(j+2);kk++){
							if(campo[k][kk]==MINA){
								conta++;
							}
						}
					}
					if(conta!='0'){
						campo[i][j]=conta;					
					}
				}
			}			
		}
	}
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


void inserisciMine(char** campo,int r,int c,int m){ /*Da implemetare in maniera piu efficiente?*/
	int i,j,ran1,ran2,contm;
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
	contm=0;
	while(contm<m){
		ran1=rand()%(r);
		ran2=rand()%(c);
		if(campo[ran1][ran2]!=MINA){
			campo[ran1][ran2]=MINA;
			contm++;
		}
	}
	//return campo;
}


void scopriCella(char** campo, char** campoHidden,int r,int c,int x,int y,int* loose){
	if(campoHidden[y-1][x-1]==BANDIERINA){
		printf("La cella che hai selezionato e MARCATA, devi prima SMARCARLA se vuoi scoprirla!\n");
	}
	else if((campoHidden[y-1][x-1]>='1' && campoHidden[y-1][x-1]<='8')||campoHidden[y-1][x-1]==SCOPERTO){
		printf("La cella che hai selezionato e gia scoperta ;)\n");
	}
	else{
		if(campo[y-1][x-1]==MINA){
			printf("Hai preso una mina stupido\n");
			*loose=1;
		}
		else if((campo[y-1][x-1]>='1')&&(campo[y-1][x-1]<='8')){
			campoHidden[y-1][x-1]=campo[y-1][x-1];
			printf("Hai scoperto con successo la casella in posizione[%d,%d]\n",y, x);
		}
		else{			
			//campoHidden[y-1][x-1]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y-1,r,c);
			printf("Hai scoperto con successo la casella in posizione[%d,%d]\n",y, x);
		}
	}	
}


void marcaCella(char** campoHidden,int x, int y){
	if(campoHidden[y-1][x-1]==COPERTO){
		campoHidden[y-1][x-1]=BANDIERINA;
		printf("Hai MARCATO correttamente la casella in posizione[%d,%d]\n",y,x);
	}
	else if(campoHidden[y-1][x-1]==BANDIERINA){
		campoHidden[y-1][x-1]=COPERTO;
		printf("Hai SMARCATO correttamente la casella in posizione[%d,%d]\n",y,x);
	}
	else{
		printf("La casella che hai selezionato e gia scoperta, non puoi marcarla!\n");
	}
}


void scopriCelleAdiacenti(char** campo,char** campoHidden,int x,int y,int r, int c){
	if(x>=0 && y>=0 && x<=c && y<=r){		
		//printf("************************************************************************SONO IN\n");	
		if(campo[y][x]!=VUOTO){//&&(campoHidden[y][x]!=SCOPERTO){
			campoHidden[y][x]=campo[y][x];
		}
		else if(x==0 && y==0){/*Cella nord ovest*/
			campoHidden[y][x]=SCOPERTO;			
			scopriCelleAdiacenti(campo,campoHidden,x+1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y+1,r,c);			
		}
		else if(x==0 && y==r){/*Cella sud ovest*/
			campoHidden[y][x]=SCOPERTO;				
			scopriCelleAdiacenti(campo,campoHidden,x,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y,r,c);					
			scopriCelleAdiacenti(campo,campoHidden,x+1,y-1,r,c);
		}
		else if(x==c && y==0){/*Cella nord est*/
			campoHidden[y][x]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y,r,c);			
			scopriCelleAdiacenti(campo,campoHidden,x,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y+1,r,c);			
		}
		else if(x==0){/*Lato ovest*/
			campoHidden[y][x]=SCOPERTO;			
			scopriCelleAdiacenti(campo,campoHidden,x,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y+1,r,c);			
			scopriCelleAdiacenti(campo,campoHidden,x+1,y-1,r,c);
		}
		else if(y==0){/*Lato nord*/
			campoHidden[y][x]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y,r,c);			
			scopriCelleAdiacenti(campo,campoHidden,x+1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y+1,r,c);		
		}
		else if(x==c && y==r){/*Cella sud est*/
			campoHidden[y][x]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y-1,r,c);	
		}
		else if(x==c){/*Lato est*/
			campoHidden[y][x]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y-1,r,c);					
			scopriCelleAdiacenti(campo,campoHidden,x,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y+1,r,c);			
		}
		else if(y==r){/*Lato sud*/
			campoHidden[y][x]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y,r,c);			
			scopriCelleAdiacenti(campo,campoHidden,x+1,y-1,r,c);
		}
		else{
			campoHidden[y][x]=SCOPERTO;
			scopriCelleAdiacenti(campo,campoHidden,x-1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y-1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x-1,y+1,r,c);
			scopriCelleAdiacenti(campo,campoHidden,x+1,y-1,r,c);
		}
	}	
}
/*--------------------------------------------------------MAIN--------------------------------------*/
int main(){
	int scelta=0;
	char** CampoMain;
	char** CampoHidden;
	printf("***---***CampoMinato***---***\n");
	printf("Cosa vuoi fare?\n1 - Generare schema tramite input\n2 - Generare schema tramite file\n3 - Uscita\n");
	scanf("%d",&scelta);
	if (scelta==1){
		int R,C,mine,X,Y,perso=0;
		do{
			printf("Dammi la dimensione del campo ((R C) > 0)\n");
			scanf("%d %d",&R, &C);
		}while((R<=0 || C<=0)||(R<=1 && C<=1));
		CampoMain=creaCampo(CampoMain,R,C);
		CampoHidden=creaCampo(CampoHidden,R,C);
		CampoMain=riempiCampo(CampoMain,R,C,VUOTO);
		CampoHidden=riempiCampo(CampoHidden,R,C,COPERTO);
		stampaCampo(CampoMain,R,C);
		stampaCampo(CampoHidden,R,C);
		do{
			printf("Dammi il numero di mine che vuoi inserire (0<mine<dimensione campo -1[=%d])\n",(R*C)-1);
			scanf("%d",&mine);
		}while(mine<=0 || mine>(R*C)-1);
		inserisciMine(CampoMain,R,C,mine);
		aggiungiNumeri(CampoMain,R,C);/*------------------------------------------------------*/
		stampaCampo(CampoMain,R,C);
		stampaCampo(CampoHidden,R,C);
		scelta=0;
		do{
			printf("Ora cosa vuoi fare?\n1 - Scoprire una cella\n2 - Marcare o smarcare una cella\n3 - Terminare il gioco\n");
			scanf("%d",&scelta);
			if(scelta==1){
				printf("Dammi le coordinate della cella che intendi scoprire (PRIMA riga POI colonna)\n");
				scanf("%d %d",&Y, &X);
				scopriCella(CampoMain,CampoHidden,R,C,X,Y,&perso);
				if(perso==0){
					stampaCampo(CampoMain,R,C);
					stampaCampo(CampoHidden,R,C);
				}
			}
			else if(scelta==2){
				printf("Dammi le coordinate della cella che intendi marcare, o se gia marcata, smarcare (PRIMA riga POI colonna)\n");
				scanf("%d %d",&Y, &X);
				marcaCella(CampoHidden,X,Y);
				stampaCampo(CampoMain,R,C);
				stampaCampo(CampoHidden,R,C);
			}
		}while(perso==0);
	}
	return 0;
}
