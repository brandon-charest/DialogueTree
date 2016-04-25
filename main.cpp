#include "main.h"
#include "DialogueTree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	DialogueTree dialogueTree;

	dialogueTree.init();

	int returnValue = dialogueTree.performDialouge();

	if (returnValue == 1) {
		cout << "You have accepted the quest!\n";
	}

	dialogueTree.destroyTree();

	cout << "Enter any key to continue... \n";
	int temp;
	cin >> temp;
	return 0;
}
