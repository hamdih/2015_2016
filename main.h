// Head file Hamdi Hmimy

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
		*/
	int add(string data);
	void remove(string pick);
	void print();
	void search(string find);
	void file(string data);
		
};
