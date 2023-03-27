#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	float gewicht,grosse,bmi;
	
	
	printf("Gewicht eingeben(kg): ");
	scanf("%f",&gewicht);
	
	printf("Grosse eingeben(m): ");
	scanf("%f",&grosse);
	
	bmi=gewicht/pow(grosse,2);
	
	printf("BMI: %f ",bmi); 
	
	return 0;
}
