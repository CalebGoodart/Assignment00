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
    char *cards[52];
};

struct player *createPlayers(struct player user, int numPlayers) {
    
    char compName[] = "computer0";
    struct player *allUsers = malloc(numPlayers * sizeof(struct player));
    allUsers[0] = user;
    for (int i = 1; i < numPlayers; i++) {
        compName[8] = '0' + i;
        strcpy(allUsers[i].first_name, compName);
    }

    return allUsers;


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

}

void distribute() {
}

void whoWins() {
}

void writeTempFile() {
}

void readTempFile() {
}

void declareWinner() {
}

void writeScoreFile() {
}

void readScoreBoard() {
}

// compares two cards, returns 1 if the first card is more powerful then the second, returns 0 otherwise
int compare(char cardOne[], char cardTwo[]) {

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
    printf("%d : %d : ", one, two);
    if (one == two) {
        return cardOne[1] > cardTwo[1];
    } else {
        return one > two;
    }

}

int main() {

    while (1) {

        char input;
        int keepInfo = 0;
        char **DECK = createDeck();
        struct player *AllPlayers = NULL;

        printf("\nMENU:\n\t1. Enter player's information\n\t2. Play\n\t3. Exit\n");
        scanf("%s", &input);


        if (input == '1' || input == '2') {

            struct player user;
            int arr[] = {1,4,8,4,3};
            user.scores = arr;
            
            printf("%d", user.scores[2]);
            if (input == '1') {
                char first[16];
                char last[16];
                char country[16];


                printf("Enter your first name\n");
                scanf("%s", &first);

                printf("Enter your last name\n");
                scanf("%s", &last);

                printf("Enter your country\n");
                scanf("%s", &country);

                strcpy(user.first_name, first);
                strcpy(user.last_name, last);
                strcpy(user.country, country);
                keepInfo = 1;

            } else if (input == '2') {
				
				printf("Enter y to continue without recording information:\n");
				scanf("%s", &input);
				
				if (input != 'y') {
					continue;
				} else {
					printf("continuing without recording info");
					struct player user;
					strcpy(user.first_name, "guest");

				}
			}

            int numPlayers;
            printf("How many players?: ");
            scanf("%d", &numPlayers);
			
            AllPlayers = createPlayers(user, numPlayers);
			
			int numRounds;
		    printf("How many rounds to play before declaring winner?: ");
		    scanf("%d", &numRounds);
			
			
        } else if (input == '3') {
            free(DECK);
            free(AllPlayers);
            printf("Goodbye\n");
            return 0;
        } else {
            printf("not recognized\n");
        }

    }

}
