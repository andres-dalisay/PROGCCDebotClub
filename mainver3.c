#include <stdio.h>
#include <stdlib.h>

void botStatement (int nDebateNum, int nRound, int *nBotScore, int *nBotScoreRound1, int *nBotScoreRound2, int *nBotScoreRound3) {
	int nScoreAdded, nPenalty;
	
	if (nDebateNum == 1){
		if (nRound == 1) {
			nScoreAdded = 3;
			nPenalty = 2;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("Team Bot Annie Cal responds with: It is a well-known fact that homework provides\n");
			printf("additional unnecessary cognitive load for students!\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Not Citing Sources*\n", nPenalty);
		}
		
		else if (nRound == 2) {
			nScoreAdded = 3;
			nPenalty = 1;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("Team Bot Annie Cal responds with: There are better ways to asses learning other than\n");
			printf("homeworks!\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for No Evidence*\n", nPenalty);
		}
		
		else if (nRound == 3) {
			nScoreAdded = 3;
			nPenalty = 0;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("Team Bot Annie Cal responds with: Learning also happens on weekends despite homework,\n");
			printf("when students get to reflect on class discussions.\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Compelling Argument*\n", nScoreAdded);
		}
	}
	
	else if (nDebateNum == 2) {
		if (nRound == 1) {
			nScoreAdded = 3;
			nPenalty = 0;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("a\n");
			printf("b\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Not Citing Sources*\n", nPenalty);
		}
		
		else if (nRound == 2) {
			nScoreAdded = 3;
			nPenalty = 0;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("c\n");
			printf("d\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for No Evidence*\n", nPenalty);
		}
		
		else if (nRound == 3) {
			nScoreAdded = 3;
			nPenalty = 2;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("e\n");
			printf("f\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Compelling Argument*\n", nScoreAdded);
		}
	}
	
	else if (nDebateNum == 3) {
		if (nRound == 1) {
			nScoreAdded = 3;
			nPenalty = 0;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("a\n");
			printf("b\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Not Citing Sources*\n", nPenalty);
		}
		
		else if (nRound == 2) {
			nScoreAdded = 3;
			nPenalty = 0;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("c\n");
			printf("d\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for No Evidence*\n", nPenalty);
		}
		
		else if (nRound == 3) {
			nScoreAdded = 3;
			nPenalty = 0;
			*nBotScore += nScoreAdded - nPenalty;
			
			printf("e\n");
			printf("f\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Compelling Argument*\n", nScoreAdded);
		}
	}
	
	sleep (1);
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
				break;
		
		case 2: printf("		- The Second Debate -\n");
				printf("Topic			: 222222\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal\n");
				break;
		
		case 3: printf("		- The Third Debate -\n");
				printf("Topic			: 3333333\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal\n");
				break;
				
	}
	//sleep (2);
}

void displayArgChoices (int nDebateNum) {
	
	switch (nDebateNum){
		
		case 1:	printf (" [1] Homework is necessary because it reinforces what students learn in the classroom.\n");
				printf (" [2] Years of data show that homework is an effective way of supplementing discussions.\n");
				printf (" [3] I don't know about you, but our forefathers would be mad if we ban homeworks.\n");
				printf (" [4] Homeworks are like the peanut to a peanut butter jelly sandwich!\n");
				break;
	}
}

void checkBonuses (int n1stChoiceCount, int n2ndChoiceCount, int n3rdChoiceCount, int n4thChoiceCount) {
	if (n1stChoiceCount >= 1 && n2ndChoiceCount == 0 && n3rdChoiceCount >= 1 && n4thChoiceCount == 0){				// All Odd Responses
		printf("All Odd");
	}
	else if (n1stChoiceCount == 3 || n2ndChoiceCount == 3 || n3rdChoiceCount == 3 || n4thChoiceCount == 3){			// Adamant
		printf("Adamant");
	}
	
	// All In Due Time here
		// need a way to store which rounds each choice was made
		
	// Book ends
		// same problem as all in due time
	
	//Absurd opening
		// same problem
	
	

}

void displayDebateSummary(int nDebateNum, int nTotalPlayerScore, int nTotalBotScore, int n1stChoiceCount, int n2ndChoiceCount, int n3rdChoiceCount, int n4thChoiceCount) {
	char * sRoundCount;
	
	if (nDebateNum == 1) {
		sRoundCount = "First";
		printf ("		- The %s Debate -\n", sRoundCount);
	}
	else if (nDebateNum == 2) {
		sRoundCount = "Second";
		printf ("		- The %s Debate -\n", sRoundCount);
	}
	else if (nDebateNum == 3) {
		sRoundCount = "Third";
		printf ("		- The %s Debate -\n", sRoundCount);
	}
	
	printf ("Team ProgCC Points:\n");
	printf ("Round 1: %d\n");
	printf ("Round 2: %d\n");
	printf ("Round 3: %d\n");
	
	checkBonuses(n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount);											//check for bonuses
	
	
	printf ("Total: %d points\n\n", nTotalPlayerScore);
	
	printf ("Team Bot Annie Cal Points:\n ");
	printf ("Round 1: %d\n");
	printf ("Round 2: %d\n");
	printf ("Round 3: %d\n");
	printf ("\n");
	printf ("Total: %d points\n\n", nTotalBotScore);
	
	if (nTotalPlayerScore > nTotalBotScore) {
		printf("Team ProgCC wins The %s Debate!\n\n", sRoundCount);
	}
	else if (nTotalPlayerScore < nTotalBotScore) {
		printf("Team Bot Annie Cal wins The %s Debate!\n\n", sRoundCount);
	}
	else {
		printf("The debate is a draw!\n\n");
	}
	//sleep(3);
	//clrScreen();
}

void playerScoreSummary (int nDebateNum, int nRepetitionStatus, int nChoice, int nScoreAdded, int nPenalty) {				// NOTES: needs to take into account debate number since answers are different
	
	if (nDebateNum == 1) {
		if (nRepetitionStatus == 0){
			if (nChoice == 1) {
				printf("Team ProgCC: Homework is necessary because it reinforces what students learn in the classroom.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Assertiveness*\n\n", nScoreAdded); 			
			}															
			
			else if (nChoice == 2) {
				printf("Team ProgCC: Years of data show that homework is an effective way of supplementing discussions.\n\n");
				//sleep (2);
			}
			
			else if (nChoice == 3) {
				printf("Team ProgCC: I don't know about you, but our forefathers would be mad if we ban homeworks.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for History*", nScoreAdded);
				printf("Team ProgCC gets -%d Argument Points for Ad Hominem*\n\n", nPenalty);
				
			}
			
			else if (nChoice == 4) {
				printf("Team ProgCC: Homeworks are like the peanut to a peanut butter jelly sandwich!\n\n");
				//sleep (2);
			}
			
		}
		
		else {
			printf("*Team ProgCC gets 0 Argument Points for Repetition*\n\n");
			//sleep (2);
		}	
	}
	
	else if (nDebateNum == 2) {
		if (nRepetitionStatus == 0) {
			
			if (nChoice == 1) {
				
			}
			
			else if (nChoice == 2) {
				
			}
			
			else if (nChoice == 3) {
				
			}
			
			else if (nChoice == 4) {
				
			}
			
		}
		else {
			printf("*Team ProgCC gets 0 Argument Points for Repetition*\n\n");
		}	
	}
	
	else if (nDebateNum == 3) {
		if (nRepetitionStatus == 0) {
			
			if (nChoice == 1) {
				
			}
			
			else if (nChoice == 2) {
				
			}
			
			else if (nChoice == 3) {
				
			}
			
			else if (nChoice == 4) {
				
			}
			
		}
		else {
			printf("*Team ProgCC gets 0 Argument Points for Repetition*\n\n");
		}	
	}
			
}

void playerAddToRoundScore(int nPlayerScore, int nRound, int *nPlayerScoreRound1, int *nPlayerScoreRound2, int *nPlayerScoreRound3){
	if (nRound == 1) {
		*nPlayerScoreRound1 = nPlayerScore;
	}
	else if (nRound == 2){
		*nPlayerScoreRound2 = nPlayerScore;
	}
	else if (nRound == 3){
		*nPlayerScoreRound3 = nPlayerScore;
	}
}

void playerAddScore (int nDebateNum, int nRound, int nChoice, int *nPlayerTotalScore, int *nPlayerScoreRound1, int *nPlayerScoreRound2, int *nPlayerScoreRound3, int *n1stChoiceCount, int *n2ndChoiceCount, int *n3rdChoiceCount, int *n4thChoiceCount) {
	
	int nScoreAdded, nPenalty, nPlayerScoreRound;
	int nRepetition = 0;
	
	if (nChoice == 1) {
		if (*n1stChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 0;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			playerAddToRoundScore(nPlayerScoreRound, nRound, &nPlayerScoreRound1, &nPlayerScoreRound2, &nPlayerScoreRound3);
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*n1stChoiceCount += 1;										// Adds count to 1st choice for detecting repetitions
		}
		else {
			*n1stChoiceCount += 1;										// if nNthChoiceCount != 0, no points, add to choice and repetition count
			nRepetition = 1;
		}
	}
	
	else if (nChoice == 2) {										// 2nd choice scoring: 3 - 1 penalty = 2
		if (*n2ndChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 1;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			playerAddToRoundScore(nPlayerScoreRound, nRound, &nPlayerScoreRound1, &nPlayerScoreRound2, &nPlayerScoreRound3);
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*n2ndChoiceCount += 1;
		}
		else {
			*n2ndChoiceCount += 1;
			nRepetition = 1;
		}
	}
	
	else if (nChoice == 3) {										// 3rd choice scoring: 3 - 2 penalty = 1
		if (*n3rdChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 2;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			playerAddToRoundScore(nPlayerScoreRound, nRound, &nPlayerScoreRound1, &nPlayerScoreRound2, &nPlayerScoreRound3);
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*n3rdChoiceCount += 1;
		}
		else {
			*n3rdChoiceCount += 1;
			nRepetition = 1;
		}
	}
	
	else if (nChoice == 4) {										// 4th choice scoring: 3 - 4 penalty = -1
		if (*n4thChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 4;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			playerAddToRoundScore(nPlayerScoreRound, nRound, &nPlayerScoreRound1, &nPlayerScoreRound2, &nPlayerScoreRound3);
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*n4thChoiceCount += 1;
		}
		else {
			*n4thChoiceCount += 1;
			nRepetition = 1;
		}
	}
	
	playerScoreSummary(nDebateNum, nRepetition, nChoice, nScoreAdded, nPenalty);
	
}

int playerSelectStatement () {
	int nChoice;
	
	while(nChoice != 1 && nChoice != 2 && nChoice != 3 && nChoice != 4 ) {
		
		printf("Your choice: ");
		scanf("%d", &nChoice);
		
		if (nChoice == 1 || nChoice == 2 || nChoice == 3 || nChoice == 4){
		continue;															// CHANGE
		}
		else {
			printf("%d is not a valid choice, please input either 1, 2, 3, or 4.\n\n", nChoice);
		}
	}
	
	return nChoice;
}

int main() {
	char cSelect = ' ';					// User prompt for starting the game
	char cTemp;
	
	int nDebateNum;						// Refers to debate number, e.g. 'First Debate', 'Second Debate', 'Third Debate'
	
	
	int nRound;							// Round number
	int nPlayerChoice;					// Argument choice selected by player
	
	int nPlayerTotalScore;					// Player score
	int nPlayerScoreRound1;
	int nPlayerScoreRound2;
	int nPlayerScoreRound3;
	
	int nBotTotalScore;						// Bot score
	int nBotScoreRound1;
	int nBotScoreRound2;
	int nBotScoreRound3;
	
	int n1stChoiceCount;				// Counters to determine if repititions happen
	int n2ndChoiceCount;				// in choices, used in playerAddScore() function
	int n3rdChoiceCount;
	int n4thChoiceCount;
	
	printf("Welcome to PROGCC Debot Club!\n\n");

	
	while (!(cSelect == 'y' || cSelect == 'Y')){
		
		printf("Would you like to start the game? <Y/N>: ");
		scanf("%c%c", &cSelect, &cTemp);
		
		if (cSelect == 'n' || cSelect == 'N') {
			printf("\n\n");
			printf("The game will now end.");
			exit(0); 							//LOOK FOR ALTERNATIVE TO exit(0);
		}
		
		else if (cSelect != 'y' && cSelect != 'Y'){
			printf("%c is not a valid response!\n\n", cSelect);
		}
		
	}
	
	cSelect = ' ';						//Resets cSelect for later select prompts
	
	printf("The game will now start!");
	sleep(1);
	clrScreen();
	
	for(nDebateNum = 1; nDebateNum <= 3; nDebateNum += 1) {
	
		// Pre-game settings
		nPlayerTotalScore = 0;
		nBotTotalScore = 0;
		
		n1stChoiceCount = 0;				// Counters to determine if repititions happen
		n2ndChoiceCount = 0;				// in choices, used in selectStatement() function
		n3rdChoiceCount = 0;
		n4thChoiceCount = 0;
		
		displayDebateDetails(nDebateNum);
		
		for(nRound = 1; nRound <= 3; nRound += 1){
				
			printf	("\n");
			printf	("		- Round %d -", nRound);
			printf	("\n\n");
			
			//sleep (1);
			
			printf	("Opening Statement (Input either 1, 2, 3, or 4):\n");
			
			displayArgChoices(nDebateNum);
			
			printf	("\n");
			
			nPlayerChoice = playerSelectStatement();
			
			playerAddScore(nDebateNum, nRound, nPlayerChoice, &nPlayerTotalScore, &nPlayerScoreRound1, &nPlayerScoreRound2, &nPlayerScoreRound3, &n1stChoiceCount, &n2ndChoiceCount, &n3rdChoiceCount, &n4thChoiceCount);
			//sleep (1);
			
			botStatement(nDebateNum, nRound, &nBotTotalScore, &nBotScoreRound1, &nBotScoreRound2, &nBotScoreRound3);
			
			printf	("\n\nDEBUG Score: %d\nnPlayerScoreRound1: %d\nnPlayerScoreRound2: %d\nnPlayerScoreRound3: %d\n\nnBot Score: %d\nn1stChoiceCount: %d\nn2ndChoiceCount: %d\nn3rdChoiceCount: %d\nn4thChoiceCount: %d\n\n", nPlayerTotalScore, nPlayerScoreRound1, nPlayerScoreRound2, nPlayerScoreRound3, nBotTotalScore, n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount);
			//sleep (1);
		}
		
		displayDebateSummary(nDebateNum, nPlayerTotalScore, nBotTotalScore, n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount);
		
		if (nDebateNum == 1) {
			printf ("Would you like to start the second debate? <Y/N>: ");
			scanf  ("%c%c", &cSelect, &cTemp);
		}
		else if (nDebateNum == 2) {
			printf ("Would you like to start the third debate? <Y/N>: ");
			scanf  ("%c%c", &cSelect, &cTemp);
		}
		else {
			printf ("Thank you for playing!");
		}
		
	}

	return 0;
}
