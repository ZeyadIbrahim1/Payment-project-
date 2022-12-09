
#ifndef TERMINAL_H
#define TERMINAL_H

#include <string.h>
#include <stdio.h>
#include<ctype.h>
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Card\card.h"
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	TERMINAL_OK,					//value of 0
	WRONG_DATE,						//value of 1
	EXPIRED_CARD,					//value of 2
	INVALID_CARD,					//value of 3
	INVALID_AMOUNT,					//value of 4
	EXCEED_MAX_AMOUNT,				//value of 5
	INVALID_MAX_AMOUNT				//value of 6

}EN_terminalError_t;

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount);
//EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);

#endif 
