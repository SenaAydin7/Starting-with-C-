#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct vocable {
char italiano[51];
char deutsch[51];
struct vocable *next;
};

struct vocable * first = NULL;
struct vocable * current = NULL;

int readDictionaryFromFile(void);
void saveDictionary(void);
void removeListItem(void);
void showDictionary(void);
void addListItem(void);
struct vocable * allocateMemory(void);
void evaluateUserChoice(char);
void showMenuEdit(void);
void clearBuffer(void);
void dictionaryBearbeiten(void);
void vokabeltrainer(void);
void trainingVokabeln(int);
int main(){ 
    
    vokabeltrainer();
    dictionaryBearbeiten();
       	
    return 0;
}
void trainingVokabeln(int count){
	printf("Das Worterbuch enthalt %d %s\n", count, (count ==1)? "Eintrag": "Eintrage");
	
	if(!first){
		return;
	}
	
	int randomNumber;
	int training = 1;
	int i;
	char answer[51];
	int trainingIndex = 0;
	
	srand((unsigned int)time(NULL));
	
	while (training){
		randomNumber = rand() % count +1;
		current = first;
		
		for (i =1; i < randomNumber; i++){
			current = current->next;
		}
		printf("Gib die Deutsche Ubersetzung ein:\n");
		printf("[No.%d]: %s ", ++trainingIndex, current->italiano);
		scanf("%s", answer);
		clearBuffer();
		
		if(strcasecmp(current->deutsch, answer) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			puts("Richtig!");
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			puts("Falsch!");
			
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		if (trainingIndex >= 20){
			trainingIndex = 0;
			printf("Mochtest du weiter machen? (0 = Abbruch) ");
			scanf("%d", &training);
			clearBuffer();
		}
	}	
}
void vokabeltrainer(void){
	
	int auswahl =-1;
	int count = readDictionaryFromFile();
	for (; auswahl != 0;){
		puts("Wahle aus, was du machen mochtest:");
		puts("(1) Vokabel trainieren");
		puts("(2) Worterbuch anlegen oder bearbeiten");
		puts("(0) Nichts tun oder Kuchen essen");
		
		scanf("%d", &auswahl);
		clearBuffer();
		
		switch (auswahl){
			case 1:
				puts("Vokabel trainieren");
				trainingVokabeln(count);
				break;
			case 2:
			    puts("Worterbuch anlegen oder bearbeiten");
			    dictionaryBearbeiten();
				break;
			case 0:
			    puts("Okay, du hast heute frei...");
				break;
			default:
			    puts("Deine Eingabe ist ungultig");
				break;		
		}
	}
}

void dictionaryBearbeiten(void){
	
char choice;
	
      do{
        
         showMenuEdit();
         choice = getchar();
         clearBuffer();
         choice = toupper(choice);
         evaluateUserChoice(choice);
         
            
    } while (choice != 'E');	
	
}

int readDictionaryFromFile(void){
	
     FILE *fp = NULL;
     char temp[51];
     int vocableCount = 0;
     
     fp = fopen("dictionary.txt","r");
     
     if (!fp){
         return -1;
     }
     
     if (fscanf(fp, "%s", temp) != EOF){
      vocableCount++;
      first = allocateMemory();
      current = first;
      strcpy(current->italiano,temp);
      fscanf(fp, "%s",temp);
      strcpy(current->deutsch,temp);
      current->next = NULL;
      
      while (fscanf(fp, "%s", temp) != EOF){
         vocableCount++;
         current->next = allocateMemory();
         current = current->next;
         strcpy(current->italiano,temp);
         fscanf(fp, "%s",temp);
         strcpy(current->deutsch,temp);
         current->next = NULL;	 
      }
      	
     }
     
     
     fclose(fp);
	 
	 return vocableCount;	 
}
void saveDictionary(void){
FILE * fp = NULL;

fp = fopen("dictionary.txt","w");

if (!fp){
    puts("Die Datei konnte nicht geöfnet werden.\nDas Speichern des Worterbuches ist fehlgeschlagen.");
    exit(1);	 
}

current = first;

while (current){
       fprintf(fp," %s %s", current->italiano, current->deutsch);
       current = current->next;	 
}
fclose(fp);

puts("Das Dictionary wurde gespeichert.");	
	
}


void removeListItem(void){
	
    if (!first) {
        puts("Wo nichts ist, da kannst du auch nichts entfernen");
        return;	 
    }
    
    struct vocable * prev = NULL;
    int removeItem;
    int count = 1;
    
 eingabe:
    
    puts("Welchen Eintrag mochtest du entfernen?");
    showDictionary();
    scanf("%d",&removeItem);
    clearBuffer();
    
    if (removeItem < count){
        goto eingabe;	 
    }
    current = first;
    
    while (count++ < removeItem){
        prev = current;
        current = current->next;
        
        
        if (current == NULL){
            puts("Diesen Eintrag gibt's gar nicht.");
            return;	
        }
    }    
    
    if (prev == NULL) {
        first = current->next;	  
    }
    else{
        prev->next = current->next;	
    }
    
    free(current);
    puts("Vokabel erfolgreich entfernt.");
    saveDictionary();	
}



void showDictionary(void){
	
    if (!first){
        puts("Was guckst du? Hier gibt's nichts zu sehen!");
        return;	 
    }
    
    int index = 1;
    current = first;
    
    puts("HIER IST DEIN WORTERBUCH");
    
    while (current){
         printf("No,%d: [%s - %s]\n",index++, current->italiano, current->deutsch);
         current = current->next; 	 
    }	 
}


void addListItem(void){
    
    if (!first){
        first = allocateMemory();
        current = first;	 
    }    
    else{
        current = first;
        
        while (current->next){
            current = current->next; 	
        }
        
        current->next = allocateMemory();
        current = current->next;	
    }
    
    printf("italiano: ");
    scanf("%s", current->italiano);
    clearBuffer();
    printf("deutsch: ");
    scanf("%s", current->deutsch);
    clearBuffer();
     
    current->next = NULL;
    
    puts("Die Vokabel wurde deinem Worterbuch erfolgreich hinzugefugt.");
    saveDictionary();	
}


struct vocable * allocateMemory(void){

    struct vocable * pVocable = malloc(sizeof(struct vocable));

    if (!pVocable) {
        puts("malloc hat' s nicht gepackt!");
        exit(1); 	 
    }

    return pVocable;
}


void evaluateUserChoice(char choice){
    switch (choice) {
             case 'A':
                 puts("Worterbuch ansehen");
                 showDictionary();
                 break;
             case 'B':
                 puts("Vokabeln hinzufugen");
                 addListItem();
                 break;
             case 'C':
                 puts("Vokabeln entfernen");
                 removeListItem();
                 break;
             case 'D':          	  
                 puts("Speichern");
                 saveDictionary();
                 break;
             case 'E':
                 puts("Bearbeiten beenden");
                 break;
             default:
                 puts("Eingabe ungultig");
                 break;          	
	      
     }	
}
void showMenuEdit(void){
         puts("Wahle aus");
         puts("(A) Worterbuch ansehen");
         puts("(B) Vokabel hinzufugen");
         puts("(C) Vokabel entfernen");
         puts("(D) Speichern");
         puts("(E) Bearbeiten beenden");	 
}
void clearBuffer(void){
    while (getchar() != '\n'){
        ;
    }
    system("PAUSE");	 
}  
         	      
     
