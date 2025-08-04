#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;
class player{
	public :
	int balance =0,coin=0,betswon=0,betslost=0,totalplay=0;
};
player addbalance(player p1){
	int deposit;
	do{

	cout<<" BALANCE :"<<p1.balance<<endl;
		cout<<" how much ammount youwant to deposit:";
		cin>>deposit;
		if(deposit<0){
			cout<<" insufficient deposit .TRY AGAIN."<<endl;
		}
	}while(deposit<0);
p1.balance+=p1.balance+deposit;
cout<<" your current balance is :"<<p1.balance<<endl;
return p1;
}
player buycoin(player p1){
 
	int coinsbuy;
	
	do{
	
	cout<<" BALANCE :"<<p1.balance<<endl;
	cout<<" COINS   :"<<p1.coin<<endl;
	cout<<" how many coins would you like to buy(each costs 3 rupee):";
	cin>>coinsbuy;
	if(p1.balance/(coinsbuy*3)<0){
		cout<<" insufficient balance . TRY AGAIN."<<endl;
	}
	}while(p1.balance/(coinsbuy*3)<0);
	
	p1.coin+=coinsbuy;
		p1.balance=p1.balance-coinsbuy*3;
	cout<<"TOTAL COINS :"<<p1.coin<<endl;
	
	return p1;
}
player placebet( player p1){
	

	int option,randomnum,leverage,coinsbet,num;
	char choice;
	 do{
	
	cout<<"press 1 to  guess a number between 1-2 (leverage 2x): "<<endl;
	cout<<" press 2 to guess a number between 1-10 (leverage 10x) :"<<endl;
	cout<<" press 3 to guess a number between 1-100 ( leverage 100x) :"<<endl;
	cin >>option;
	
	switch(option){
		case 1:
			randomnum=1+rand()%2;
			leverage=2;
				cout<<" coin :"<<p1.coin<<" how much would  you like to bet :";
	cin>>coinsbet;
	cout<<" guess a number between 1-2 :";
	cin>>num;
			break;
			case 2 :
				randomnum=1+rand()%10;
				leverage=10;
				cout<<" coin :"<<p1.coin<<" how much would  you like to bet :";
	cin>>coinsbet;
	cout<<" guess a number between 1-10:";
	cin>>num;
				break ;
				case 3 :
					randomnum=1+rand()%100;
					leverage=100;
					cout<<" coin :"<<p1.coin<<" how much would  you like to bet :";
	cin>>coinsbet;
	cout<<" guess a number between 1-100 :";
	cin>>num;
					break;
			
	}
	if(num==randomnum){
		cout<<" you won  :"<<coinsbet<<endl;
		switch(option){
			case 1:
				p1.coin+=coinsbet;
				break;
				case 2 :
					p1.coin+=coinsbet*9;
					break;
					case 3 :
						p1.coin+=coinsbet*99;
						break;
		}
		cout<<" TOTAL COINS :"<<p1.coin;
		p1.betswon++;
	}
	else{
		cout<<" you lost :"<<coinsbet<<endl;
		p1.coin-=coinsbet;
		cout<<" remaining coins :"<<p1.coin;
		p1.betslost--;
	}
	p1.totalplay++;
	cout<<" do you want to place more bets (y/n)"<<endl;

	
	cin>>choice;
}while(choice=='Y'||choice=='y');

return p1;


}
player statistics(player p1){

	cout<<" TOTAL PLAY :"<<p1.totalplay<<endl;
	cout<<" BETSWON :"<<p1.betswon<<endl;
	cout<<" BETS LOST :"<<p1.betslost<<endl;
	cout<<" WIN PERCENTAGE :"<<(p1.betswon/p1.totalplay)*100<<endl;
	
	return p1;}
	player withdraw(player p1){
		char conversion;
		int coinsconvert;
		string accnum;
		int withdraw;
		cout<<" BALANCE :"<<p1.balance<<endl;
		cout<<" COINS   :"<<p1.coin<<endl;
		cout<<" would you like to convert the coins before withdrawal(y/n) :";
		cin>>conversion;
		if(conversion=='Y'||conversion=='y'){
			do{			
			cout<<" how many coins would you like to convert :";
			cin>>coinsconvert;
			if(coinsconvert>p1.coin){
				cout<<" insufficient coins try again"<<endl;
			}
	}while(coinsconvert>p1.coin);
	p1.balance+=coinsconvert*3;
	p1.coin-=coinsconvert;
		}
		do{
		
		cout<<" enter your account  number :";
		cin>>accnum;
		if(accnum.size()<8||accnum.size()>17){
			cout<<" tryagain ."<<endl;
		}	}while(accnum.size()<8||accnum.size()>17);
		do{
		
		cout<<" how much you want to withdraw:";
		cin>>withdraw;
		if(withdraw>p1.balance){
			cout<<"insufficinet balance .TRY AGAIN"<<endl;
		}}
		while(withdraw>p1.balance);
		cout<<" you have successfully withdrawn "<<withdraw<<" Rs in your account . "<<endl;
		p1.balance-=withdraw ;
		cout<<" REMAINING BALANCE :"<<p1.balance<<endl;
		return p1;
	}
int main(){
	player p1;
	int option;
	do{
	
	cout<<" welcome to betting app :"<<endl;
	cout<<" BALANCE :"<<p1.balance<<endl;
	cout<<" COINS :"<<p1.coin<<endl;
	cout<<" press 1 to add balance ."<<endl;
	cout<<" press 2 to buy coins ."<<endl;
	cout<<" press 3 to  bet ."<<endl;
	cout<<" press 4 to view statistics ."<<endl;
	cout<<" press 5 to withdraw ."<<endl;
	cout<<" press 6 to exit ."<<endl;
	cin>>option;
	switch(option){
		case 1:
			 p1=addbalance(p1);
			break;
			case 2 :
				p1=buycoin(p1);
				break;
				case 3 :
					p1=placebet(p1);
					break;
					case 4 :
						p1=statistics(p1);
						break;
						case 5:
							p1=withdraw(p1);
							break;
						
	}
	}while(option!=6);
	
	return 0;
}

