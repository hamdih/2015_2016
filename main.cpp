//
//  main.cpp
//  Program2
//
//  Created by Hamdi Hmimy on 9/28/15.
//  Copyright © 2015 Hamdi Hmimy. All rights reserved.
//
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

class student{
    friend class students;
    private:
    string name;       // Full name of student, First and Last
    int id;
    student *next;
    public:
    
    student(string nm,int num){
	name = nm;
	id = num;
    }


    int getId(){return id;}    
    string getName(){return name;}
    student *getNext(){return next;}	
    void setNext(student *n){next = n;}

};
    

class students{
     private:
            int count;
     public:
            student *head;
     	    student *tail;
	
	    students()
	    {
	
          	count = 0;
         	head = tail = NULL;
	    }	
		
	/*~students()
	{
	student *now = head;
	while(now!= tail)
		{
			student *next = now->getNext();
			delete now;
			now = next;
		}

	}*/


	 
	int add(string data)
	{
	string nm = data;
	int id = 1;
	student *temp,*temp2;
	id = id+count;
	cout<<"Added: ID "<<setfill('0')<<setw(3)<<id<<" "<<nm;
	temp2 = head;
	temp = new student(nm,id);

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

	void remove(string pick)
	{
	student *now = head;
	if(now !=NULL)
	{
	student *picked = head->getNext();
	}
	student *before = head;
	student *here = NULL;
	while(now!=NULL)
		{

		if(pick == now->getName())
			{
				if(now == head)
					{	
						here = head;
						head = here->getNext();
						delete here;	
						cout<<"Removal Succesfull";
						return;
					}
				before = now->getNext();
				delete now;
				cout<<"Removal Sucessful";
				return;
			}		
			before = now;
			now = now->getNext();	
		

		}
		cout<<"ERROR:Not Found for Removal:"<<pick;
	};
void print()
	{

	student *now = head;
	if(now== NULL)
	{
		cout<<"NO NAMES IN LIST";
	}
	else

	while(now!=NULL)
		{
		cout<<"ID:"<<" "<<setfill('0')<<setw(3)<<now->getId();
		cout<<" "<<now->getName()<<endl;
		now=now->getNext();	
		}
	
	}

void search(string find)
	{
		student *now = head;
		student *found = head->getNext();
		student *before = head;
		student *here = NULL;
		while(now != NULL)
		{
			if( find == now->getName())
			{
			cout<<"TRUE:"<<""<<now->getName();
			return;
			}
			else
			before = now;
			now= now->getNext();		
	
		}
			cout<<"FALSE:"<<""<<find;
};


void file(string data)
	{
	string value;
	ifstream f;
	string filename;
	filename = data;
	f.open(filename.c_str());
	if(f.is_open())
	{	
		
			while(!f.eof())
	{	
			getline(f,value,',');
			if(value == "add")
			   {	
			getline(f,value);
			add(value);
			   }	
			else if(value == "remove")
			{
				getline(f,value);
				remove(value);
			}	
			else if(value == "print")
			{
				getline(f,value);
				print();
			}
			else if(value== "search");
			{
			getline(f,value);
			search(value);

			}
	}		
			

	
	}	//if(value == "add")
		//	{
		//	getline(myfile,value,',');
		//	cout<<value;
			//add("hello");		
		//	}
	//cout<<string(value,0,value.length())<<"\n";	
				
	else
	cout<<"ERROR: CANNOT OPEN INPUT FILE";

	
	};


};



int main(/*int argc, const char * argv[]*/) {

	cout<<"Name: Hamdi Hmimy Course: CSCE 2100 Date: 10/11/2015 Prof: Mr. Burke\n";   
    students kids;
    string command;
    string data;
    
 while(command != "quit")
    {
        cout<<"\ncmd>";
        cin>>command;
	if(command != "print")
	{
	cin>> data;
    	}
    if( command == "add")
    {
        kids.add(data);
    }
    
    else if(command == "search")
    {
    	kids.search(data);    
    }
    else if(command == "remove")
    {
	kids.remove(data);
    }
    else if(command == "print")
    {
        kids.print();
    }
    else if(command == "file")
    {
       kids.file(data); 
    }     
    else 
	{
		cout<<"ERROR Missing Parameters";
	}    
    }
    
    
    return 0;
}

