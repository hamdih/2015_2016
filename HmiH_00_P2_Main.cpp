// Professor Burke
// 10/19/15
// Purpose: This Program will represent a address book, with a add,remove,search, and a print functionality.
// This Program also furthers the understanding of linked lists and File I/O;  
//	
//  HmiH_00_P2_Main.cpp
//  Program2
//
//  Created by Hamdi Hmimy on 9/28/15.
//  Copyright © 2015 Hamdi Hmimy. All rights reserved.
//
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

class student{				//class that holds students and his information
    friend class students;
    friend class children;
    private:
    string name;       // Full name of student, First and Last
    student *spouse;		// pointer to spouse
    student *child;		// pointer to children
    student *child2;
    student *child3;	
    student *next;
    string spousename;
    int id;
    string ID;
	
    string address;
    string city;
    string st;
    string zip;
    string dob;	// date of birth
    string dod;	// date of death
    string dow;	// date of wedding
    			// the pointer to the node for the linked list
     public:
    
    student(string nm,int num){
	name = nm;
	id = num;
	spouse = NULL;
	child = NULL;
 	child2 = NULL;
	child3 = NULL;
	 }



    
    string getID(){return ID;}	
    string getAdress(){return address;}
    string getCity(){return city;}
    string getSt(){return st;}
    string getZip(){return zip;}
    string getDob(){return dob;}
    string getDod(){return dod;}
    string getDow(){return dow;}
    int getId(){return id;} 
    student *getSpouse(){return spouse;}  
   	 
    string getSpouseName(){return spousename;}
    student *getChild(){return child;}
    string getName(){return name;}
    student *getNext(){return next;}
   // void setChild(string child1){child = child1;}	
    void setName(string name1){name = name1;}
    void setAdd(string addy){address = addy;}
    void setCity(string city1){city = city1;}
    void setSt(string street){st = street;}
    void setdob(string birth){dob = birth;}
    void setdod(string death){dod = death;}
    void setdow(string wedding){dow = wedding;}
    void setzip(string zip1){zip = zip1;}
    void setNext(student *n){next = n;}
    //void setNextChild(student *c){child = c;}
    void setSpouseName(string spouse2){spousename = spouse2;}

};
    


class students{					// class of students that will rerepresent the linked list
     private:
            int count;
     public:
	    student *curr;
            student *head;
     	    student *tail;
	//    child *top;	
        //    child *bottom;
	    students()
	    {
	
          	count = 0;
         	head = tail= curr = NULL;
	    }	
void addAddress(string uid, string addy)		// add address to person
{
	student *now = head;
	while(now != NULL)
	{

		if(now->getID() == uid)
		{
		now->address = addy;
		cout<<"ADDED ADDRESS:"<<addy<<" UID: "<<uid<<endl;
		return;
		}
	now = now->getNext();
	}


};
void addZip(string uid, string zippy) 	//add zip to person
{
	student *now = head;
	while(now != NULL)
	{

		if(now->getID() == uid)
		{
		now->zip = zippy;
		cout<<"ADDED ZIP:"<<zippy<<" UID: "<<uid<<endl<<endl;
		return;
		}
	now = now->getNext();
	}


};
void addDateob(string uid, string dob1)		//add Date of birth to person
{
	student *now = head;
	while(now != NULL)
	{

		if(now->getID() == uid)
		{
		now->dob = dob1;
		cout<<"ADDED BIRTHDAY:"<<dob1<<" UID: "<<uid<<endl;
		return;
		}
	now = now->getNext();
	}


};
void addDeath(string uid, string death)		//add date of death to person
{
	student *now = head;
	while(now != NULL)
	{

		if(now->getID() == uid)
		{
		now->dod = death;
		cout<<"ADDED DATE of Death:"<<death<<" UID: "<<uid<<endl;
		return;
		}
	now = now->getNext();
	}


};
void addWedding(string uid, string wedding)		//add wedding of person and spouse
{
	student *now = head;
	while(now != NULL)
	{

		if(now->getID() == uid)
		{
		now->dow = wedding;
		now->spouse->dow = wedding;
		cout<<"ADDED WEDDING DAY:"<<wedding<<" UID: "<<uid<<endl;
		return;
		}
	now = now->getNext();
	}


};
void addCity(string uid, string city1)		//add city to person
{
	student *now = head;
	while(now!=NULL)
	{
		if(now->getID() == uid)
		{
		now->city = city1;
		cout<<"ADDED CITY:"<<city1<<" UID: "<<uid<<endl;
		return;
		}
	now = now->getNext();
	}



};
void addState(string uid, string state)		// add state of person
{
	student *now = head;
	while(now!=NULL)
	{
		if(now->getID() == uid)
		{
		now->st = state;
		cout<<"ADDED STATE:"<<state<<" UID: "<<uid<<endl;
		return;
		}
	now = now->getNext();
	}
};
void addChild(string uid, string childName)	//add child as person and as child to person
{
	ostringstream oss;	
	student *now = head;
	student *end = tail;
	int i;
	while(now != NULL)
	{

			if(now->getName() == childName)
			{
			cout<< "DUPLICATE:"<<childName<<endl;
			return;
			}
	now = now->getNext();
	}
	int id =1 ;	
	string nm = childName;
	student *temp,*temp2;
	id = id+count;
	cout<<"Added: ID "<<setfill('0')<<setw(3)<<id<<" "<<nm<<endl;
	temp2 = head;
	temp = new student(nm,id);
	oss<<"ID00"<<id;
	string temps = oss.str();
	temp->ID = temps;

	if(head == NULL)
	{
	head = tail = temp;
	temp->setNext(NULL);
	count++;
	}	

	else
	{
	tail->setNext(temp);
	tail=temp;
	temp->setNext(NULL);
	count++;

	}
		student *here = head;
		student *found = NULL;
		student *before = head;
		while(here != NULL)
			{
				
				if (uid == here->getID())
				{
					if(here->child == NULL)
					{
					here->child = temp;
					here->spouse->child = temp;	
					return;
					}	
					else if(here->child2 == NULL)
					{
					here->child2 = temp;
					here->spouse->child2 = temp;
					return;
					}
					else 
					{
						here->child3 = temp;
						here->spouse->child3 = temp;
						return;
					}
				}
			else
			before = here;
			here = here->getNext();
			}



};
void addSpouse(string uid,string spouse1)  //add spouse as person and as spouse to person
	{	
	ostringstream oss;
	student *now = head;
	student *end = tail;
	int i;
	while(now != NULL)
	{

			if(now->getName() == spouse1)
			{
			cout<< "DUPLICATE:"<<spouse1<<endl;
			return;
			}
	now = now->getNext();
	}
	
	string nm = spouse1;
	int id = 1;
	student *temp,*temp2;
	id = id+count;
	cout<<"Added: ID "<<setfill('0')<<setw(3)<<id<<" "<<nm<<endl;
	temp2 = head;
	temp = new student(nm,id);
	oss<<"ID00"<<id;
	string temps = oss.str();
	temp->ID = temps;

	if(head == NULL)
	{
	head = tail = temp;
	temp->setNext(NULL);
	count++;
	}	

	else
	{
	tail->setNext(temp);
	tail=temp;
	temp->setNext(NULL);
	count++;

	}
		
		student *here = head;
		student *found = NULL;
		student *before = head;
		while(here != NULL)
			{
				if (uid == here->getID())
				{
				here->spouse = temp;
				temp->spouse = here;
				return;	
				}
			else
			before = here;
			here = here->getNext();
			}


};
void add(string data)		//this function will add a student to the linked list
	{
	ostringstream oss;
	student *now = head;
	student *end = tail;
	int i;
	while(now != NULL)
	{

			if(now->getName() == data)
			{
			cout<< "DUPLICATE:"<<data<<endl;
			return;
			}
	now = now->getNext();
	}
	
	string nm = data;
	int id = 1;
	student *temp,*temp2;
	id = id+count;
	cout<<"Added: ID "<<setfill('0')<<setw(3)<<id<<" "<<nm<<endl;
	temp2 = head;
	temp = new student(nm,id);
	oss<<"ID00"<<id;
	string temps = oss.str();
	temp->ID = temps;
	
	if(count == 0)
	{
	head = tail = temp;
	temp->setNext(NULL);
	count++;
	}	

	else
	{
	tail->setNext(temp);
	tail=temp;
	temp->setNext(NULL);
	count++;

	}
	
};	


		
	
	
/*	void remove(string pick)	//this function will remove a student from the linked list based on the name picked
	{

	student *curr = head;	
	student *before = head;
	student *here = NULL;
	while(curr!=NULL)

		{

		if(pick == curr->getName())
			{
				if(curr == head)
					{	
						curr= head;
						head = curr->getNext();			//if the student is at the head
						
						delete here;	
						cout<<"Removal Succesfull:"<<pick;
						count--;
						return;
					}
				before->next = curr->next;			// if the student is a node after the head
				if(curr == tail)
				tail = before;
				
				delete curr;
				cout<<"Removal Sucessful:"<< pick;
				count--;
				return;
			}			
			before = curr;						// point at next student
			curr = curr->getNext();	
			

		}
		cout<<"ERROR:Not Found for Removal:"<<pick;
	};*/
void printpeople() 	// this function will print all the students name and IDs in the linked list
	{
	int i;
	student *now = head;
	//student *end = tail;
	//student *test = now->getNext();
	if(count==0)						// to see if there is a node
	{
		cout<<"NO NAMES IN LIST"<<endl;
		
	}
	

	for(i = 0;i<count;i++)				// loop through each node and print the student
		{
		cout<<"ID:"<<" "<<setfill('0')<<setw(3)<<now->getId();
		cout<<" "<<now->getName()<<endl;
		now = now->getNext();
		//cout<<"Child 1: "<<now->child->getName();
		}
	cout<<endl;
	
};
void Print(string data)
{
student *now = head;
student *end = tail;
//string str1 (now->getID());
//string str2 (data);
if (now == NULL)
	{
	cout<<"NO NAMES IN LIST";
	}
while( now != NULL)
	{
		if(now->getID() == data)
			{
				cout<<"ID:"<<" "<<now->getID()<<endl;
				cout<<"NAME:"<<now->getName()<<endl;
				cout<<"ADDRESS1:"<<now->getAdress()<<endl;
				cout<<"CITY:"<<now->getCity()<<endl;
				cout<<"STATE:"<<now->getSt()<<endl;
				cout<<"ZIP:"<<now->getZip()<<endl;
				cout<<"Date_Birth:"<<now->getDob()<<endl;
				cout<<"Date_death:"<<now->getDod()<<endl;
				cout<<"Date_wedding:"<<now->getDow()<<endl;
				if(now->spouse == NULL)
				{
				cout<<"Spouse: None"<<endl;
				}
				else
				{
				cout<<"Spouse:"<<now->spouse->getName()<<endl;
				}
				if(now->child == NULL)
				{
				cout<<"Child: None"<<endl;
				}	
				else
				cout<<"Child1:"<<now->child->getName()<<endl;
				if(now->child2 != NULL)
				cout<<"Child2:"<<now->child2->getName()<<endl;
				if(now->child3 != NULL)
				cout<<"Child3:"<<now->child3->getName()<<endl;
			cout<<endl<<endl;
			return;
			}
		else
		now = now->getNext();
			
	}


};
void abc(){					// this function will alphabatize all the students after adding them
	int i;
	for(i = 0;i<(count);i++)
	{
	student *now = head;				
	student *next = head->getNext();		// set up pointers to be compared
	string temp1,temp2;
	if(now->getNext() == NULL)
	{
	return;
	}
	else
		{	
		while(now!= NULL)
			{
			temp1 = now->getName();			// set pointers to newly added student
			temp2 = next->getName();
	
		if(temp1 > temp2)			// compare and change
			{
				now->setName(temp2);
				next->setName(temp1);
			
			}
		if(next->getNext() != NULL)
		{
			next = next->getNext();
		}				// keep looping through students to alphabatize
		now = now->getNext();
			}
		}
	}
};



void search(string find) 	// this function will search for a student in the linked list based on their name
	{
		student *now = head;
		student *found = head->getNext();
		student *before = head;
		student *here = NULL;
		while(now != NULL)				
		{
			if( find == now->getName())	// compare student name to searching name
			{
			cout<<"FOUND:"<<""<<now->getName()<<" "<<"UID:"<<now->getID();
			return;
			}
			else
			before = now;
			now= now->getNext();		
	
		}
			cout<<"NOT FOUND:"<<""<<find;
};

/*void child(int uid,string child1)
{

	        student *now = head;
		student *found = head->getNext();
		student *before = head;
		student *here = NULL;
		while(now != NULL)
			{
				if (uid == now->getId())
				{
				//now->setChild(child1);	
				return;	
				}
			else
			before = now;
			now = now->getNext();
			}



};*/
void file(string data)	// this function will open a file based on the file name entered by the user, if there isnt a file a error will appear
{
	string value;
	string value1;
	ifstream a;
	string filename;
	filename = data;
	a.open(filename.c_str());
	if(a.is_open())	// check to see if file exists
	{	
		
			while(!a.eof())			// while there is data in the file
			{	
			getline(a,value,',');		// get everything before the comma
			if(value == "add")		// Menu of functions
			  	 {
			        	getline(a,value,',');
		        		if(value == "name")
						{
						getline(a,value);
						add(value);
						}
				
					else if(value == "spouse")
						{
						getline(a,value,',');
						getline(a,value1);
						addSpouse(value,value1);
						}
					else if(value == "child")
						{
						getline(a,value,',');
						getline(a,value1);
						addChild(value,value1);
						}
					else if (value == "address1")
						{
						getline(a,value,',');
						getline(a,value1);
						addAddress(value,value1);
						}
					else if (value == "city")
						{
						getline(a,value,',');
						getline(a,value1);
						addCity(value,value1);	
						}
					else if(value == "state")	
						{
						getline(a,value,',');
						getline(a,value1);
						addCity(value,value1);	
						}
					else if (value == "date_birth")
						{
						getline(a,value,',');
						getline(a,value1);
						addDateob(value,value1);
						}
					else if(value == "date_wedding")
						{
						getline(a,value,',');
						getline(a,value1);
						addWedding(value,value1);	
						}   
					else if(value == "zip")
						{
						getline(a,value,',');
						getline(a,value1);
						addZip(value,value1);
						}
					else if(value == "date_death")
						{
						getline(a,value,',');
						getline(a,value1);
						addDeath(value,value1);
						}
				}	
			
			
			 else if(value == "print")
				{
				string trash;
				string trash1;
				getline(a,value,',');
				if(value == "all")	
				{
				getline(a,trash,',');
				getline(a,trash1);
				printpeople();
				}
				else
				{
				getline(a,trash,',');
				getline(a,trash1);
				Print(value);
				}
				}
			else if(value == "search")
				{
				string trash;
				string trash1;
				getline(a,value,',');
				getline(a,trash,',');
				getline(a,trash1);
				search(value);
				cout<<endl;
				}
		}	
	}	
			else
			{
			cout<<"ERROR: CANNOT OPEN INPUT FILE";
		  	}
a.close();
};	
	


};

void commands(){


cout<<"add name <name>  ==>  Add a new name (First Last) to the Address Book"<<endl;
cout<<"add spouse <uid> <name>  ==> Add spouse of <uid> (First Last) to the Address Book"<<endl;
cout<<"add child  <uid> <name>  ==>  Add a child of <uid> (First Last) to the Address Book"<<endl;
cout<<"add address1 <uid> <address>  ==> Add/change the address for <uid>"<<endl;
cout<<"add city <uid> <city>    ==> Add/change the city for <uid>"<<endl;
cout<<"add state <uid> <state>  ==> Add/change the state for <uid>"<<endl;
cout<<"add zip <uid> <zipcode>  ==> Add/change the zipcode for <uid>"<<endl;
cout<<"add date_birth <uid> <ddmmyyyy>  ==> Add/change the birthday for <uid>"<<endl;
cout<<"add date_wedding <uid> <ddmmyyyy>   ==> Add/change the wedding day for <uid>"<<endl;
cout<<"add date_death <uid> <ddmmyyyy>   ==> Add/change the date of death for <uid>"<<endl;
cout<<"search <name>  ==> searches for name (First Last) and returns the <uid>, if found"<<endl;
cout<<"print all ==>  Prints a list of ALL of the names in the Address Book with their <uid>"<<endl;
cout<<"print <uid>  ==>  Prints all of the fields for <uid>"<<endl;
cout<<"file  ==>  user is prompted for a filename that contains correctly formatted commands"<<endl;
cout<<"		--- the file must be in CSV format with one full command per line"<<endl;
cout<<"quit  ==>  processing complete"<<endl<<endl;




};

int main(/*int argc, const char * argv[]*/) {
    ostringstream oss;
    cout<<endl<<"Name: Hamdi Hmimy"<<endl<<"Course:CSCE 2100 Program 2"<<endl<<"Date: 10/11/2015"<<endl<<"Professor: Mr. Burke\n"<<endl<<endl<<"Create Your Address Book"<<endl;    
    students kids;
    string uid;
    //string ID = "ID";	
    string command;
    string trash;
    string data;
    string choose;	 
	commands(); 
while(command != "quit" && command!="QUIT")	//The loop for the menu function until the user enters quit	
    {  
	cout<<"\ncmd>";
        cin>>command;
	if(command == "quit")
		{
		return 0;

		}
	/*if(command!= "commands" && command!= "quit"&& command!= "QUIT" && command != "print" && command!= "PRINT")  // quit and print command
	{
	//cin>>choose;
    	//getline(cin,data);
	}*/
    else if(command == "commands")
	{
	system("clear");
	commands();

	}
    else if( command == "add")				// add function
    {
	cin>>choose;
	if(choose == "name")
	
		{
		getline(cin,data);
		kids.add(data);
		}
	else if( choose == "spouse")
		{
		cin>>uid;
		getline(cin,data);
		kids.addSpouse(uid,data);		
		}
	else if(choose == "child")
		{
		cin>> uid;
		getline(cin,data);
		kids.addChild(uid,data);
		}
	else if(choose == "address1")
		{
		cin>>uid;
		getline(cin,data);
		kids.addAddress(uid,data);
	
		}
	else if(choose == "city")
		{
		cin>>uid;
		getline(cin,data);
		kids.addCity(uid,data);
	
		}
	else if(choose == "state")
		{
		cin>>uid;
		getline(cin,data);
		kids.addState(uid,data);
		}
	else if(choose == "date_birth")
		{
		cin>>uid;
		getline(cin,data);
		kids.addDateob(uid,data);
	
		}
	else if(choose == "date_wedding")
		{
		cin>>uid;
		getline(cin,data);
		kids.addWedding(uid,data);

		}
	else if(choose == "zip")
		{
		cin>>uid;
		getline(cin,data);
		kids.addZip(uid,data);

		}
	else if(choose == "date_death")
		{
		cin>>uid;
		getline(cin,data);
		kids.addDeath(uid,data);
	
		}
	else
		{
		cout<<"ERROR PARAMATER";
		}
        //kids.add(data);
	//kids.abc();
    }
    else if (command == "ADD")
	{
	kids.add(data);
	kids.abc();
	}
    else if(command == "SEARCH")			// search function
	{
	getline(cin,data);
	kids.search(data);
	}
    else if(command == "search")			
    
    {
	getline(cin,data);
    	kids.search(data);    
    }
/*   else if(command == "REMOVE")				// remove function
	{
	kids.remove(data);
	}
    else if(command == "remove")
    {
	kids.remove(data);
    }*/
  
/* else if(command == "print")
	{
	kids.printpeople();

	}*/ 
 else if(command == "print" || command == "PRINT") // print function
    {

	cin>>data;
	if(data == "all")
	{
	kids.printpeople();
	}
	else
	kids.Print(data);	
	
    
    }
    /*else if(command == "PRINT")
	{
	kids.printAll();
	}*/
    else if(command == "file")				// file function
    {
        cin>>data;
	kids.file(data); 
    }     
   else if(command=="FILE")
	{
	kids.file(data);
	}
    else 
	{
		cout<< command<<" "<<choose<<" "<<uid<<" "<<data;
		cout<<"ERROR Missing Parameters";  // wrong command or parameters
	}    
    }
    
    
    return 0;
}

