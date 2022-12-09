

#ifndef SERVER_H
#define SERVER_H
#include <string.h>
#include <stdio.h>
#include<ctype.h>
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Card\card.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Terminal\terminal.h"
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"

typedef enum EN_transState_t
{
	APPROVED,							//value of 0
	DECLINED_INSUFFECIENT_FUND,			//value of 1
	DECLINED_STOLEN_CARD,				//value of 2
	FRAUD_CARD,							//value of 3
	INTERNAL_SERVER_ERROR				//value of 4
}EN_transState_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;


typedef enum EN_serverError_t
{
	SERVER_OK,					//value of 0
	SAVING_FAILED,				//value of 1
	TRANSACTION_NOT_FOUND,		//value of 2
	ACCOUNT_NOT_FOUND,			//value of 3
	LOW_BALANCE,				//value of 4
	BLOCKED_ACCOUNT				//value of 5
}EN_serverError_t;


typedef enum EN_accountState_t
{
	RUNNING,					//value of 0
	BLOCKED						//value of 1
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
	float balance;
	EN_accountState_t state;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

void listSavedTransactions(void);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData,  ST_accountsDB_t* accountRefrence);
void listSavedTransactions(void);
//EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);





#endif // !SERVER_H
