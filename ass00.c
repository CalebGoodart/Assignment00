#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>

struct player {
	char first_name[16];
	char last_name[16];
	char country[16];
	int *scores;
	char **cards;
};

void printDeck(char ** deck){
	printf("[");
	for(int i = 0; i < 52; i++){
		if(i != 0 && i%13 == 0){
			printf("\n");
		}
		printf("\'%s\'", deck[i]);
		if(i != 51) printf(",");
	}
	printf("]\n\n");
}

void printScores(struct player *players, int numPlayers, int round){
	printf("The total score of each player is: [");
	for (int i = 0; i < numPlayers; i++) {
		printf("%d", players[i].scores[round]);
		if(i != numPlayers-1) printf(",");
	}
	printf("]\n\n");
}

void printHands(struct player *players, int numPlayers, int numCards){
	for (int i = 0; i < numPlayers; i++) {
		printf("%s: [", players[i].first_name);
			for (int j = 0; j < numCards; j++) {
				printf("\'%s\' ", players[i].cards[j]);
				if(j != numCards-1) printf(",");
			}
			printf("]\n");
	}
	printf("\n");
}

struct player *createPlayers(struct player user, int numPlayers, int numRounds) {

	struct player *players = malloc(numPlayers * sizeof(struct player));
	int cards = 52 / numPlayers;

	for (int i = 0; i < numPlayers; i++) {
		char compName[16];
		strcpy(compName, "computer");
		sprintf(players[i].first_name, "%s%d", compName, i);

		players[i].scores = (int *) malloc(numRounds * sizeof(int));
		int arr[numRounds];
		for (int j = 0; j < numRounds; j++) {
			arr[j] = 0;
			players[i].scores[j] = arr[j];
		}

		players[i].cards = (char **) malloc(cards * sizeof(char) + 1);

		int max = 52 / numPlayers;
		for (int j = 0; j < max; j++) {
			players[i].cards[j] = malloc(3 * sizeof(char));
		}
	}

	strcpy(players[0].first_name, user.first_name);
	return players;
}

char **createDeck() {

	char **deck = (char **) malloc(52 * sizeof(char) + 1);
	char *og[] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h",
				  "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d",
				  "Td", "Jd", "Qd", "Kd", "Ad", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc",
				  "Ac"};

	for (int i = 0; i < 52; i++) {
		deck[i] = (char *) malloc(3 * sizeof(char));
		deck[i] = og[i];
	}

	return deck;
}

void shuffle(char *deck[]) {

	for (int i = 0; i < 52; i++) {
		int j = rand() % (52 - i);
		char *temp0 = deck[i];
		deck[i] = deck[j];
		deck[j] = temp0;
	}
	
	printf("The created deck of card is as follows:\n");
	printDeck(deck);
}

void distribute(char **deck, struct player *players, int numPlayers) {
	int cards = 52 / numPlayers;
	int total = cards * numPlayers;
	int index = 0;
	for (int i = 0; i < cards; i++) {
		for (int j = 0; j < numPlayers; j++) {
			players[j].cards[i] = deck[index];
			index++;
		}
	}
	
	printHands(players, numPlayers, cards);
}


// compares two cards, returns 1 if the first card is more powerful then the second, returns 0 otherwise
int compareCards(char cardOne[], char cardTwo[]) {

	int one = 0;
	int two = 0;

	switch (cardOne[0]) {
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

	switch (cardTwo[0]) {
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
	if (one == two) {
		return cardOne[1] > cardTwo[1];
	} else {
		return one > two;
	}
}

void whoWins(struct player *players, int numPlayers, int round) {
	int max = 52 / numPlayers;
	int winner = 0;

	for (int i = 0; i < max; i++) {
		winner = 0;
		for (int j = 1; j < numPlayers; j++) {		
			if (!compareCards(players[winner].cards[i], players[j].cards[i])) {
				winner = j;
			}
		}

		int value = players[winner].scores[round];
		value++;
		players[winner].scores[round] = value;
	}
	
	printScores(players, numPlayers, round);
	
}

void writeTempFile() {
}

void readTempFile() {
}

void declareWinner(struct player *players, int numPlayers, int numRounds) {
	int totalScores[numPlayers];
	
	for(int i = 0; i < numPlayers; i++){
		totalScores[i] = 0;
		for (int j = 0; j < numRounds; j++){
			totalScores[i] = totalScores[i] + players[i].scores[j];
		}
	}
	
	int winner = 0;
	for(int i = 1; i < numPlayers; i++){
		if(totalScores[winner] < totalScores[i]){
			winner = i;
		}
	}
	
	printf("The final score at the end of all round is: [");
	for(int i = 0; i < numPlayers; i++){
		printf("%d",totalScores[i]);
		if(i != numPlayers-1) printf(",");
	}
	printf("]\n\n");
	
	printf("The Winner(s) is: %s", players[winner].first_name);
	for(int i = 1; i < numPlayers; i++){
		if(totalScores[winner] == totalScores[i]){
			printf(", %s", players[i].first_name);
		}
	}
	printf("\n\n");
}

void writeScoreFile() {
}

void readScoreBoard() {
}

int main() {

	while (1) {

		char input;
		int keepInfo = 0;
		char **DECK = NULL;
		struct player *AllPlayers = NULL;

		printf("\nMENU:\n\t1. Enter player's information\n\t2. Play\n\t3. Exit\n");
		scanf("%s", &input);

		if (input == '1' || input == '2') {

			struct player user;

			if (input == '2') {

				char snd;
				printf("Enter y to continue without recording information:\n");
				scanf("%s", &snd);

				if (snd == 'y') {
					printf("continuing without recording info\n");
					strcpy(user.first_name, "guest");

				} else {
					keepInfo = 1;
				}
			}

			if (input == '1') {
				keepInfo = 1;
			}

			if (keepInfo == 1) {
				char first[16];
				char last[16];
				char country[16];


				printf("Enter your first name\n");
				scanf("%16s", &first);

				printf("Enter your last name\n");
				scanf("%16s", &last);

				printf("Enter your country\n");
				scanf("%16s", &country);

				strcpy(user.first_name, first);
				strcpy(user.last_name, last);
				strcpy(user.country, country);
			}

			int numPlayers;
			printf("How many players?: \n");
			scanf("%d", &numPlayers);
			
			int numRounds;
			printf("How many rounds to play before declaring winner?: \n");
			scanf("%d", &numRounds);
			
			char display[4];
			printf("Display Scores?: \n");
			scanf("%s", &display);
			
			DECK = createDeck();
			AllPlayers = createPlayers(user, numPlayers, numRounds);

			int numCards = 52 / numPlayers;

			for (int round = 0; round < numRounds; round++) {

				printf("ROUND %d\n\n", round);
				shuffle(DECK);
				distribute(DECK, AllPlayers, numPlayers);
				whoWins(AllPlayers, numPlayers, round);
			}

			declareWinner(AllPlayers,numPlayers,numRounds);
			free(DECK);
			free(AllPlayers);

		} else if (input == '3') {
			printf("Goodbye\n");
			return 0;
		} else {
			printf("not recognized\n");
		}
	}
}
