#include "Tree.h"
#include <bits/stdc++.h>
using namespace std;

Tree :: Tree(string input)
{
	postfix = input;
}

Node* Tree :: getnewnode(char idata)
{
	Node* node = new Node(idata);
	
	node->left = node->right = NULL;
	return node;
}

void Tree :: makeTree()
{
	stack<Node*> st; //A stack to store all nodes
	
	for(int i=0;i<postfix.length();i++)
	{
		
		//If the scanned character is an operand just push it into the stack node
		if(postfix[i]>='a' && postfix[i]<='z')
		{
			Node* newnode = getnewnode(postfix[i]);
			st.push(newnode);
	
		}
		//If the scanned character is an binary operator pop the top two elements from the stack and assign the right pointer of the node to the top node
		else if(postfix[i]=='V' || postfix[i]=='^' || postfix[i]=='>')
		{
			Node* newnode = getnewnode(postfix[i]);
			Node* right = st.top();
			st.pop();
			Node* left = st.top();
			st.pop();
			newnode->left = left;
			newnode->right = right;
			st.push(newnode);
		}
		//If the scanned character is an unary operator pop the top element from the stack and assign the right pointer of the current node to the top node
		else if(postfix[i]=='~')
		{
			Node* newnode = getnewnode(postfix[i]);
			Node* right = st.top();
			st.pop();
			newnode->right = right;
			st.push(newnode);
		}
	}

	rootptr = st.top();
	chn = "";

}

void Tree :: inorder(Node* root)
{
	if(root!=NULL)
	{
		if(!(root->data >='a' && root->data <='z'))
	        {
			chn+= "(";
			inorder(root->left);
		       	chn+= (root->data);
			inorder(root->right);
		 	chn+= ")";
		}
		else if(root->data >='a' && root->data <='z')
		{
			chn+= (root->data);
		}
	}
}
