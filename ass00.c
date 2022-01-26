#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>

struct player{
	char first_name[64]; 
	char last_name[64];
	char country[64];
	char scores[64];
	char cards[52][2];
};

void createPlayers(){

	int numPlayers;
	printf("How many players?: ");
	scanf("%d",&numPlayers);
	int numRounds;
	printf("How many rounds to play before declaring winner?:");
	scanf("%d", &numRounds);

}

char** createDeck(){

	char **deck = (char**)malloc(52 * sizeof(char) + 1);
	char *og[] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac"};
	
	for (int i = 0; i < 52; i++){
		deck[i] = (char*)malloc(3 * sizeof(char));
		deck[i] = og[i];
	}
	
	return deck;
}

void shuffle(char *deck[]){
	
	for(int i = 0; i < 52; i++){
		int j = rand() % (52-i);
		char *temp0 = deck[i];
		deck[i] = deck[j];
		deck[j] = temp0;
	}
	
}

void distribute(){
}

void whoWins(){
}

void writeTempFile(){
}

void readTempFile(){
}

void declareWinner(){
}

void writeScoreFile(){
}

void readScoreBoard(){
}

// compares two cards, returns 1 if the first card is more powerfull then the second, returns 0 otherwise
int compare(char cardOne[], char cardTwo[]){

	int one = 0;
	int two = 0;
	
	switch(cardOne[0]){
		case 'A':
			one = 14;
		case 'K':
			one = 13;
		case 'Q':
			one = 12;
		case 'J':
			one = 11;
		case 'T':
			one = 10;
		default:
			one = cardOne[0] - '0';
	}
			
	switch(cardTwo[0]){
		case 'A':
			two = 14;
		case 'K':
			two = 13;
		case 'Q':
			two = 12;
		case 'J':
			two = 11;
		case 'T':
			two = 10;
		default:
			two = cardTwo[0] - '0';
	}
	printf("%d : %d : ", one, two);
	if(one == two){
		return cardOne[1] > cardTwo[1];
	}else{
		return one > two;
	}
	
}

int main(){
	
	while(1){
		printf("\nMENU:\n\t1. Enter player's information\n\t2. Play\n\t3. Exit\n");
		char input;
		int keepInfo = 0;
		scanf("%1s",&input);
		//char *DECK[] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac"};
		char **DECK = createDeck();
		
			if(input == '1'){
			
			struct player *user = malloc(sizeof(struct player));
			printf("Enter your first name\n");
			scanf("%s",&user->first_name);
			
			printf("Enter your last name\n");
			scanf("%s",&user->last_name);
			
			printf("Enter your country\n");
			scanf("%s",&user->country);
			
			}else if(input == '2'){
			
				if(!keepInfo){
					printf("Enter y to continue without recording information:\n");
					scanf("%s", &input);
						if(input != 'y'){
							continue;
						}else{
							printf("continuing without recording info");
						}
						
				}
				
				
			}else if(input == '3'){
				printf("Goodbye\n");
				return 0;
			}else{ 
				printf("not recognized\n");
			}
			
			free(DECK);
		}
	

	return 0;
}
