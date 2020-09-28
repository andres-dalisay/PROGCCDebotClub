/*	Programmed by:		Andres Dalisay	S12
	Description:		This program is a debate-style
						game where the user selects various arguments
						to get a higher score than the opposition bot team.
	Last Modified:		SEPT-27-2020
	
	Known Bugs:			- Entering two characters in prompts may result in input buffer issues, causing succeeding prompts to not work properly.
*/
#include <stdio.h>
#include <stdlib.h>

/*	Prints newlines based on amount specified in the nLines parameter.
	@param	(int)	nLines is the number of newlines desired
*/
void
newLine(int nLines){
	int i;
	
	for (i = 1; i <= nLines; i += 1){
		printf("\n");
	}
}

/* Clears the command line screen. */
void
clrScreen() {
	system("cls");
}

/*	Asks user for Y/N input to start the game at the beginning of the program.
	@return (int) 1 to continue game, 0 to exit and stop the program
*/
int 
startGame() {
	char cSelect = ' ';
	char cTemp;
	
	int nStartGame = 0;		
	
	printf("Welcome to PROGCC Debot Club!");
	newLine(2);

	while (!(cSelect == 'y' || cSelect == 'Y' || cSelect == 'n' || cSelect == 'N')){
		
		printf("Would you like to start the game? <Y/N>: ");
		scanf("%c%c", &cSelect, &cTemp);

		if (!(cSelect == 'y' || cSelect == 'Y' || cSelect == 'n' || cSelect == 'N')){		// Input validation
			printf("%c is not a valid response!", cSelect);
			newLine(2);
		}
		
	}
	
	if (cSelect == 'n' || cSelect == 'N') {
		nStartGame = 0;
	}
	if (cSelect == 'y' || cSelect == 'Y'){
		nStartGame = 1;
	}
	
	
	return nStartGame;
}

/*	Displays the debate number, topic, affirmative team, and opposing team.
	@param 	(int) 	nDebateNum is the current debate iteration.
*/
void
displayDebateDetails (int nDebateNum){
	
	switch (nDebateNum){
		
		case 1:	printf("		- The First Debate -\n");
				printf("Topic			: Homework should be banned.\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal");
				newLine(2);
				break;
		
		case 2: printf("		- The Second Debate -\n");
				printf("Topic			: We should work towards colonizing Mars.\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal");
				newLine(2);
				break;
		
		case 3: printf("		- The Third Debate -\n");
				printf("Topic			: Dota 2 is better than League of Legends\n");
				printf("Affirmative team	: Team ProgCC\n");
				printf("Opposing team		: Team Bot Annie Cal");
				newLine(2);
				break;
				
	}
	
	sleep(1);
	
}

/*	Displays the round number.
	@param	(int)	nRound is the current round number.
*/
void
displayRoundNumber(int nRound) {
	printf	("		- Round %d -", nRound);
	newLine(2);
	sleep(1);
}

/*	Displays argument choices based on respective debate number.
	@param	(int)	nDebateNum is the current debate iteration.
	@param	(int)	nRound is the current round number.
*/
void
displayArgChoices (int nDebateNum, int nRound) {
	
	if (nRound == 1) {														// Switches from "Opening statement" in the first round to "Your
		printf("Opening statement (Input either 1, 2, 3, or 4):\n");		// response" in the second and third rounds.
	}
	else {
		printf("Your response (Input either 1, 2, 3, or 4):\n");
	}
	
	switch (nDebateNum){
		case 1:	
				printf(" [1] Homework is necessary because it reinforces what students learn in the classroom.\n");
				printf(" [2] Years of data show that homework is an effective way of supplementing discussions.\n");
				printf(" [3] I don't know about you, but our forefathers would be mad if we ban homeworks.\n");
				printf(" [4] Homeworks are like the peanut to a peanut butter jelly sandwich!");
				break;
		case 2:
				printf(" [1] A mass extinction event on Earth may naturally occur sooner or later.\n");
				printf(" [2] We will be able to get more resources from Mars.\n");
				printf(" [3] It may help us understand our own planet more.\n");
				printf(" [4] We can fulfill our destiny to explore the great unknown!");
				break;
		case 3:
				printf(" [1] All the heroes in Dota 2 are unlocked from the start.\n");
				printf(" [2] The biggest Dota 2 tournament has the largest prize pool in esports history.\n");
				printf(" [3] Dota 2 is a much more complex game.\n");
				printf(" [4] Dota 2 is better, and LoL players can't deny.");
				break;
	}
	newLine(2);
}

/*	Asks user to input 1, 2, 3, or 4 to choose an argument.
	@return	(char)	choice inputted by the player
*/
char
playerSelectStatement () {
	char cChoice = ' ';		// cChoice has a char datatype instead of int because
	char cTemp;				// of an infinite loop bug in the input validation
							// while loop caused by entering a string when datatype is
							// int.
	
	while(!(cChoice == '1' || cChoice == '2' || cChoice == '3' || cChoice == '4')) {				// As of now, inputting a negative sign (-) with
																									// a valid choice (1, 2, 3, 4) is accepted because
		printf("Your choice: ");																	// cChoice is a char, not an int. Not sure how to fix.
		scanf("%c%c", &cChoice, &cTemp);
		
		if (!(cChoice == '1' || cChoice == '2' || cChoice == '3' || cChoice == '4')){
			printf("%c is not a valid choice, please input either 1, 2, 3, or 4.", cChoice);		
			newLine(2);
		}
		
	}
	newLine(1);
	
	
	return cChoice;
}

/*	Displays the player's argument choice, as well as additions and deductions to points with "justifications."
	@param	(int)	nDebateNum is the current debate iteration.
	@param	(int)	nRepetitionStatus is 0 for no repetition of choice, and 1 when a choice is repeated.
	@param	(char)	cChoice is the choice selected by the user (1, 2, 3, or 4).
	@param	(int)	nScoreAdded is the number of points added to the player's score.
	@param	(int)	nPenalty is the number of points deducted from the player's score.
*/
void
playerRoundScoreSummary (int nDebateNum, int nRepetitionStatus, char cChoice, int nScoreAdded, int nPenalty) {
	
	if (nDebateNum == 1) {							// Displays statements relevant to debate topic	
	
		if (cChoice == '1') {
			printf("Team ProgCC: Homework is necessary because it reinforces what students learn in the classroom.");
			sleep(1);
			newLine(2);
			
			// Check for repetition
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Assertiveness*", nScoreAdded);
			}
			// If repetition is detected, player gets no points.
			else {								
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}	
		}															
		
		else if (cChoice == '2') {
			printf("Team ProgCC: Years of data show that homework is an effective way of supplementing discussions.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){
				printf("*Team ProgCC gets %d Argument Points for Use of Statistics*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Possible Selection Bias*", nPenalty);
			}
			else {
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}	
		}
		
		else if (cChoice == '3') {
			printf("Team ProgCC: I don't know about you, but our forefathers would be mad if we ban homeworks.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for History*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Ad Hominem*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}
			
			
		}
		
		else if (cChoice == '4') {
			printf("Team ProgCC: Homeworks are like the peanut to a peanut butter jelly sandwich!");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Analogy*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Baseless Argument*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}

		}
		
		newLine(2);	
	}
	
	else if (nDebateNum == 2) {
			
		if (cChoice == '1') {
			printf("Team ProgCC: A mass extinction event on Earth may naturally occur sooner or later.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
			printf("*Team ProgCC gets %d Argument Points for Realism*", nScoreAdded);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}

		}
		
		else if (cChoice == '2') {
			printf("Team ProgCC: We may be able to get more resources from Mars.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Resourcefulness*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Slight Greed*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}
		}
		
		else if (cChoice == '3') {
			printf("Team ProgCC: It may help us understand our own planet more.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Concern for Earth*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Not Specific*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}
		}
		
		else if (cChoice == '4') {
			printf("Team ProgCC: We can fulfill our destiny to explore the great unknown!");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Concern for Fatalism*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Vagueness*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}
			
		}
		
		newLine(2);
	}
	
	else if (nDebateNum == 3) {

		if (cChoice == '1') {
			printf("Team ProgCC: All the heroes in Dota 2 are unlocked from the start.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Freedom of Choice*", nScoreAdded);
			}

			else {			
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}
		}
		
		else if (cChoice == '2') {
			printf("Team ProgCC: The biggest Dota 2 tournament has the largest prize pool in esports history.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for Prize Pool Flex*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Bravado*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}

		}
		
		else if (cChoice == '3') {
			printf("Team ProgCC: Dota 2 is a much more complex game.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for \"To be fair, you have to have a very high IQ to understand Dota 2\"*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Complex != Better*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}

		}
		
		else if (cChoice == '4') {
			printf("Team ProgCC: Dota 2 is better, and LoL players can't deny.");
			sleep(1);
			newLine(2);
			
			if (nRepetitionStatus == 0){		
				printf("*Team ProgCC gets %d Argument Points for the Memes*\n", nScoreAdded);
				printf("*Team ProgCC gets -%d Argument Points for Overused Joke*", nPenalty);
			}

			else {		
				printf("*Team ProgCC gets 0 Argument Points for Repetition*");
			}

		}
		
		newLine(2);
	
	}
	sleep(1);	
}

/*	Computes for the player's score for each round and keeps track of the choices chosen each round as well as how many times it was used in the debate.
	@param (int)	nDebateNum is the current debate iteration.
	@param (int)	nRound is the current round number.
	@param (int)	cChoice is the choice selected by the user (1, 2, 3, or 4).
	@param (int*)	nPlayerTotalScore is the current total score of the player.
	@param (int*)	nPlayerScoreRoundOne is the number of points obtained by the player in round one.
	@param (int*)	nPlayerScoreRoundTwo is the number of points obtained by the player in round two.
	@param (int*)	nPlayerScoreRoundThree is the number of points obtained by the player in round three.
	@param (int*)	nFirstChoiceCount is the number of times the player chose the first choice.
	@param (int*)	nSecondChoiceCount is the number of times the player chose the second choice.
	@param (int*)	nThirdChoiceCount is the number of times the player chose the third choice.
	@param (int*)	nFourthChoiceCount is the number of times the player chose the fourth choice.
	@param (int*)	nRoundOneChoice is the player's choice in round one of the debate.
	@param (int*)	nRoundTwoChoice is the player's choice in round two of the debate.
	@param (int*)	nRoundThreeChoice is the player's choice in round three of the debate.
*/
void
playerAddScore (int nDebateNum, int nRound, char cChoice, int *nPlayerTotalScore, int *nPlayerScoreRoundOne, int *nPlayerScoreRoundTwo, int *nPlayerScoreRoundThree, int *nFirstChoiceCount, int *nSecondChoiceCount, int *nThirdChoiceCount, int *nFourthChoiceCount, int *nRoundOneChoice, int *nRoundTwoChoice, int *nRoundThreeChoice) {
	
	int nScoreAdded, nPenalty, nPlayerScoreRound;
	int nRepetition = 0;
	
	if (cChoice == '1') {			// 1st choice scoring: 3 - 0 penalty = 3
		if (*nFirstChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 0;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			// Checks current round and stores player score and choice of that round to respective variables
			if (nRound == 1) {
				*nPlayerScoreRoundOne = nPlayerScoreRound;
				*nRoundOneChoice = cChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRoundTwo = nPlayerScoreRound;
				*nRoundTwoChoice = cChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRoundThree = nPlayerScoreRound;		
				*nRoundThreeChoice = cChoice;
			}
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*nFirstChoiceCount += 1;								// Adds count to 1st choice for detecting repetitions
		}
		else {
			*nFirstChoiceCount += 1;								// if nNthChoiceCount != 0, no points, add to choice and repetition count
			nRepetition = 1;
		}
	}
	
	else if (cChoice == '2') {			// 2nd choice scoring: 3 - 1 penalty = 2
		if (*nSecondChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 1;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			if (nRound == 1) {
				*nPlayerScoreRoundOne = nPlayerScoreRound;
				*nRoundOneChoice = cChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRoundTwo = nPlayerScoreRound;
				*nRoundTwoChoice = cChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRoundThree = nPlayerScoreRound;
				*nRoundThreeChoice = cChoice;
			}
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*nSecondChoiceCount += 1;
		}
		else {
			*nSecondChoiceCount += 1;
			nRepetition = 1;
		}
	}
	
	else if (cChoice == '3') {			// 3rd choice scoring: 3 - 2 penalty = 1
		if (*nThirdChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 2;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			if (nRound == 1) {
				*nPlayerScoreRoundOne = nPlayerScoreRound;
				*nRoundOneChoice = cChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRoundTwo = nPlayerScoreRound;
				*nRoundTwoChoice = cChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRoundThree = nPlayerScoreRound;
				*nRoundThreeChoice = cChoice;
			}
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*nThirdChoiceCount += 1;
		}
		else {
			*nThirdChoiceCount += 1;
			nRepetition = 1;
		}
	}
	
	else if (cChoice == '4') {			// 4th choice scoring: 3 - 4 penalty = -1
		if (*nFourthChoiceCount == 0){
			nScoreAdded = 3;
			nPenalty = 4;
			nPlayerScoreRound = nScoreAdded - nPenalty;
			
			if (nRound == 1) {
				*nPlayerScoreRoundOne = nPlayerScoreRound;
				*nRoundOneChoice = cChoice;
			}
			else if (nRound == 2){
				*nPlayerScoreRoundTwo = nPlayerScoreRound;
				*nRoundTwoChoice = cChoice;
			}
			else if (nRound == 3){
				*nPlayerScoreRoundThree = nPlayerScoreRound;
				*nRoundThreeChoice = cChoice;
			}
			
			*nPlayerTotalScore += nPlayerScoreRound;
			*nFourthChoiceCount += 1;
		}
		else {
			*nFourthChoiceCount += 1;
			nRepetition = 1;
		}
	}
	
	playerRoundScoreSummary(nDebateNum, nRepetition, cChoice, nScoreAdded, nPenalty);
	
}

/*	Displays the bot's argument choice, as well as additions and deductions to points with "justifications."
	@param	(int)	nDebateNum is the current debate iteration.
	@param	(int)	nRound is the current round number.
	@param	(int)	nBotScoreAdded is the number of points added to the bot's score.
	@param	(int)	nBotPenalty is the number of points deducted from the bot's score.
*/
void
botRoundScoreSummary (int nDebateNum, int nRound, int nBotScoreAdded, int nBotPenalty) {
	
	if (nDebateNum == 1){
		if (nRound == 1) {
			printf("Team Bot Annie Cal responds with: It is a well-known fact that homework provides\n");
			printf("additional unnecessary cognitive load for students!");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nBotScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Not Citing Sources*", nBotPenalty);
			newLine(2);
		}
		
		else if (nRound == 2) {
			printf("Team Bot Annie Cal responds with: There are better ways to asses learning other than\n");
			printf("homeworks!");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Assertiveness*\n", nBotScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for No Evidence*", nBotPenalty);
			newLine(2);
		}
		
		else if (nRound == 3) {
			printf("Team Bot Annie Cal responds with: Learning also happens on weekends despite homework,\n");
			printf("when students get to reflect on class discussions.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Compelling Argument*", nBotScoreAdded);
			newLine(2);
		}
	}
	
	else if (nDebateNum == 2) {
		if (nRound == 1) {
			printf("Team Bot Annie Cal responds with: Shifting our focus to Mars may lead to neglect towards sustaining Earth.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Environmentalism*", nBotScoreAdded);
			newLine(2);
		}
		
		else if (nRound == 2) {
			printf("Team Bot Annie Cal responds with: We may risk contaminating the Martian environment.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Contamination-Conscious*", nBotScoreAdded);
			newLine(2);
		}
		
		else if (nRound == 3) {
			printf("Team Bot Annie Cal responds with: All that we need is on Earth.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Contentedness*\n", nBotScoreAdded);
			printf("*Team Bot Annie Cal gets -%d Argument Points for Denial of Current Issues*", nBotPenalty);
			newLine(2);
		}
	}
	
	else if (nDebateNum == 3) {
		if (nRound == 1) {
			printf("Team Bot Annie Cal responds with: League of Legends has a bigger playerbase.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Healthy Playerbase*", nBotScoreAdded);
			newLine(2);
		}
		
		else if (nRound == 2) {
			printf("Team Bot Annie Cal responds with: League of Legends doesn't have a very steep learning curve to play.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Accessibility*", nBotScoreAdded);
			newLine(2);
		}
		
		else if (nRound == 3) {
			printf("Team Bot Annie Cal responds with: League of Legends is better promoted with short animated movies and original songs.");
			newLine(2);
			sleep(1);
			
			printf("*Team Bot Annie Cal gets %d Argument Points for Creativity*", nBotScoreAdded);
			newLine(2);
		}
	}	
}

/*	Computes for the bot's score each round.
	@param	(int)	nDebateNum is the current debate iteration.
	@param	(int)	nRound is the current round number.
	@param	(int*)	nBotTotalScore is the current total score of the bot.
	@param	(int*)	nBotScoreRoundOne is the number of points obtained by the bot in round one.
	@param	(int*)	nBotScoreRoundTwo is the number of points obtained by the bot in round two.
	@param	(int*)	nBotScoreRoundThree is the number of points obtained by the bot in round three.
*/
void
botAddScore (int nDebateNum, int nRound, int *nBotTotalScore, int *nBotScoreRoundOne, int *nBotScoreRoundTwo, int *nBotScoreRoundThree) {
	int nBotScoreAdded, nBotPenalty, nBotScoreRound;
	
	if (nDebateNum == 1){
		if (nRound == 1) {
			nBotScoreAdded = 3;
			nBotPenalty = 2;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundOne = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
		
		else if (nRound == 2) {
			nBotScoreAdded = 3;
			nBotPenalty = 1;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundTwo = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
		
		else if (nRound == 3) {
			nBotScoreAdded = 3;
			nBotPenalty = 0;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundThree = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
	}
	
	else if (nDebateNum == 2) {
		if (nRound == 1) {
			nBotScoreAdded = 3;
			nBotPenalty = 0;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundOne = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
		
		else if (nRound == 2) {
			nBotScoreAdded = 3;
			nBotPenalty = 0;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundTwo = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
		
		else if (nRound == 3) {
			nBotScoreAdded = 3;
			nBotPenalty = 2;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundThree = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
	}
	
	else if (nDebateNum == 3) {
		if (nRound == 1) {
			nBotScoreAdded = 3;
			nBotPenalty = 0;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundOne = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
		
		else if (nRound == 2) {
			nBotScoreAdded = 3;
			nBotPenalty = 0;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundTwo = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
		
		else if (nRound == 3) {
			nBotScoreAdded = 3;
			nBotPenalty = 0;
			nBotScoreRound = nBotScoreAdded - nBotPenalty;
			
			*nBotScoreRoundThree = nBotScoreRound;
			
			*nBotTotalScore += nBotScoreRound;
		}
	}
	botRoundScoreSummary(nDebateNum, nRound, nBotScoreAdded, nBotPenalty);
	sleep(2);
}

/*	Used mainly for nRoundXChoice variables to convert from cChoice ASCII value to proper integer.
	@param 	(int*)	nRoundOneChoice is the player's choice in round one of the debate.
	@param 	(int*)	nRoundTwoChoice is the player's choice in round two of the debate.
	@param 	(int*)	nRoundThreeChoice is the player's choice in round three of the debate.	
*/
void
convertASCIIValueToInt (int *nRoundOneChoice, int *nRoundTwoChoice, int *nRoundThreeChoice) {
	
	if (*nRoundOneChoice == 49){				//	49 = 1
		*nRoundOneChoice = 1;					//	50 = 2
	}											//	51 = 3
	else if (*nRoundOneChoice == 50){			//	52 = 4
		*nRoundOneChoice = 2;
	}
	else if (*nRoundOneChoice == 51){
		*nRoundOneChoice = 3;
	}
	else if (*nRoundOneChoice == 52){
		*nRoundOneChoice = 4;
	}
	
	if (*nRoundTwoChoice == 49){
		*nRoundTwoChoice = 1;
	}
	else if (*nRoundTwoChoice == 50){
		*nRoundTwoChoice = 2;
	}
	else if (*nRoundTwoChoice == 51){
		*nRoundTwoChoice = 3;
	}
	else if (*nRoundTwoChoice == 52){
		*nRoundTwoChoice = 4;
	}
	
	if (*nRoundThreeChoice == 49){
		*nRoundThreeChoice = 1;
	}
	else if (*nRoundThreeChoice == 50){
		*nRoundThreeChoice = 2;
	}
	else if (*nRoundThreeChoice == 51){
		*nRoundThreeChoice = 3;
	}
	else if (*nRoundThreeChoice == 52){
		*nRoundThreeChoice = 4;
	}
}

/*	Used to trace certain variables in-between debate rounds for debug purposes.
	@param 	(int)	nPlayerTotalScore is the current total score of the player.
	@param 	(int)	nPlayerScoreRoundOne is the number of points obtained by the player in round one.
	@param 	(int)	nPlayerScoreRoundTwo is the number of points obtained by the player in round two.
	@param	(int)	nPlayerScoreRoundThree is the number of points obtained by the player in round three.
	@param	(int*)	nBotTotalScore is the current total score of the bot.
	@param	(int*)	nBotScoreRoundOne is the number of points obtained by the bot in round one.
	@param	(int*)	nBotScoreRoundTwo is the number of points obtained by the bot in round two.
	@param	(int*)	nBotScoreRoundThree is the number of points obtained by the bot in round three.
	@param 	(int)	nFirstChoiceCount is the number of times the player chose the first choice.
	@param 	(int)	nSecondChoiceCount is the number of times the player chose the second choice.
	@param 	(int)	nThirdChoiceCount is the number of times the player chose the third choice.
	@param 	(int)	nFourthChoiceCount is the number of times the player chose the fourth choice.
	@param 	(int)	nRoundOneChoice is the player's choice in round one of the debate.
	@param 	(int)	nRoundTwoChoice is the player's choice in round two of the debate.
	@param 	(int)	nRoundThreeChoice is the player's choice in round three of the debate.
*/
void
varDebug (int nPlayerTotalScore, int nPlayerScoreRoundOne, int nPlayerScoreRoundTwo, int nPlayerScoreRoundThree, int nBotTotalScore, int nBotScoreRoundOne, int nBotScoreRoundTwo, int nBotScoreRoundThree, int nFirstChoiceCount, int nSecondChoiceCount, int nThirdChoiceCount, int nFourthChoiceCount, int nRoundOneChoice, int nRoundTwoChoice, int nRoundThreeChoice) {	
	printf	("\n");
	printf	("DEBUG\n");
	printf	("\n");
	printf	("nPlayerTotalScore: %d\nnPlayerScoreRoundOne: %d\nnPlayerScoreRoundTwo: %d\nnPlayerScoreRoundThree: %d\n", nPlayerTotalScore, nPlayerScoreRoundOne, nPlayerScoreRoundTwo, nPlayerScoreRoundThree);
	printf	("\n");
	printf ("nRoundOneChoice: %d\nnRoundTwoChoice: %d\nnRoundThreeChoice: %d\n", nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);
	printf	("\n");
	printf	("nBotTotalScore: %d\nnBotScoreRoundOne: %d\nnBotScoreRoundTwo: %d\nnBotScoreRoundThree: %d\n", nBotTotalScore, nBotScoreRoundOne, nBotScoreRoundTwo, nBotScoreRoundThree);
	printf	("\n");
	printf	("nFirstChoiceCount: %d\nnSecondChoiceCount: %d\nnThirdChoiceCount: %d\nnFourthChoiceCount: %d\n", nFirstChoiceCount, nSecondChoiceCount, nThirdChoiceCount, nFourthChoiceCount);
}

/*	Checks for bonus conditions and returns sum of bonus points.
	@param 	(int)	nFirstChoiceCount is the number of times the player chose the first choice.
	@param 	(int)	nSecondChoiceCount is the number of times the player chose the second choice.
	@param 	(int)	nThirdChoiceCount is the number of times the player chose the third choice.
	@param 	(int)	nFourthChoiceCount is the number of times the player chose the fourth choice.
	@param 	(int)	nRoundOneChoice is the player's choice in round one of the debate.
	@param 	(int)	nRoundTwoChoice is the player's choice in round two of the debate.
	@param 	(int)	nRoundThreeChoice is the player's choice in round three of the debate.
	@return	(int)	sum of bonus points awarded
*/
int
checkBonuses (int nFirstChoiceCount, int nSecondChoiceCount, int nThirdChoiceCount, int nFourthChoiceCount, int nRoundOneChoice, int nRoundTwoChoice, int nRoundThreeChoice) {
	int nBonusPoints = 0;
	
	printf("Bonuses:\n");
	
	// All Odd Responses
	if (nFirstChoiceCount >= 1 && nSecondChoiceCount == 0 && nThirdChoiceCount >= 1 && nFourthChoiceCount == 0){				
		printf("	- All odd responses: 3\n");
		nBonusPoints += 3;
	}
	// Adamant
	else if (nFirstChoiceCount == 3 || nSecondChoiceCount == 3 || nThirdChoiceCount == 3 || nFourthChoiceCount == 3){			
		printf("	- Adamant: 6\n");
		nBonusPoints += 6;
	}
	// All In Due Time
	else if (nRoundThreeChoice - nRoundTwoChoice == 1 && nRoundTwoChoice - nRoundOneChoice == 1) {
		printf("	- All in due time: 4\n");
		nBonusPoints += 4;
	}
		
	// Book Ends
	if (nFirstChoiceCount <= 1 && nSecondChoiceCount <= 1 && nThirdChoiceCount <= 1 && nFourthChoiceCount <= 1) {
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
	
	newLine(1);
	
	return nBonusPoints;
	

}

/*	Displays the point summary of the debate.
	@param	(int)	nDebateNum is the current debate iteration.
	@param 	(int)	nPlayerTotalScore is the current total score of the player.
	@param 	(int)	nPlayerScoreRoundOne is the number of points obtained by the player in round one.
	@param 	(int)	nPlayerScoreRoundTwo is the number of points obtained by the player in round two.
	@param	(int)	nPlayerScoreRoundThree is the number of points obtained by the player in round three.
	@param	(int)	nBotTotalScore is the current total score of the bot.
	@param	(int)	nBotScoreRoundOne is the number of points obtained by the bot in round one.
	@param	(int)	nBotScoreRoundTwo is the number of points obtained by the bot in round two.
	@param	(int)	nBotScoreRoundThree is the number of points obtained by the bot in round three.
	@param 	(int)	nFirstChoiceCount is the number of times the player chose the first choice.
	@param 	(int)	nSecondChoiceCount is the number of times the player chose the second choice.
	@param 	(int)	nThirdChoiceCount is the number of times the player chose the third choice.
	@param 	(int)	nFourthChoiceCount is the number of times the player chose the fourth choice.
	@param 	(int)	nRoundOneChoice is the player's choice in round one of the debate.
	@param 	(int)	nRoundTwoChoice is the player's choice in round two of the debate.
	@param 	(int)	nRoundThreeChoice is the player's choice in round three of the debate.
*/
void displayDebateSummary(int nDebateNum, int nTotalPlayerScore, int nPlayerScoreRoundOne, int nPlayerScoreRoundTwo, int nPlayerScoreRoundThree, int nTotalBotScore, int nBotScoreRoundOne,  int nBotScoreRoundTwo, int nBotScoreRoundThree, int nFirstChoiceCount, int nSecondChoiceCount, int nThirdChoiceCount, int nFourthChoiceCount, int nRoundOneChoice, int nRoundTwoChoice, int nRoundThreeChoice) {
	char * sRoundCount;
	int nBonusPoints;
	
	if (nDebateNum == 1) {
		sRoundCount = "First";
		printf ("		- The %s Debate -", sRoundCount);
	}
	else if (nDebateNum == 2) {
		sRoundCount = "Second";
		printf ("		- The %s Debate -", sRoundCount);
	}
	else if (nDebateNum == 3) {
		sRoundCount = "Third";
		printf ("		- The %s Debate -", sRoundCount);
	}
	
	newLine(2);
	
	printf ("Team ProgCC Points:\n");
	printf ("	- Round 1: %d\n", nPlayerScoreRoundOne);
	printf ("	- Round 2: %d\n", nPlayerScoreRoundTwo);
	printf ("	- Round 3: %d\n", nPlayerScoreRoundThree);
	newLine(1);
	
	nBonusPoints = checkBonuses(nFirstChoiceCount, nSecondChoiceCount, nThirdChoiceCount, nFourthChoiceCount, nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);											//check for bonuses
	nTotalPlayerScore += nBonusPoints;
	printf ("Total: %d points", nTotalPlayerScore);
	newLine(2);
	
	printf ("Team Bot Annie Cal Points:\n");
	printf ("	- Round 1: %d\n", nBotScoreRoundOne);
	printf ("	- Round 2: %d\n", nBotScoreRoundTwo);
	printf ("	- Round 3: %d\n", nBotScoreRoundThree);
	printf ("\n");
	printf ("Total: %d points", nTotalBotScore);
	newLine(2);
	
	if (nTotalPlayerScore > nTotalBotScore) {
		printf("Team ProgCC wins The %s Debate!", sRoundCount);
	}
	else if (nTotalPlayerScore < nTotalBotScore) {
		printf("Team Bot Annie Cal wins The %s Debate!", sRoundCount);
	}
	else {
		printf("The debate is a draw!");
		newLine(2);
	}
	newLine(2);
}

/*	Asks user for Y/N input to continue to the next debate after the end of the first or second debate.
	@param	(int)	nDebateNum is the current debate iteration.
	@return	(int)	value of 1 to continue game, 0 to exit and stop the program
*/
int continueGame (int nDebateNum){
	char cSelect = ' ';
	char cTemp;
	int nContinueState;
	
	if (nDebateNum == 1) {
		
		while (!(cSelect == 'y' || cSelect == 'Y' || cSelect == 'n' || cSelect == 'N')){
			printf ("Would you like to start the second debate? <Y/N>: ");
			scanf  ("%c%c", &cSelect, &cTemp);
			
			if (!(cSelect == 'y' || cSelect == 'Y' || cSelect == 'n' || cSelect == 'N')){
				printf("%c is not a valid response!", cSelect);
				newLine(2);
			}	
		}
		
		if (cSelect == 'n' || cSelect == 'N') {
			printf("The game will now exit. Thank you for playing!");
			nContinueState = 0;
		}
		if (cSelect == 'y' || cSelect == 'Y'){
			nContinueState = 1;
		}
	}
	
	else if (nDebateNum == 2) {
		
		while (!(cSelect == 'y' || cSelect == 'Y' || cSelect == 'n' || cSelect == 'N')){
			printf ("Would you like to start the third debate? <Y/N>: ");
			scanf  ("%c%c", &cSelect, &cTemp);
			
			if (!(cSelect == 'y' || cSelect == 'Y' || cSelect == 'n' || cSelect == 'N')){
				printf("%c is not a valid response!", cSelect);
				newLine(2);
			}	
		}
		
		if (cSelect == 'n' || cSelect == 'N') {
			printf("The game will now exit. Thank you for playing!");
			nContinueState = 0;
		}
		if (cSelect == 'y' || cSelect == 'Y'){
			nContinueState = 1;
		}
	}
	
	return nContinueState;
}

int main() {
/*------------------------------------------------------VARIABLE DECLARATIONS------------------------------------------------------*/	
	
	int nStartGameState;		// A value of 1 means the game continues, while a value of 0 means the game stops and the program ends.
	
	int nDebateNum;				// Refers to debate number, e.g. 'First Debate', 'Second Debate', 'Third Debate'
	
	int nRound;					// Round number
	char cPlayerChoice;			// Argument choice selected by player. Set to char datatype as int will cause problems in input validation when chars/strings are inputted, causing an infinite loop.
	
	int nPlayerTotalScore;		// Player score
	int nPlayerScoreRoundOne;	// Player score for individual rounds
	int nPlayerScoreRoundTwo;
	int nPlayerScoreRoundThree;		
	
	int nRoundOneChoice;		// Takes choices from cPlayerChoice in each round. Converts character value of cPlayerChoice to an integer ASCII value.
	int nRoundTwoChoice;		// Used in checkBonuses() function
	int nRoundThreeChoice;
	
	int nFirstChoiceCount;		// Counters to determine if repititions happen
	int nSecondChoiceCount;		// in choices, used in playerAddScore() function
	int nThirdChoiceCount;
	int nFourthChoiceCount;
	
	int nBotTotalScore;			// Total bot score for each debate
	int nBotScoreRoundOne;		// Bot scores for individual rounds
	int nBotScoreRoundTwo;
	int nBotScoreRoundThree;
	
/*------------------------------------------------------GAME PROPER------------------------------------------------------*/
	
	nStartGameState = startGame();
	
	if (nStartGameState == 1){					// Proceed with game if nStartGameState == 1.
		printf("The game will now start!");		// If user decides to quit at the start of the program,
												// nStartGameState == 0 and the program exits.
		sleep(1);
		clrScreen();
		
			/*------------------------------------------------------DEBATE PROPER------------------------------------------------------*/
			
			for (nDebateNum = 1; nDebateNum <= 3 && nStartGameState == 1; nDebateNum += 1) {		// Loops the whole debate section three times, 
																									// and watches out for nStartGameState in case
																									// user decides to quit game after a debate.
			
				/*------------------------------------------------------PRE-DEBATE RESET SETTINGS------------------------------------------------------*/
				// Makes sure that all values are reset to 0 after each debate to avoid any logical errors at the start of each debate.
				nPlayerTotalScore 	= 0;
				nPlayerScoreRoundOne 	= 0;	
				nPlayerScoreRoundTwo 	= 0;
				nPlayerScoreRoundThree 	= 0;
				
				nRoundOneChoice 	= 0;
				nRoundTwoChoice 	= 0;
				nRoundThreeChoice 	= 0;
				
				nFirstChoiceCount 	= 0;			
				nSecondChoiceCount 	= 0;			
				nThirdChoiceCount 	= 0;
				nFourthChoiceCount 	= 0;
				
				nFirstChoiceCount 	= 0;				
				nSecondChoiceCount 	= 0;				
				nThirdChoiceCount 	= 0;
				nFourthChoiceCount 	= 0;
				
				
				nBotTotalScore 		= 0;
				nBotScoreRoundOne 	= 0;	
				nBotScoreRoundTwo 	= 0;
				nBotScoreRoundThree 	= 0;
				
				displayDebateDetails(nDebateNum);
				
				/*------------------------------------------------------ROUND PROPER------------------------------------------------------*/
				for(nRound = 1; nRound <= 3; nRound += 1){		// Repeats rounds 3 times
					displayRoundNumber(nRound);			
					displayArgChoices(nDebateNum, nRound);
					cPlayerChoice = playerSelectStatement();
					playerAddScore(nDebateNum, nRound, cPlayerChoice, &nPlayerTotalScore, &nPlayerScoreRoundOne, &nPlayerScoreRoundTwo, &nPlayerScoreRoundThree, &nFirstChoiceCount, &nSecondChoiceCount, &nThirdChoiceCount, &nFourthChoiceCount, &nRoundOneChoice, &nRoundTwoChoice, &nRoundThreeChoice);
					botAddScore(nDebateNum, nRound, &nBotTotalScore, &nBotScoreRoundOne, &nBotScoreRoundTwo, &nBotScoreRoundThree);
					
					convertASCIIValueToInt(&nRoundOneChoice, &nRoundTwoChoice, &nRoundThreeChoice);		// Because cPlayerChoice is a char, nRoundXChoice variables come out as their
																										// ASCII value equivalents. Thus, they need to be changed to their real integer
																										// counterparts because the "Absurd opening" bonus in the checkBonuses() function
																										// won't work with the ASCII value.
					
					/* Uncomment this to show trace values after each round */
					//varDebug(nPlayerTotalScore, nPlayerScoreRoundOne, nPlayerScoreRoundTwo, nPlayerScoreRoundThree, nBotTotalScore, nBotScoreRoundOne, nBotScoreRoundTwo, nBotScoreRoundThree, nFirstChoiceCount, nSecondChoiceCount, nThirdChoiceCount, nFourthChoiceCount, nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);
				}
				
				sleep(1);
				/*------------------------------------------------------POST-DEBATE------------------------------------------------------*/
				clrScreen();
				displayDebateSummary(nDebateNum, nPlayerTotalScore, nPlayerScoreRoundOne,nPlayerScoreRoundTwo, nPlayerScoreRoundThree, nBotTotalScore, nBotScoreRoundOne, nBotScoreRoundTwo, nBotScoreRoundThree, nFirstChoiceCount, nSecondChoiceCount, nThirdChoiceCount, nFourthChoiceCount, nRoundOneChoice, nRoundTwoChoice, nRoundThreeChoice);
				
				if (nDebateNum == 1 || nDebateNum == 2){			// Only runs continueGame() function after the first and second debates
					nStartGameState = continueGame(nDebateNum);		// since the game will end after the third debate anyways.
					clrScreen();
				}
				else {
					printf("Thank you for playing!");
					nStartGameState = 0;							// Ends the game by breaking the while loop.
				}
			}
	}
	newLine(2);
	printf("The game will now end.\n");
	return 0;
	
}
