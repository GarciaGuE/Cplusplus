#include <iostream>
#include <vector>
#include "dice.h"

using namespace std;


int main(){
	Dice d;
	int opt=0, dado=0;		
	int v[5];					
	while(opt!=14){			
		switch(opt){			
			case 1:	
				d.roll();
				cout<<"Dice are rolled"<<endl;
			break;

			case 2:	
				cout<<"Die 1: "<<d.getDie1()<<endl;
			break;
			
			case 3:	
				cout<<"Die 2: "<<d.getDie2()<<endl;
			break;

			case 4:	
				cout<<"Addition: "<<d.getAdd()<<endl;
			break;
				
			case 5: 
				cout<<"Difference: "<<d.getDiff()<<endl;
			break;

			case 6:	
				cout<<"Write value of die 1"<<endl;
				cin>>dado;
				if(d.setDie1(dado)==false)
					cout<<"Value denied"<<endl;
			break;

			case 7: 
				cout<<"Write value of die 2"<<endl;
				cin>>dado;
				if(d.setDie2(dado)==false)
					cout<<"Value denied"<<endl;
			break;

			case 8:
				cout<<"Average die 1: "<<d.getAvg1()<<endl;			
			break;

			case 9:
				cout<<"Average die 2: "<<d.getAvg2()<<endl;
			break;	

			case 10:
				cout<<"Rolls and changes in die 1: "<<d.getRolls1()<<endl;
			break;

			case 11: 
				cout<<"Rolls and changes in die 2: "<<d.getRolls2()<<endl;
			break;

			case 12:
				d.getLast1(v);
				cout<<"Last values of die 1: "<<endl;
				for(int i=0; i<5; i++)
        			cout<<"["<<i<<"]: "<<v[i]<<endl;  
			break;

			case 13:
				d.getLast2(v);
				cout<<"Last values of die 2: "<<endl;
				for(int i=0; i<5; i++)
        			cout<<"["<<i<<"]: "<<v[i]<<endl;
			break;

			default:
			break;

		}

		//Menu
		cout<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"Select an option:"<<endl;
		cout<<"		1. Roll dice"<<endl;
		cout<<"		2. Get Die 1"<<endl;
		cout<<"		3. Get Die 2"<<endl;
		cout<<"		4. Get Dice's Addition"<<endl;
		cout<<"		5. Dice Difference"<<endl;	
		cout<<"		6. Change Die 1"<<endl;
		cout<<"		7. Change Die 2"<<endl;
		cout<<"		8. Get Average Die 1"<<endl;
		cout<<"		9. Get Average Die 2"<<endl;
		cout<<"		10. Get Rolls Die 1"<<endl;
		cout<<"		11. Get Rolls Die 2"<<endl;
		cout<<"		12. Get Last Values Die 1"<<endl;
		cout<<"		13. Get Last Values Die 2"<<endl;
		cout<<"		14. Exit"<<endl;
		cout<<"Option: ";
		cin>>opt;
	}
	return 0;
}