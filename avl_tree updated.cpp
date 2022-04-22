#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
        string t_l,data,name,genre,o_v,r_d,status,language,rate;  //data acting as keyword for input
		int height;
		Node *left,*right,*next;
		Node()                   //Default constructor
		{
			left = right = next = NULL;
		}
		Node(string n)
		{
			height = 1;
			data = n;
			left = right = next = NULL;
		}
		Node(string d,string n,string g,string o,string s,string r,string l,string t,string ra)   //parametrized constructor
		{
			height = 1;
			left = right = next = NULL;
			data=d;
			rate = ra;  //rating 
			t_l = t;
			name=n;
			genre=g;
			o_v=o;
			r_d=r;
			status=s;
			language=l;
		}

		
};
class AVL{
    public:
    	int f;
        Node *root;
        AVL()
        {
            root = NULL;
            f=0;
        }
        int getBF(Node *root)
        {
            if(root==NULL)
            {
                return 0;
            }
            int hl = getHeight(root->left);
            int hr = getHeight(root->right);
            return (hl-hr);
        }
        int getHeight(Node *r)
        {
            if(r==NULL)
            {
                return -1;
            }
            int hl = getHeight(r->left);
            int hr = getHeight(r->right);
            
            int h = max(hl,hr);
            return h+1;
        }
        Node *leftrotate(Node *x)
        {
            Node *y = x->right;
            Node *temp = y->left;

            x->right = temp;
            y->left = x;

            return y;
        }
        Node *rightrotate(Node *x)
        {
            Node *y = x->left;
            Node *temp = y->right;
            
            y->right = x;
            x->left = temp;
            return y;
        }
        Node *insert(Node *root,string data,string n,string g,string o,string s,string r,string l,string t_l,string ra)
        {
            if(root == NULL)
            {
                return new Node(data,n,g,o,s,r,l,t_l,ra);
            }
            else
            {
                if(data < root->data)
                {
                    root->left = insert(root->left,data,n,g,o,s,r,l,t_l,ra);
                }
                else if(data > root->data)
                {
                    root->right = insert(root->right,data,n,g,o,s,r,l,t_l,ra);
                }
                else
                {
                    return root;
                }
            }
            int bal = getBF(root);
            if(bal > 1 && data < root->left->data)
            {
                return rightrotate(root);
            }
            if(bal < -1 && data > root->right->data)
            {
                return leftrotate(root);
            }
            if(bal > 1 && data > root->left->data)
            {
                root->left = leftrotate(root->left);
                return rightrotate(root);
            }
            if(bal < -1 && data < root->right->data)
            {
                root->right = rightrotate(root->right);
                return leftrotate(root);
            }
            return root;
        }
		void inOrder(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
            inOrder(root->left);
			cout <<"\n\nMovie name : "<<root->name<<"\nTagline :"<<root->t_l<<"\nOverview :"<<root->o_v<<"\nStatus :"<<root->status<<"\n Release date :"<<root->r_d<<"\nLanguage :"<<root->language<<"\nRating (/10) "<<root->rate<<"\n";
            inOrder(root->right);
        }
        void inOrder_name(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
            inOrder_name(root->left);
			cout <<"\n\nMovie name : "<<root->name<<"\nRating (/10) "<<root->rate<<"\n";
            inOrder_name(root->right);
        }
        void inOrder_rate(Node *root,string ch)
        {
            if(root == NULL)
            {
                return;
            }
            inOrder_rate(root->left,ch);
            //cout<<"aaaasd";
            if((root->rate>=ch))
            {
            	cout <<"\n\nMovie name : "<<root->name<<"("<<root->rate<<")\n";
			}
            inOrder_rate(root->right,ch);
        }
        void search(Node *root,string v)
	        {
	            if(root == NULL)
	            {
	                return;
	            }
	            search(root->left,v);
	            
				if(root->name==v)
	            {
	            	cout<<"\nMovie name :"<<root->name;
					cout<<"\nTagline :"<<root->t_l;
					cout<<"\nOver view :"<<root->o_v;
					//cout<<"\nGenre :"<<
					cout<<"\nStatus"<<root->status;
					cout<<"\nRelease date :"<<root->r_d;
					cout<<"\nRating :"<<root->rate;
					f=1;
					
				}
	            search(root->right,v);
	        }
};

