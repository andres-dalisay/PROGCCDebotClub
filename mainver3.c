#include <stdio.h>
#include <stdlib.h>

void clrScreen () {
	system("cls");
}

void startGame () {
	int cSelect = ' ';
	int cTemp;
	
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
}

void displayDebateDetails (int nDebateNum){
	
	switch (nDebateNum){
		
		case 1:	printf("		- The First Debate -\n");
				printf("Topic			: Homework should be banned.\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal\n");
				break;
		
		case 2: printf("		- The Second Debate -\n");
				printf("Topic			: We should work towards colonizing Mars.\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal\n");
				break;
		
		case 3: printf("		- The Third Debate -\n");
				printf("Topic			: Dota 2 is better than League of Legends\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal\n");
				break;
				
	}
	//sleep (2);
}

void displayRoundNumber(int nRound) {
	printf	("\n");
	printf	("		- Round %d -", nRound);
	printf	("\n\n");
}

void displayArgChoices (int nDebateNum, int nRound) {
	
	if (nRound == 1) {
		printf	("Opening Statement (Input either 1, 2, 3, or 4):\n");
	}
	else {
		printf	("Your response (Input either 1, 2, 3, or 4):\n");
	}
	
	switch (nDebateNum){
		
		case 1:	
				printf (" [1] Homework is necessary because it reinforces what students learn in the classroom.\n");
				printf (" [2] Years of data show that homework is an effective way of supplementing discussions.\n");
				printf (" [3] I don't know about you, but our forefathers would be mad if we ban homeworks.\n");
				printf (" [4] Homeworks are like the peanut to a peanut butter jelly sandwich!\n");
				break;
		case 2:
				printf (" [1] A mass extinction event on Earth may naturally occur sooner or later.\n");
				printf (" [2] We will be able to get more resources from Mars.\n");
				printf (" [3] It may help us understand our own planet more.\n");
				printf (" [4] We can fulfill our destiny to explore the great unknown!\n");
				break;
		case 3:
				printf (" [1] All the heroes in Dota 2 are unlocked from the start.\n");
				printf (" [2] The biggest Dota 2 tournament has the largest prize pool in esports history.\n");
				printf (" [3] Dota 2 is a much more complex game.\n");
				printf (" [4] Dota 2 is better, and LoL players can't deny.\n");
				break;
	}
	
	printf ("\n");
}

int playerSelectStatement () {
	int nChoice = 0;
	
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

void playerScoreSummary (int nDebateNum, int nRepetitionStatus, int nChoice, int nScoreAdded, int nPenalty) {				// NOTES: needs to take into account debate number since answers are different
	
	if (nDebateNum == 1) {
		if (nRepetitionStatus == 0){
			if (nChoice == 1) {
				printf("Team ProgCC: Homework is necessary because it reinforces what students learn in the classroom.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Assertiveness*", nScoreAdded); 			
			}															
			
			else if (nChoice == 2) {
				printf("Team ProgCC: Years of data show that homework is an effective way of supplementing discussions.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Use of Statistics*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Possible Selection Bias*", nPenalty);
			}
			
			else if (nChoice == 3) {
				printf("Team ProgCC: I don't know about you, but our forefathers would be mad if we ban homeworks.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for History*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Ad Hominem*", nPenalty);
				
			}
			
			else if (nChoice == 4) {
				printf("Team ProgCC: Homeworks are like the peanut to a peanut butter jelly sandwich!\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Analogy*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Baseless Argument*", nPenalty);
			}
			
			printf("\n\n"); 
			
		}
		
		else {
			printf("*Team ProgCC gets 0 Argument Points for Repetition*\n\n");
			//sleep (2);
		}	
	}
	
	else if (nDebateNum == 2) {
		if (nRepetitionStatus == 0) {
			
			if (nChoice == 1) {
				printf("Team ProgCC: A mass extinction event on Earth may naturally occur sooner or later.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Realism*", nScoreAdded);
			}
			
			else if (nChoice == 2) {
				printf("Team ProgCC: We may be able to get more resources from Mars.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Resourcefulness*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Slight Greed*", nPenalty);
			}
			
			else if (nChoice == 3) {
				printf("Team ProgCC: It may help us understand our own planet more.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Concern for Earth*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Not Specific*", nPenalty);
			}
			
			else if (nChoice == 4) {
				printf("Team ProgCC: We can fulfill our destiny to explore the great unknown!\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Concern for Fatalism*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Vagueness*", nPenalty);
			}
			
			printf("\n\n"); 
			
		}
		else {
			printf("*Team ProgCC gets 0 Argument Points for Repetition*\n\n");
		}	
	}
	
	else if (nDebateNum == 3) {
		if (nRepetitionStatus == 0) {
			
			if (nChoice == 1) {
				printf("Team ProgCC: All the heroes in Dota 2 are unlocked from the start.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Freedom of Choice*\n", nScoreAdded);
			}
			
			else if (nChoice == 2) {
				printf("Team ProgCC: The biggest Dota 2 tournament has the largest prize pool in esports history.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for Prize Pool Flex*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Bravado*", nPenalty);
			}
			
			else if (nChoice == 3) {
				printf("Team ProgCC: Dota 2 is a much more complex game.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for \"To be fair, you have to have a very high IQ to understand Dota 2\"*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Complex != Better*", nPenalty);
			}
			
			else if (nChoice == 4) {
				printf("Team ProgCC: Dota 2 is better, and LoL players can’t deny.\n\n");
				//sleep (2);
				printf("*Team ProgCC gets %d Argument Points for the Memes*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Overused Joke*", nPenalty);
			}
			
			printf("\n\n"); 
			
		}
		else {
			printf("*Team ProgCC gets 0 Argument Points for Repetition*\n\n");
		}	
	}
			
}

void playerAddScore (int nDebateNum, int nRound, int nChoice, int *nPlayerTotalScore, int *nPlayerScoreRound1, int *nPlayerScoreRound2, int *nPlayerScoreRound3, int *n1stChoiceCount, int *n2ndChoiceCount, int *n3rdChoiceCount, int *n4thChoiceCount, int *nRoundOneChoice, int *nRoundTwoChoice, int *nRoundThreeChoice) {
	
	int nScoreAdded, nPenalty, nPlayerScoreRound;
	int nRepetition = 0;
	
	if (nChoice == 1) {
		if (*n1stChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 0;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			if (nRound == 1) {
				*nPlayerScoreRound1 = nPlayerScoreRound;
				*nRoundOneChoice = nChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRound2 = nPlayerScoreRound;
				*nRoundTwoChoice = nChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRound3 = nPlayerScoreRound;
				*nRoundThreeChoice = nChoice;
			}
			
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
			
			if (nRound == 1) {
				*nPlayerScoreRound1 = nPlayerScoreRound;
				*nRoundOneChoice = nChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRound2 = nPlayerScoreRound;
				*nRoundTwoChoice = nChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRound3 = nPlayerScoreRound;
				*nRoundThreeChoice = nChoice;
			}
			
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
			
			if (nRound == 1) {
				*nPlayerScoreRound1 = nPlayerScoreRound;
				*nRoundOneChoice = nChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRound2 = nPlayerScoreRound;
				*nRoundTwoChoice = nChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRound3 = nPlayerScoreRound;
				*nRoundThreeChoice = nChoice;
			}
			
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
			
			if (nRound == 1) {
				*nPlayerScoreRound1 = nPlayerScoreRound;
				*nRoundOneChoice = nChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRound2 = nPlayerScoreRound;
				*nRoundTwoChoice = nChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRound3 = nPlayerScoreRound;
				*nRoundThreeChoice = nChoice;
			}
			
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

void botStatement (int nDebateNum, int nRound, int *nBotTotalScore, int *nBotScoreRound1, int *nBotScoreRound2, int *nBotScoreRound3) {
	int nScoreAdded, nPenalty, nBotScoreRound;
	
	if (nDebateNum == 1){
		if (nRound == 1) {
			nScoreAdded = 3;
			nPenalty = 2;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound1 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("Team Bot Annie Cal responds with: It is a well-known fact that homework provides\n");
			printf("additional unnecessary cognitive load for students!\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Not Citing Sources*\n", nPenalty);
		}
		
		else if (nRound == 2) {
			nScoreAdded = 3;
			nPenalty = 1;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound2 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("Team Bot Annie Cal responds with: There are better ways to asses learning other than\n");
			printf("homeworks!\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for No Evidence*\n", nPenalty);
		}
		
		else if (nRound == 3) {
			nScoreAdded = 3;
			nPenalty = 0;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound3 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
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
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound1 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("Shifting our focus to Mars may lead to neglect towards sustaining Earth.\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Environmentalism*\n", nScoreAdded);
		}
		
		else if (nRound == 2) {
			nScoreAdded = 3;
			nPenalty = 0;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound2 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("We may risk contaminating the Martian environment.\n\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Contamination-Conscious*\n", nScoreAdded);
		}
		
		else if (nRound == 3) {
			nScoreAdded = 3;
			nPenalty = 2;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound3 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("All that we need is on Earth.\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Contentedness*\n", nScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Denial of Current Issues*\n", nPenalty);
		}
	}
	
	else if (nDebateNum == 3) {
		if (nRound == 1) {
			nScoreAdded = 3;
			nPenalty = 0;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound1 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("League of Legends has a bigger playerbase.\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Healthy Playerbase*\n", nScoreAdded);
		}
		
		else if (nRound == 2) {
			nScoreAdded = 3;
			nPenalty = 0;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound2 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("League of Legends doesn’t have a very steep learning curve to play.\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Accessibility*\n", nScoreAdded);
		}
		
		else if (nRound == 3) {
			nScoreAdded = 3;
			nPenalty = 0;
			nBotScoreRound = nScoreAdded - nPenalty;
			
			*nBotScoreRound3 = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
			
			printf("League of Legends is better promoted with short animated movies and original songs.\n");
			//sleep (1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Creativity*\n", nScoreAdded);
		}
	}
	
	sleep (1);
}

void varDebug (int nPlayerTotalScore, int nPlayerScoreRound1, int nPlayerScoreRound2, int nPlayerScoreRound3, int nBotTotalScore, int nBotScoreRound1, int nBotScoreRound2, int nBotScoreRound3, int n1stChoiceCount, int n2ndChoiceCount, int n3rdChoiceCount, int n4thChoiceCount, int nRoundOneChoice, int nRoundTwoChoice, int nRoundThreeChoice) {	
	printf	("\n");
	printf	("DEBUG\n");
	printf	("\n");
	printf	("nPlayerTotalScore: %d\nnPlayerScoreRound1: %d\nnPlayerScoreRound2: %d\nnPlayerScoreRound3: %d\n", nPlayerTotalScore, nPlayerScoreRound1, nPlayerScoreRound2, nPlayerScoreRound3);
	printf	("\n");
	printf ("nRoundOneChoice: %d\nnRoundTwoChoice: %d\nnRoundThreeChoice: %d\n", nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);
	printf	("\n");
	printf	("nBotTotalScore: %d\nnBotScoreRound1: %d\nnBotScoreRound2: %d\nnBotScoreRound3: %d\n", nBotTotalScore, nBotScoreRound1, nBotScoreRound2, nBotScoreRound3);
	printf	("\n");
	printf	("n1stChoiceCount: %d\nn2ndChoiceCount: %d\nn3rdChoiceCount: %d\nn4thChoiceCount: %d\n", n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount);
}

int checkBonuses (int n1stChoiceCount, int n2ndChoiceCount, int n3rdChoiceCount, int n4thChoiceCount, int nRoundOneChoice, int nRoundTwoChoice, int nRoundThreeChoice) {
	int nBonusPoints = 0;
	printf("Bonuses:\n");
	
	// All Odd Responses
	if (n1stChoiceCount >= 1 && n2ndChoiceCount == 0 && n3rdChoiceCount >= 1 && n4thChoiceCount == 0){				
		printf("	- All odd responses: 3\n");
		nBonusPoints += 3;
	}
	// Adamant
	else if (n1stChoiceCount == 3 || n2ndChoiceCount == 3 || n3rdChoiceCount == 3 || n4thChoiceCount == 3){			
		printf("	- Adamant: 6\n");
		nBonusPoints += 6;
	}
	// All In Due Time
	else if (nRoundThreeChoice - nRoundTwoChoice == 1 && nRoundTwoChoice - nRoundOneChoice == 1) {
		printf("	- All in due time: 4\n");
		nBonusPoints += 4;
	}
		
	// Book Ends
	if (n1stChoiceCount <= 1 && n2ndChoiceCount <= 1 && n3rdChoiceCount <= 1 && n4thChoiceCount <= 1) {
		if (nRoundOneChoice == 1 && nRoundThreeChoice == 4 || nRoundOneChoice == 4 && nRoundThreeChoice == 1){
			printf("	- Book ends: 4\n");
			nBonusPoints += 4;
		}
	}
	//Absurd Opening
	if (nRoundOneChoice == 4) {
		printf("	- Absurd opening: 2\n");
		nBonusPoints += 2;
	}
	
	return nBonusPoints;
	

}

void displayDebateSummary(int nDebateNum, int nTotalPlayerScore, int nPlayerScoreRound1, int nPlayerScoreRound2, int nPlayerScoreRound3, int nTotalBotScore, int nBotScoreRound1,  int nBotScoreRound2, int nBotScoreRound3, int n1stChoiceCount, int n2ndChoiceCount, int n3rdChoiceCount, int n4thChoiceCount, int nRoundOneChoice, int nRoundTwoChoice, int nRoundThreeChoice) {
	char * sRoundCount;
	int nBonusPoints;
	
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
	printf ("	- Round 1: %d\n", nPlayerScoreRound1);
	printf ("	- Round 2: %d\n", nPlayerScoreRound2);
	printf ("	- Round 3: %d\n", nPlayerScoreRound3);
	
	nBonusPoints = checkBonuses(n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount, nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);											//check for bonuses
	nTotalPlayerScore += nBonusPoints;
	printf ("\n");
	printf ("Total: %d points\n\n", nTotalPlayerScore);
	
	printf ("Team Bot Annie Cal Points:\n");
	printf ("	- Round 1: %d\n", nBotScoreRound1);
	printf ("	- Round 2: %d\n", nBotScoreRound2);
	printf ("	- Round 3: %d\n", nBotScoreRound3);
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

int main() {
	char cSelect = ' ';					// User prompt for starting the game
	char cTemp;
	
	int nDebateNum;						// Refers to debate number, e.g. 'First Debate', 'Second Debate', 'Third Debate'
	
	int nRound;							// Round number
	int nPlayerChoice;					// Argument choice selected by player
	
	int nPlayerTotalScore;				// Player score
	int nPlayerScoreRound1;				// Player score for individual rounds
	int nPlayerScoreRound2;
	int nPlayerScoreRound3;
	
	int nRoundOneChoice 	= 0;
	int nRoundTwoChoice 	= 0;
	int nRoundThreeChoice 	= 0;
	
	int n1stChoiceCount;				// Counters to determine if repititions happen
	int n2ndChoiceCount;				// in choices, used in playerAddScore() function
	int n3rdChoiceCount;
	int n4thChoiceCount;
	
	int nBotTotalScore;					// Bot score
	int nBotScoreRound1 	= 0;		// Bot score for individual rounds
	int nBotScoreRound2 	= 0;
	int nBotScoreRound3 	= 0;
	
	startGame();
	
	printf("The game will now start!");
	sleep(1);
	clrScreen();
	
	for(nDebateNum = 1; nDebateNum <= 3; nDebateNum += 1) {
	
		// Pre-game reset settings
		nPlayerTotalScore 	= 0;
		nPlayerScoreRound1 	= 0;	
		nPlayerScoreRound2 	= 0;
		nPlayerScoreRound3 	= 0;
		
		nRoundOneChoice 	= 0;
		nRoundTwoChoice 	= 0;
		nRoundThreeChoice 	= 0;
		
		n1stChoiceCount 	= 0;			
		n2ndChoiceCount 	= 0;			
		n3rdChoiceCount 	= 0;
		n4thChoiceCount 	= 0;
		
		n1stChoiceCount 	= 0;				
		n2ndChoiceCount 	= 0;				
		n3rdChoiceCount 	= 0;
		n4thChoiceCount 	= 0;
		
		
		nBotTotalScore 		= 0;
		nBotScoreRound1 	= 0;	
		nBotScoreRound2 	= 0;
		nBotScoreRound3 	= 0;
		
		
		displayDebateDetails(nDebateNum);
		
		for(nRound = 1; nRound <= 3; nRound += 1){
				
			displayRoundNumber(nRound);
			
			//sleep (1);
			
			displayArgChoices(nDebateNum, nRound);
			
			nPlayerChoice = playerSelectStatement();
			
			playerAddScore(nDebateNum, nRound, nPlayerChoice, &nPlayerTotalScore, &nPlayerScoreRound1, &nPlayerScoreRound2, &nPlayerScoreRound3, &n1stChoiceCount, &n2ndChoiceCount, &n3rdChoiceCount, &n4thChoiceCount, &nRoundOneChoice, &nRoundTwoChoice, &nRoundThreeChoice);
			//sleep (1);
			
			botStatement(nDebateNum, nRound, &nBotTotalScore, &nBotScoreRound1, &nBotScoreRound2, &nBotScoreRound3);
			
			//varDebug(nPlayerTotalScore, nPlayerScoreRound1, nPlayerScoreRound2, nPlayerScoreRound3, nBotTotalScore, nBotScoreRound1, nBotScoreRound2, nBotScoreRound3, n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount, nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);
			
			//sleep (1);
		}
		
		displayDebateSummary(nDebateNum, nPlayerTotalScore, nPlayerScoreRound1, nPlayerScoreRound2, nPlayerScoreRound3, nBotTotalScore, nBotScoreRound1, nBotScoreRound2, nBotScoreRound3, n1stChoiceCount, n2ndChoiceCount, n3rdChoiceCount, n4thChoiceCount, nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);
		
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
		
		cSelect = ' ';						//Resets cSelect for later select prompts
		
	}

	return 0;
}
