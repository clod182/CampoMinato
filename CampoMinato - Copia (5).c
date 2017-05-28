#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MINA '*'
#define VUOTO '0'
#define BANDIERINA '?'
#define COPERTO 'X'
#define SCOPERTO 'O'
#define LINEAOUT "----->>>>>"

char** creaCampo(char** campo,int r,int c){ /*Creo il campo sotto forma di matrice*/
	int i,j;
	campo=(char**)malloc(r*sizeof(char*));
	for(i=0;i<r;i++){
		campo[i]=(char*)malloc(c*sizeof(char));
	}
	return campo;
}


char** riempiCampo(char** campo,int r, int c, char carattere){ /*Funzione per riempire il campo di gioco con un certo carattere*/
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			campo[i][j]=carattere;
		}
	}
	return campo;
}


void aggiungiNumeri(char** campo,int r, int c){ /*Funzione che inseriesce nel campo di gioco il numero delle mine adiacenti*/
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


void stampaCampo(char** campo,int r,int c){ /*Funzione per stampare il campo*/
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


void inserisciMine(char** campo,int r,int c,int m){ /*Inserisco le mine in maniera randomica nel campo*/
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
}


void scopriCelleAdiacenti(char** campo,char** campoHidden,int x,int y,int r, int c){ /*Funzione cje scopre tutte le celle vuote adiacenti alla cella vuota selezionata*/
	if((x>=0 && y>=0 && x<=c && y<r)&&(campoHidden[y][x]==COPERTO)){		
		if(campo[y][x]!=VUOTO){
			campoHidden[y][x]=campo[y][x];
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

void scopriCella(char** campo, char** campoHidden,int r,int c,int x,int y,int* loose){ /*Funzione che gestisce lo scoprimento di una cella*/
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


void marcaCella(char** campoHidden,int x, int y){/*Funzione per marcare e smarcare una cella*/
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


void checkVittoria(char** campoHidden,int mine, int r, int c,int* vittoria){
	int i,j,tot4win,conta=0;
	tot4win=(c*r)-mine;	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if((campoHidden[i][j]==SCOPERTO)||(campoHidden[i][j]>='1' && campoHidden[i][j]<='8')){
				conta++;
			}			
		}
	}
	if(conta==tot4win){
		*vittoria=1;
		printf("Grande!Hai vinto :)\n");
	}
}


void leggiRigheColonne(int* r,int* c){
	FILE *f;	
	f=fopen("partitaInput.txt","r"); /*apro il file*/
	if( f==NULL ){
    	perror("Errore in apertura del file");    
  	}
  	fscanf(f,"%d%*c%*c%d",r,c);  	
  	fclose(f);
}

void leggiMine(char** campo,int* mine){
	int flag=0;
	int y,x;
	FILE *f;
	char line[256];	
	f=fopen("partitaInput.txt","r"); /*apro il file*/
	if( f==NULL ){
    	perror("Errore in apertura del file");    
  	}
  	while (fgets(line, sizeof(line), f)){
	  if(flag>0){
	  	fscanf(f,"%d%*c%*c%d",&y,&x);	  		
  		campo[y][x]=MINA;		  		
	  }
	  flag++;  				       
    }    
    fclose(f);
}

void contaMineLette(char** campo,int r,int c,int* mine){
	int contam=0,i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(campo[i][j]==MINA){
				contam++;
			}			
		}
	}
	*mine=contam;
	printf("Ho letto dal file %d mine\n", *mine);
}


void generaCampoOut(char** campo,int r,int c){
	int i,j;
	FILE *f;
	f=fopen("capoSalvatoOut.txt","w");
	if( f==NULL ){
    	perror("Errore in apertura del file");    
  	}
  	fprintf(f,"%d, %d\n",r,c);
  	fprintf(f,"\n");
  	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(campo[i][j]==MINA){
				fprintf(f,"%d, %d\n",i,j);
			}			
		}
	}  	
	fclose(f);
	printf("Ho salvato con successo lo stato del campo nel file --capoSalvatoOut.txt--\n");
}

struct listacam{
	char** campo;
	int nmossa;
	struct listacam *next;
};
typedef struct listacam *ListaCam;

ListaCam salvaStato(char** campoAtm,ListaCam stato,int R,int C,int *nmosse){
	ListaCam testa =(ListaCam) malloc(sizeof(struct listacam));
	if(testa){
		testa->campo=campoAtm;
		testa->next=stato;
		testa->nmossa=*nmosse;
		stato=testa;
		return stato;
	}
	else{
		printf("Erorre malloc stati\n");
		return NULL;
	}
}




void turnoPlayer(char** CampoMain,char** CampoHidden,int R,int C,int perso, int vittoria,int X, int Y,int mine,int* tornamenu){
	int scelta=0;
	do{
			printf("Ora cosa vuoi fare?\n1 - Scoprire una cella\n2 - Marcare o smarcare una cella\n3 - Uscire e tornare al menu\n4 - Salvare lo stato del campo di gioco:\n");
			scanf("%d",&scelta);
			if(scelta==1){
				printf("Dammi le coordinate della cella che intendi scoprire (PRIMA riga POI colonna)\n");
				scanf("%d %d",&Y, &X);
				scopriCella(CampoMain,CampoHidden,R,C,X,Y,&perso);
				
				checkVittoria(CampoHidden,mine,R,C,&vittoria);
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
			else if(scelta==3){
				*tornamenu=1;
			}			
			else if(scelta==4){
				generaCampoOut(CampoMain,R,C);
			}
		}while(perso==0 && vittoria==0 && *tornamenu==0);		
}
/*--------------------------------------------------------MAIN--------------------------------------*/
int main(){
	int scelta=0,escigioco=0;	
	char** CampoMain;
	char** CampoHidden;
	ListaCam listaMain;
	int nmossemain=0;
	printf("***---***CampoMinato***---***\n");
	int tornamenu=0;
		do{
			tornamenu=0;		
			printf("Cosa vuoi fare?\n1 - Generare schema tramite input\n2 - Generare schema tramite file\n3 - Uscita\n");
			scanf("%d",&scelta);	
			if (scelta==1){		
				int R,C,mine,X,Y,perso=0,vittoria=0;
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
				aggiungiNumeri(CampoMain,R,C);
				stampaCampo(CampoMain,R,C);
				stampaCampo(CampoHidden,R,C);
				turnoPlayer(CampoMain,CampoHidden,R,C,perso,vittoria,X,Y,mine,&tornamenu);							
			}			
			else if(scelta==2){
				int R,C,X,Y,mine,perso=0,vittoria=0;
				leggiRigheColonne(&R,&C);				
				printf("Ho creato,leggendo file,un campo di: \n-%d righe\n-%d colonne\n",R,C);
				CampoMain=creaCampo(CampoMain,R,C);
				CampoHidden=creaCampo(CampoHidden,R,C);
				CampoMain=riempiCampo(CampoMain,R,C,VUOTO);
				CampoHidden=riempiCampo(CampoHidden,R,C,COPERTO);
				leggiMine(CampoMain,&mine);
				contaMineLette(CampoMain,R,C,&mine);
				aggiungiNumeri(CampoMain,R,C);
				stampaCampo(CampoMain,R,C);
				stampaCampo(CampoHidden,R,C);
				turnoPlayer(CampoMain,CampoHidden,R,C,perso,vittoria,X,Y,mine,&tornamenu);			
			}
			else if(scelta==3){
				printf("Hai deciso di uscire dal gioco\n");
				escigioco=1;				
			}	
		}while(tornamenu==1 && escigioco==0);
	
	return 0;
}
