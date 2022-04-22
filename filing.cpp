#include<iostream>
#include<fstream>
using namespace std;
bool search_string(string line,string word)            //"family 
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
int main()
{
	ifstream fin;
	fin.open("movies_metadata.csv");
	if(!fin)
	{
		cout<<"file not opened :"<<endl;
	}
	string line;
int i,c;
	//cout<<line<<endl<<endl;
for(i=0;i<1000;i++)
{
	getline(fin,line,'\n');  //point to 2nd line after it
	getline(fin,line,',');
	//cout<<line;
	getline(fin,line,'}');
	//cout<<line;
	getline(fin,line,',');
	//cout<<line;
	getline(fin,line,',');
	//cout<<line;
	getline(fin,line,']');
//	cout<<line<<"\n";
	if(search_string(line,"Family"))	
{
	c++;
	getline(fin,line,',');
	getline(fin,line,',');
	getline(fin,line,',');
	getline(fin,line,',');
	getline(fin,line,',');
	getline(fin,line,',');
	cout<<line<<endl<<endl;
}
}
cout<<"\ntotal results for genre family are :"<<c;
	fin.close();
}

