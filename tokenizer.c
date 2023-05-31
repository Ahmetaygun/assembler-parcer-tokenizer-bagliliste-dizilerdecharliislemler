#include<stdio.h>
#include<string.h>

char yigit[1000];
int top=0;
int bottom=0;
int operatorkont(int bas){
	if(yigit[bas]=='{' || yigit[bas]=='}' || yigit[bas]=='(' || yigit[bas]==')' ){
		return 1;
	}
	return 0;
}
int operandkont(int bas){
	if(yigit[bas]=='+' || yigit[bas]=='-' || yigit[bas]=='*' || yigit[bas]=='/'  || yigit[bas]=='%'  || yigit[bas]=='=' || yigit[bas]=='&' ){
		return 1;
	}
	return 0;
}
int noktakont(int bas){
	if(yigit[bas]==':' || yigit[bas]==';' || yigit[bas]==',' || yigit[bas]=='.'){
		return 1;
	}
	return 0;
}
int harfkont(int bas){
	if(yigit[bas]>=65 && yigit[bas]<=90 ){
		return 1;
	}
	return 0;
}
int rakamkont(int bas){
	if(yigit[bas]=='1' || yigit[bas]=='2' || yigit[bas]=='3' || yigit[bas]=='4' || yigit[bas]=='5' || yigit[bas]=='6' || yigit[bas]=='7' || yigit[bas]=='8' || yigit[bas]=='9' || yigit[bas]=='0'){
		return 1;
	}
	return 0;
}

int main(){
	FILE *dd;
	char no; 
	char dosya[1000];
	char kelime[100];
	int i=0;
	int j=0;
	char dosyayolu[256];
	printf("Dosya yolu giriniz: ");
	gets(dosyayolu);
	if ((dd=fopen(dosyayolu,"r")) == NULL)
		printf("Surucu veya dosya bulunamadi.\n");
	else{ 
		while (fscanf(dd,"%c",&no)!=EOF){
			printf("%c",no);
			 dosya[i++]=no;
	   }
	   i=0;
	   while(dosya[i]!='\0'){
	   		if(dosya[i]==10 || dosya[i]==32){}
	   		else{
	   	    	kelime[j++]=dosya[i];		
		   }
		   i++;
	   }
		printf("\n");
	    i=0;
	    while(kelime[i]!='\0'){
	    	if(kelime[i]!='{' && kelime[i]!='}' && kelime[i]!='(' && kelime[i]!=')' && kelime[i]!=';' && kelime[i]!=',' && kelime[i]!='&' && kelime[i]!='>' && kelime[i]!='<' && kelime[i]!='=' && kelime[i]!='?') {
	           printf("%c",kelime[i]);		
			}
			else{
				printf("\n");
			}
			i++;
		}
		i=0;
		while(kelime[i]!='\0'){
			yigit[top++]=kelime[i++]; 						
		}
		top--;
		int bas=top;
		int sonuc;
		printf("%c",yigit[bas]);
	
		while(bas>=bottom){
			sonuc=0;
			if(sonuc==0){
	    		sonuc=operatorkont(bas);
	       	}
	    	if(sonuc==0){
	    		sonuc=operandkont(bas);
			}
			if(sonuc==0){
				sonuc=noktakont(bas);
			}
			if(sonuc==0){
				sonuc=harfkont(bas);
			}
			if(sonuc==0){
				sonuc=rakamkont(bas);
			}
			if(sonuc==0){
				printf("Syntax hatasi");
			
			}
			bas--;
	   }
	   if(sonuc==1)
	   		printf("Kodunuz Dogrudur");
		
		
         fclose(dd);
	}
}

