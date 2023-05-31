#include <stdio.h>
#include <stdlib.h>
//-------AHMET AYGÜN 02220224565 YAZILIM MÜHENDÝSLÝÐÝ
int stringTointeger(char s){
	int sayi = 0;
	sayi = s - '0';
	return sayi;
}

void toplama(int boyut,int boyut2,int dizi1[],int dizi2[]){
	int i,bastop,mod,kalan,gecici,elde;
	int islem[boyut2+1];
	if (boyut < boyut2){
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}else if(boyut2 < boyut){
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
	}else{
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}
	for(i = boyut2-1; i >= 0; i--){
		bastop = dizi1[i] + dizi2[i];
		mod = bastop % 10;
		kalan = bastop - mod;
		elde = kalan/10;
		if (i == boyut2-1){
			islem[i] = mod;
			gecici = elde;
		}else if (i != boyut2-1){
			islem[i] = mod + gecici;
			gecici = elde;
		}
	}
	printf("\nSonuc:");
	for (i = 0; i < boyut2; i++){
		printf("%d ",islem[i]);
	}
}

void cikarma(int boyut,int boyut2,int dizi1[],int dizi2[]){
	int i,bascik;
	int islem[boyut2+1];
	if (boyut < boyut2){
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}else if(boyut2 < boyut){
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}else{
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}
	for(i = boyut2-1; i >= 0; i--){
		if (dizi1[i] < dizi2[i]){
			dizi1[i-1] -= 1;
			dizi1[i] += 10;
			bascik = dizi1[i] - dizi2[i];
			islem[i] = bascik; 
		}else {
			bascik = dizi1[i] - dizi2[i];
			islem[i] = bascik;
		}
	}
	printf("\nSonuc:");
	for (i = 0; i < boyut2; i++){
		printf("%d ",islem[i]);
	}
}

void carpma(int boyut,int boyut2,int dizi1[],int dizi2[]){
    int x,i,j,p,top;
    int a[boyut2],c[boyut2],b[boyut2];
    if (boyut < boyut2){
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}else if(boyut2 < boyut){
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
	}else{
		printf("Sayi1:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi1[i]);
		}
		printf("\nSayi2:");
		for (i = 0; i < boyut2; i++){
			printf("%d ",dizi2[i]);
		}
	}
	for(p=0;p<boyut2;p++){
        c[p]=0;
    }
    for(i=0; i < boyut2; i++){
        a[i]= dizi1[i];
    }
    for(i=0; i < boyut2; i++){
        b[i]=dizi2[i];
    }
    for(i=0;i<=boyut2;i++){
        top=0;
        p=0;
        for(j=i;j<=(2*(boyut2-1));j++){
            x=c[j]+b[i]*a[p]+top;
            c[j]=x%10;
            top=x/10;
            p++;
        }
    }
    printf("\nSonuc:");
    for(p=2*(boyut2-1);p>=0;p--){
        if(p>boyut2&&c[p]==0){
            continue;
        }
        printf("%d ",c[p]);
    }
}

void menu(int boyut,int boyut2,int dizi1[],int dizi2[]){
	int tercih,i;
	printf("\n[1] - '+'\n");
	printf("[2] - '-'\n");
	printf("[3] - '*'\n");
	printf("[0] - Cikis\n");
	printf("Yapmak istediginiz islemi seciniz:");
	scanf("%d",&tercih);
	switch(tercih){
		case 1: 
			toplama(boyut,boyut2,dizi1,dizi2);
			break;
		case 2:
			cikarma(boyut,boyut2,dizi1,dizi2);
			break;
		case 3:
			carpma(boyut,boyut2,dizi1,dizi2);
			break;
		case 0:
			break;
		default:
            printf("Lutfen menude yer alan islemlerden birini seciniz!\n");
		}	
}

int main(int argc, char *argv[]) {
	int boyut,i,boyut2,sifir,n,j;
	int tmp = 0;
	int t = 0;
	int u,h;
	printf("Ilk sayi kac basamakli olacak:");
	scanf("%d",&boyut);

     for(u=boyut;u!=0;u/=10)
   {
          if(!(u%10==0 || u%10==1 || u%10==2|| u%10==3|| u%10==4|| u%10==5|| u%10==6|| u%10==7|| u%10==8|| u%10==9))
	   {
		     printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		    return 0;
	   }
   }
	printf("Ikinci sayi kac boyutunda olacak:");
	scanf("%d",&boyut2);
	
	   for(h=boyut2;h!=0;h/=10)
    {
           if(!(h%10==0 || h%10==1 || h%10==2|| h%10==3|| h%10==4|| h%10==5|| h%10==6|| h%10==7|| h%10==8|| h%10==9))
  	    {
	    	printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		   return 0;
     	}
    }
	
	if (boyut < boyut2){
		char sayi1[boyut2];
		char sayi2[boyut2];
		int dizi1[boyut2], dizi2[boyut2];
		printf("Birinci sayiyi giriniz:");
		scanf("%s",&sayi1);
		
		printf("Ikinci sayiyi giriniz:");
		scanf("%s",&sayi2);
	
		sifir = boyut2 - boyut;
		for (i = boyut2-1;i > boyut-1; i--){
			sayi1[i] = '0';
		}
		i = boyut2-1;
		for (n = 0; n < sifir; n++){
			for(j = t; j < boyut2-1; j++){
				tmp = sayi1[i];
				sayi1[i] = sayi1[j];
				sayi1[j] = tmp;
			}
			t++;
		}
		for (i = boyut2 - 1; i >=0; i--){
			dizi1[i] = stringTointeger(sayi1[i]);
			dizi2[i] = stringTointeger(sayi2[i]);
			
			if(!(dizi1[i]==0 || dizi1[i]==1 || dizi1[i]==2|| dizi1[i]==3|| dizi1[i]==4|| dizi1[i]==5|| dizi1[i]==6|| dizi1[i]==7|| dizi1[i]==8|| dizi1[i]==9))
		{
		printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		return 0;
		}
			if(!(dizi2[i]==0 || dizi2[i]==1 || dizi2[i]==2|| dizi2[i]==3|| dizi2[i]==4|| dizi2[i]==5|| dizi2[i]==6|| dizi2[i]==7|| dizi2[i]==8|| dizi2[i]==9))
		{
		printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		return 0;
		}
		
		}
		
	
		menu(boyut,boyut2,dizi1,dizi2);
	}else if(boyut > boyut2){
		t = 0;
		char sayi1[boyut];
		char sayi2[boyut];
		int dizi1[boyut], dizi2[boyut];
		printf("Birinci sayiyi giriniz:");
		scanf("%s",&sayi1);
		printf("Ikinci sayiyi giriniz:");
		scanf("%s",&sayi2);
		sifir = boyut - boyut2;
		for (i = boyut-1;i > boyut2-1; i--){
			sayi2[i] = '0';
		}
		i = boyut-1;
		for (n = 0; n < sifir; n++){
			for(j = t; j < boyut-1; j++){
				tmp = sayi2[i];
				sayi2[i] = sayi2[j];
				sayi2[j] = tmp;
			}
			t++;
		}
		for (i = boyut - 1; i >=0; i--){
			dizi1[i] = stringTointeger(sayi1[i]);
			dizi2[i] = stringTointeger(sayi2[i]);
				if(!(dizi1[i]==0 || dizi1[i]==1 || dizi1[i]==2|| dizi1[i]==3|| dizi1[i]==4|| dizi1[i]==5|| dizi1[i]==6|| dizi1[i]==7|| dizi1[i]==8|| dizi1[i]==9))
		{
		printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		return 0;
		}
			if(!(dizi2[i]==0 || dizi2[i]==1 || dizi2[i]==2|| dizi2[i]==3|| dizi2[i]==4|| dizi2[i]==5|| dizi2[i]==6|| dizi2[i]==7|| dizi2[i]==8|| dizi2[i]==9))
		{
		printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		return 0;
		}
		}
		menu(boyut2,boyut,dizi1,dizi2);
	}else if(boyut == boyut2){
		char sayi1[boyut2];
		char sayi2[boyut2];
		int dizi1[boyut2], dizi2[boyut2];
		printf("Birinci sayiyi giriniz:");
		scanf("%s",&sayi1);
		printf("Ikinci sayiyi giriniz:");
		scanf("%s",&sayi2);
		for (i = boyut2 - 1; i >=0; i--){
			dizi1[i] = stringTointeger(sayi1[i]);
			dizi2[i] = stringTointeger(sayi2[i]);
				
				if(!(dizi1[i]==0 || dizi1[i]==1 || dizi1[i]==2|| dizi1[i]==3|| dizi1[i]==4|| dizi1[i]==5|| dizi1[i]==6|| dizi1[i]==7|| dizi1[i]==8|| dizi1[i]==9))
		{
		printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		return 0;
		}
			if(!(dizi2[i]==0 || dizi2[i]==1 || dizi2[i]==2|| dizi2[i]==3|| dizi2[i]==4|| dizi2[i]==5|| dizi2[i]==6|| dizi2[i]==7|| dizi2[i]==8|| dizi2[i]==9))
		{
		printf("lutfen sayi disinda birsey girmeyin ve tekrar deneyin proje kapatildi tekrar acin\n");
		return 0;
		}
		}
		menu(boyut,boyut2,dizi1,dizi2);
	}

	return 0;
}
