#include "Formula.h"
#include <stack>
#include <string>
using namespace std;

string Formula :: infixTOpostfix(string infix)
{
	string postfix;

    	stack<char> st;

	int l = infix.length();

	for(int i=0;i<l;i++)
	{

		//If the scanned character is an operand then just add it to output string
		if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z' && infix[i]!='V')
		postfix+=infix[i];


		//If the scanned character is '(' then push it into a stack
		else if(infix[i]=='(')
		st.push(infix[i]);


		//If the scanned character is ')' , add the top element to output string and pop it until '(' is encountered and also pop '('
		else if(infix[i]==')')
		{
			while(st.top()!='(')
			{
				postfix+=st.top();
				st.pop();
			}
			st.pop();
		}

		//If the scanned character is operator then we are pushing it into a stack.Since it is given that the given formula is fully paranthesized we need not check precedence of operators here
		else
		{
			st.push(infix[i]);
		}

	}

	//This is optional since it is given that formula is fully paranthesized
	while(!st.empty())
	{
		postfix+=st.top();
		st.pop();
	}

    return postfix;
}

