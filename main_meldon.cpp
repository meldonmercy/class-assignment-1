#include <iostream>
#include <string>
using namespace std;
class BankAccount{
	private:
		int accountNumber;
		string accountHolder;
		double balance;
		
	public:
		//constructor using initilizer list
	BankAccount(int accNum,string holder,double bal)
	    :accountNumber(accNum), accountHolder(holder), balance(bal){
		}
		//deposit money
void deposit(double amount){
	if(amount>0){
		balance+=amount;
		cout<<"Deposit successful:"<<amount<<endl;
		cout<<"updated Balance:"<<balance<<endl;
	}
	else {
		cout<<"Invalid deposit amount!"<<endl;
	}
}
// withdraw amount
void withdraw(double amount){
	if(amount<=0){
		cout<<"Invalid withdrawal amount!"<<endl;
	}
	else if(amount>balance){
		cout<<"Withdrawal Failed:Insuffcient funds."<<endl;
	}
	else{
		balance-=amount;
		cout<<"Withdrawal successful:"<<amount<<endl;
		cout<<"Remaining Balance:"<<balance<<endl;
	}
}
//diplay account details
void displayAccount()const{
cout<<"\nAccount Detail"<<endl;	
cout<<"Account Number:"<<accountNumber<<endl;
cout<<"Account Holder:"<<accountHolder<<endl;
cout<<"Balance:"<<balance<<endl;
cout<<"----------------------------"<<endl;
}
//Getter for balance
double getBalance()const{
return balance;
}
};


int main(int argc, char** argv) {
	//Creating two accounts
	BankAccount account1(101,"John",5000);
	BankAccount account2(102,"Mary",3000);
	
	// Display initial accounts
	cout<<"Initial Account Information\n";
	account1.displayAccount();
	account2.displayAccount();
	
	cout<<"\n--- Transactions ---\n";
	// Transactions
	account1.deposit(1000);
	account1.withdraw(2000);
	
	account2.deposit(500);
	account2.withdraw(4000);//should fail
	
	// Display final accounts
	cout<<"\nFinal Account Information\n";
	account1.displayAccount();
	account2.displayAccount();
	
	return 0;

	
}
