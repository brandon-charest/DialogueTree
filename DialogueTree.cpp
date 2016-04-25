#include "DialogueTree.h"



DialogueTree::DialogueTree()
{

}

void DialogueTree::init()
{
	DialogueNode *node0 = new DialogueNode("Hello Brave Warrior!");
	DialogueNode *node1 = new DialogueNode("I dont want to talk to you.");
	DialogueNode *node2 = new DialogueNode("I have a quest for you!");
	DialogueNode *node3 = new DialogueNode("You will get 5 gold, and no more.");
	DialogueNode *node4 = new DialogueNode("Travel to the 5th dimension of pain and slay its king!");

	// -> is same thing as (*node0).dialogueOptions.blahblah
	//node0
	node0 -> dialogueOptions.push_back(DialogueOption("Whats up noob?!", 0, node1));
	node0 -> dialogueOptions.push_back(DialogueOption("Hello Strange Voice!", 0, node2));
	dialogueNode.push_back(node0);

	//node1
	node1->dialogueOptions.push_back(DialogueOption("Aww....", 0, nullptr));
	dialogueNode.push_back(node1);

	//node2
	node2->dialogueOptions.push_back(DialogueOption("Kthnxbye", 0, nullptr));
	node2->dialogueOptions.push_back(DialogueOption("What is it...", 0, node4));
	node2->dialogueOptions.push_back(DialogueOption("Whats the pay??", 0, node3));
	dialogueNode.push_back(node2);

	//node3
	node3->dialogueOptions.push_back(DialogueOption("I dont roll out of bed for atleast 10 gold. Im out.", 0, nullptr));
	node3->dialogueOptions.push_back(DialogueOption("Ok then what is it?", 0, node4));
	dialogueNode.push_back(node3);

	//node4
	//return 1 accepting the quest
	node4->dialogueOptions.push_back(DialogueOption("FOR 5 GOLD!? NO WAY!", 1, nullptr));
	node4->dialogueOptions.push_back(DialogueOption("Money isnt going to earn itself! Im in!", 0, nullptr));
	dialogueNode.push_back(node4);
}

void DialogueTree::destroyTree()
{
	//deletes heep memory for the dialogue entrys
	for (int i = 0; i < dialogueNode.size(); i++) {
		delete dialogueNode[i];
	}

	dialogueNode.clear();
}

int DialogueTree::performDialouge()
{
	if (dialogueNode.size() == 0) {
		return -1;
	}

	//sets pointer to first node.
	DialogueNode *currentNode = dialogueNode[0];

	while (true) {
		
		cout << currentNode->text << "\n\n";

		for (int i = 0; i < currentNode->dialogueOptions.size(); i++) {
			cout << i + 1 << ": " << currentNode->dialogueOptions[i].text << endl;
		}
		cout << endl;

		int input;
		cin >> input;
		input--;
		//checks input
		if (input < 0 || input > currentNode->dialogueOptions.size()) {
			cout << "Invalid Input!\n";

		}
		else {
			//checks for end of conversation
			if (currentNode->dialogueOptions[input].nextNode == nullptr) {
				return currentNode->dialogueOptions[input].returnCode;
			}

			currentNode = currentNode->dialogueOptions[input].nextNode;
		}
		cout << endl;
	}
	return 0;
}

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode * NextNode)
{
	text = Text;
	returnCode = ReturnCode;
	nextNode = NextNode;
}

DialogueNode::DialogueNode(string Text)
{
	text = Text;
}
