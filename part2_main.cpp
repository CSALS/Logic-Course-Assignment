#include "Formula.h"
#include "Node.h"
#include "Tree.h"
#include "Rule.h"
#include <bits/stdc++.h>
using namespace std;


int n;
int flag = 0;

int main()
{
	
	cout << "Enter number of statements in the proof which you want to validate :- " << endl;
	cin >> n;

	string steps[n+1][6];
	
	int ct=0;
	int count=0;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<6;j++)
		steps[i][j]="NA";
	}
	
	cout << "Enter the steps in your proof...." << endl;
	
	string s;
	for(int i=0;i<n;i++)
	{
		
		cin >> s;
		Rule new_rule(s);
		if(new_rule.isValid == -1) { flag = -1; break; }
		else
		{
			if(new_rule.isPremise == true)
			{ ct++; steps[i+1][0] = new_rule.conclusion; }
			else
			{
				count++;
				steps[i+1][0] = new_rule.conclusion;
				steps[i+1][1] = new_rule.rule;
				steps[i+1][2] = new_rule.a;
				if(!(new_rule.b == "Not present"))
				steps[i+1][3] = new_rule.b;
				
				new_rule.verify(ct,count,steps);
				if(new_rule.isValid == -1) { flag = -1; break; }
				
			}
		}
		
		
	
	}
		
	
	if(flag == -1)
	cout << "Invalid Proof" << endl;
	else
	cout << "Valid Proof" << endl;
	
	
	return 0;
}

