#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_
#define MAX_ACCOUNTS 20


struct account{
  char *name;
  float balance;
  int in_session;
  int index;
};
typedef struct account* AccountPtr;

struct account_storage{
  int last_account_index;
  int threads[MAX_ACCOUNTS];
  AccountPtr accounts[MAX_ACCOUNTS];
};
typedef struct account_storage* AccountStoragePtr;

AccountPtr accountGet(char *accountname, AccountStoragePtr collection);

//-account create
AccountPtr accountCreate(char* name, AccountStoragePtr all_accounts);

void destroyAccount(AccountPtr account);
//-account query
float accountGetBalance(int thread, AccountStoragePtr all_accounts);

//-account deposit
//deposit should change account balance and return 0 for failure 1 for success
int accountDeposit(int thread, float amount, AccountStoragePtr all_accounts);

//withdraw should change account balance and return 0 for failure 1 for success
int accountWithdraw(int thread, float amount, AccountStoragePtr all_accounts);

// print account details
void accountPrint(AccountPtr account);

void printAccounts(AccountStoragePtr bank);

int accountServe(int thread, char* account_name, AccountStoragePtr all_accounts);

void accountEndConnection(int thread, AccountStoragePtr all_accounts);

AccountPtr getThreadAccount(int thread, AccountStoragePtr all_accounts);
#endif
