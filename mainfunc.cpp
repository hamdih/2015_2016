// functions for Main.cpp
 #include "main.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
int students:: add(string data)
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
}

void students::remove(string pick)
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
}

void students::print()
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

void students:: search(string find)
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
}


void students:: file(string data)
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

	
}



