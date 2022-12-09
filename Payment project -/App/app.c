
#include <string.h>
#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Card\card.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Terminal\terminal.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Server\server.h"
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"
#include"app.h"


ST_cardData_t app_card;
ST_terminalData_t app_terminal;
//ST_accountsDB_t app_DB;
float app_maxAmount = 10000.0;

void appStart(void) {
	/*
	//card variables
	EN_cardError_t card_name  = getCardHolderName(&app_card);
	EN_cardError_t card_pan   = getCardPAN(&app_card);
	EN_cardError_t card_date  = getCardExpiryDate(&app_card);


	//terminal variables 
	EN_terminalError_t terminal_date      = getTransactionDate(&app_terminal);
	EN_terminalError_t terminal_amount    = isAmountAvailable(&app_terminal ,&app_DB);
	EN_terminalError_t terminal_max       = setMaxAmount(&app_terminal, app_maxAmount);
	EN_terminalError_t terminal_below     = isBelowMaxAmount(&app_terminal);
	EN_terminalError_t terminal_Card_Exp  = isCardExpired(&app_card, &app_terminal);

	//server variables 
	
	EN_serverError_t server_recieve = recieveTransactionData(&app_server);
	*/
	/**************************************************************************************************************************/
	//Card logic

	EN_cardError_t card_name = getCardHolderName(&app_card);
	if (card_name == WRONG_NAME) {
		printf("wrong name \n");
		exit(0);
	}


	EN_cardError_t card_pan = getCardPAN(&app_card);
	if (card_pan == WRONG_PAN) {
		printf("wrong primary account number \n");
		exit(0);
	}

	EN_cardError_t card_date = getCardExpiryDate(&app_card);
	if (card_date == WRONG_DATE) {
		printf("wrong date \n");
		exit(0);
	}

	/****************************************************************************************************************************************/

	//Terminal logic


	
	
	 
	 EN_terminalError_t terminal_date = getTransactionDate(&app_terminal);
	if (terminal_date == WRONG_DATE) {
		printf("wrong date \n");
		exit(0);
	}



	

	EN_terminalError_t terminal_Card_Exp = isCardExpired(&app_card, &app_terminal);
	if (terminal_Card_Exp == EXPIRED_CARD) {
		printf("card expired \n");
		exit(0);
	}

	getTransactionAmount(&app_terminal);

	EN_terminalError_t terminal_max = setMaxAmount(&app_terminal, app_maxAmount);
	if (terminal_max == INVALID_MAX_AMOUNT) {
		printf("invalid max amount ");
		exit(0);
	}

	EN_terminalError_t terminal_below = isBelowMaxAmount(&app_terminal);
	if (terminal_below == EXCEED_MAX_AMOUNT) {
		printf("exceeded maximum amount \n");
		exit(0);
	}




	/***********************************************************************************************/
	ST_transaction_t app_server;
	app_server.cardHolderData = app_card;
	app_server.terminalData = app_terminal;

	//isCardExpired(&app_card, &app_terminal);
	//isBlockedAccount(&app_DB);

	/*EN_terminalError_t terminal_amount = isAmountAvailable(&app_terminal, &app_DB);
	if (terminal_amount == LOW_BALANCE) {
		printf("invalid amount \n");
		exit(0);
	}
*/
	
	//server logic 

		/*APPROVED,							//value of 0
		DECLINED_INSUFFECIENT_FUND,			//value of 1
		DECLINED_STOLEN_CARD,				//value of 2
		FRAUD_CARD,							//value of 3
		INTERNAL_SERVER_ERROR				//value of 4*/


	EN_serverError_t server_recieve = recieveTransactionData(&app_server);

	if (server_recieve == APPROVED) {
		printf("transaction approved  \n");
		exit(0);
	}

	if (server_recieve == DECLINED_INSUFFECIENT_FUND) {
		printf("sorry transaction  declined\n");
		exit(0);
	}
	if (server_recieve == DECLINED_STOLEN_CARD) {
		printf("error :	stolen card \n");
		exit(0);
	}

	if (server_recieve == FRAUD_CARD) {
		printf("Error fraud card \n");
		exit(0);
	}
	if (server_recieve == INTERNAL_SERVER_ERROR) {
		printf("try again later \n");
		exit(0);

	}

	
}


int main() {
/*
	getCardHolderNameTest();
	getCardExpiryDateTest();
	getCardPANTest();
	getTransactionDateTest();
	getTransactionAmountTest();
	setMaxAmountTest();
	isBelowMaxAmountTest();
	isCardExpriedTest();
	isValidAccountTest();
	isBlockedAccountTest();
	isAmountAvailableTest();
	saveTransactionTest();
	*/

	 appStart();



}
