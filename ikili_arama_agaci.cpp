#include <stdio.h>
#include <stdlib.h>
typedef struct agac
{
	int deger;
	struct agac *sol;
	struct agac *sag;
	
}Agaclar;

Agaclar *kok=NULL;

Agaclar *Deger_Al()
{
	Agaclar *bilgi;
	bilgi=(Agaclar *)malloc(sizeof(Agaclar));
	printf("Eklemek istediginiz sayiyi giriniz = ");
	scanf("%d",&bilgi->deger);
	bilgi->sag=NULL;
	bilgi->sol=NULL;
	return bilgi;
}/*
void Ekle(Agaclar *bilgi){
	Agaclar *gecici,*parent;
	
	if(kok==NULL)kok=bilgi;
	else{
		gecici=kok;
		while(gecici!=NULL)
		{
			parent=gecici;
			if(bilgi->deger<gecici->deger)gecici=gecici->sol;
			else gecici=gecici->sag;
			
		}
		if(bilgi->deger<parent->deger)parent->sol=bilgi;
		else parent->sag=bilgi;	
	}
	
}*/

void Ekleme(Agaclar *gecici,Agaclar *bilgi){
	if(kok==NULL){
		kok=bilgi;
	}
	else{
		if(bilgi->deger<gecici->deger){
			if(gecici->sol==NULL)gecici->sol=bilgi;
			else Ekleme(gecici->sol,bilgi);
		}
		else {
			if(gecici->sag==NULL)gecici->sag=bilgi;
			else Ekleme(gecici->sag,bilgi);
			
		}
		
		
		
	}
	
	
	
}

Agaclar *arama(Agaclar *gecici,int aranan)
{
	gecici=kok;
	while(gecici!=NULL)
	{
		if(gecici->deger==aranan)return gecici;
		if(aranan>gecici->deger)gecici=gecici->sag;
		else gecici=gecici->sol;
		
	}
	return NULL;
}

Agaclar *aramarec(Agaclar *gecici,int aranan)
{
	if(gecici==NULL)return NULL;
	if(gecici->deger<aranan)aramarec(gecici->sag,aranan);
	if(gecici->deger>aranan)aramarec(gecici->sol,aranan);
	else return gecici;
	
}
Agaclar *enkucuk(Agaclar *gecici)
{
	if(gecici->sol==NULL) return gecici;
	else enkucuk(gecici->sol);
	
}















main(){
	
}

