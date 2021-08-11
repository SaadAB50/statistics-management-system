#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class player{
	protected:
	string name, category;
	int xmatches, age, counter;
	int id;	
	
	public:
	friend void filter(float compare_value,char greaterthanlessthancheck,float compare_value1,char greaterthanlessthancheck1, string stat_type,string stat_type1);

};

class bowler:virtual public player{
	protected:
	int  wickets;
	float average, economy;
	
	public:
		friend void filter(float compare_value,char greaterthanlessthancheck,float compare_value1,char greaterthanlessthancheck1, string stat_type,string stat_type1);

		void read()
	{
			ifstream file_obj;
			file_obj.open("bowlers.txt", ios::in);
			
			bowler obj;
			
       
       	file_obj>>obj.name>>obj.category>>obj.id>>obj.age>>obj.xmatches>>obj.wickets>>obj.average>>obj.economy>>obj.counter;
		   cout<<"\n\tName "<<"\t\t Category "<<"\t\tAge"<<"\t\tMatches"<<"\t\tWickets"<<"\t\tAverage "<<"\tEconomy "<<"\tID "<<endl;
       	while(!file_obj.eof()){	
        cout<<"\n\t"<< obj.name<<"\t\t"<<obj.category<<"\t\t"<<obj.age<<"\t\t"<<obj.xmatches<<"\t\t"<<obj.wickets<<"\t\t"<<obj.average<<"\t\t"<<obj.economy<<"\t\t"<<obj.id<<"\n"<<endl;
        file_obj>>obj.name>>obj.category>>obj.id>>obj.age>>obj.xmatches>>obj.wickets>>obj.average>>obj.economy>>obj.counter;;//That's a line
    }
    
    
		file_obj.close(); 
			
    }
    vote(int x)
    {
    	ifstream file_obj;
		file_obj.open("bowlers.txt", ios::in);
		bowler obj[30];
		int i=0, flag=0; 
		file_obj>>obj[i].name>>obj[i].category>>obj[i].id>>obj[i].age>>obj[i].xmatches>>obj[i].wickets>>obj[i].average>>obj[i].economy>>obj[i].counter;
		if(x==obj[i].id)
        {
		flag=1;
		obj[i].counter++;
		}
       	while(!file_obj.eof()){	 //LOOP TO STORE FILE CONTENTS IN OBJECTS' ARRAY
       	i++;
        file_obj>>obj[i].name>>obj[i].category>>obj[i].id>>obj[i].age>>obj[i].xmatches>>obj[i].wickets>>obj[i].average>>obj[i].economy>>obj[i].counter;//That's a line
        
        
        if(x==obj[i].id)
        {
		flag=1;
		obj[i].counter++;
		}
        
        else{continue;}
        
    }
    file_obj.close();
    
    
    if(flag!=1)
	{  cout<<"\n\nERROR! Wrong id entered ";
	   cout<<"\nEnter id again: ";
	   int y;
	   cin >> y;
	   vote(y);
	}	
    

    
    //now we have the whole info in the array of objects. We will now replace it with the current file contents.
    ofstream file_obj1;
	file_obj1.open("bowlers.txt", ios::out);
	int j=0;
	
	for(j=0;j<i;j++)
	{
		
		file_obj1<<obj[j].name<<" "<<obj[j].category<<" "<<obj[j].id<<" "<<obj[j].age<<" "<<obj[j].xmatches<<" "<<obj[j].wickets<<" "<<obj[j].average<<" "<<obj[j].economy<<" "<<obj[j].counter<<"\n";
		
	}
	cout<<"\nSuccessfully voted!";
			file_obj1.close();
			 
}
	friend void favourite();
};



class batsman:virtual public player
	{
	protected:
	int runs, xhundreds, xfifties;
	float bat_average, bat_sRate;
	
	public:
	friend void filter(float compare_value,char greaterthanlessthancheck,float compare_value1,char greaterthanlessthancheck1, string stat_type,string stat_type1);

	void read()
	{
		int i=0;
		ifstream file_obj;
		file_obj.open("batsmen.txt", ios::in);
			
		batsman obj;
			
       
      	
		file_obj>>obj.name>>obj.category>>obj.id>>obj.xmatches>>obj.age>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;
		cout<<"\n\tName "<<"\t\t  Category "<<"\t\tAge "<<"\t\tMatches "<<"\tAverage "<<"\tStrike rate  "<<"\tID "<<endl;

       	while(!file_obj.eof()){	
       	cout<<"\n\t"<< obj.name<<"\t\t"<<obj.category<<"\t\t"<<obj.age<<"\t\t"<<obj.xmatches<<"\t\t"<<obj.bat_average<<"\t\t"<<obj.bat_sRate<<"\t\t"<<obj.id<<endl;
		file_obj>>obj.name>>obj.category>>obj.id>>obj.xmatches>>obj.age>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;

    }
    
    
		file_obj.close(); 
	}

	
	vote(int x)
	
	{
    	
    	int flag = 0;
    	ifstream file_obj;
		file_obj.open("batsmen.txt", ios::in);
		batsman obj[30];
		int i=0;
			
	    file_obj>>obj[i].name>>obj[i].category>>obj[i].id>>obj[i].xmatches>>obj[i].age>>obj[i].runs>>obj[i].xhundreds>>obj[i].xfifties>>obj[i].bat_average>>obj[i].bat_sRate>>obj[i].counter;
	    if(x==obj[i].id)
        {
        flag = 1;	
		obj[i].counter++;
		}
		
       	while(!file_obj.eof())
		   {	 //LOOP TO STORE FILE CONTENTS IN OBJECTS' ARRAY
       		i++;
        	file_obj>>obj[i].name>>obj[i].category>>obj[i].id>>obj[i].xmatches>>obj[i].age>>obj[i].runs>>obj[i].xhundreds>>obj[i].xfifties>>obj[i].bat_average>>obj[i].bat_sRate>>obj[i].counter;//That's a line
        
        
        if(x==obj[i].id)
    	{
        	flag = 1;	
			obj[i].counter++;
		}
	else
	{continue;}
}
file_obj.close();
	
	if(flag!=1)
	{
	cout<<"\n\nERROR! Wrong id entered ";
	cout<<"\nEnter id again: ";
	int y;
	cin >> y;
	vote(y);
	}	

		
		
	ofstream file_obj1;
	file_obj1.open("batsmen.txt", ios::out);
	int j=0;
	
	for(j=0;j<i;j++)
	{
		
		file_obj1<<obj[j].name<<" "<<obj[j].category<<" "<<obj[j].id<<" "<<obj[j].xmatches<<" "<<obj[j].age<<" "<<obj[j].runs<<" "<<obj[j].xhundreds<<" "<<obj[j].xfifties<<" "<<obj[j].bat_average<<" "<<obj[j].bat_sRate<<" "<<obj[j].counter<<endl;
		
	}
	cout<<"\nSuccessfully voted!";
			file_obj1.close();
	
}
    
    friend void favourite();

};

class allrounder: public batsman, public bowler{
	
	public:
		friend void filter(float compare_value,char greaterthanlessthancheck,float compare_value1,char greaterthanlessthancheck1, string stat_type,string stat_type1);

		void read()
	{
			ifstream file_obj;
			file_obj.open("allrounders.txt", ios::in);
			
			allrounder obj;

       
        file_obj>>obj.name>>obj.category>>obj.id>>obj.age>>obj.xmatches>>obj.wickets>>obj.average>>obj.economy>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;
       	cout<<"\nName: "<<"\tCategory: "<<"\tAge: "<<"\tMatches: "<<"\tWickets: "<<"\tBowlAvg: "<<"\tBowlEcon: "<<"\tRuns: "<<"\tHundreds: "<<"\tFifties: "<<"\tBatAvg: "<<"\tSR: "<<"\tID: "<<endl;	
		while(!file_obj.eof()){
		cout<<"\n"<<obj.name<<"\t"<<obj.category<<"\t"<<obj.age<<"\t"<<obj.xmatches<<"\t\t"<<obj.wickets<<"\t\t"<<obj.average<<"\t\t"<<obj.economy<<"\t\t"<<obj.runs<<"\t\t"<<obj.xhundreds<<"\t\t"<<obj.xfifties<<"\t"<<obj.bat_average<<"\t\t"<<obj.bat_sRate<<"\t"<<obj.id<<endl;	
        file_obj>>obj.name>>obj.category>>obj.id>>obj.age>>obj.xmatches>>obj.wickets>>obj.average>>obj.economy>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;//That's a line
    }
			file_obj.close(); 	
    }
    
    
    
    
    friend void favourite();
  	vote(int x)
	{
       int flag = 0;
    	ifstream file_obj;
		file_obj.open("allrounders.txt", ios::in);
		allrounder obj[30];
		int i=0;
			
	    file_obj>>obj[i].name>>obj[i].category>>obj[i].id>>obj[i].age>>obj[i].xmatches>>obj[i].wickets>>obj[i].average>>obj[i].economy>>obj[i].runs>>obj[i].xhundreds>>obj[i].xfifties>>obj[i].bat_average>>obj[i].bat_sRate>>obj[i].counter;;
	    if(x==obj[i].id)
        {
        	flag = 1;	
			obj[i].counter++;
		}
		
       	while(!file_obj.eof())
		{	 //LOOP TO STORE FILE CONTENTS IN OBJECTS' ARRAY
       	i++;
	    file_obj>>obj[i].name>>obj[i].category>>obj[i].id>>obj[i].age>>obj[i].xmatches>>obj[i].wickets>>obj[i].average>>obj[i].economy>>obj[i].runs>>obj[i].xhundreds>>obj[i].xfifties>>obj[i].bat_average>>obj[i].bat_sRate>>obj[i].counter;;
        
        
        if(x==obj[i].id)
    	{
        	flag = 1;	
			obj[i].counter++;
		}
		else
		{continue;}
}
file_obj.close();
	
	if(flag!=1)
	{
	cout<<"\n\nERROR! Wrong id entered ";
	cout<<"\nEnter id again: ";
	int y;
	cin >> y;
	vote(y);
	}	

		
		
	ofstream file_obj1;
	file_obj1.open("allrounders.txt", ios::out);
	int j=0;
	
	for(j=0;j<i;j++)
	{
		
	    file_obj1<<obj[j].name<<" "<<obj[j].category<<" "<<obj[j].id<<" "<<obj[j].age<<" "<<obj[j].xmatches<<" "<<obj[j].wickets<<" "<<obj[j].average<<" "<<obj[j].economy<<" "<<obj[j].runs<<" "<<obj[j].xhundreds<<" "<<obj[j].xfifties<<" "<<obj[j].bat_average<<" "<<obj[j].bat_sRate<<" "<<obj[j].counter<<endl;
		
	}
	cout<<"\nSuccessfully voted!";
			file_obj1.close();
		

}
};


class login{
	private:
		string id, pass;
		
	public:
	int compare(string id1,string pass1)
	{
		ifstream file_obj;
		file_obj.open("franchiselogin.txt", ios::in);
		login l;
		
		file_obj>>l.id>>l.pass;
		while(!file_obj.eof()){
		if(l.id==id1 && l.pass==pass1)
		{return 1;}
		
		file_obj>>l.id>>l.pass;
	}
	file_obj.close();
	}
	
	
};


	 void favourite()
	{
		string name1;
		int highest = 0;
		
		ifstream file_obj;
		file_obj.open("allrounders.txt", ios::in);
			
		allrounder obj;

       
       file_obj>>obj.name>>obj.category>>obj.id>>obj.age>>obj.xmatches>>obj.wickets>>obj.average>>obj.economy>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;
       if(obj.counter>highest)
       {
       	highest = obj.counter;
       	name1 = obj.name;
	   }
       	while(!file_obj.eof()){	
        file_obj>>obj.name>>obj.category>>obj.id>>obj.age>>obj.xmatches>>obj.wickets>>obj.average>>obj.economy>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;//That's a line
        if(obj.counter>highest)
       {
       	highest = obj.counter;
       	name1 = obj.name;
	   }
    }
			file_obj.close(); 	
			
			
			
			
		ifstream file_obj1;
		file_obj.open("batsmen.txt", ios::in);
			

			
       batsman obj1;
      file_obj1>>obj1.name>>obj1.category>>obj1.id>>obj1.xmatches>>obj1.age>>obj1.runs>>obj1.xhundreds>>obj1.xfifties>>obj1.bat_average>>obj1.bat_sRate>>obj1.counter;
if(obj.counter>highest)
       {
       	highest = obj1.counter;
       	name1 = obj1.name;
	   }
       	while(!file_obj1.eof()){	
      file_obj1>>obj1.name>>obj1.category>>obj1.id>>obj1.xmatches>>obj1.age>>obj1.runs>>obj1.xhundreds>>obj1.xfifties>>obj1.bat_average>>obj1.bat_sRate>>obj1.counter;
      if(obj1.counter>highest)
       {
       	highest = obj1.counter;
       	name1 = obj1.name;
	   }

    }
    
    
			file_obj1.close(); 
			
			
			
			
			
			
			
			ifstream file_obj2;
			file_obj2.open("bowlers.txt", ios::in);
			
			bowler obj2;
			
       
       file_obj2>>obj2.name>>obj2.category>>obj2.id>>obj2.age>>obj2.xmatches>>obj2.wickets>>obj2.average>>obj2.economy>>obj2.counter;
       if(obj2.counter>highest)
       {
       	highest = obj2.counter;
       	name1 = obj2.name;
	   }
       	while(!file_obj2.eof()){	
       file_obj2>>obj2.name>>obj2.category>>obj2.id>>obj2.age>>obj2.xmatches>>obj2.wickets>>obj2.average>>obj2.economy>>obj2.counter;
        if(obj2.counter>highest)
       {
       	highest = obj2.counter;
       	name1 = obj2.name;
	   }
    }
    
    
			file_obj2.close();
			if(highest==0) 	
			cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer of the week: "<<"NONE"<<"\n\n\n";
			
			else
			cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer of the week: "<<name1<<"\n\n\n";
}


void filter(float compare_value,char greaterthanlessthancheck,float compare_value1,char greaterthanlessthancheck1, string stat_type,string stat_type1)   //filter(compare_value,stat_type,greaterthanlessthancheck); 
{
	        ifstream file_obj, file_obj1, file_obj2;
	        
			file_obj.open("batsmen.txt",ios::in);
			file_obj1.open("allrounders.txt",ios::in);
			file_obj2.open("bowlers.txt",ios::in);
			
            batsman obj;
			allrounder obj1;
			bowler obj2;
	
       		int count = 0;
       		file_obj>>obj.name>>obj.category>>obj.id>>obj.xmatches>>obj.age>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;
			file_obj1>>obj1.name>>obj1.category>>obj1.id>>obj1.age>>obj1.xmatches>>obj1.wickets>>obj1.average>>obj1.economy>>obj1.runs>>obj1.xhundreds>>obj1.xfifties>>obj1.bat_average>>obj1.bat_sRate>>obj1.counter;
			file_obj2>>obj2.name>>obj2.category>>obj2.id>>obj2.age>>obj2.xmatches>>obj2.wickets>>obj2.average>>obj2.economy>>obj2.counter;

       		while(!file_obj.eof() && !file_obj.eof())
			{
				//single  runs
       			if(stat_type=="runcheck" && greaterthanlessthancheck=='l' && stat_type1=="0" && greaterthanlessthancheck1=='0')
		   	{
		   			if(obj.runs<compare_value && !file_obj.eof())
		   		    cout<<obj.name<<"\t\t\t"<<obj.runs<<endl;
		   		
		   		    if(obj1.runs<compare_value &&  !file_obj1.eof())
		   		    cout<<obj1.name<<"\t\t\t"<<obj1.runs<<endl;
       		}
       		
       		
       			else if(stat_type=="runcheck" && greaterthanlessthancheck=='g')
       		{
       				if(obj.runs>compare_value && !file_obj.eof())
		   		    cout<<obj.name<<"\t\t\t"<<obj.runs<<endl;
		   		
		   		    if(obj1.runs>compare_value &&  !file_obj1.eof())
		   		    cout<<obj1.name<<"\t\t\t"<<obj1.runs<<endl;
       			
			}
			
			
			//multiple   wickets and runs
			    else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='g' && stat_type1=="runcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.wickets>compare_value && obj1.runs>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.wickets<<"\t\t\t"<<obj1.runs<<endl;
			}
			
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='g' && stat_type1=="runcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.wickets>compare_value && obj1.runs<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.wickets<<"\t\t\t"<<obj1.runs<<endl;
			}
			
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='l' && stat_type1=="runcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.wickets<compare_value && obj1.runs>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.wickets<<"\t\t\t"<<obj1.runs<<endl;
			}
			
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='l' && stat_type1=="runcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.wickets<compare_value && obj1.runs<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.wickets<<"\t\t\t"<<obj1.runs<<endl;
			}
			
			
			//multiple runs and age
			else if(stat_type=="agecheck" && greaterthanlessthancheck=='g' && stat_type1=="runcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.age>compare_value && obj1.runs>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.age<<"\t\t\t"<<obj1.runs<<endl;
		   		
		   		if(obj.age>compare_value && obj.runs>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.age<<"\t\t\t"<<obj.runs<<endl;

			}
			
			else if(stat_type=="agecheck" && greaterthanlessthancheck=='g' && stat_type1=="runcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.age>compare_value && obj1.runs<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.age<<"\t\t\t"<<obj1.runs<<endl;
		   		
		   		if(obj.age>compare_value && obj.runs<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.age<<"\t\t\t"<<obj.runs<<endl;
			}
			
			else if(stat_type=="agecheck" && greaterthanlessthancheck=='l' && stat_type1=="runcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.age<compare_value && obj1.runs>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.age<<"\t\t\t"<<obj1.runs<<endl;
		   		
		   		if(obj.age<compare_value && obj.runs>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.age<<"\t\t\t"<<obj.runs<<endl;
			}
			
			else if(stat_type=="agecheck" && greaterthanlessthancheck=='l' && stat_type1=="runcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.age<compare_value && obj1.runs<compare_value1 && !file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.age<<"\t\t\t"<<obj1.runs<<endl;
		   		
		   		if(obj.age<compare_value && obj.runs<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.age<<"\t\t\t"<<obj.runs<<endl;
			}
			
			
			//multiple match wickets
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='g' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.wickets>compare_value && obj1.xmatches>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.xmatches<<"\t\t\t"<<obj1.wickets<<endl;
		   		
				if(obj2.wickets>compare_value && obj2.xmatches>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.xmatches<<"\t\t\t"<<obj2.wickets<<endl;

			}
			
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='g' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.wickets>compare_value && obj1.xmatches<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.xmatches<<"\t\t\t"<<obj1.wickets<<endl;
		   		
				if(obj2.wickets>compare_value && obj2.xmatches<compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.xmatches<<"\t\t\t"<<obj2.wickets<<endl;
			}
			
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='l' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.wickets<compare_value && obj1.xmatches>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.xmatches<<"\t\t\t"<<obj1.wickets<<endl;
		   		
				if(obj2.wickets<compare_value && obj2.xmatches>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.xmatches<<"\t\t\t"<<obj2.wickets<<endl;
			}
			
			else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='l' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.age>compare_value && obj1.runs>compare_value1 && !file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.xmatches<<"\t\t\t"<<obj1.wickets<<endl;
		   		
		   		if(obj.age>compare_value && obj.runs>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.xmatches<<"\t\t\t"<<obj2.wickets<<endl;
			}
			
			
			
			//multiple sr avg
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='g' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.bat_sRate>compare_value && obj1.bat_average>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_sRate<<"\t\t\t"<<obj1.bat_average<<endl;
		   		
				if(obj.bat_sRate>compare_value && obj.bat_average>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_sRate<<"\t\t\t"<<obj.bat_average<<endl;

			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='g' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.bat_sRate>compare_value && obj1.bat_average<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_sRate<<"\t\t\t"<<obj1.bat_average<<endl;
		   		
				if(obj.bat_sRate>compare_value && obj.bat_average<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_sRate<<"\t\t\t"<<obj.bat_average<<endl;
			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='l' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.bat_sRate<compare_value && obj1.bat_average>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_sRate<<"\t\t\t"<<obj1.bat_average<<endl;
		   		
				if(obj.bat_sRate<compare_value && obj.bat_average>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_sRate<<"\t\t\t"<<obj.bat_average<<endl;
			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='l' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.bat_sRate<compare_value && obj1.bat_average<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_sRate<<"\t\t\t"<<obj1.bat_average<<endl;
		   		
				if(obj.bat_sRate<compare_value && obj.bat_average<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_sRate<<"\t\t\t"<<obj.bat_average<<endl;
			}
			
			
		   	
		   	
		   	// multiple bowlavg bowlecon
		   	else if(stat_type=="bowlavg" && greaterthanlessthancheck=='g' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='g')
			{
				if(obj1.average>compare_value && obj1.economy>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average>compare_value && obj2.economy>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;

			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='g' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.average>compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average>compare_value && obj2.economy<compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;
			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='l' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.average<compare_value && obj1.economy>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average<compare_value && obj2.economy>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;
			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='l' && stat_type1=="avgcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.average<compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average<compare_value && obj2.economy<compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;
			}
			// multiple bowlavg bowlecon
		   	else if(stat_type=="bowlavg" && greaterthanlessthancheck=='g' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='g')
			{
				if(obj1.average>compare_value && obj1.economy>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average>compare_value && obj2.economy>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;

			}
			
			else if(stat_type=="bowlavg" && greaterthanlessthancheck=='g' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='l')
			{
				if(obj1.average>compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average>compare_value && obj2.economy<compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;
			}
			
			else if(stat_type=="bowlavg" && greaterthanlessthancheck=='l' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='g')
			{
				if(obj1.average<compare_value && obj1.economy>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average<compare_value && obj2.economy>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;
			}
			
			else if(stat_type=="bowlavg" && greaterthanlessthancheck=='l' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='l')
			{
				if(obj1.average<compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average<compare_value && obj2.economy<compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;
			}
            else if(stat_type=="srcheck" && greaterthanlessthancheck=='g' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='g')
			{
				if(obj1.average>compare_value && obj1.economy>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.average<<endl;
		   		
				if(obj2.average>compare_value && obj2.economy>compare_value1 &&!file_obj2.eof())
		   		cout<<obj2.name<<"\t\t\t"<<obj2.economy<<"\t\t\t"<<obj2.average<<endl;

			}
			//srcheck and bowlecon
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='g' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='l')
			{
				if(obj1.bat_sRate>compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.bat_sRate<<endl;
                
		   		
			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='l' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='g')
			{
				if(obj1.bat_sRate<compare_value && obj1.economy>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.bat_sRate<<endl;
		   		
			}
			
			else if(stat_type=="srcheck" && greaterthanlessthancheck=='l' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='l')
			{
				if(obj1.bat_sRate<compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.bat_sRate<<endl;
		   		
			}
            else if(stat_type=="srcheck" && greaterthanlessthancheck=='g' && stat_type1=="bowlecon" && greaterthanlessthancheck1=='g')
			{
				if(obj1.bat_sRate<compare_value && obj1.economy<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.economy<<"\t\t\t"<<obj1.bat_sRate<<endl;
		   		
			}
            //runs and matches
            else if(stat_type=="runcheck" && greaterthanlessthancheck=='g' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='l')
			{
				
				if(obj1.runs>compare_value && obj1.xmatches<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.runs<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.runs>compare_value && obj.xmatches<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.runs<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
			
			else if(stat_type=="runcheck" && greaterthanlessthancheck=='l' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.runs<compare_value && obj1.xmatches>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.runs<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.runs<compare_value && obj.xmatches>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.runs<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
			
			else if(stat_type=="runcheck" && greaterthanlessthancheck=='l' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.runs<compare_value && obj1.xmatches<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.runs<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.runs<compare_value && obj.xmatches<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.runs<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
            else if(stat_type=="runcheck" && greaterthanlessthancheck=='g' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.runs>compare_value && obj1.xmatches>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.runs<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.runs>compare_value && obj.xmatches>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.runs<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
            //batting average and matches
            else if(stat_type=="bataverage" && greaterthanlessthancheck=='g' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.bat_average>compare_value && obj1.xmatches<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_average<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.bat_average>compare_value && obj.xmatches<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_average<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
			
			else if(stat_type=="bataverage" && greaterthanlessthancheck=='l' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.bat_average<compare_value && obj1.xmatches>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_average<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.bat_average<compare_value && obj.xmatches>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_average<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
			
			else if(stat_type=="bataverage" && greaterthanlessthancheck=='l' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='l')
			{
				if(obj1.bat_average<compare_value && obj1.xmatches<compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_average<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.bat_average<compare_value && obj.xmatches<compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_average<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
            else if(stat_type=="bataverage" && greaterthanlessthancheck=='g' && stat_type1=="matchcheck" && greaterthanlessthancheck1=='g')
			{
				if(obj1.bat_average>compare_value && obj1.xmatches>compare_value1 &&!file_obj1.eof())
		   		cout<<obj1.name<<"\t\t\t"<<obj1.bat_average<<"\t\t\t"<<obj1.xmatches<<endl;

                if(obj.bat_average>compare_value && obj.xmatches>compare_value1 &&!file_obj.eof())
		   		cout<<obj.name<<"\t\t\t"<<obj.bat_average<<"\t\t\t"<<obj.xmatches<<endl;
		   		
			}
		   	
		   	//single wickets
			    else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='g' && stat_type1=="0" && greaterthanlessthancheck1=='0')
       		{
       				if(obj2.wickets>compare_value && !file_obj2.eof())
		   		    cout<<obj2.name<<"\t\t\t"<<obj2.wickets<<endl;
		   		    
		   		    if(obj1.wickets>compare_value && !file_obj1.eof())
		   		    cout<<obj1.name<<"\t\t\t"<<obj1.wickets<<endl;
			}
			    else if(stat_type=="wicketcheck" && greaterthanlessthancheck=='l')
       		{
       				if(obj2.wickets<compare_value && !file_obj2.eof())
		   		    cout<<obj2.name<<"\t\t\t"<<obj2.wickets<<endl;
		   		    
		   		    if(obj1.wickets<compare_value && !file_obj1.eof())
		   		    cout<<obj1.name<<"\t\t\t"<<obj1.wickets<<endl;
		   	}
		   	//single matches
			else if(stat_type=="matchcheck" && greaterthanlessthancheck=='l'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
       		{
       				if(obj1.xmatches<compare_value && !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.xmatches<<endl;

		   			if(obj.xmatches<compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.xmatches<<endl;
					
					if(obj2.xmatches<compare_value&& !file_obj2.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.xmatches<<endl;
					
       			
			}
			else if(stat_type=="matchcheck" && greaterthanlessthancheck=='g'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
       		{
       				if(obj1.xmatches>compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.xmatches<<endl;

		   			if(obj.xmatches>compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.xmatches<<endl;
					
					if(obj2.xmatches>compare_value&& !file_obj2.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.xmatches<<endl;
			}
			else if(stat_type=="agecheck" && greaterthanlessthancheck=='l'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.age<compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.age<<endl;

		   			if(obj.age<compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.age<<endl;
					
					if(obj2.age<compare_value&& !file_obj2.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.age<<endl;
			}
			else if(stat_type=="agecheck" && greaterthanlessthancheck=='g'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.age>compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.age<<endl;

		   			if(obj.age>compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.age<<endl;
					
					if(obj2.age>compare_value&& !file_obj2.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.age<<endl;
			}
			else if(stat_type=="bataverage" && greaterthanlessthancheck=='l'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
				
					if(obj1.bat_average<compare_value && !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.bat_average<<endl;

		   			if(obj.bat_average<compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.bat_average<<endl;
					
			}
			else if(stat_type=="bataverage" && greaterthanlessthancheck=='g'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.bat_average>compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.bat_average<<endl;

		   			if(obj.bat_average>compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.bat_average<<endl;
					
			}
			else if(stat_type=="bowlaverage" && greaterthanlessthancheck=='l'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.average<compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.average<<endl;

		   			if(obj2.average<compare_value&& !file_obj2.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.average<<endl;
					
			}
			else if(stat_type=="bowlaverage" && greaterthanlessthancheck=='g'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.average>compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.average<<endl;

		   			if(obj2.average>compare_value&& !file_obj2.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.average<<endl;
			}
			else if(stat_type=="batsrate" && greaterthanlessthancheck=='l'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.bat_sRate<compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.bat_sRate<<endl;

		   			if(obj.bat_sRate<compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.bat_sRate<<endl;
			}
			else if(stat_type=="batsrate" && greaterthanlessthancheck=='g'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
	
					if(obj1.bat_sRate>compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.bat_sRate<<endl;

		   			if(obj.bat_sRate>compare_value&& !file_obj.eof())
					cout<<obj.name<<"\t\t\t"<<obj.bat_sRate<<endl;
			}
			else if(stat_type=="bowlecon" && greaterthanlessthancheck=='l'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.economy<compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.economy<<endl;

		   			if(obj2.economy<compare_value&& !file_obj.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.economy<<endl;
			}
			else if(stat_type=="bowlecon" && greaterthanlessthancheck=='g'&& stat_type1=="0" && greaterthanlessthancheck1=='0')
			{
					if(obj1.economy>compare_value&& !file_obj1.eof())
       				cout<<obj1.name<<"\t\t\t"<<obj1.economy<<endl;

		   			if(obj2.economy>compare_value&& !file_obj.eof())
					cout<<obj2.name<<"\t\t\t"<<obj2.economy<<endl;
			}

				
       			
       			file_obj>>obj.name>>obj.category>>obj.id>>obj.xmatches>>obj.age>>obj.runs>>obj.xhundreds>>obj.xfifties>>obj.bat_average>>obj.bat_sRate>>obj.counter;
			    file_obj1>>obj1.name>>obj1.category>>obj1.id>>obj1.age>>obj1.xmatches>>obj1.wickets>>obj1.economy>>obj1.average>>obj1.runs>>obj1.xhundreds>>obj1.xfifties>>obj1.bat_average>>obj1.bat_sRate>>obj1.counter;
			    file_obj2>>obj2.name>>obj2.category>>obj2.id>>obj2.age>>obj2.xmatches>>obj2.wickets>>obj2.average>>obj2.economy>>obj2.counter;

		   		}
       	
   			
			file_obj.close();
			file_obj1.close();
			file_obj2.close();
}




int clear(int id, char x)
{
            ifstream file_obj;
		    ofstream kk;
			ofstream pz;
			ofstream qg;
			ofstream ms;
			ofstream lq;
			ofstream iu;
	        int id1[100];
	        string name1[100], name2, cat2;
	        string cat1[100];
			file_obj.open("TotalPlayers.txt",ios::in);
			int count = 0;
			int id2;
		
       		
       		file_obj>>name2>>id2>>cat2;
       		while(!file_obj.eof())
       		{
       			if(id2!=id)
       			{
       				id1[count] = id2;
       				name1[count] = name2;
       				cat1[count] = cat2;
       				count++;
       				file_obj>>name2>>id2>>cat2;
				}
				
			
				
				
				else if(x=='k' && id2==id)
				{
					kk.open("KK.txt",ios::app);
					kk<<name2<<" "<<id2<<" "<<cat2<<endl;
					kk.close();
					file_obj>>name2>>id2>>cat2;
				}
				
				else if(x=='q' && id2==id)
				{
					qg.open("QG.txt",ios::app);
					qg<<name2<<" "<<id2<<" "<<cat2<<endl;
					qg.close();
					file_obj>>name2>>id2>>cat2;
				}
				
				else if(x=='p' && id2==id)
				{
					pz.open("PZ.txt",ios::app);
					pz<<name2<<" "<<id2<<" "<<cat2<<endl;
					pz.close();
					file_obj>>name2>>id2>>cat2;
				}
				
				else if(x=='m' && id2==id)
				{
					ms.open("MS.txt",ios::app);
					ms<<name2<<" "<<id2<<" "<<cat2<<endl;
					ms.close();
					file_obj>>name2>>id2>>cat2;
				}
				
				else if(x=='i' && id2==id)
				{
					iu.open("IU.txt",ios::app);
					iu<<name2<<" "<<id2<<" "<<cat2<<endl;
					iu.close();
					file_obj>>name2>>id2>>cat2;
				}
				
				else if(x=='l' && id2==id)
				{
					lq.open("LQ.txt",ios::app);
					lq<<name2<<" "<<id2<<" "<<cat2<<endl;
					lq.close();
					file_obj>>name2>>id2>>cat2;
				}
		    }
		    
		    
		
			file_obj.close();
			
			
		    
		    
			
			ofstream file_obj1;
			file_obj1.open("TotalPlayers.txt",ios::out);
			int j=0;
			int i;
			for(i=0;i<count;i++)
			{
				file_obj1<<name1[j]<<" "<<id1[j]<<" "<<cat1[j]<<endl;
				j++;
			}
			file_obj1.close();
			
		
			
}


void display_lot(int z) // int z
{
	            int id3; string name3, cat;
	            
	            
				
				ifstream x;
				cout<<"\n\n\n\t\t\t\t\t\t\t---Available Players---\n\n   \t\t\t\t\t\tName\t\t\t\t\t\tID\n\n\n";
				x.open("TotalPlayers.txt",ios::in);
				
				
				
				x>>name3>>id3>>cat;
				while(!x.eof())
	        {
					if(z==1 && cat=="P")  //3 rounds
				{
					cout<<"\t\t\t\t\t"<<name3<<"\t\t\t\t\t"<<id3<<endl<<endl;
				    
			    } 
					 if(z==2 && cat=="D" )  //2 rounds
				{	
				    cout<<"\t\t\t\t\t"<<name3<<"\t\t\t\t\t"<<id3<<endl<<endl;
				}
					
					 if(z==3 && cat=="G" )  //4 rounds
				{
					cout<<"\t\t\t\t\t"<<name3<<"\t\t\t\t\t"<<id3<<endl<<endl;
				}
					
					if(z==4 && cat=="S" )  //2 rounds
				{
					cout<<"\t\t\t\t\t"<<name3<<"\t\t\t\t\t"<<id3<<endl<<endl;
					
				}
				x>>name3>>id3>>cat;
           }
           x.close();

}
//void opinions()
//{
//	fstream f;
//	f.open("Opinions.txt",ios::in);
//	f.write()
//}


class franchise_Interface
{
	public:
		friend int clear(int id, char x);
		friend void display_lot(int z);
		interface()
		{
		login l;
	    string un, pass;
		cout<<"\n\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ L O  G  I  N  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLogin with PCB's official login credentials\n\n";
		cout<<"\n\n\n\n\n\t\t\t\tUsername: ";
		cin>>un;
		cout<<"\n\n\t\t\t\tPassword: ";
		cin>>pass;
		if(l.compare(un,pass)==1)
		{	
		}
		
		else
		{
			system("CLS");
			cout<<"\n\t\t\t\t\t\t\t\t\tWrong credentials, enter id and password again!";
			interface();
		}
		}
		
		draft()
		{
			int i,j,kid,mid,iid,lid,pid,qid;
		
			cout<<"\n\n\t\t\t\t\tT H E   D R A F T    ------   P L A T A N I U M   R O U N D";
		
			for(j=0;j<1;j++)
			{
				display_lot(1);
				
				cout<<"\n\n\t\t\t\t\t\t\tK A R A C H I   K I N G S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> kid;
				system("CLS");
				clear(kid,'k');
			    display_lot(1);
			
				
				cout<<"\n\n\t\t\t\t\t\t\tP E S H A W A R   Z A L M I\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> pid;
				while(pid==kid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>pid;
			}
			
			system("CLS");
				
				clear(pid,'p');
				display_lot(1);
				cout<<"\n\n\t\t\t\t\t\t\tM U L T A N   S U L T A N S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> mid;
				while(mid==kid || mid == pid ){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			system("CLS");
				
				clear(mid,'m');
				display_lot(1);
				cout<<"\n\n\t\t\t\t\t\t\tI S L A M A B A D   U N I T E D\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> iid;
				while(iid==kid || iid == pid || iid==mid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>iid;
			}
			system("CLS");
				
				clear(iid,'i');
				display_lot(1);
				cout<<"\n\n\t\t\t\t\t\t\tL A H O R E   Q A L A N D E R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> lid;
				while(lid==kid || lid == pid || lid==mid || lid == iid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>lid;
			}
			system("CLS");
				
				clear(lid,'l');
				display_lot(1);
				cout<<"\n\n\t\t\t\t\t\t\tQ U E T T A   G A L D I A T O R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> qid;
				while(qid==kid || qid == pid || qid==mid || qid == iid || qid ==lid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			clear(qid,'q'); 
			system("CLS");	
		}
			
		
		
		

		
		
		//DIAMOND
		
			cout<<"\n\n\t\t\t\t\tT H E   D R A F T    ------  D I A M O N D   R O U N D";
		
			for(j=0;j<1;j++)
			{
				display_lot(2);
				
				cout<<"\n\n\t\t\t\t\t\t\tK A R A C H I   K I N G S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> kid;
				system("CLS");
				
				clear(kid,'k');
				display_lot(2);
				
				cout<<"\n\n\t\t\t\t\t\t\tP E S H A W A R   Z A L M I\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> pid;
				while(pid==kid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>pid;
			}
			
			system("CLS");
				
				clear(pid,'p');
				display_lot(2);
				cout<<"\n\n\t\t\t\t\t\t\tM U L T A N   S U L T A N S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> mid;
				while(mid==kid || mid == pid ){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			system("CLS");
				
				clear(mid,'m');
				display_lot(2);
				cout<<"\n\n\t\t\t\t\t\t\tI S L A M A B A D   U N I T E D\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> iid;
				while(iid==kid || iid == pid || iid==mid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>iid;
			}
			system("CLS");
				
				clear(iid,'i');
				display_lot(2);
				cout<<"\n\n\t\t\t\t\t\t\tL A H O R E   Q A L A N D E R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> lid;
				while(lid==kid || lid == pid || lid==mid || lid == iid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>lid;
			}
			system("CLS");
				
				clear(lid,'l');
				display_lot(2);
				cout<<"\n\n\t\t\t\t\t\t\tQ U E T T A   G A L D I A T O R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> qid;
				while(qid==kid || qid == pid || qid==mid || qid == iid || qid ==lid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			clear(qid,'q'); 
			system("CLS");	
			}
			
		
		//gold round
		
			cout<<"\n\n\t\t\t\t\tT H E   D R A F T    ------  G O L D   R O U N D";
		
			for(j=0;j<1;j++)
			{
				display_lot(3);
				
				cout<<"\n\n\t\t\t\t\t\t\tK A R A C H I   K I N G S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> kid;
				system("CLS");
				
				clear(kid,'k');
				display_lot(3);
				
				cout<<"\n\n\t\t\t\t\t\t\tP E S H A W A R   Z A L M I\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> pid;
				while(pid==kid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>pid;
			}
			
			system("CLS");
				
				clear(pid,'p');
				display_lot(3);
				cout<<"\n\n\t\t\t\t\t\t\tM U L T A N   S U L T A N S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> mid;
				while(mid==kid || mid == pid ){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			system("CLS");
				
				clear(mid,'m');
				display_lot(3);
				cout<<"\n\n\t\t\t\t\t\t\tI S L A M A B A D   U N I T E D\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> iid;
				while(iid==kid || iid == pid || iid==mid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>iid;
			}
			system("CLS");
				
				clear(iid,'i');
				display_lot(3);
				cout<<"\n\n\t\t\t\t\t\t\tL A H O R E   Q A L A N D E R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> lid;
				while(lid==kid || lid == pid || lid==mid || lid == iid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>lid;
			}
			system("CLS");
				
				clear(lid,'l');
				display_lot(3);
				cout<<"\n\n\t\t\t\t\t\t\tQ U E T T A   G A L D I A T O R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> qid;
				while(qid==kid || qid == pid || qid==mid || qid == iid || qid ==lid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			clear(qid,'q'); 
			system("CLS");	
			}
			
		
		
		
		//SILVER
		
			cout<<"\n\n\t\t\t\t\tT H E   D R A F T    ------  S I L V E R   R O U N D";
		
			for(j=0;j<1;j++)
			{
				display_lot(4);
				
				cout<<"\n\n\t\t\t\t\t\t\tK A R A C H I   K I N G S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> kid;
				system("CLS");
				
				clear(kid,'k');
				display_lot(4);
				
				cout<<"\n\n\t\t\t\t\t\t\tP E S H A W A R   Z A L M I\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> pid;
				while(pid==kid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>pid;
			}
			
			system("CLS");
				
				clear(pid,'p');
				display_lot(4);
				cout<<"\n\n\t\t\t\t\t\t\tM U L T A N   S U L T A N S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> mid;
				while(mid==kid || mid == pid ){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			system("CLS");
				
				clear(mid,'m');
				display_lot(4);
				cout<<"\n\n\t\t\t\t\t\t\tI S L A M A B A D   U N I T E D\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> iid;
				while(iid==kid || iid == pid || iid==mid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>iid;
			}
			system("CLS");
				
				clear(iid,'i');
				display_lot(4);
				cout<<"\n\n\t\t\t\t\t\t\tL A H O R E   Q A L A N D E R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> lid;
				while(lid==kid || lid == pid || lid==mid || lid == iid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>lid;
			}
			system("CLS");
				
				clear(lid,'l');
				display_lot(4);
				cout<<"\n\n\t\t\t\t\t\t\tQ U E T T A   G A L D I A T O R S\n\n\n\t\tEnter ID of player you want to select: ";
				cin >> qid;
				while(qid==kid || qid == pid || qid==mid || qid == iid || qid ==lid){
				cout<<"\n\t\t\t----The Player has been already selected by previous team-----\n\t\t\t\t\tEnter ID of a differnt player: ";
				cin>>mid;
			}
			clear(qid,'q'); 
			system("CLS");	
			}
			
	}
	
	
	viewteams()
	{
		string team;
		cout<<"\n\n\n\n\n\t\t\t\t\t\tWhich team you want to display? (kk, qg, lq, pz, ms, iu) ";
		cin>>team;
		
		ifstream kk,lq,ms,pz,iu,qg;
		string namekk, catkk,nameqg, catqg,namepz, catpz, namems, catms,namelq, catlq, nameiu, catiu;
		int idkk, idqg, idpz, idms, idiu, idlq;
		kk.open("KK.txt",ios::in);
		qg.open("QG.txt",ios::in);
		iu.open("IU.txt",ios::in);
		pz.open("PZ.txt",ios::in);
		lq.open("LQ.txt",ios::in);
		ms.open("MS.txt",ios::in);
		
		
		
		if(team=="kk")
	    cout<<"\n\n\n\t\t\t\t\t\t\tK A R A C H I    K I N G S\n\n";
	    
	    else if(team=="lq")
	    cout<<"\n\n\n\t\t\t\t\t\t\tL A H O R E     Q A L A N D A R S\n\n";
	    
	    else if(team=="lq")
	    cout<<"\n\n\n\t\t\t\t\t\t\tM U L T A N     S U L T A N S\n\n";
	    
	    else if(team=="lq")
	    cout<<"\n\n\n\t\t\t\t\t\t\tP E S H A W A R   Z A L M I\n\n";
	    
	    else if(team=="lq")
	    cout<<"\n\n\n\t\t\t\t\t\t\tI S L A M A B A D     U N I T E D\n\n";
	    
	    else if(team=="lq")
	    cout<<"\n\n\n\t\t\t\t\t\t\tQ U E T T A   G L A D I A T O R S\n\n";

	    
		cout<<"\t\t\t\t   ----------------------------SQUAD 2021-----------------------------";
		kk>>namekk>>idkk>>catkk;
		qg>>nameqg>>idqg>>catqg;
		pz>>namepz>>idpz>>catpz;
		ms>>namems>>idms>>catms;
		lq>>namelq>>idlq>>catlq;
		iu>>nameiu>>idiu>>catiu;
		while(!kk.eof() && !qg.eof() &&!ms.eof() &&!iu.eof() &&!ms.eof() &&!pz.eof())
		{
			if(team=="kk")
			cout<<"\t\t\t\t\t\t>>"<<namekk<<endl;
			
			else if(team=="qg")
			cout<<"\t\t\t\t\t\t"<<nameqg<<endl;
			
			else if(team=="ms")
			cout<<"\t\t\t\t\t\t"<<namems<<endl;
			
			else if(team=="lq")
			cout<<"\t\t\t\t\t\t"<<namelq<<endl;
			
			else if(team=="iu")
			cout<<"\t\t\t\t\t\t"<<nameiu<<endl;
			
			else if(team=="pz")
			cout<<"\t\t\t\t\t\t"<<namepz<<endl;
			
		kk>>namekk>>idkk>>catkk;
		qg>>nameqg>>idqg>>catqg;
		pz>>namepz>>idpz>>catpz;
		ms>>namems>>idms>>catms;
		lq>>namelq>>idlq>>catlq;
		iu>>nameiu>>idiu>>catiu;
			
		}
	}
};







int main()
{
	 
	char choice;
	
	login l;
	string un, pass;
	cout<<"\n\n\n\n\t\t\t\t\t\t------------W E L C O M E------------\n\t\t\t\t\t\t------------      T O     -----------\n\t\t\t\t\t\t-----------S T A T V E R S E---------\n\n\n";
	favourite();

	cout<<"\t\t\t\tAre you a fan or a PCB offical?( A FOR FAN B FOR PCB OFFICIAL)";
	cin>>choice;
	system("CLS");
	
	if(choice=='B' || choice =='b')
	{
		franchise_Interface f;
		f.interface();
		

		system("CLS");
		cout<<"\n\n\n\n\t\t\t\t\t\t\tLogin successfull!\n\n\n";
		int i=0,j;
		f.draft();
		cout<<"\n\n\n\t\t\t-------------------- P L A Y E R    D R A F T    C O M P L E T E D ---------------------------\n\n";
		f.viewteams();
		main();
	}
	
	else if(choice=='A' || choice=='a')
	
	{
		cout<<"\n\n\n\n\n\t\t\t------------------------------- H E L L O    C R I C K E T    L O V E R ------------------------------\n\n\n\n";
		cout<<" \n\n\t\t\t1) View bowlers stats\n\n\t\t\t2) View batsmen stats\n\n\t\t\t3) View All-Rounders stats\n\n\t\t\t4) Stats guru analysis\n\n\t\t\t5) Vote for your favourite player\n\n\n\n\t\t\t\t\t\t\t\tEnter Your choice: ";
		int choice;
		cin>>choice;
		if(choice==1)
		{
			bowler b;
			b.read();  //display bowler file
			main();	
		}
		
		else if(choice==2)
		{
			batsman b1;
			b1.read();
			main();	
			
		}
		
		else if(choice==3)
		{
			allrounder a;
			a.read();
			main();	
		}
		
	else if(choice==4)
		{
	           char ch;
	            cout<<"Single filter or Multiple filter? (s or m)";
	            cin>>ch;
	              if(ch=='s'|| ch=='S')
	                  {   
		                  int c;
		                  cout<<"1)No of runs\n2)No of wickets\n3)No of matches played\n4)Age\n5)Batting Average\n6)Bowling Average\n7)Batting SR\n8)Bowling Economy\n\n\t\t";
		                  cin>>c;
        
                                if(c==1)
		                               {
		                                 	int r;
		                                 	char x;
		                                 	cout<<"\nEnter the no of runs: ";
		                                	cin>>r;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = r;
											int compare_value1 = 0;
											string stat_type = "runcheck";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
		
											if(x=='l')
											cout<<"\nBatsmen and allrounders with runs less than "<<compare_value<<" are:\n\n\n   Player\t\t\tRuns Scored\n\n";
		
											else if(x=='g')
											cout<<"\nBatsmen and allrounders with runs greater than "<<compare_value<<" are:\n\n\n   Player\t\t\tRuns Scored\n\n";

											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);		
										}		
								else if(c==2)
									    {
											int w;
									    	char x;
		
											cout<<"\nEnter the no of wickets: ";
											cin>>w;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = w;
											int compare_value1 = 0;
											string stat_type = "wicketcheck";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
		
		
		
											if(x=='l')
											cout<<"\nBowlers with less than "<<compare_value<<" wickets are:\n\n\n   Player\t\t\tWickets Taken\n\n";
											
											if(x=='g')
											cout<<"\nBowlers with greater than "<<compare_value<<" wickets are:\n\n\n   Player\t\t\tWickets Taken\n\n";
									
											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);           
										}
	    						else if(c==3)
										{
									        int m;
											char x;
											
											cout<<"\nEnter the no of matches played: ";
											cin>>m;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = m;
											string stat_type = "matchcheck";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
											int compare_value1 = 0;
									
											
											if(x=='l')
											cout<<"\nPlayers that played less than "<<compare_value<<" matches are:\n\n\n   Player\t\t\tMatches Played\n\n";
											
											else if(x=='g')
											cout<<"\nPlayers that played greater than "<<compare_value<<" matches are:\n\n\n   Player\t\t\tMatches Played\n\n";
									
											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
										}
	                     		else if(c==4)
										{
											int a;
											char x;
											
											cout<<"\nEnter the age of player: ";
											cin>>a;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = a;
											int compare_value1 = 0;
											string stat_type = "agecheck";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
											
											if(x=='l')
											cout<<"\nPlayers with age less than "<<compare_value<<" are:\n\n\n   Player\t\t\tAge\n\n";
											
											else if(x=='g')
											cout<<"\nPlayers with age greater than "<<compare_value<<" are:\n\n\n   Player\t\t\tAge\n\n";

											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
										}
								else if(c==5)
										{
											int a;
											char x;
											
											cout<<"\nEnter the batting average of player ";
											cin>>a;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = a;
											int compare_value1 = 0;
											string stat_type = "bataverage";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
											
											if(x=='l')
											cout<<"\nPlayers with batting average less than "<<compare_value<<" are:\n\n\n   Player\t\t\tAverage\n\n";
											
											else if(x=='g')
											cout<<"\nPlayers with batting average greater than "<<compare_value<<" are:\n\n\n   Player\t\t\tAverage\n\n";
									
											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);
										}
								else if(c==6)
										{
											int a;
											char x;
											
											cout<<"\nEnter the bowling average of player ";
											cin>>a;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = a;
											int compare_value1 = 0;
											string stat_type = "bowlaverage";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
											
											if(x=='l')
											cout<<"\nPlayers with bowling average less than "<<compare_value<<" are:\n\n\n   Player\t\t\tAverage\n\n";
											
											else if(x=='g')
											cout<<"\nPlayers with bowling average greater than "<<compare_value<<" are:\n\n\n   Player\t\t\tAverage\n\n";
									
									        filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);		
										}
	                            else if(c==7)
		                                {
											int a;
											char x;
											
											cout<<"\nEnter the batting strikerate of player ";
											cin>>a;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = a;
											int compare_value1 = 0;
											string stat_type = "batsrate";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
											
											if(x=='l')
											cout<<"\nPlayers with batting strikerate less than "<<compare_value<<" are:\n\n\n   Player\t\t\tStrike Rate\n\n";
											
											else if(x=='g')
											cout<<"\nPlayers with batting strikerate greater than "<<compare_value<<" are:\n\n\n   Player\t\t\tStrike Rate\n\n";
									
											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);
                                        }
								else if(c==8)
										{
										   	int a;
											char x;
											
											cout<<"\nEnter the economy of player ";
											cin>>a;
											cout<<"\nLess than or greater than(l or g)";
											cin>>x;
											int compare_value = a;
											int compare_value1 = 0;
											string stat_type = "bowlecon";
											char greaterthanlessthancheck = x;
											string stat_type1 = "0";
											char greaterthanlessthancheck1 = '0';
											
											if(x=='l')
											cout<<"\nPlayers with bowling economy less than "<<compare_value<<" are:\n\n\n   Player\t\t\tEconomy\n\n";
											
											else if(x=='g')
											cout<<"\nPlayers with bowling economy greater than "<<compare_value<<" are:\n\n\n   Player\t\t\tEconomy\n\n";
									
											filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);
										}
										main();
                            }
	


else if(ch=='m' || ch=='M')
	{
		int c;
		cout<<"\n\n\t\tEnter filter combination: \n\t\t\t1. Wickets and runs\n\t\t\t2. Runs and age\n\t\t\t3. Wickets and Macthes\n\t\t\t4. Batting average and Batting Strike Rate\n\t\t\t5. Bowling Average and economy\n\t\t\t6. Batting Strike Rate and Bowling Economy    \n\t\t\t7. Runs and Matches        \n\t\t\t8. Batting Average and Macthes      \n\n";
		cin>>c;
		
		
		int w,r;
		char x,y;
		if(c==1)
		{
			cout<<"\nEnter number of wickets and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //wickets  w,x
			char greaterthanlessthancheck = x;
			string stat_type="wicketcheck"   ;     
			 
			cout<<"\nEnter number of runs and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="runcheck"   ;
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nAll rounders with runs greater than "<<r<<" runs and wickets greater than "<<w<<" are:\n\n\n   Player\t\t\tWickets\t\t\tRuns\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nAll rounders with runs lesser than "<<r<<" and wickets greater than "<<w<<" are:\n\n\n   Player\t\t\tWickets\t\t\tRuns\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nAll rounders with runs greater than "<<r<<" and wickets less than "<<w<<" are:\n\n\n   Player\t\t\tWickets\t\t\tRuns\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nAll rounders with runs lesser than "<<r<<" and wickets lesser than "<<w<<" are:\n\n\n   Player\t\t\tWickets\t\t\tRuns\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();		
		}
		
		if(c==2)
		{
		    cout<<"\nEnter age and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="agecheck"   ;     
			 
			cout<<"\nEnter number of runs and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="runcheck";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with age greater than "<<w<<" and runs greater than "<<r<<" are:\n\n\n   Player\t\t\tAge\t\t\tRuns\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with age greater than "<<w<<" and runs less than "<<r<<" are:\n\n\n   Player\t\t\tAge\t\t\tRuns\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with age lesser than "<<w<<" and runs greater than "<<r<<" are:\n\n\n   Player\t\t\tAge\t\t\tRuns\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with age lesser than "<<w<<" and runs lesser than "<<r<<" are:\n\n\n   Player\t\t\tAge\t\t\tRuns\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();		
			
		}
		    
		
		if(c==3)
		{
			cout<<"\nEnter wickets and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="wicketcheck"   ;     
			 
			cout<<"\nEnter number of matches and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="matchcheck";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with wickets greater than "<<w<<" and macthes greater than "<<r<<" are:\n\n\n   Player\t\t\tWickets\t\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with wickets greater than "<<w<<" and macthes lesser than "<<r<<" are:\n\n\n    Player\t\t\tWickets\t\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with wickets lesser than "<<w<<" and macthes greater than "<<r<<" are:\n\n\n    Player\t\t\tWickets\t\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with wickets lesser than "<<w<<" and macthes lesser than "<<r<<" are:\n\n\n     Player\t\t\tWickets\t\t\tMatches\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();		
		}
		
		
		else if(c==4)
		{
			cout<<"\nEnter batting strike rate and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="srcheck"   ;     
			 
			cout<<"\nEnter batting average and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="avgcheck";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with Strike Rate greater than "<<w<<" and Average greater than "<<r<<" are:\n\n\n   Player\t\t\tStrike Rate\t\tBatting Average\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with Strike Rate greater than "<<w<<" and Average lesser than "<<r<<" are:\n\n\n    Player\t\t\tStrike Rate\t\tBatting Average\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with Strike Rate lesser than "<<w<<" and Average greater than "<<r<<" are:\n\n\n    Player\t\t\tStrike Rate\t\tBatting Average\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with Strike Rate lesser than "<<w<<" and Average lesser than "<<r<<" are:\n\n\n     Player\t\t\tStrike Rate\t\tBatting Average\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();	
		}
		
	else if(c==5)
	{
		cout<<"\nEnter Bowling average and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="bowlavg"   ;     
			 
			cout<<"\nEnter bowling economy and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="bowlecon";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with economy greater than "<<r<<" and bowling average  greater than "<<w<<" are:\n\n\n  Player\t\t\tEconomy\t\tBowling Average\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with economy greater than "<<r<<" and bowling average lesser than "<<w<<" are:\n\n\n    Player\t\t\tEconomy\t\tBowling Average\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with economy lesser than "<<r<<" and bowling average greater than "<<w<<" are:\n\n\n    Player\t\t\tEconomy\t\tBowling Average\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with economy lesser than "<<r<<" and bowling average lesser than "<<w<<" are:\n\n\n     Player\t\t\tEconomy\t\tBowling Average\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();	
	}
	else if(c==6)
	{
		cout<<"\nEnter Batting strike rate and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="srcheck"   ;     
			 
			cout<<"\nEnter bowling economy and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="bowlecon";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with economy greater than "<<r<<" and batting strike rate  greater than "<<w<<" are:\n\n\n  Player\t\t\tEconomy\t\tBatting strike rate\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with economy greater than "<<r<<" and batting strike rate lesser than "<<w<<" are:\n\n\n    Player\t\t\tEconomy\t\tBatting strike rate\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with economy lesser than "<<r<<" and batting strike rate greater than "<<w<<" are:\n\n\n    Player\t\t\tEconomy\t\tBatting strike rate\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with economy lesser than "<<r<<" and batting strike rate lesser than "<<w<<" are:\n\n\n     Player\t\t\tEconomy\t\tBatting strike rate\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();	
	}
    else if(c==7)
	{
		cout<<"\nEnter Runs and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="runcheck"   ;     
			 
			cout<<"\nEnter Matches and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="matchcheck";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with runs greater than "<<w<<" and matches greater than "<<r<<" are:\n\n\n  Player\t\t\tRuns\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with runs greater than "<<w<<" and matches lesser than "<<r<<" are:\n\n\n    Player\t\t\tRuns\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with runs lesser than "<<w<<" and matches greater than "<<r<<" are:\n\n\n    Player\t\t\tRuns\t\tMatches\n\n";
		
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with runs lesser than "<<w<<" and matches lesser than "<<r<<" are:\n\n\n     Player\t\t\tRuns\t\tMatches\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();	
	}
    else if(c=8)
	{
		cout<<"\nEnter Batting average and greater than or less than (g or l): ";
			cin>>w>>x;
			int compare_value = w;                    //age  w,x
			char greaterthanlessthancheck = x;
			string stat_type="bataverage"   ;     
			 
			cout<<"\nEnter Matches and greater than or less than(g or l): ";
			cin>>r>>y;
			int compare_value1 = r;                        //runs  r,y
			char greaterthanlessthancheck1 = y;
			string stat_type1="matchcheck";
			
			if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='g' )
			cout<<"\nPlayers with batting average greater than "<<w<<" and matches greater than "<<r<<" are:\n\n\n  Player\t\t\tBatting average\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='g' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with batting average greater than "<<w<<" and matches lesser than "<<r<<" are:\n\n\n    Player\t\t\tBatting average\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='g')
			cout<<"\nPlayers with batting average lesser than "<<w<<" and matches greater than "<<r<<" are:\n\n\n    Player\t\t\tBatting average\t\tMatches\n\n";
			
			else if(greaterthanlessthancheck=='l' && greaterthanlessthancheck1=='l')
			cout<<"\nPlayers with batting average lesser than "<<w<<" and matches lesser than "<<r<<" are:\n\n\n     Player\t\t\tBatting average\t\tMatches\n\n";
			
			filter(compare_value,greaterthanlessthancheck,compare_value1,greaterthanlessthancheck1, stat_type, stat_type1);	
			main();	
	}
   
	}

		}

else if(choice==5)
{
	int f,thisid;
	cout<<"\n\n\t\t\tIs your favourite player a bowler, batsmen or an all-rounder?(1, 2 or 3): ";
	cin>>f;
	if(f==1)
	{
		bowler b;
		b.read();  
		cout<<"\n\t\tHere is a list of bowlers. Enter the id of player you want to vote.. ";
		cin>>thisid;
		b.vote(thisid); //function to vote bowler in Bowler class
	}
	if(f==2)
	{
		batsman b;
		b.read();
		cout<<"\n\t\tHere is a list of batsmen. Enter the id of player you want to vote.. ";
		cin>>thisid;
		b.vote(thisid);
	}
	
	if(f==3)
	{
		allrounder a;
		a.read();
		cout<<"\n\n\tHere is a list of All-rounders. Enter the id of player you want to vote.. ";
		cin>>thisid;
	    a.vote(thisid);
	}
	main();	
}
}
	
}

	







