#ifndef RULE_H
#define RULE_H
#include <string>
using namespace std;
class Rule
{
	public:
	string conclusion;
	string rule;
	string a;
	string b;
	int isValid;
	bool isPremise;
	void verify(int ct,int count,string steps[][6]);
	Rule(string s);
	



};



#endif
