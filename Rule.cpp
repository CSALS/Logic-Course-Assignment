#include "Rule.h"
#include "Formula.h"
#include "Tree.h"

Rule :: Rule(string s)
{
	
	int index1=-1;
	isPremise=false;
	isValid = 0;
	for(int j=0;j<s.length();j++)
	{
		if(s[j]=='/')
		{
			index1 = j;
			break;
		}
					
	}
	if(index1==-1) {  isValid=-1; return; }
	else
	{			
		conclusion = s.substr(0,index1);
		if(conclusion[0] == '~')	
		conclusion = "(" + conclusion + ")";
	}
	
	if( (s.length() - index1 - 1) == 1)
	{
		if( !(s.substr(index1+1,1) == "P"))
		{ isValid=-1; return; }
		else
		{ rule == "P"; isPremise=true; }
	}
	else
	{
		int index2=-1;
		for(int j=index1+1;j<s.length();j++)
		{
			if(s[j]=='/')
			{
				index2 = j;
				break;
			}
					
		}
		if(index2==-1) { isValid=-1; return; }
		else
		{
			rule = s.substr(index1+1 , index2-index1-1);
			int index3=-1;
			for(int j=index2+1;j<s.length();j++)
			{
				if(s[j]=='/')
				{
					index3 = j;
					break;
				}
					
					
			}
			
			if(index3 == -1)
			{
				a = (s.substr(index2+1 , s.length()-index2-1));
				b = "Not present";
			}
			else
			{
				a = (s.substr(index2+1 , index3-index2-1));
				b = (s.substr(index3+1 , s.length()-index3));
			}
			
		}
	
	}

}
	
	
void Rule :: verify(int ct,int count,string steps[][6])
{
	Formula formula;
	
	for(int i=ct+1;i<=count+ct;i++)
	{
		//If the rule is AND introduction
		
		if(steps[i][1] == "^i") 
		{
			if(steps[i][2] == "NA" || steps[i][3] == "NA") { isValid=-1; break; }
			string post = formula.infixTOpostfix(steps[i][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != '^')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->left);
				string left = tree.chn;
			
				tree.chn = "";
				tree.inorder((tree.rootptr)->right);
				string right = tree.chn;
				
				if( !(left == steps[stoi(steps[i][2])][0] && right == steps[stoi(steps[i][3])][0]) )
				{ isValid=-1; break; }
			}
		}
		
		//If the rule is AND elimination (^e1 = eliminates 2nd operand , ^e2 = eliminates 1st operand )
		
		else if(steps[i][1] == "^e1")
		{
			if(steps[i][3] !="NA") { isValid = -1; break; }
			string post = formula.infixTOpostfix(steps[stoi(steps[i][2])][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != '^')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->left);
				string left = tree.chn;
			
				tree.chn="";
				if( !(left  == steps[i][0]) )
				{ isValid = -1; break; }
			}
		}
		
		else if(steps[i][1] == "^e2")
		{
			if(steps[i][3] !="NA") { isValid = -1; break; }
			string post = formula.infixTOpostfix(steps[stoi(steps[i][2])][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != '^')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->right);
				string right = tree.chn;
			
				tree.chn="";
				if( !(right  == steps[i][0]) )
				{ isValid = -1; break; }
			}
		}
		
		//If the rule is OR introduction (Vi1 = 2nd operand can be anything , Vi2 = 1st operand can be anything
		
		else if(steps[i][1] == "Vi1")
		{
			if(steps[i][3] !="NA") { isValid = -1; break; }
			string post = formula.infixTOpostfix(steps[i][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != 'V')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->left);
				string left = tree.chn;
			
				tree.chn="";
				if( !(left  == steps[stoi(steps[i][2])][0]) )
				{ isValid = -1; break; }
			}
		}
		
		else if(steps[i][1] == "Vi2")
		{
			if(steps[i][3] !="NA") { isValid = -1; break; }
			string post = formula.infixTOpostfix(steps[i][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != 'V')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->right);
				string right = tree.chn;
				
				tree.chn="";
				if( !(right  == steps[stoi(steps[i][2])][0]))
				{ isValid = -1; break; }
			}
		}
		
		//If the rule is Implies elimination
		
		else if(steps[i][1] == ">e" )
		{
			if(steps[i][2] == "NA" || steps[i][3] == "NA") { isValid=-1; break; }
			string post = formula.infixTOpostfix(steps[stoi(steps[i][2])][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != '>')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->left);
				string left = tree.chn;
				
				tree.chn = "";
				tree.inorder((tree.rootptr)->right);
				string right = tree.chn;
				
				if( !(left == steps[stoi(steps[i][3])][0] && right == steps[i][0]) )
				{ isValid=-1; break; }
			}
		}
		
		//If the rule is MT
		
		else if(steps[i][1] == "MT")
		{
			if(steps[i][2] == "NA" || steps[i][3] == "NA") { isValid=-1; break; }
			string post = formula.infixTOpostfix(steps[stoi(steps[i][2])][0]);
			Tree tree(post);
			tree.makeTree();
			if(((tree.rootptr)->data) != '>')
			{ isValid=-1; break; }
			else
			{
				tree.inorder((tree.rootptr)->left);
				string left = tree.chn;
				left = "(~" + left + ")";
				
				 
				tree.chn = "";
				
				tree.inorder((tree.rootptr)->right);
				string right = tree.chn;
				right = "(~" + right + ")" ;
				
				if( !(left == steps[i][0] && right == steps[stoi(steps[i][3])][0]) )
				{ isValid =-1; break; }
			}
		}





	}



}	
	
	
	
	
	
	

