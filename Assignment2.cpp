#include "Restaurant2.h"
int main(){
	int pax, choice;                               //Declaration of the variables
	string pno, name, date, tempChoice, tempPax;
	int key = -1;
	
	Record list[MAX];
	list[0] = Record("Jean" , "016-4585874" , "12-02-2019", 20190212, 12);      //Premade records
	list[1] = Record("Timmy", "012-1237890" , "23-07-2018", 20180723, 23);
	list[2] = Record("John", "017-1234567", "28-05-2001", 20010528, 34);
	list[3] = Record("Andrewn", "012-2345678", "20-02-1990",19900220, 3);
	list[4] = Record("Yong", "012-3456789", "28-12-2019", 20191228, 119);
	list[5] = Record("Jonathan", "014-2323234", "12-02-2019", 20190212, 3); 
	list[6] = Record("George", "016-1234567", "20-02-1990", 19900220, 23); 
	list[7] = Record("Winston", "018-9876543", "13-01-2000", 20000113, 23); 
	list[8] = Record("Alicia", "019-4343222", "20-02-1990", 19900220, 12);
	list[9] = Record("Will Smith", "012-3543542", "20-02-1990", 19900220, 30);
	
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";   //Design of program
	cout << "                                     WELCOME TO RESTAURANT RESERVATION SYSTEM!!!\n\n";                                                  
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	
	do{
		cout <<"Choice 1: Display all reservation records."<<endl                            //Let user to choose the choices
		<<"Choice 2: Display all reservation records sorted by customer name."<<endl
		<<"Choice 3: Display all reservation records sorted by date."<<endl
		<<"Choice 4: Search reservation record by customer's phone number."<<endl
		<<"Choice 5: Search reservation record by customer name."<<endl
		<<"Choice 6: Display all records in given date."<<endl
		<<"Choice 7: Display all records in given number of pax."<<endl
		<<"Choice 8: Quit the program."<<endl
		<<"Input: ";
		getline(cin,tempChoice);
		choice = atoi(tempChoice.c_str());

		if (choice == 1){                            //Choice 1 is to display the records
			cout <<"************************************************************************************************************************\n";
			cout<<"                                                Reservation Records"<<endl<<endl;
			cout <<"************************************************************************************************************************\n";
			for (int i=0; i<MAX; i++)
				list[i].display();
		}
		
		else if (choice == 2){                       //Choice 2 is to display the records sorted by customer name
			cout <<"************************************************************************************************************************\n";
			cout<<"                                         Reservation Records (Name Sorted)"<<endl<<endl;
			cout <<"************************************************************************************************************************\n";
			nameBubbleSort(list);
			for (int i=0; i<MAX; i++)
				list[i].display();
		}
		
		else if (choice == 3){                       //Choice 3 is to display the records sorted by date
			cout <<"************************************************************************************************************************\n";
			cout<<"                                         Reservation Records (Date Sorted)"<<endl<<endl;
			cout <<"************************************************************************************************************************\n";
			dateBubbleSort(list);
			for (int i=0; i<MAX; i++)
				list[i].display();
		}
		
		else if (choice == 4){                       //Choice 4 is to let the user to search and display the specific record by using phone number
			pNoBubbleSort(list);
			cout <<"________________________________________________________________________________________________________________________\n";
			cout<<"Enter customer's phone number: ";
			getline(cin, pno);
			key = pNoBinarySearch(list, pno, 0, MAX-1);
			if (key != -1){
				cout <<"________________________________________________________________________________________________________________________\n";
				list[key].display();
			}
			else{
				cout <<"________________________________________________________________________________________________________________________\n";
				cout <<"                                                       No Record."<<endl;
				cout <<"________________________________________________________________________________________________________________________\n";
			}
		}
		
		else if (choice == 5){                       //Choice 5 is to let the user to search and display the specific record by using customer name
			nameBubbleSort(list);
			cout <<"________________________________________________________________________________________________________________________\n";
			cout<<"Enter customer name: ";
			getline(cin, name);
			key = nameBinarySearch(list, name, 0, MAX-1);
			if (key != -1){
				cout <<"________________________________________________________________________________________________________________________\n";
				list[key].display();
			}
			else{
				cout <<"________________________________________________________________________________________________________________________\n";
				cout <<"                                                       No Record."<<endl;
				cout <<"________________________________________________________________________________________________________________________\n";
			}
		}
		
		else if (choice == 6){                       //Choice 6 is to let the user to enter a date and display all records with same date
			cout <<"________________________________________________________________________________________________________________________\n";
			cout<<"Enter given date: ";
			getline(cin, date);
			cout <<"________________________________________________________________________________________________________________________\n";
			displayGivenDate(list, date);
			cout<<endl;
		}
		
		else if (choice == 7){                       //Choice 7 is to let the user to enter number of pax and display all records that have at least the given number of pax.
			paxBubbleSort(list);
			cout <<"________________________________________________________________________________________________________________________\n";
			cout<<"Enter given number of pax: ";
			getline(cin, tempPax);
			pax = atoi(tempPax.c_str());
			
			if (!onlyNum(tempPax)){
				cout <<"________________________________________________________________________________________________________________________\n";
				cout <<"                                                        No Record"<<endl;
				cout <<"________________________________________________________________________________________________________________________\n";
			}
			else{
				cout <<"________________________________________________________________________________________________________________________\n";
				displayGivenPax(list, pax);
				cout<<endl;
			}
		}
		
		else if (choice == 8){                       //Choice 8 is to let the user to quit the program
			cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
			cout<<"                                                     HAVE A NICE DAY!!!"<<endl<<endl;
			cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		}
		
		else{                       //If the user inputs wrong choices, it will display an error messages
			cin.clear();
			cout <<"________________________________________________________________________________________________________________________\n";
			cout<<"                                              Invalid input. Please try again."<<endl;
			cout <<"________________________________________________________________________________________________________________________\n";
		}
	}while (choice != 8);	 //It repeats until the user inputs 8 to end the loop
	system("pause");
	return 0;
}
