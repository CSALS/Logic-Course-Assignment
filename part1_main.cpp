#include "Formula.h"
#include "Tree.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string infix;
	cout << "Enter a propositional logic formula(fully parenthesized) in its infix notation" << endl;
	cin >> infix;
	Formula new_formula;
	string postfix = new_formula.infixTOpostfix(infix);
	cout << "Its postfix notation" << endl;
	cout << postfix << endl;
	Tree new_tree(postfix);

	cout << "Making parse tree using the postfix notation of the infix notation you have provided" << endl;
	new_tree.makeTree();

	cout << "rootptr points to the root node of the parse tree" << endl;
	cout << "Doing inorder traversal for the parse tree" << endl;
	new_tree.inorder(new_tree.rootptr);
	cout << "And the formula obtained from inorder traversal is :- " << endl;

	cout << (new_tree.chn) << endl;
	
	return 0;
}
