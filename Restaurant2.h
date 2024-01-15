#ifndef RESTAURANT2_H 
#define RESTAURANT2_H
#include <iostream>
#include <string>
#include <cstdlib>
#define MAX 10
using namespace std;
class Record{       //Create a class called Record
	private :             //Declaration of the variables in class
	string custname;
	string phonenum;
	string date;
	int ID;
	int numofpax;	
	
   public :
   	    Record(){           //Preset record
			custname = "Elvis Yeoh";
   			phonenum = "016-4446789";
   			date = "12-04-2015";
   			ID = 20150412;
   			numofpax = 7;
		}

	   	Record(string cn, string pn, string d, int id, int pax){	//Declaration of the variables
			custname = cn;
	    	phonenum = pn;
	    	date = d;
	    	ID = id;
	    	numofpax = pax;
		}
		
	   	void setCustname(string cn){            
			custname = cn;
	  	}
	   
	   	void setPhonenum(string pn){
			phonenum = pn;
		}
		
	   	void setDate(string d){
			date = d;
	   	}
	   
		void setID(int id){
			ID = id;
		}

		void setNumofpax(int nop){
	   		numofpax = nop;
	   	}

	   	string getCustname(){
	   		return custname;
	   	}
	   
	   	string getPhonenum(){
	   		return phonenum;
	   	}

	   	string getDate(){
	   		return date;
	   	}
		
		int getID(){
			return ID;
		}
		
		int getNumofpax(){
			return numofpax;
		}
	   		 
		void display(){            //Display the customer's record
			cout <<  " Customer Name " << ":" << custname << endl
			<< " Phone Number  " <<  ":" << phonenum << endl
        	<< " Date          " <<  ":" << date << endl
    		<< " Number of pax " <<  ":" << numofpax << endl;
			cout <<"________________________________________________________________________________________________________________________\n"; 
	   } 
};

void nameBubbleSort(Record list[]){                 //This is a function used to sort the customer names from A-Z by using Bubble Sort
	int i, j;
	Record temp;
	for (i=0; i<MAX; i++){
		for (j=0; j<MAX-1; j++){
			if (list[j].getCustname() > list[j+1].getCustname()){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}	
	}
}

void dateBubbleSort(Record list[]){                 //This is a function used to sort the date from earliest to latest by using Bubble Sort
	int i, j;
	Record temp;
	for (i=0; i<MAX; i++){
		for (j=0; j<MAX-1; j++){
			if (list[j].getID() > list[j+1].getID()){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}	
	}
}

void pNoBubbleSort(Record list[]){                 //This is a function used to sort the phone number from smallest to biggest by using Bubble Sort
	int i, j;
	Record temp;
	for (i=0; i<MAX; i++){
		for (j=0; j<MAX-1; j++){
			if (list[j].getPhonenum() > list[j+1].getPhonenum()){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}	
	}
}

void paxBubbleSort(Record list[]){                 //This is a function used to sort the number of pax from smallest to biggest by using Bubble Sort
	int i, j;
	Record temp;
	for (i=0; i<MAX; i++){
		for (j=0; j<MAX-1; j++){
			if (list[j].getNumofpax() > list[j+1].getNumofpax()){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}	
	}
}

int pNoBinarySearch(Record list[], string search, int low, int high){      //This is a function used to search the phone number by using binary search
	int middle;
	while ( low <= high ) {
		middle = ( low + high ) / 2;
		if ( search == list[middle].getPhonenum() ) {
			return middle;
		}
		else if ( search < list[middle].getPhonenum() ) {
		    high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	return -1;
}

int nameBinarySearch(Record list[], string search, int low, int high){     //This is a function used to search the customer names by using binary search
	int middle;
	while ( low <= high ) {
		middle = ( low + high ) / 2;
		if ( search == list[middle].getCustname() ) {
			return middle;
		}
		else if ( search < list[middle].getCustname() ) {
		    high = middle - 1;
		}
		else { 
			low = middle + 1;
		}
	}
	return -1;
}

void displayGivenDate(Record list[], string date){             //This is a function used to display the record by given date
	int count=0;
	for (int i=0; i<MAX; i++){
		if (list[i].getDate() == date){
			list[i].display();
			count++;
		}
		else
			continue;
		}
	if (count==0){
		cout <<"________________________________________________________________________________________________________________________\n";
		cout <<"                                                        No Record."<<endl;
		cout <<"________________________________________________________________________________________________________________________\n";
	}
}

void displayGivenPax(Record list[], int pax){                //This is a function used to display the record by given number of pax
	int count=0;
	for (int i=0; i<MAX; i++){
		if (list[i].getNumofpax() == pax || list[i].getNumofpax() > pax){
			list[i].display();
			count++;
		}
		else
			continue;
	 	}
	if (count==0){
		cout <<"________________________________________________________________________________________________________________________\n";
		cout <<"                                                        No Record"<<endl;
		cout <<"________________________________________________________________________________________________________________________\n";
	}
}

bool onlyNum (string st){										//function for checking string contains number only
	int slength = st.length();
	for (int i=0; i<slength; i++){
		int s = st[i];
		if (!isdigit(s))
			return false;
	}
return true;
}

#endif
