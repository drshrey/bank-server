#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_
#define MAX_ACCOUNTS 20


struct account{
  char *name;
  float balance;
  int in_session;
};
typedef struct account* Account;

struct account_storage{
  Account[MAX_ACCOUNTS] accounts;
};
typedef struct account_storage* AccountStorage;

AccountPtr get_account(char *accountname);

//-account create
AccountPtr AccountCreate(char* name, int index);

//-account query
float getBalance(AccountPtr account);

//-account deposit
//deposit should change account balance and return 0 for failure 1 for success
int deposit(float amount, AccountPtr account);

//withdraw should change account balance and return 0 for failure 1 for success
int withdraw(float amount, AccountPtr account);

void PrintAccount(AccountPtr account);

#endif
