#ifndef CARD_H
#define CARD_H
#include <string.h>
#include <stdio.h>
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"

#define MaxCardHolderName 24
#define MinCardHolderName 20
#define ExpiryDateStrlen 19
#define MinCardPAN 16

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];

	uint8_t cardExpirationDate[6];
	uint8_t primaryAccountNumber[20];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	CARD_OK,               //value of 0
	WRONG_NAME,			   //value of 1
	WRONG_EXP_DATE,		   //value of 2 
	WRONG_PAN			   //value of 3
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);


#endif // !CARD_H
