#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include<windows.h>
#include<iomanip>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
class Loading_system
{
     public:
	  void loading()
	  {
	  	    SetConsoleTextAttribute(h,3);
		    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
			cout<<"\t\t Loading ";
		    char x=219;
		    
		    for(int i=0;i<35;i++)
		    {
		    	cout<<x;
		    	if(i<10)
		    	{
		    	    Sleep(300);	
				}
		    	else if(i>10 && i<20)
		    	{
		    		Sleep(150);	
				}
				else if(i>10)
				{
					Sleep(25);
				}
			}
			system("cls");	
	  }	
};

class Node
{
	public:
		int patient_id;
		string patient_name;
		string patient_father_name;
		string id_card;
		string patient_phone_no;
		string patient_entry_record_date;
		string patient_address;
		string appointment_date;
		string appointment_name;
		string doctor_name;
		string doctor_profession;
		string appointment_time;
		string disease_name;
		string leaving_time_hospital;
		string patient_gender;
		Node* next;		
	Node()
	{
		int patient_id = 0;
		long id_card = 0;
		long patient_phone_no = 0;
		next=NULL;
	}
	Node(int id,string address,string entry_record_data,string name,string father_name,string gender,int id_c,int p_no,
	string disease,string a_date,string a_name,string doc_name,string pro_name,string appointment_time1,
	string time_hospital )
	{
		int patient_id = id;
		string patient_address = address;
		string patient_entry_record_date = entry_record_data;
		string patient_name = name;
		string patient_father_name = father_name;
        string patient_gender = gender;
		long id_card = id_c;
		long patient_phone_no = p_no;
		string disease_name = disease ;
		string appointment_date = a_date;
		string appointment_name = a_name;
		string doctor_name = doc_name;
		string doctor_profession = pro_name;
		string appointment_time = appointment_time1;
		string leaving_time_hospital = time_hospital;
	}
};
class Singly_linklist
{
	public:
	Node* head;
	Singly_linklist()
	{
		head=NULL;
	}
		
	Singly_linklist(Node* n)
	{
		head=n;
	}	
		
	// 1 : NodeExisting
	// like cerate	
	Node* nodeExist(int d)
	{
		Node* temp=NULL;
		Node* ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->patient_id==d)
			{
				temp=ptr;
			}
			ptr=ptr->next;
		}
			return temp;
	}
		
	// 2 : ApendNode
	//Insert at end
	void AppendNode(Node* n)
	{
		if(nodeExist(n->patient_id)!=NULL)
		{
			cout<<"\n\t\t\t\t\t\t\t\tThis Key is Already Exist = "<<n->patient_id<<"\n\t\t\t\t\t\t\t\tEnter Another key to creat a record";
		}
		else
		{
			if(head==NULL)
			{
				head=n;
				cout<<"\n\t\t\t\t\t\t\t\tAppend data is Create :-)";
			}
			else
			{
				Node* ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				cout<<"\n\t\t\t\t\t\t\t\tAppend data is Creat :-)";
			}
		}
	}
		
	// 3 : PrependNode
	//Insert at begin
	void PrependNode(Node* n)
	{
		if(nodeExist(n->patient_id)!=NULL)
		{
			cout<<"\n\t\t\t\t\t\t\t\tThis Key is Already Exist= "<<n->patient_id<<"\n\t\t\t\t\t\t\t\tEnter Another key to create record";
		}
		else
		{
			n->next=head;
			head=n;
			cout<<"\n\t\t\t\t\t\t\t\tPrepend data is Create :-)";
		}
    }
		
	// 4 : InsertNode
	void insertNode(int d,Node* n)
	{
		Node* ptr=nodeExist(d);
		if(ptr==NULL)
		{
			cout<<"\n\t\t\t\t\t\t\t\tThis Key is Already Exist";
		}
		else
		{
			n->next=ptr->next;
			ptr->next=n;
			cout<<"\n\t\t\t\t\t\t\t\tInsert Data is Create :-)";
		}
	}
		
	// 5 : DetelingNode 
	void deletNode(int d)
	{
		if(head==NULL)
		{
			cout<<"\n\t\t\t\t\t\t\t\tRecord Already Empty";
		}
		else if(head!=NULL)
		{
			if(head->patient_id==d)
			{
				head=head->next;
				cout<<"\n\t\t\t\t\t\t\t\tUnlike Record was Delete";
			}
		    else
			{
				Node* temp=NULL;
				Node* Preptr=head;
				Node* creptr=head->next;
				while(creptr!=NULL)
				{
					if(creptr->patient_id==d)
				    {
						temp=creptr;
						creptr=NULL;
					}
					else
					{
						Preptr=Preptr->next;
						creptr=creptr->next;
					}
				}
				if(temp!=NULL)
				{
					Preptr->next=temp->next;
					cout<<"\n\t\t\t\t\t\t\t\tUnlike record was Delete";
				}
				else
				{
					cout<<"\n\t\t\t\t\t\t\t\tThis key not exist";
				}
				}
		}		
	}
		
	// 6 : UpdateNode
	void updatNode(int id,string address,string entry_record_data,string name,string father_name,string gender,string id_c,
	string p_no,string disease,string a_date,string a_name,string doc_name,string pro_name,string appointment_time1,
	string time_hospital)
	{
		Node* ptr=nodeExist(id);
		if(ptr==NULL)
		{
			cout<<"\n\t\t\t\t\t\t\t\tThis key Already exist";
		}
		else
		{
			ptr->patient_id = id;
			ptr->patient_address = address;
			ptr->patient_entry_record_date = entry_record_data;
		    ptr->patient_name = name;
		    ptr->patient_father_name = father_name;
            ptr->patient_gender = gender;
		    ptr->id_card = id_c;
		    ptr->patient_phone_no = p_no;
		    ptr->disease_name = disease ;
		    ptr->appointment_date = a_date;
		    ptr->appointment_name = a_name;
		    ptr->doctor_name = doc_name;
		    ptr->doctor_profession = pro_name;
		    ptr->appointment_time = appointment_time1;
		    ptr->leaving_time_hospital = time_hospital;
			cout<<"\n\t\t\t\t\t\t\t\tData is Update :-)"<<id<<endl;
		}
	}
	
	//Search Node
	void Search_Node(int id)
	{
		Node* ptr=nodeExist(id);
		if(ptr==NULL)
		{
				cout<<"\n\t\t\t\t\t\t\t\trecord Not Exist :-(";
			}
			else if(id==ptr->patient_id)
			{
			cout<<"\n\t\t\t\t\t\t\t\t|   Patient ID :                                   | = "<<ptr->patient_id;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Address :                              | = "<<ptr->patient_address;
		    time_t timetoday;
            time(&timetoday);
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Entry Date and Time Hospital:          | = "<<asctime(localtime(&timetoday));
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Patient Entry Record Date,Time and Day:| = "<<ptr->patient_entry_record_date;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Name :                                 | = "<<ptr->patient_name;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Father Name :                          | = "<<ptr->patient_father_name;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Gender :                               | = "<<ptr->patient_gender;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient ID Card :                              | = "<<ptr->id_card;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Phone Number :                         | = "<<ptr->patient_phone_no;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Disease Name :                         | = "<<ptr->disease_name;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Paitent Appointment Date :                     | = "<<ptr->appointment_date;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Paitent Appointment Name :                     | = "<<ptr->appointment_name;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Doctor Name :                          | = "<<ptr->doctor_name;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Professional DOC Name :                | = "<<ptr->doctor_profession;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Patient Doctor Checkup Time :                  | = "<<ptr->appointment_time;
		    cout<<"\n\t\t\t\t\t\t\t\t|   Paitent Levaing Hospital Time :                | = "<<ptr->leaving_time_hospital;
		    cout<<"\n\t\t\t\t\t\t\t\t|                                                  |";
		    cout<<"\n\t\t\t\t\t\t\t\t|__________________________________________________|---->";
			}
		}
		
		// 7 : printNode
		void PrintNode()
		{
			if(head==NULL)
			{
				cout<<"\n\t\t\t\t\t\t\t\tRecord Alredy Empty";
			}
			else
			{
				cout<<"\n\t\t\t\t\t\t\t\tRecord Value";
				Node* ptr=head;
				while(ptr!=NULL)
				{
			        cout<<"\n\t\t\t\t\t\t\t\t|   Patient ID :                                   | = "<<ptr->patient_id;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Address :                              | = "<<ptr->patient_address;
		            time_t timetoday;
                    time(&timetoday);
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Entry Date and Time Hospital:          | = "<<asctime(localtime(&timetoday));
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Patient Entry Record Date,Time and Day:| = "<<ptr->patient_entry_record_date;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Name :                                 | = "<<ptr->patient_name;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Father Name :                          | = "<<ptr->patient_father_name;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Gender :                               | = "<<ptr->patient_gender;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient ID Card :                              | = "<<ptr->id_card;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Phone Number :                         | = "<<ptr->patient_phone_no;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Disease Name :                         | = "<<ptr->disease_name;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Paitent Appointment Date :                     | = "<<ptr->appointment_date;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Paitent Appointment Name :                     | = "<<ptr->appointment_name;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Doctor Name :                          | = "<<ptr->doctor_name;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Professional DOC Name :                | = "<<ptr->doctor_profession;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Patient Doctor Appointment Time :              | = "<<ptr->appointment_time;
		            cout<<"\n\t\t\t\t\t\t\t\t|   Paitent Levaing Hospital Time :                | = "<<ptr->leaving_time_hospital;
		            cout<<"\n\t\t\t\t\t\t\t\t|                                                  |";
		            cout<<"\n\t\t\t\t\t\t\t\t|__________________________________________________|---->";
					ptr=ptr->next;
				}
			}
		}
};
int main()
{
	Singly_linklist s;
	Loading_system ls;
	ls.loading();
	system ("color 3F");
	
	int op;
	int key1,d1,data1;
	int o; 
	int patient_id1;
	string patient_name1;
	string patient_father_name1;
	string id_card1;
	string patient_phone_no1;
	string patient_entry_record_date1;
	string patient_address1;
	string appointment_date1;
	string appointment_name1;
	string doctor_name1;
	string doctor_profession1;
	string appointment_time1;
	string disease_name1;
	string leaving_time_hospital1;
	string patient_gender1;
	string month ;
    string year ;
    string day;                    		
	fstream Paient_File;
	fstream Paient_File1;
	
	cout<<"\n\n\n\n\n\t\t\t\t\t\t _________________________________________________________________________";
	cout<<"\n\t\t\t\t\t\t|                                                                         |";
	cout<<"\n\t\t\t\t\t\t|    _________________________________________________________________    |";
	cout<<"\n\t\t\t\t\t\t|   |                                                                 |   |";
	cout<<"\n\t\t\t\t\t\t|   |                         HOSPITAL ZUNI                           |   |";
	cout<<"\n\t\t\t\t\t\t|   |                                                                 |   |";
	cout<<"\n\t\t\t\t\t\t|   |                 ##############################                  |   |";
	cout<<"\n\t\t\t\t\t\t|   |                                                                 |   |";
	cout<<"\n\t\t\t\t\t\t|   |                  WELCOME TO THE ZUNI HOSPITAL                   |   |";
	cout<<"\n\t\t\t\t\t\t|   |                                                                 |   |";
	cout<<"\n\t\t\t\t\t\t|   |_________________________________________________________________|   |";
	cout<<"\n\t\t\t\t\t\t|                                                                         |";
	cout<<"\n\t\t\t\t\t\t|_________________________________________________________________________|\n\n\n\n";
			
		main_meun:	
	    menu:
		
		cout<<"\n\t\t\t\t\t\t    ___________________________________________________________________";
	    cout<<"\n\t\t\t\t\t\t   |                                                                   |";
	    cout<<"\n\t\t\t\t\t\t   |       |   Press 1 : To the Patient Data by physically      |      |";
	    cout<<"\n\t\t\t\t\t\t   |       |   Press 2 : To the Patient Data by Online From     |      |";
	    cout<<"\n\t\t\t\t\t\t   |       |   Press 3 : To the Patient Data File Panel         |      |";
	    cout<<"\n\t\t\t\t\t\t   |       |   Press 4 : To Exit                                |      |";
	    cout<<"\n\t\t\t\t\t\t   |___________________________________________________________________|\n\n";
		cout<<"\n\t\t\t\t\t\t   SELECT ANY OPTION DO YOU WANT :-)= ";
		cin>>o;
		system("cls");
		if(o==1)
		{
			do
	        {	
	            
	            	
	            cout<<"\n\t\t\t\t\t\t\t _______________________________________________________ ";
		        cout<<"\n\t\t\t\t\t\t\t|    _______________________________________________    |";    
		        cout<<"\n\t\t\t\t\t\t\t|   |                                               |   |";
		        cout<<"\n\t\t\t\t\t\t\t|   |          Patient Data by physically           |   |";
		        cout<<"\n\t\t\t\t\t\t\t|   |_______________________________________________|   |";
		        cout<<"\n\t\t\t\t\t\t\t|_______________________________________________________|\n";

		        cout<<"\n\t\t\t\t\t ___________________________________________________________________________________________";
		        cout<<"\n\t\t\t\t\t|                                                                                           |";
		        cout<<"\n\t\t\t\t\t|    ___________________________________________________________________________________    |";
		        cout<<"\n\t\t\t\t\t|   |                                                                                   |   |";
		        cout<<"\n\t\t\t\t\t|   |                                                                                   |   |";
	        	cout<<"\n\t\t\t\t\t|   |          PRESS 1 : ENTER THE NEW PATIENT DATA                                     |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 2 : ENTER THE NEW PATIENT DATA IN FIRST ON HEAD ASSIGN             |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 3 : INSERT THE NEW PATIENT DATA IN OTHER                           |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 4 : DELETE THE ANY OTHER PATIENT DATA                              |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 5 : UPDATE THE PATIENT DATA                                        |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 6 : SEARCH THE PATIENT DATA                                        |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 7 : DISPLAY THE ALL PATIENT RECORDS                                |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 8 : FOR GROUP INFORMATION                                          |   |";
		        cout<<"\n\t\t\t\t\t|   |                                                                                   |   |";
		        cout<<"\n\t\t\t\t\t|   |          PRESS 0 : Back To Main menu                                              |   |";
		        cout<<"\n\t\t\t\t\t|   |                                                                                   |   |";
		        cout<<"\n\t\t\t\t\t|   |___________________________________________________________________________________|   |";
		        cout<<"\n\t\t\t\t\t|                                                                                           |";
		        cout<<"\n\t\t\t\t\t|___________________________________________________________________________________________|\n\n";
		        
		        cout<<"\t\t\t\t\t\t ________________________________________________________________";
		        cout<<"\n\t\t\t\t\t\t|    ________________________________________________________    |";   
		        cout<<"\n\t\t\t\t\t\t|   |          SELECT ANY OPTION DO YOU WANT :-)             |   |";
		        cout<<endl<<"        \t\t\t\t                                                         ";
				cin>>op;
		        cout<<"\t\t\t\t\t\t|   |________________________________________________________|   |";
		        cout<<"\n\t\t\t\t\t\t|________________________________________________________________|\n\n";
	      		system("cls");
		        Node *n1=new Node;
		        switch(op)
		        {
			        case 0:
				        break;
				        
			        case 1:
				
				        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
			            cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
				        cout<<"\n\n\t\t\t\t\t\t\t\t______  WELCOME TO ADD THE NEW PATIENT DATA  ______";
				        cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
				        cout<<"\n\n\t\t\t\t\t\t\t\t***************************************************\n\n";
				    
				        cout<<"\n\t\t\t\t\t\t\t\tPatient ID :";
		                cin>>patient_id1;

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Address : ";
		                cin.ignore();
		                getline(cin,patient_address1);

                        time_t timetoday;
                        time(&timetoday);
		    
		                patient_entry_record_date1 = asctime(localtime(&timetoday));
								
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Name : ";
		                getline(cin,patient_name1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Father Name : ";
		                getline(cin,patient_father_name1);
		                
		                back:
		                cout<<"\n\t\t\t\t\t\t\t\tEnter Gender Male/Female :";
		                cin>>patient_gender1;
		                if(patient_gender1 == "Female")
		                {
		                	cout<<" ";
						}
						else if(patient_gender1 == "Male")
						{
							cout<<" ";
						}
						else 
						{
							goto back;
						}
		
		                p1:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient ID Card : ";
		                cin>>id_card1;
		                if ((id_card1.length() > 15) || (id_card1.length() < 15))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p1;
                        }
		
		                p2:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Phone Number : ";
		                cin>>patient_phone_no1;
		                if ((patient_phone_no1.length() > 11) || (patient_phone_no1.length() < 11))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p2;
                        }
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Disease Name : ";
		                cin.ignore();
		                getline(cin,disease_name1);
		        
		                
                        cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Date : ";
                        cout<<"\n\t\t\t\t\t\t\t\tMonth:";
                        cin>>month;
                        cout<<"\n\t\t\t\t\t\t\t\tYear:";
                        cin>>year;
                        cout<<"\n\t\t\t\t\t\t\t\tDay:";
                        cin>>day;
                        appointment_date1 = day + "/" + month + "/" +year;
		                cin.ignore();
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Name : ";
	                	getline(cin,appointment_name1);
	 
	                	cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Name : ";
		                getline(cin,doctor_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Professional Doctor Name : ";
		                getline(cin,doctor_profession1);

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Checkup Time : ";
		                getline(cin,appointment_time1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Levaing Hospital Time : ";
		                getline(cin,leaving_time_hospital1);
	         		
         				n1->patient_id = patient_id1;
			            n1->patient_address = patient_address1;
			            n1->patient_entry_record_date = patient_entry_record_date1;
		                n1->patient_name = patient_name1;
		                n1->patient_father_name = patient_father_name1;
                        n1->patient_gender = patient_gender1;
		                n1->id_card = id_card1;
		                n1->patient_phone_no = patient_phone_no1;
		                n1->disease_name = disease_name1 ;
		                n1->appointment_date = appointment_date1;
		                n1->appointment_name = appointment_name1;
		                n1->doctor_name = doctor_name1;
		                n1->doctor_profession = doctor_profession1;
		                n1->appointment_time = appointment_time1;
		                n1->leaving_time_hospital = leaving_time_hospital1;
				        
         				s.AppendNode(n1);
         				system("cls");
	         			break;
	         			
         			case 2:
				
         				cout<<"\n\n\n\n\t\t\t\t\t\t\t\t********************************************************************";
         		        cout<<"\n\n\t\t\t\t\t\t\t\t______                                                        ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t______WELCOME TO ADD NEW PATIENT DATA IN FIRST ON HEAD ASSIGN ______";
		                cout<<"\n\n\t\t\t\t\t\t\t\t______                                                        ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t*********************************************************************\n\n";        
				
         				cout<<"\n\t\t\t\t\t\t\t\tPatient ID :";
		                cin>>patient_id1;

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Address : ";
		                cin.ignore();
		                getline(cin,patient_address1);
		
		                
	    
                        time(&timetoday);
		    
		                patient_entry_record_date1 = asctime(localtime(&timetoday));
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Name : ";
		                getline(cin,patient_name1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Father Name : ";
		                getline(cin,patient_father_name1);
		
		                back1:
		                cout<<"\n\t\t\t\t\t\t\t\tEnter Gender Male/Female :";
		                cin>>patient_gender1;
		                if(patient_gender1 == "Female")
		                {
		                	cout<<" ";
						}
						else if(patient_gender1 == "Male")
						{
							cout<<" ";
						}
						else 
						{
							goto back1;
						}
		
		                p11:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient ID Card : ";
		                cin>>id_card1;
		                if ((id_card1.length() > 15) || (id_card1.length() < 15))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p11;
                        }
		
		                p22:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Phone Number : ";
		                cin>>patient_phone_no1;
		                if ((patient_phone_no1.length() > 11) || (patient_phone_no1.length() < 11))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p22;
                        }
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Disease Name : ";
		                cin.ignore();
		                getline(cin,disease_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Date : ";
                        cout<<"\n\t\t\t\t\t\t\t\tMonth:";
                        cin>>month;
                        cout<<"\n\t\t\t\t\t\t\t\tYear:";
                        cin>>year;
                        cout<<"\n\t\t\t\t\t\t\t\tDay:";
                        cin>>day;
                        appointment_date1 = day + "/" + month + "/" +year;
		                cin.ignore();
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Name : ";
	                	getline(cin,appointment_name1);
	 
	                	cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Name : ";
		                getline(cin,doctor_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Professional DOC Name : ";
		                getline(cin,doctor_profession1);

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Checkup Time : ";
		                getline(cin,appointment_time1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Levaing Hospital Time : ";
		                getline(cin,leaving_time_hospital1);
		                
	         		    n1->patient_id = patient_id1;
			            n1->patient_address = patient_address1;
			            n1->patient_entry_record_date = patient_entry_record_date1;
		                n1->patient_name = patient_name1;
		                n1->patient_father_name = patient_father_name1;
		                n1->patient_gender = patient_gender1;
		                n1->id_card = id_card1;
		                n1->patient_phone_no = patient_phone_no1;
		                n1->disease_name = disease_name1 ;
		                n1->appointment_date = appointment_date1;
		                n1->appointment_name = appointment_name1;
		                n1->doctor_name = doctor_name1;
		                n1->doctor_profession = doctor_profession1;
		                n1->appointment_time = appointment_time1;
		                n1->leaving_time_hospital = leaving_time_hospital1;
				
	         			s.PrependNode(n1);
	         			system("cls");
	         			break;
	         			
			         case 3:
				
         				cout<<"\n\n\n\n\t\t\t\t\t\t\t\t*********************************************************************";
         		        cout<<"\n\n\t\t\t\t\t\t\t\t______                                                         ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t______      WELCOME TO INSERT THE NEW PATIENT DATA IN OTHER    ______";
		                cout<<"\n\n\t\t\t\t\t\t\t\t______                                                         ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t**********************************************************************\n\n"; 
				
		         		cout<<"\n\t\t\t\t\t\t\t\tEnter the Patient ID do you want To insert OR Add the new Patinet Data = ";
			         	cin>>d1;
			         	
         				cout<<"\n\t\t\t\t\t\t\t\tPatient ID :";
		                cin>>patient_id1;

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Address : ";
		                cin.ignore();
		                getline(cin,patient_address1);
	                
	                    
                        time(&timetoday);
		    
		                patient_entry_record_date1 = asctime(localtime(&timetoday));
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Name : ";
		                getline(cin,patient_name1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Father Name : ";
		                getline(cin,patient_father_name1);
		
		                back11:
		                cout<<"\n\t\t\t\t\t\t\t\tEnter Gender Male/Female:";
		                cin>>patient_gender1;
		                if(patient_gender1 == "Female")
		                {
		                	cout<<" ";
						}
						else if(patient_gender1 == "Male")
						{
							cout<<" ";
						}
						else 
						{
							goto back11;
						}
		                p111:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient ID Card : ";
		                cin>>id_card1;
		                if ((id_card1.length() > 15) || (id_card1.length() < 15))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p111;
                        }
		
		                p222:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Phone Number : ";
		                cin>>patient_phone_no1;
		                if ((patient_phone_no1.length() > 11) || (patient_phone_no1.length() < 11))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p222;
                        }
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Disease Name : ";
		                cin.ignore();
		                getline(cin,disease_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Date : ";
                        cout<<"\n\t\t\t\t\t\t\t\tMonth:";
                        cin>>month;
                        cout<<"\n\t\t\t\t\t\t\t\tYear:";
                        cin>>year;
                        cout<<"\n\t\t\t\t\t\t\t\tDay:";
                        cin>>day;
                        appointment_date1 = day + "/" + month + "/" +year;
		                cin.ignore();
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Name : ";
	                	getline(cin,appointment_name1);
	 
	                	cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Name : ";
		                getline(cin,doctor_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Professional DOC Name : ";
		                getline(cin,doctor_profession1);

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Checkup Time : ";
		                getline(cin,appointment_time1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Levaing Hospital Time : ";
		                getline(cin,leaving_time_hospital1);
	         		
         				n1->patient_id = patient_id1;
			            n1->patient_address = patient_address1;
			            n1->patient_entry_record_date = patient_entry_record_date1;
		                n1->patient_name = patient_name1;
		                n1->patient_father_name = patient_father_name1;
		                n1->patient_gender = patient_gender1;
		                n1->id_card = id_card1;
		                n1->patient_phone_no = patient_phone_no1;
		                n1->disease_name = disease_name1 ;
		                n1->appointment_date = appointment_date1;
		                n1->appointment_name = appointment_name1;
		                n1->doctor_name = doctor_name1;
		                n1->doctor_profession = doctor_profession1;
		                n1->appointment_time = appointment_time1;
		                n1->leaving_time_hospital = leaving_time_hospital1;
			
	         			s.insertNode(d1,n1);
	         			system("cls");
		         		break;
		         		
         			case 4:
				
	         			cout<<"\n\n\n\n\t\t\t\t\t\t\t\t******************************************************************";
         		        cout<<"\n\n\t\t\t\t\t\t\t\t______                                                      ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t______      WELCOME DELETE THE ANY OTHER PATIENT DATA       ______";
		                cout<<"\n\n\t\t\t\t\t\t\t\t______                                                      ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t*******************************************************************\n\n"; 
				
	         			cout<<"\n\t\t\t\t\t\t\t\tEnter the Patinet ID do you want to Delte it = ";
		         		cin>>d1;
				        s.deletNode(d1);
				        system("cls");
				        break;
				        
         			case 5:
	         			
	         			cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
         		        cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t______      WELCOME UPDATE THE PATIENT DATA  ______";
		                cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	         	        cout<<"\n\n\t\t\t\t\t\t\t\t***************************************************\n\n"; 
				
         				cout<<"\n\t\t\t\t\t\t\t\tPatient ID :";
		                cin>>patient_id1;

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Address : ";
		                cin.ignore();
		                getline(cin,patient_address1);

	                    
                        time(&timetoday);
		    
		                patient_entry_record_date1 = asctime(localtime(&timetoday));
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Name : ";
		                getline(cin,patient_name1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Father Name : ";
		                getline(cin,patient_father_name1);
		
		                back111:
		                cout<<"\n\t\t\t\t\t\t\t\tEnter Gender Male/Female :";
		                cin>>patient_gender1;
		                if(patient_gender1 == "Female")
		                {
		                	cout<<" ";
						}
						else if(patient_gender1 == "Male")
						{
							cout<<" ";
						}
						else 
						{
							goto back111;
						}
		
		                p1111:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient ID Card : ";
		                cin>>id_card1;
		                if ((id_card1.length() > 15) || (id_card1.length() < 15))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p1111;
                        }
		
		                p2222:
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Phone Number : ";
		                cin>>patient_phone_no1;
		                if ((patient_phone_no1.length() > 11) || (patient_phone_no1.length() < 11))
                        {
                        cout << "\t\t\t\t\t\t\t\tInvalid Length" << endl;
                        goto p2222;
                        }
		
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Disease Name : ";
		                cin.ignore();
		                getline(cin,disease_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Date : ";
                        cout<<"\n\t\t\t\t\t\t\t\tMonth:";
                        cin>>month;
                        cout<<"\n\t\t\t\t\t\t\t\tYear:";
                        cin>>year;
                        cout<<"\n\t\t\t\t\t\t\t\tDay:";
                        cin>>day;
                        appointment_date1 = day + "/" + month + "/" +year;
		                cin.ignore();
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Name : ";
	                	getline(cin,appointment_name1);
	 
	                	cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Name : ";
		                getline(cin,doctor_name1);
	
		                cout<<"\n\t\t\t\t\t\t\t\tPatient Professional DOC Name : ";
		                getline(cin,doctor_profession1);

		                cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Checkup Time : ";
		                getline(cin,appointment_time1);
		
		                cout<<"\n\t\t\t\t\t\t\t\tPaitent Levaing Hospital Time : ";
		                getline(cin,leaving_time_hospital1);
	         		
         				n1->patient_id = patient_id1;
			            n1->patient_address = patient_address1;
			            n1->patient_entry_record_date = patient_entry_record_date1;
		                n1->patient_name = patient_name1;
		                n1->patient_father_name = patient_father_name1;
		                n1->patient_gender = patient_gender1;
		                n1->id_card = id_card1;
		                n1->patient_phone_no = patient_phone_no1;
		                n1->disease_name = disease_name1 ;
		                n1->appointment_date = appointment_date1;
		                n1->appointment_name = appointment_name1;
		                n1->doctor_name = doctor_name1;
		                n1->doctor_profession = doctor_profession1;
		                n1->appointment_time = appointment_time1;
		                n1->leaving_time_hospital = leaving_time_hospital1;
				
			         	s.updatNode(patient_id1,patient_address1,patient_entry_record_date1,
						patient_name1,patient_father_name1,patient_gender1,id_card1,patient_phone_no1,disease_name1,appointment_date1,appointment_name1,doctor_name1,doctor_profession1,
						appointment_time1,leaving_time_hospital1);
						system("cls");
			         	break;
			         	
			        case 6:
			        	
			        	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
         				cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	         			cout<<"\n\n\t\t\t\t\t\t\t\t______      WELCOME SEARCH THE PATIENT DATA  ______";
		         		cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	         			cout<<"\n\n\t\t\t\t\t\t\t\t***************************************************\n\n";
	         			
	         			cout<<"\n\t\t\t\t\t\t\t\tEnter the Patinet do you want to search = ";
		         		cin>>d1;
		         		
		         		s.Search_Node(d1);
		         		system("cls");
		         		break;
	         			
         			case 7:
				
	         			cout<<"\n\n\n\n\t\t\t\t\t\t\t\t******************************************************************";
         				cout<<"\n\n\t\t\t\t\t\t\t\t______                                                      ______";
	         			cout<<"\n\n\t\t\t\t\t\t\t\t______      WELCOME TO DISPLAY THE ALL PATIENT RECORDS      ______";
		         		cout<<"\n\n\t\t\t\t\t\t\t\t______                                                      ______";
	         			cout<<"\n\n\t\t\t\t\t\t\t\t*******************************************************************\n\n";
				
         				s.PrintNode();
         				system("pause");
         				system("cls");
	         			break;
	         		case 8:
	
	                    system("cls");
	                    cout << endl << setw(129)<<"=====================================================================================" << endl;
	                    cout << setw(90) << " ABOUT US";
	                    cout << endl << setw(129)<<"=====================================================================================" << endl;
	                    cout << setw(133) << "||                                   (3A)                                                 ||";                
	                    cout << endl << setw(133) << "||                           SEMESTER 3 PROJECT                                           ||";
	                    cout << endl << setw(133) << "||                                                                                        ||";
	                    cout << endl << setw(133) << "||             NAME :                                     ROLL NO :                       ||";
	                    cout << endl << setw(133) << "||                                                                                        ||";
	                    cout << endl << setw(133) << "||         Zunaira Javaid                                   090                           ||";
	                    cout << endl << setw(133) << "||                                                                                        ||";
	                    cout << endl << setw(133) << "||           SIR NAME:             ARIF                                                   ||";
	                    cout << endl << setw(133) << "||                                                                                        ||";
	                    cout << endl << setw(133) << "||                                                                                        ||";
	                    cout << endl << setw(133) << "||                                                                                        ||";
	                    cout << endl << setw(133) << "||                     Superior University Lahore Gold Campus                             ||";
	                    cout << endl << setw(136)  << "<------------------------------------------------------------------------------------------------->" << endl << endl << endl;
	                    system("pause");
	                    system("cls");
	                     break;
		         		
		         	default:
		         		cout<<"\n\n\n\n\t\t\t\t\t\t\t\t=======================";
			         	cout<<"\n\t\t\t\t\t\t\t\tSelect the right option";
			         	cout<<"\n\t\t\t\t\t\t\t\t=======================\n";
						system("pause");
	                    system("cls");
	                    break;	
		        }          
	        }
	        while(op!=0);
	        goto main_meun;
		}
		else if(o==2)
		{
			string y="start https://www.youtube.com/";
			string f="start https://websitedemos.net/multimed-04/";
			string s="start https://websitedemos.net/multimed-04/about/";
			char a;
			u:
			cout<<"\n\n\n\n\t\t\t\t\t\t\t\t___________________________________________________________________";
		    cout<<"\n\t\t\t\t\t\t\t\t(                                                                  )";
		    cout<<"\n\t\t\t\t\t\t\t\t(       |  Press Y : To open up the youtube              |         )";
		    cout<<"\n\t\t\t\t\t\t\t\t(       |  Press F : To open up the Online patient Form  |         )";
		    cout<<"\n\t\t\t\t\t\t\t\t(       |  Press S : To see the Hospital Information     |         )";
		    cout<<"\n\t\t\t\t\t\t\t\t(       |  Press b : Back to main menu)";
		    cout<<"\n\t\t\t\t\t\t\t\t(__________________________________________________________________)\n\n";
		    cout<<"\n\t\t\t\t\t\t\t\tEnter your Choice = ";
			cin>>a;
			
	        if(a=='y'||a=='Y')
			{
				system(y.c_str());
				system("pause");
	            system("cls");
				goto u;
			}
			else if(a=='f'||a=='F')
			{
				system(f.c_str());
				system("pause");
	            system("cls");
				goto u;
			}
			else if(a=='s'||a=='S')
			{
				system(s.c_str());
				system("pause");
	            system("cls");
				goto u;
			}
			else if(a=='b'||a=='B')
			{
	            system("cls");
				goto menu;
			}
			else
			{
				cout<<"\n\n\n\n\t\t\t\t\t\t\t\t=============";
	            cout<<"\n\t\t\t\t\t\t\t\tInvalid Input";
	            cout<<"\n\t\t\t\t\t\t\t\t=============\n\n";
	            system("pause");
	            system("cls");
				goto u;
			}
		}	
	    else if(o==3)
	    {
	        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
         	cout<<"\n\t\t\t\t\t\t\t\t______                                       ______";
         	cout<<"\n\t\t\t\t\t\t\t\t______     Patient Save Data in File         ______";
         	cout<<"\n\t\t\t\t\t\t\t\t______                                       ______";
	        cout<<"\n\t\t\t\t\t\t\t\t***************************************************\n\n";
	        
            Paient_File.open("Paient_File.csv",ios::in | ios::app);
			Paient_File<<"\nPatient ID :                           = "<<patient_id1;
		    Paient_File<<"\nPatient Address :                      = "<<patient_address1;
		    time_t tt;
	        struct tm *ti;
	        time(&tt);
	        ti= localtime(&tt);
		    Paient_File<<"\nPatient Entry Date and Time Hospital:  = "<<asctime(ti);
		    Paient_File<<"\nPatient Entry Record Date,Time and Day:= "<<patient_entry_record_date1;
	        Paient_File<<"\nPatient Name :                         = "<<patient_name1;
		    Paient_File<<"\nPatient Father Name :                  = "<<patient_father_name1;
	        Paient_File<<"\nPatient Gender :                       = "<<patient_gender1;
		    Paient_File<<"\nPatient ID Card :                      = "<<id_card1;
		    Paient_File<<"\nPatient Phone Number :                 = "<<patient_phone_no1;
		    Paient_File<<"\nPatient Disease Name :                 = "<<disease_name1;
		    Paient_File<<"\nPaitent Appointment Date :             = "<<appointment_date1;
		    Paient_File<<"\nPaitent Appointment Name :             = "<<appointment_name1;
		    Paient_File<<"\nPatient Doctor Name :                  = "<<doctor_name1;
		    Paient_File<<"\nPatient Professional DOC Name :        = "<<doctor_profession1;
		    Paient_File<<"\nPatient Appointment Time :             = "<<appointment_time1;
		    Paient_File<<"\nPaitent Levaing Hospital Time :        = "<<leaving_time_hospital1;
		    Paient_File<<"\n                                         ";
		    Paient_File<<"\n=========================================---->";
			Paient_File.close();	 
			int a;
			string store;
			main_me:
			cout<<"\n\n\t\t\t\t\t\t\t  *************************************************************";
         	cout<<"\n\t\t\t\t\t\t\t  ______                                                 ______";
         	cout<<"\n\t\t\t\t\t\t\t  ______     Press 1 : To Find the All Data by File      ______";
         	cout<<"\n\t\t\t\t\t\t\t  ______     Press 2 : To Update the Paient Data File    ______";
         	cout<<"\n\t\t\t\t\t\t\t  ______     Press 3 : To Delete the Paient Data File    ______";
         	cout<<"\n\t\t\t\t\t\t\t  ______     Press 4 : Back to main menu                 ______";
         	cout<<"\n\t\t\t\t\t\t\t  ______                                                 ______";
	        cout<<"\n\t\t\t\t\t\t\t  *************************************************************";
	        cout<<"\n\t\t\t\t\t\t\t  ______     Enter your choice do you want               ______";
			cin>>a;
			
			if(a==1)
	        {
	        	system("cls");
	            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
         		cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
         		cout<<"\n\n\t\t\t\t\t\t\t\t______   Display All Patient Data in File    ______";
         		cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	         	cout<<"\n\n\t\t\t\t\t\t\t\t***************************************************\n\n";
                 
	 	        Paient_File.open("Paient_File.txt" , ios::in);
	 	        while(Paient_File)
	 	        {
	 		        getline(Paient_File,store);
	 		        cout<<store<<endl;
		        }
		        Paient_File.close();
		        system("pause");
		        system("cls");
				goto main_me;	 	
	        }
	        else if(a==2)
	        { 
	            system("cls");
	            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
         	    cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
         	    cout<<"\n\n\t\t\t\t\t\t\t\t______   UPDATE All Patient Data in File      ______";
         	    cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	            cout<<"\n\n\t\t\t\t\t\t\t\t***************************************************\n\n";
	         	
	            cout<<"\n\t\t\t\t\t\t\t\tPatient ID :";
		        cin>>patient_id1;

		        cout<<"\n\t\t\t\t\t\t\t\tPatient Address : ";
		        cin.ignore();
		        getline(cin,patient_address1);

		        time_t timetoday;
                time(&timetoday);
		    
		        patient_entry_record_date1 = asctime(localtime(&timetoday));
		
		        cout<<"\n\t\t\t\t\t\t\t\tPatient Name : ";
		        getline(cin,patient_name1);
		
		        cout<<"\n\t\t\t\t\t\t\t\tPatient Father Name : ";
		        getline(cin,patient_father_name1);
		
		        back1111:
		        cout<<"\n\t\t\t\t\t\t\t\tEnter Gender Male/Female:";
		        cin>>patient_gender1;
		        if(patient_gender1 == "Female")
		        {
		            cout<<" ";
				}
				else if(patient_gender1 == "Male")
				{
					cout<<" ";
				}
				else 
				{
					goto back1111;
				}
		
		       cout<<"\n\t\t\t\t\t\t\t\tPatient ID Card : ";
		       cin>>id_card1;
		
		       cout<<"\n\t\t\t\t\t\t\t\tPatient Phone Number : ";
		       cin>>patient_phone_no1;
		
		       cout<<"\n\t\t\t\t\t\t\t\tPatient Disease Name : ";
		       cin.ignore();
		       getline(cin,disease_name1);
	
		       cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Date : ";
                cout<<"\n\t\t\t\t\t\t\t\tMonth:";
                cin>>month;
                cout<<"\n\t\t\t\t\t\t\t\tYear:";
                cin>>year;
                cout<<"\n\t\t\t\t\t\t\t\tDay:";
                cin>>day;
                appointment_date1 = day + "/" + month + "/" +year;
		        cin.ignore();
		       cout<<"\n\t\t\t\t\t\t\t\tPaitent Appointment Name : ";
	           getline(cin,appointment_name1);
	 
	           cout<<"\n\t\t\t\t\t\t\t\tPatient Doctor Name : ";
		       getline(cin,doctor_name1);
	
		       cout<<"\n\t\t\t\t\t\t\t\tPatient Professional DOC Name : ";
		       getline(cin,doctor_profession1);

		       cout<<"\n\t\t\t\t\t\t\t\tPatient Appointment Time : ";
		       getline(cin,appointment_time1);
		
		       cout<<"\n\t\t\t\t\t\t\t\tPaitent Levaing Hospital Time : ";
		       getline(cin,leaving_time_hospital1);
		         		
		       Paient_File1.open("newPatient.csv",ios::in | ios::app);
			   Paient_File<<"\nPatient ID :                           = "<<patient_id1;
		       Paient_File<<"\nPatient Address :                      = "<<patient_address1;
	    
               time(&timetoday);
		    
		       Paient_File<<"\nPatient Entry Date and Time Hospital:  = "<<asctime(localtime(&timetoday));
		       Paient_File<<"\nPatient Entry Record Date,Time and Day:= "<<patient_entry_record_date1;
	           Paient_File<<"\nPatient Name :                         = "<<patient_name1;
		       Paient_File<<"\nPatient Father Name :                  = "<<patient_father_name1;
	           Paient_File<<"\nPatient Gender :                       = "<<patient_gender1;
		       Paient_File<<"\nPatient ID Card :                      = "<<id_card1;
		       Paient_File<<"\nPatient Phone Number :                 = "<<patient_phone_no1;
		       Paient_File<<"\nPatient Disease Name :                 = "<<disease_name1;
		       Paient_File<<"\nPaitent Appointment Date :             = "<<appointment_date1;
		       Paient_File<<"\nPaitent Appointment Name :             = "<<appointment_name1;
		       Paient_File<<"\nPatient Doctor Name :                  = "<<doctor_name1;
		       Paient_File<<"\nPatient Professional DOC Name :        = "<<doctor_profession1;
		       Paient_File<<"\nPatient Appointment Time :             = "<<appointment_time1;
		       Paient_File<<"\nPaitent Levaing Hospital Time :        = "<<leaving_time_hospital1;
		       Paient_File<<"\n                                            ";
		       Paient_File<<"\n============================================---->";
			   Paient_File1.close();
			   remove("Paient_File.csv");
			   rename("newPatient.csv","Paient_File.csv");
			   system("pause");
		       system("cls");
			   goto main_me;
		   }
	       else if(a==3)
	       {  
		       system("cls");
	           cout<<"\n\n\n\n\t\t\t\t\t\t\t\t***************************************************";
         	   cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
         	   cout<<"\n\n\t\t\t\t\t\t\t\t______     Delete Patient Data File          ______";
         	   cout<<"\n\n\t\t\t\t\t\t\t\t______                                       ______";
	           cout<<"\n\n\t\t\t\t\t\t\t\t***************************************************\n\n";
        
	           remove("Paient_File.cvs");
	           system("pause");
		       system("cls");
	           goto main_me;
		    }
		    else if(a==4)
			{
				system("cls");
				goto menu;
			}
		    else
		    {
		       cout<<"\n\n\n\n\t\t\t\t\t\t\t\t   =======================";
			   cout<<"\n\t\t\t\t\t\t\t\t   Select the right option";
			   cout<<"\n\t\t\t\t\t\t\t\t   =======================\n";
			   system("pause");
	           system("cls");
	           goto main_me;
		    }      	
	    }
	    else if(o==4)
	   {
	        exit(0);
	   }
	   else 
	   {
	   	    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t=============";
	        cout<<"\n\t\t\t\t\t\t\t\tInvalid Input";
	        cout<<"\n\t\t\t\t\t\t\t\t=============\n\n";
	        system("pause");
	        system("cls");
	        goto menu;
	   }		
	return 0;
}
