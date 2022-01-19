#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>


void createPlayers(){
}

void createDeck(){
}

void shuffle(){
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

int main(){
	char DECK[52][2] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac"};
	
	while(1){
		printf("MENU:\n\t1. Enter player's information\n\t2. Play\n\t3. Exit\n");
		char input;
		scanf("%1s",&input);
		switch(input){
			case '1' :
				printf("one\n");
				break;
			case '2' :
				printf("two\n");
				break;
			case '3' :
				printf("Goodbye\n");
				return 0;
				break;
			default: 
				printf("not reconized\n");
		}
	}
	
	return 0;
}
