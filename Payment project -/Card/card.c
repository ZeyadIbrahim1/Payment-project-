#include <stdio.h>
#include <string.h>
#include "card.h"
#include <ctype.h>
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"



#define MaxCardHolderName 24
#define MinCardHolderName 20
#define ExpiryDateStrlen 5
#define MaxCardPAN 19
#define MinCardPAN 16


//ST_cardData_t* cardData;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

	printf("Please Enter the Card Holder's Name \n");  // print to the user to let him write the holder name
	//scanf("%[^\n]s", &cardData->cardHolderName);
	scanf_s("%[^\n]s", &cardData->cardHolderName, MaxCardHolderName + 1);  // scanf_s to avoid    //
	if (strlen(cardData->cardHolderName) < MinCardHolderName || strlen(cardData->cardHolderName) > MaxCardHolderName || (cardData->cardHolderName == NULL)) {
		return WRONG_NAME;

	}

	for (int i = 0; i<strlen(cardData->cardHolderName); i++) {

		if (!((cardData->cardHolderName[i] >= 97 && cardData->cardHolderName[i] <= 122) || (cardData->cardHolderName[i] >= 65 && cardData->cardHolderName[i] <= 90 ) || (cardData->cardHolderName[i] == 32))){

			return WRONG_NAME;
			
		}

		

	}
	
	//chech if the card holder's name formate 

	return CARD_OK;

}


EN_cardError_t getCardPAN(ST_cardData_t* cardData) {

	printf("please enter the Primary Account Number \n");

	scanf_s("%s", &cardData->primaryAccountNumber,MaxCardPAN+1);
	//|| (cardData->primaryAccountNumber) == NULL
	if (strlen(cardData->primaryAccountNumber) < MinCardPAN || strlen(cardData->primaryAccountNumber) > MaxCardPAN )
		return WRONG_PAN;
	for (int i = 0; i < strlen(cardData->primaryAccountNumber); i++) {
		if (!(cardData->primaryAccountNumber[i] >= '0' && cardData->primaryAccountNumber[i] <= '9')) {
			return WRONG_PAN;
		}
	}
//	else 
	//	printf("Your Primary Account Number is : %s \n", cardData->primaryAccountNumber);
	return CARD_OK;

}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {

	printf("please Enter the date in formate of MM/YY \n");

	scanf_s("%s[^\n]", &cardData->cardExpirationDate, ExpiryDateStrlen + 1); fflush(stdin);

	if (strlen(cardData->cardExpirationDate) != ExpiryDateStrlen || (cardData->cardExpirationDate) == NULL )
		return WRONG_EXP_DATE;

	else if (!isdigit(cardData->cardExpirationDate[0]) || !isdigit(cardData->cardExpirationDate[1]) || !isdigit(cardData->cardExpirationDate[3]) || !isdigit(cardData->cardExpirationDate[4])  )
		return WRONG_EXP_DATE;

	else if (cardData->cardExpirationDate[2] != '/')
		return WRONG_EXP_DATE;


	else 
		printf("Your card expiry is %s  \n ", cardData->cardExpirationDate);

		
	return CARD_OK;

}






