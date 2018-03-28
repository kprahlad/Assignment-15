#include<iostream>
using namespace std;
int flag=1;
class node
{
	public:
	node* parent;
	node* left;
	node* right;
	int data;	
	node()
	{
		parent=left=right=NULL;
	}
};
class tree
{
	public:
	node * root;
	tree()
	{
		root=NULL;
	}
	void insert(int data);
	void display(node *blah);
	void search(node *blah, int data);
	void del(node *blah, int data);
}ob;
void tree::insert(int data)
{
	node *temp=new node;
	if(!temp) cout<<"Overflow!";
	else
	{
		temp->data=data; 
		if(root==NULL) root=temp;
		else
		{
			node *curr=root;
			int flag=1;
			while(flag)
			{
				if(curr->data<data) 
				{
					if(curr->right) curr=curr->right;
					else 
					{
						temp->parent=curr;
						curr->right=temp;
						flag=0;
					}
				}
				else 
				{
					if(curr->left) curr=curr->left;
					else
					{
						temp->parent=curr;
						curr->left=temp;
						flag=0;
					}
				}
			}
	    }  
	}
}
void tree::display(node *blah)
{
	node* curr=blah;
	if(curr)
	{
		display(curr->left);
		cout<<curr->data<<" ";
		display(curr->right);
	}
}
void tree::search(node *blah,int data)
{
	node* curr=blah;
	if(curr&&flag)
	{
		if(data<curr->data) search(curr->left,data);
		else if(data>curr->data) search(curr->right,data);
		else 
		{
			flag=0;
			cout<<"\nYay!";
		}
	}
}
void tree::del(node *blah,int data)
{
	node* curr=blah;
	if(curr&&flag)
	{
		if(data<curr->data) del(curr->left,data);
		else if(data>curr->data) del(curr->right,data);
		else 
		{
			flag=0;
			node* replace=curr;
			replace=replace->left;
			if(replace)
			 while(replace->right) replace=replace->right;
			if(replace)
			{
				if(replace->parent!=curr)
				{
					(replace->parent)->right=replace->left;
					replace->left=curr->left;
				}
				replace->right=curr->right;
			}
			if(curr==root) root=replace;
			else
			{
				if(curr->data>(curr->parent)->data) (curr->parent)->right=replace;
				else (curr->parent)->left=replace;
			}
		}
	}
}
int main()
{
	ob.insert(1);
	ob.insert(12);
	ob.insert(-1);
	ob.insert(5);
	ob.insert(14);
	ob.insert(0);
	ob.insert(3);
	ob.insert(-8);
	ob.insert(7);
	ob.insert(6);	
	ob.display(ob.root);
	ob.search(ob.root,124);
	if(flag) cout<<"\nNope!";
	flag=1;
	ob.del(ob.root,-8);
	ob.display(ob.root);
	return 0;
}
