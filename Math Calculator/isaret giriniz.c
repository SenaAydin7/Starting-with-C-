#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 
 
   int s1,s2,toplama,cikarma,carpma,isaret;
   float bolme;
   
   printf("S1= ");
   scanf("%d",&s1);
   
   printf("S2= ");
   scanf("%d",&s2);
   
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
   printf("isaret giriniz: ");
   scanf("%s",&isaret);
   
   
   switch(isaret){
   case'+':toplama=s1+s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
   printf("Toplama Sonucu: %d\n",toplama);
   break;
   case'-':cikarma=s1-s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
   printf("Cikarma Sonucu: %d\n",cikarma);
   break;
   case'*':carpma=s1*s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
   printf("Carpma Sonucu: %d\n",carpma);
   break;
   case'/':bolme=s1/s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
   printf("Bolme Sonucu: %f\n",bolme);
   break;
    	
   }
   
   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
   printf("isaret giriniz: ");
   scanf("%s",&isaret);
  
   switch(isaret){
   case'+':toplama=s1+s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
   printf("Toplama Sonucu: %d ",toplama);
   break;
   case'-':cikarma=s1-s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
   printf("Cikarma Sonucu: %d",cikarma);
   break;
   case'*':carpma=s1*s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
   printf("Carpma Sonucu: %d",carpma);
   break;
   case'/':bolme=s1/s2;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
   printf("Bolme Sonucu: %f",bolme);
   break;
   
}
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
   	return 0;
}
