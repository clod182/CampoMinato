//Salva in testa lo stato corrente del campo da gioco nella lista degli stati
ListaS salvaStato(CellaC *campo,ListaS stati){
	ListaS testa=malloc(sizeof(struct NodoS));
	if(testa){ 		
		testa->stato=nuovaMatriceVuota(lunColonne,lunRighe);
		copiaMat(campo,testa->stato); 
		testa->next=stati;
		stati=testa;
		return stati;
	}
	else{
		printf("Erorre malloc stati\n");
		return NULL;
	}
}

//Copia nel campo lo stato in testa ovvero l'ultima giocata effettuata
void getStato(CellaC** campo,ListaS stati){
	copiaMat(stati->stato,campo);
	stati=stati->next;
}

int cellePremute(CellaC** campo){
	int i,j,c=0;
	for (i = 0; i < lunColonne; i++){ 
		for (j = 0; j < lunRighe; j++){
			if(campo[i][j]->isPremuto==1){
				c++;
			}
		}
	}
	return c;
}

