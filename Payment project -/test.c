#include <stdio.h>
#include <string.h>
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Card/card.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Terminal\terminal.h"
#include "Z:\AAST\Embeded\FWD\tasks\C project\Payment project\Server\server.h"
#include <ctype.h>
#include"Z:\AAST\Embeded\FWD\tasks\C project\Payment project\types.h"


//structere
ST_cardData_t z_card;
ST_terminalData_t z_terminal;
ST_accountsDB_t z_DB;
ST_transaction_t z_server;
float test_maxAmount =1000.0;

//card Functions 
void getCardHolderNameTest(void) {
	printf("tester name is zeyad ibrahim \n");
	printf("function name is getCardHolderName \n");
	printf("input data is zeyad ibrahim sadek case 1  \n");
	printf("exepected result wrong name = 0\n ");
	printf("actual value is %d \n", getCardHolderName(&z_card));

	printf("**************   END OF FUNCTION  **************************\n");


}
void getCardExpiryDateTest(void) {
	
	printf("tester name is zeyad ibrahim \n");
	printf("function name is void getCardExpiryDate\n");
	printf("input data is 05/23 case 2 \n");
	printf("exepected result card ok  = 0 \n ");
	printf("actual result is %d \n", getCardExpiryDate(&z_card));
	printf("**************   END OF FUNCTION  **************************\n");
}
void getCardPANTest(void) {

	printf("tester name is zeyad ibrahim \n");
	printf("function name is void getCardPAN\n");
	printf("input data is 1234567891012345 case 0 \n");
	printf("exepected result  = 0\n ");
	printf("actual result is %d \n", getCardPAN(&z_card));
	printf("**************   END OF FUNCTION  **************************\n");


}


//Terminal Functions
void getTransactionDateTest(void) {
	printf("tester name is zeyad ibrahim \n");
	printf("function name is getTransactionDate\n");
	printf("input data is 05/23 \n");
	printf("exepected result  = 0 \n ");
	printf("actual result is %d \n", getTransactionDate(&z_terminal));
	printf("**************   END OF FUNCTION  **************************\n");

}
void getTransactionAmountTest(void) {
	printf("tester name is zeyad ibrahim \n");
	printf("function name is getTransactionAmount\n");
	printf("input data is 200 \n");
	printf("exepected result  =  0 \n ");
	printf("actual result is %d \n", getTransactionAmount(&z_terminal));
	printf("**************   END OF FUNCTION  **************************\n");


}
void setMaxAmountTest(void) {
	printf("tester name is zeyad ibrahim \n");
	printf("function name is setMaxAmount\n");
	printf("input data is 1000 \n");
	printf("exepected result  = 0\n ");
	printf("actual result is %d \n", setMaxAmount(&z_terminal, test_maxAmount));
	printf("**************   END OF FUNCTION  **************************\n");
}
void isBelowMaxAmountTest(void){
	printf("tester name is zeyad ibrahim \n");
	printf("function name is isBelowMaxAmount \n");
	printf("input data is 1000 \n");
	printf("exepected result  = 0 \n ");
	printf("actual result is %d \n", isBelowMaxAmount(&z_terminal));
	printf("**************   END OF FUNCTION  **************************\n");


}
void isCardExpriedTest(void) {

	printf("tester name is zeyad ibrahim \n");
	printf("function name is void getCardExpiryDate\n");
	printf("input data is 05/23 & 21/05/2024  \n");
	printf("exepected result not expired= 0\n ");
	printf("actual result is %d \n", isCardExpired (&z_card ,&z_terminal) );
	printf("**************   END OF FUNCTION  **************************\n");


}

//Server Functions
void isValidAccountTest(void){
	printf("tester name is zeyad ibrahim \n");
	printf("function name is void isValidAccount\n");
	printf("input data is 8989374615436851  \n");
	printf("exepected result  = 0\n ");
	printf("actual result is %d \n", isValidAccount(&z_card,&z_DB));
	printf("**************   END OF FUNCTION  **************************\n");
}
void isBlockedAccountTest(void) {
	printf("tester name is zeyad ibrahim \n");
	printf("function name is void isBlockedAccount\n");
	printf("input data is blocked  \n");
	printf("exepected result   = 0\n ");
	printf("actual result is %d \n", isBlockedAccount(&z_DB));
	printf("**************   END OF FUNCTION  **************************\n");
}
void isAmountAvailableTest(void) {
	/*z_server.cardHolderData.cardExpirationDate = {0,5, / ,2,3};
	 z_server.terminalData;
	 z_server transState;
	 z_server transactionSequenceNumber;*/ 
	printf("tester name is zeyad ibrahim \n");
	printf("function name is void isAmountAvailable\n");
	printf("input data is 200  \n");
	printf("exepected result server ok = 0\n ");
	printf("actual result is %d \n", isAmountAvailable(&z_terminal ,&z_DB));
	printf("**************   END OF FUNCTION  **************************\n");
}

void saveTransactionTest(void) {

	printf("tester name is zeyad ibrahim \n");
	printf("function name is saveTransactionTest\n");
	printf("input data is 500000  \n");
	printf("exepected result server ok = 0\n ");
	printf("actual result is %d \n", saveTransaction(&z_server));
	printf("**************   END OF FUNCTION  **************************\n");
}
void listSavedTransactionsTest(void) {

	printf("tester name is zeyad ibrahim \n");
	printf("function name is void listSavedTransactions\n");
	listSavedTransactions();
	printf("**************   END OF FUNCTION  **************************\n");
}




void recieveTransactionDataTest(void) {
	printf("tester name is zeyad ibrahim \n");
	printf("function name is void isAmountAvailable\n");
	printf("input data is 500000  \n");
	printf("exepected result server ok = 0\n ");
	printf("actual result is %d \n", recieveTransactionData (&z_server));
	printf("**************   END OF FUNCTION  **************************\n");
}

/*

int main() {

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
	recieveTransactionDataTest();
	z_server.cardHolderData = z_card;
	z_server.terminalData = z_terminal;
	saveTransactionTest();
	listSavedTransactionsTest();


}
*/