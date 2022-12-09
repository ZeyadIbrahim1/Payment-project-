
#include <stdio.h>
#include <string.h>
#include "terminal.h"
#include <time.h>
#include <ctype.h>
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"


#define Transaction_date_Len   10

float maxAmount = 10000.0;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implement gatTransactionAmount function
/This function asks for the transaction amount and saves it into terminal data.
If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return OK.
You should deliver a maximum 2min video to discuss your implementation and run different test cases on this function

*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	printf("please enter the date in formate of DD/MM/YYYY \n");

	scanf_s("%s[^\n] ", termData->transactionDate, Transaction_date_Len + 1); //fflush(stdin);
	//					arr			   0 1 2 3 4 5 6 7 8 9
	//                  val            2 1 / 0 5 / 2 0 0 0
	
	/*
	if ((termData->transactionDate[0] >= 0) && (termData->transactionDate[0] <= 3) &&

		(termData->transactionDate[1] >= 0) && (termData->transactionDate[1] <= 9) &&

		(termData->transactionDate[3] >= 0) && (termData->transactionDate[3] <= 1) &&

		(termData->transactionDate[4] >= 0) && (termData->transactionDate[0] <= 9) &&

		(termData->transactionDate[6] >= 0) && (termData->transactionDate[6] <= 9) &&

		(termData->transactionDate[7] >= 0) && (termData->transactionDate[7] <= 9) &&

		(termData->transactionDate[8] >= 0) && (termData->transactionDate[8] <= 9) &&

		(termData->transactionDate[9] >= 0) && (termData->transactionDate[9] <= 9) &&

		(termData->transactionDate[2] == '/') && (termData->transactionDate[5] == '/')) {

		return TERMINAL_OK;



	}
	


	if ((termData->transactionDate[0] <= 0) && (termData->transactionDate[0] >= 3)) {

		if ((termData->transactionDate[1] <= 0) && (termData->transactionDate[1] >= 9)) {

			if ((termData->transactionDate[3] <= 0) && (termData->transactionDate[3] >= 1)) {

				if ((termData->transactionDate[4] <= 0) && (termData->transactionDate[0] >= 9)) {

					if ((termData->transactionDate[6] <= 0) && (termData->transactionDate[6] >= 9)) {

						if ((termData->transactionDate[7] <= 0) && (termData->transactionDate[7] >= 9)) {

							if ((termData->transactionDate[8] <= 0) && (termData->transactionDate[8] >= 9)) {

								if ((termData->transactionDate[9] <= 0) && (termData->transactionDate[9] >= 9)) {

									if ((termData->transactionDate[2] != '/') && (termData->transactionDate[5] != '/')) {

										return WRONG_DATE;

									}

								}
							}
						}
					}
				}
			}
		}
	}
	*/



	if ((termData->transactionDate[0] < 0) && (termData->transactionDate[0] > 3)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[1] < 0) && (termData->transactionDate[1] > 9)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[3] < 0) && (termData->transactionDate[3] > 1)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[4] < 0) && (termData->transactionDate[0] > 9)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[6] < 0) && (termData->transactionDate[6] > 9)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[7] < 0) && (termData->transactionDate[7] > 9)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[8] <0) && (termData->transactionDate[8] >9)) 
		return WRONG_DATE;

	else if ((termData->transactionDate[9] < 0) && (termData->transactionDate[9] > 9)) 
		return WRONG_DATE;


	else if ((termData->transactionDate[2] != '/') && (termData->transactionDate[5] != '/')) 

		return WRONG_DATE;

	else if ((termData->transactionDate < Transaction_date_Len) || termData->transactionDate == NULL)
		return WRONG_DATE;

	



	return TERMINAL_OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("please enter the transaction amount \n");

	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
		return INVALID_AMOUNT;

//	printf("your transaction amount is %.2f  \n", termData->transAmount);

	return TERMINAL_OK;

}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {

	termData->maxTransAmount = maxAmount;

	printf("Max Transaction Amount is : %.2f\n", termData->maxTransAmount);


	if ((termData->maxTransAmount <= 0)) {
		printf("laaaa");
		return INVALID_MAX_AMOUNT;

	}

	else {
		return TERMINAL_OK;
	}
	
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {

	if (termData->transAmount > termData->maxTransAmount)
		return EXCEED_MAX_AMOUNT;

	return TERMINAL_OK;
}



EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	// cardExpirationDate MM/YY      transactionDate DD/MM/YYYY
	//                    05/22						 21/05/2022
	if ((cardData->cardExpirationDate[3]) < (termData->transactionDate[8]))
		return EXPIRED_CARD;
	
	else if ((cardData->cardExpirationDate[4]) < (termData->transactionDate[9]))
		return EXPIRED_CARD;

	else if ((cardData->cardExpirationDate[0]) < (termData->transactionDate[3])) 
		return EXPIRED_CARD;

	else if ((cardData->cardExpirationDate[1]) < (termData->transactionDate[4]))
			return 	EXPIRED_CARD;
	

		return TERMINAL_OK;
}


/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////












*/


