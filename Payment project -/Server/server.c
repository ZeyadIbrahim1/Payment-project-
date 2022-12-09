
#include <stdio.h>
#include <string.h>
#include "server.h"	
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Card\card.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Terminal\terminal.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Server\server.h"
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"


ST_accountsDB_t accountsDB[255] = { {2000.0, RUNNING, "8989374615436851"},
								  {100000.0, BLOCKED, "5807007076043875"} ,
								  {90000.0, BLOCKED, "5318649531024657"},
								  {3500.0, RUNNING, "3245123698746512"},
								  {30.0, RUNNING, "3214569874621345"} };

ST_transaction_t Transactions[255] = { 0 };
uint32_t TransactionNumber = 0;

int acc_counter = 0;

ST_accountsDB_t accountRefrence;


EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence){

		
	for (acc_counter = 0; acc_counter < 255; acc_counter++) {


		if (!strcmp(cardData->primaryAccountNumber, accountsDB[acc_counter].primaryAccountNumber))

		{
			*accountRefrence = accountsDB[acc_counter];
			return SERVER_OK;

		}
		else {
			continue;
		}
	}
		return ACCOUNT_NOT_FOUND;

	}
	//fe 8alta



EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {

		if (termData->transAmount <= accountRefrence->balance)
		{
			return SERVER_OK;
		}
		else
			return LOW_BALANCE;
}
/**/
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {
/*
	for (acc_counter = (0 + acc_counter); acc_counter < 255; acc_counter++) {

		//5807007076043875 BLOCKED
		//8989374615436851 RUNNING

		if (accountRefrence->state & Accounts[acc_counter].state == BLOCKED) {
			return BLOCKED_ACCOUNT;
			break;
		}
		else if (accountRefrence->state & Accounts[acc_counter].state == RUNNING) {
			return SERVER_OK;
			break;
		}

	}
	*/
	

		//5807007076043875 BLOCKED
		//8989374615436851 RUNNING

		if (accountRefrence->state == BLOCKED) {
			return BLOCKED_ACCOUNT;
			
		}
		else if ( accountRefrence->state == RUNNING) {
			return SERVER_OK;
			
		}

	

}

EN_serverError_t saveTransaction(ST_transaction_t* transData) {

	transData->transactionSequenceNumber = 0 + TransactionNumber;
	if (transData->transactionSequenceNumber < 255) {

		Transactions[transData->transactionSequenceNumber].cardHolderData = transData->cardHolderData;
		Transactions[transData->transactionSequenceNumber].transState = transData->transState;
		Transactions[transData->transactionSequenceNumber].terminalData = transData->terminalData;
		Transactions[transData->transactionSequenceNumber].transactionSequenceNumber = transData->transactionSequenceNumber + 1;
		TransactionNumber++;
		return SERVER_OK;
	}

	return INTERNAL_SERVER_ERROR;
}
EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	//ST_cardData_t t;//lazem te create dh struct we teb3t address bta3 struct t "card data" , wel function ele hena hatb3tlha el address 
	//strcpy(t.cardHolderName, "");

	//account_local = isValidAccount(&transData->cardHolderData, &accountRefrence);
	//amount_local = 
	//saving_local = 
	//block_local 

	int account_local = isValidAccount(&transData->cardHolderData, &accountRefrence);

	if (account_local == ACCOUNT_NOT_FOUND) {
		//saveTransaction(&transData);

		return FRAUD_CARD;
	}
	int amount_local = isAmountAvailable(&transData->terminalData, &accountRefrence);

	if (amount_local == LOW_BALANCE) {
		//saveTransaction(&transData);

		return DECLINED_INSUFFECIENT_FUND;
	}
	EN_serverError_t block_local = isBlockedAccount(&accountRefrence);

	if (block_local == BLOCKED_ACCOUNT) {
		//saveTransaction(&transData);

		return DECLINED_STOLEN_CARD;
	}
		//saving_local=saveTransaction(&transData);

	//if (saving_local == INTERNAL_SERVER_ERROR)
	//	return SAVING_FAILED;

	for (int i = 0; i < 255; i++) {
		if (!strcmp(transData->cardHolderData.primaryAccountNumber, accountsDB[i].primaryAccountNumber)) {
			accountsDB[i].balance = accountsDB[i].balance - transData->terminalData.transAmount;
			printf("the new balance is: %f\n", accountsDB[i].balance);
			break;
		}
		else {
			continue;
		}
	}
	
	return APPROVED;


	//if (validAccount = isValidAccount(transData->cardHolderData) == ACCOUNT_NOT_FOUND);

}

void listSavedTransactions(void) {

	for (int i = 0; i < 255; i++) {
		
		
		
		//Transaction Sequence Number :
		printf("The transaction sequence number is %d \n", Transactions[i].transactionSequenceNumber);
		//Transaction Date :
		printf("the transaction date is %s \n", Transactions[i].terminalData.transactionDate);
		//Transaction Amount :
		printf("the transaction amount is %lf \n", Transactions[i].terminalData.transAmount);
		//Transaction State :
		printf("the transaction state is %d \n",Transactions[i].transState);
		//Terminal Max Amount :
		printf("the max amount is %f \n", Transactions[i].terminalData.maxTransAmount);
		//Cardholder Name :
		printf("the card holder name is %s \n", Transactions[i].cardHolderData.cardHolderName);
		//PAN:
		printf("the primary account number is %s \n", Transactions[i].cardHolderData.primaryAccountNumber);
		//Card Expiration Date :
		printf("the Expiration date is %s \n", Transactions[i].cardHolderData.cardExpirationDate);
	}

	
}

/*








 */