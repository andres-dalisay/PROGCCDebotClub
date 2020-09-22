#include <stdio.h>
#include <stdlib.h>

void botStatement (int nDebateNum, int nRound, int *nBotScore) {
	int nBotAddedPoints, nBotPenalty;
	
	if (nDebateNum){
		if (nRound == 1) {
			nBotAddedPoints = 3;
			nBotPenalty = 2;
			*nBotScore += nBotAddedPoints - nBotPenalty;
			
			printf("Team Bot Annie Cal responds with: It is a well-known fact that homework provides\n");
			printf("additional unecessary cognitive load for students!\n");
			printf("\n");
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nBotAddedPoints);
			printf("*Team Bot Annie Cal gets %d Argument Points for Not citing Sources*\n", nBotPenalty);
		}
		
		else if (nRound == 2) {
			
		}
		
		else if (nRound == 3) {
			
		}
	}
}

void clrScreen () {
	system("cls");
}

void displayDebateDetails (int nDebateNum){
	switch (nDebateNum){
		case 1:	printf("		- The First Debate -\n");
				printf("Topic			: Homework should be banned\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal\n");
	}
}

void displayArgChoices (int nDebateNum) {
	switch (nDebateNum){
		case 1:	printf(" [1] Homework is necessary because it reinforces what students learn in the classroom.\n");
				printf(" [2] Years of data show that homework is an effective way of supplementing discussions.\n");
				printf(" [3] I don't know about you, but our forefathers would be mad if we ban homeworks.\n");
				printf(" [4] Homeworks are like the peanut to a peanut butter jelly sandwich!\n");
	}
}

void showStatement (int nRound, int nPlayerChoice) {
	

	if (nPlayerChoice == 1) {
		printf("Team ProgCC: Homework is necessary because it reinforces what students learn in the classroom.\n\n");
		printf("*Team ProgCC gets 3 Argument Points for Assertiveness*\n\n"); 
		
		
	}

			
	}


void selectStatement (int nRound, int *nPlayerScore, int *n1stChoiceCount, int *n2ndChoiceCount, int *n3rdChoiceCount, int *n4thChoiceCount) {
	int nPlayerChoice, nPlayerScoreAdded, nPlayerPenalty;
	
	while(1) {
		printf("Your choice: ");
		scanf("%d", &nPlayerChoice);
		
			if (nPlayerChoice >= 1 && nPlayerChoice <= 4) {				// Input validation; only integers 1-4 are valid inputs
				if (nPlayerChoice == 1) {
					nPlayerScoreAdded = 3;
					nPlayerPenalty = 0;
				}
				
				
				
				
				switch (nPlayerChoice) {
					case 1: 
						if (*n1stChoiceCount == 0) {
							*nPlayerScore += 3;
							*n1stChoiceCount += 1;						// Adds count to 1st choice for detecting repetitions
							
							showStatement(nRound, nPlayerChoice);
							
							break;
							
						}
						else {											// If nNthChoiceCount != 0, no points
							*n1stChoiceCount += 1;
							break;
						}
					case 2: 
						if (*n2ndChoiceCount == 0) {					// 2nd choice scoring: 3 - 1 penalty = 2
							*nPlayerScore += 3 - 1;
							*n2ndChoiceCount += 1;
							break;
						}
						else {
							*n2ndChoiceCount += 1;
							break;
						}
					case 3: 
						if (*n3rdChoiceCount == 0) {					// 3rd choice scoring: 3 - 2 penalty = 1
							*nPlayerScore += 3 - 2;
							*n3rdChoiceCount += 1;
							break;
						}
						else {
							*n3rdChoiceCount += 1;
							break;
						}
					case 4: 
						if (*n4thChoiceCount == 0) {					// 4th choice scoring: 3 - 4 penalty = -1
							*nPlayerScore += 3 - 4;
							*n4thChoiceCount += 1;
							break;
						}
						else {
							*n4thChoiceCount += 1;
							break;
						}	
				}
				
				break;
				
			}
			else {
				printf("%d is not a valid choice, please input either 1, 2, 3, or 4.\n", nPlayerChoice);	
			}
	}
}

int main() {
	char cStart = ' ';					// User prompt for starting the game
	
	int nDebateNum;						// Refers to debate number, e.g. 'First Debate', 'Second Debate', 'Third Debate'
	int nPlayerScore;					// Player score
	int nBotScore;						// Bot score
	int nRound;							// Round number
	
	int n1stChoiceCount;				// Counters to determine if repititions happen
	int n2ndChoiceCount;				// in choices, used in selectStatement() function
	int n3rdChoiceCount;
	int n4thChoiceCount;
	
	printf("Welcome to PROGCC Debot Club!\n\n");

	
	while (cStart != 'y' && cStart != 'Y'){
		
		printf("Would you like to start the game? <Y/N>: ");
		scanf("%c", &cStart);
		
		if (cStart == 'y' || cStart == 'Y') {
			continue;
		}
		
		else if (cStart == 'n' || cStart == 'N') {
			printf("\n");
			printf("The game will now end.");
			exit(0);
		}
		
		else {
			printf("%c is not a valid response!\n\n", cStart);
		}
		
	}
	
	printf("The game will now start!");
	//nStartCondition = 1;
	sleep(1);
	clrScreen();
	
	// Pre-game settings
	nPlayerScore = 0;
	nBotScore = 0;
	nDebateNum = 1;
	
	n1stChoiceCount = 0;				// Counters to determine if repititions happen
	n2ndChoiceCount = 0;				// in choices, used in selectStatement() function
	n3rdChoiceCount = 0;
	n4thChoiceCount = 0;
	
	// - FIRST DEBATE -
	
	displayDebateDetails(nDebateNum);
	
		// ROUND 1
	nRound = 1;
	
	printf	("\n");
	printf	("		- Round 1 -");
	printf	("\n\n");
	printf	("Opening Statement (Input either 1, 2, 3, or 4):\n");
	
	displayArgChoices(nDebateNum);
	
	printf("\n");
	
	selectStatement(nRound, &nPlayerScore, &n1stChoiceCount, &n2ndChoiceCount, &n3rdChoiceCount, &n4thChoiceCount);
	
	botStatement(nDebateNum, nRound, &nBotScore);
	
	printf("Score: %d, 1stChoiceCount: %d, n2ndChoiceCount: %d, n3rdChoiceCount: %d, n4thChoiceCount: %d", nPlayerScore, n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount);

	return 0;
}
