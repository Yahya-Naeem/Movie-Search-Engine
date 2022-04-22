#include<iostream>
#include<windows.h>
#include<string>
#include"avl_tree updated.cpp"
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void display_menu();  //prototype
void load();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);    //globally defining
class user
{
		public:
			AVL t,g,rtree;
			AVL gen[14];
			user()
			{
				read_file();
			}
			void show_user_menu()
			{
				cout<<"\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t";
				cout<<"Loading";
				SetConsoleTextAttribute(h,3);    //blue
				load();
				SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
				int choice;
				cout<<"\n\t\t\t\t**USER OPTIONS**";
				cout<<"\n\t\t\t\t_______________________________";
				cout<<"\n\n\t\t\t\t1- Search Details of movie \n";
				cout<<"\t\t\t\t2- Search by Genre \n";
				cout<<"\t\t\t\t3- Search top rating \n";
				cout<<"\t\t\t\t4- Return to main Menu \n";
				cout<<"\n\t\t\t\t_______________________________";
				cout<<"\n\n\t\t\t\tEnter Choice :";
				cin>>choice;
				switch (choice)
				{
					case 1:
						search_name();
						break;
					case 2:
						search_genre();
						break;
					case 3:
						rating();	
						break;
					case 4:
						system("cls");
						display_menu();
						break;
					default:
						system("cls");
						SetConsoleTextAttribute(h,4);        //red 
						cout<<"\t\t\t\twrong choice :\n\n";
						SetConsoleTextAttribute(h,13);        //origional
						show_user_menu();
						break;							
				 } 
			}
			//search with rating
			void rating() 
			{
				string ch;
				system("cls");
				cout<<"\n\t\t\t\t*SEARCH BY RATING*\n";
				cout<<"\t\t\tEnter Rating (1 - 10) for Movies :\n";
				cout<<"\n\t\t\t\tEnter choice";
				cin>>ch;
				cout<<"\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t";
				cout<<"Loading";
				SetConsoleTextAttribute(h,3);    //blue
				load();
				SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
				t.inOrder_rate(t.root,ch);
				SetConsoleTextAttribute(h,3);       //blue
				cout<<"\n\t\t\tPress any key for user menu :";
				SetConsoleTextAttribute(h,13);
				getch();
				system("cls");
				show_user_menu();        //recursive call
			}
			void search_name()  //search with name
			{
				system("cls");
				label:
				string name;
				cout<<"\n\t\t\t\t*SEARCH MOVIE DETAIL*\n";
				cout<<"\n\t\t\t\tEnter Movie Name :";
				fflush(stdin);                     //clearing buffer
				getline(cin,name);
				cout<<"\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t";
				cout<<"Loading";
				SetConsoleTextAttribute(h,3);    //blue
				load();
				SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
				t.search(t.root,name);
				                                   //Wrong name or Out of data
				if(t.f==0)
				{
					t.f=1;
					int choice;
					system("cls");
					cout<<"\n\t\t\t\tNo results found :\n";
					cout<<"\n\t\t\t\t1 - User Menu :\n";
					cout<<"\t\t\t\t2 - Enter name again";
					cout<<"\n\t\t\t\tEnter Choice :";
					cin>>choice;
					                                    //check conditions
					if(choice == 1)
					{
						show_user_menu();
					}
					else if(choice == 2)
					{
					    goto label;                    //back to start of function	
					}
					else
					{
						SetConsoleTextAttribute(h,4);  //red
						cout<<"Wrong choice :\n";
						cout<<"press key to exit :";
						SetConsoleTextAttribute(h,13);
						getch();
					}
				}
		    }
			//search all movies with genre
			void search_genre()
			{	
				string g[13] = {"Animation","Family","Action","Drama","Thriller","Science Fiction","Fantasy","Comedy","Romance","TV Movie","Mystery","Foreign","Music"};
				Node *n=t.root;
				int choice;
				system("cls");
				cout<<"\n\t\t\t\t*SEARCH BY GENRE*\n";
				number:
				for(int i=0;i<13;i++)
				{
					cout<<i+1<<"- "<<g[i]<<endl;
				}
				cout<<"\n\t\t\t\tEnter number :";
				cin>>choice;
				if((choice<1) || (choice>13))       //check condition on choice
				{
					system("cls");                //clearing console
					int t;
					SetConsoleTextAttribute(h,4); //red
					cout<<"\n\t\t\t\tWrong Genre choice :\n\n\n";
					SetConsoleTextAttribute(h,13);
					label: //for recursive calls in case of wrong choice
					cout<<"\t\t\t\t1- User menu :\n";
					cout<<"\t\t\t\t2- Enter no again:\n";
					cout<<"\t\t\t\t Enter choice :";
					cin>>t;
					if(t==1)
					{
						system("cls");
						show_user_menu();
					}
					else if(t==2)
					{
						goto number;
					}
					else
					{
						SetConsoleTextAttribute(h,4);      //red
						cout<<"\t\t\t\tWrong attempt :\n";
						SetConsoleTextAttribute(h,13);
						system("cls");
						goto label;
					}
				}
				searching_genre(choice,g[choice-1],n);
				cout<<"\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t";
				cout<<"Loading";
				SetConsoleTextAttribute(h,3);    //blue
				load();
				SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
				gen[choice].inOrder_name(gen[choice].root);   //for printing movie data
				// Backing options 
				SetConsoleTextAttribute(h,3);                  //blue
				cout<<"Press Any key for user  menu :";
				SetConsoleTextAttribute(h,15);
 				getch();
				system("cls");
				show_user_menu(); //recursice call
			}
			//This function makes 13 objects of Avl each consisting of its own type of genre from table
			void searching_genre(int choice,string ch,Node *n)
			{
				if(n==NULL)
				{
					return;
				}
				searching_genre(choice,ch,n->left);
				if(search_string(n->genre,ch)==true)
				{
					gen[choice].root = gen[choice].insert(gen[choice].root,n->data,n->name,ch,n->o_v,n->status,n->r_d,n->language,n->t_l,n->rate);
				}
				searching_genre(choice,ch,n->right);
			}
			void read_file()
			{
				string extra;
				string name,genre,o_v ,r_d ,status ,language,t_l, r;
				string data;
				ifstream fin;
				fin.open("movies_metadata.csv");
				if(!fin)
				{
					SetConsoleTextAttribute(h,4);            //red
					cout<<"Exception in file opening:\n";
					SetConsoleTextAttribute(h,13);
				}
				while(!fin.eof())
				{	
					getline(fin,extra,'\n');        //extra data
					getline(fin,genre,']');         //genre
					getline(fin,extra,',');
					getline(fin,language,',');      //language
					getline(fin,extra,'[');
					getline(fin,name,'[');          //name
					getline(fin,extra,',');
					getline(fin,extra,'[');
					getline(fin,o_v,']');           //overview
					getline(fin,extra,',');
					getline(fin,r_d,',');           //release date
					getline(fin,status,',');
					getline(fin,extra,'[');
					getline(fin,t_l,']');
					getline(fin,extra,',');
					getline(fin,r,',');             //rating 
					data = r;
					if(t_l == "") 
					{
						t_l = " No Tagline ";
					}
					t.root = t.insert(t.root,data,name,genre,o_v,status,r_d,language,t_l,r);
			    }
			    fin.close();                        //closing file
		}
			//Function to search word from line
			bool search_string(string line,string word)
			{
				int isfound = line.find(word);
				if(isfound != string::npos)
	            {
	            	return 1;
				}
				else
				{
					return 0;
				}
			}
			//for appending prepending strings with [ ]
			string app_pre(string a)
			{
				string temp;
				temp+="[";
				int i=0;         //loop counter
				while(a[i] !='\0')
				{
					temp+=a[i];
					i++;
				}
				temp+="]";
				return temp;
			}
			//apppending file
			void admin()
			{
				cout<<"\n\n\n\n\n\n\n\n\n\n\n";
				cout<<"\t\t\t";
				cout<<"Loading";
				SetConsoleTextAttribute(h,3);    //blue
				load();
				SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
				cout<<"\n\t\t\t\t*** Admin Control ***\n";
				string name,password;
				name ="Yahya";
				password ="123";
				string temp1,temp2;
				cout<<"\n\t\t\t\t______________________________";
				cout<<"\n\t\t\t\tEnter User name : ";
				cin>>temp1;
				cout<<"\n\t\t\t\tEnter Password : ";
				cin>>temp2;
				cout<<"\n\t\t\t\t______________________________";
				try
				{
					if( name != temp1 || password != temp2 )
					throw 1;
					else
					{
					system("cls");	
					cout<<"\n\n\n\n\n\n\n\n\n\n\n";
					cout<<"\t\t\tLOGGING IN";
					SetConsoleTextAttribute(h,3);    //blue
					load();
					SetConsoleTextAttribute(h,15);   //setting to origional
					write_file();
				}
				}catch(int i)
				{
					SetConsoleTextAttribute(h,4);       //red
					cout<<"\n\t\t\t\tWrong Username or Password ";
					cout<<"\n\t\t\t\tEnter Key For Main Menu :";
					getch();
					SetConsoleTextAttribute(h,15);
					system("cls");
					display_menu();
				}
			}
			void write_file()
			{
				system("cls");
				cout<<"\n\t\t\t\t*** Admin Control ***\n";
				string temp;                                   //for temp use 
				string data , name , genre , o_v /*over view*/ ,r_d , status , language, t_l /*tagline*/ , r /*rating*/;
				ofstream fout;                                 //File handle
				fout.open("movies_metadata.csv", ios :: app);  //append mode
				if(!fout)
				{
					SetConsoleTextAttribute(h,4);  //red
					cout<<"Exception in file opening:\n";
					SetConsoleTextAttribute(h,15);
			    }
				cout<<"Enter Movie Name :";
				cin>>temp;
				name = app_pre(temp);
				cout<<"\nEnter Genre With first letter Capital : ";
				cin>>genre;
				cout<<"\nEnter Movie Overview :";
				cin>>temp;
				o_v = app_pre(temp);
				cout<<"\nEnter Movie Status :";
				cin>>status;
				cout<<"\nEnter released date :";
				cin>>r_d;
				cout<<"\nEnter Movie Tagline :";
				cin>>temp;
				t_l = app_pre(temp);
				cout<<"\nEnter Movie Language :";
				cin>>language;
				cout<<"\nEnter Movie Rating :";
				cin>>r;
				                                                       //writing to file
				fout<<genre<<",";
				fout<<language<<",";
				fout<<name<<",";
				fout<<o_v<<",";
				fout<<r_d<<",";
				fout<<status<<",";
				fout<<t_l<<",";
				fout<<r<<"\n"; 
				data=r;
				t.root = t.insert(t.root,data,name,genre,o_v,status,r_d,language,t_l,r);
				fout.close();    //closing file
				SetConsoleTextAttribute(h,3);           //blue
				cout<<"\nFile appended successfully :"<<endl;
				cout<<"Press Any key For main menu :";
				SetConsoleTextAttribute(h,15);
				getch();
				display_menu();
			}
};
void about_us()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t";
	cout<<"Loading";
	SetConsoleTextAttribute(h,3);    //blue
	load();
	SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
	system("cls");
	cout<<"\n\n\t\t\t\tABOUT US"<<endl<<endl<<endl;
	cout<<"Muhammad Yahya Naeem(20k-1065) and Mehma Waseem(20k-****) , ";
	cout<<"from section 3D.We made this project on movie data set for our course DATA STRUCTURES. ";
	cout<<"We tried to put maximum efforts to cover most of the topics that we studied in Class ,lab or found on internet.";	
	cout<<"\n\t\t\t\tPress any key for Main Menu :";
	getch();
	display_menu();
}
void help()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t";
	cout<<"Loading";
	SetConsoleTextAttribute(h,3);    //blue
	load();
	SetConsoleTextAttribute(h,15);    //origional colour(Bright White)
	system("cls");
	cout<<"\n\t\t\t\t***HELP***"<<endl;
	cout<<"________________________________________________________________________________________________________________________________________________________________";
	cout<<"\nAdmin :\n\t He will be able to append file with new movies addition So that file remains useful for user.";
	cout<<"\n\nUser :\n\tUser can search movies by genres , search by name ,search by rating .\n";
	cout<<"\nNote : This program is user friendly ,user giuded by multiple exceptions for wrong enteries";
	cout<<". BUT FOR accurate results user should be good in giving inputs \n";
	cout<<"________________________________________________________________________________________________________________________________________________________________";
	cout<<"\n\t\t\t\tPress any key for Main menu :";
	getch();
	display_menu();
}
void load()
{
	char y = 219;       //ascii code 
	for(int i=0;i<30;i++)
	{
		cout<<y;
		//controlling speed of loading gradually increasing time = 1/speed and vice versa
		if(i<10)
		Sleep(200);      //delaying for 300 ms
		else if(i<20 && i>10)
		Sleep(150);
		else
		Sleep(50);
		
	}
	system("cls");
}
void display_menu()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\tLoading ";
	SetConsoleTextAttribute(h,3);   
	load();
	SetConsoleTextAttribute(h,15);   
	cout<<"\n\t\t\t\t*** MOVIE SEARCH ENGINE ***"<<endl<<endl<<endl;
	cout<<"\n\t\t\t\t\tMAIN MENU";
	cout<<"\n\t\t\t\t_______________________________\n";
	cout<<"\n\t\t\t\t1- USER OPTIONS :"<<endl;
	cout<<"\t\t\t\t2- ADMIN OPTIONS :"<<endl;
	cout<<"\t\t\t\t3- ABOUT US: "<<endl;
	cout<<"\t\t\t\t4- HELP :"<<endl;
	cout<<"\n\t\t\t\t_______________________________";
	int choice;                       //User selection choice
	cout<<"\n\n\t\t\t\tEnter Choice :";
	cin>>choice;
	user u;
	switch (choice)
	{
		case 1:
			{
				system("cls");
			    u.show_user_menu();
				break;
			}
		case 2:
			{
				system("cls");
			    u.admin();
				break;
			}	
		case 3:
			{
			system("cls");	
			    about_us();
			    break;
			}
		case 4:
			{	
			system("cls");
			    help();
			    break;
			}
		default:
			{
				system("cls");
				SetConsoleTextAttribute(h,4);        //red
			    cout<<"\n\n\t\t\t\tInvalid choice :<<endl";
			    SetConsoleTextAttribute(h,15);    
			    display_menu();
				break;
			}
	}
}
//main body
int main()
{
	display_menu();
}
