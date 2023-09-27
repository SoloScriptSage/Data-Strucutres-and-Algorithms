/*

██╗░░░░░██╗███╗░░██╗██╗░░██╗███████╗██████╗░  ██╗░░░░░██╗░██████╗████████╗
██║░░░░░██║████╗░██║██║░██╔╝██╔════╝██╔══██╗  ██║░░░░░██║██╔════╝╚══██╔══╝
██║░░░░░██║██╔██╗██║█████═╝░█████╗░░██║░░██║  ██║░░░░░██║╚█████╗░░░░██║░░░
██║░░░░░██║██║╚████║██╔═██╗░██╔══╝░░██║░░██║  ██║░░░░░██║░╚═══██╗░░░██║░░░
███████╗██║██║░╚███║██║░╚██╗███████╗██████╔╝  ███████╗██║██████╔╝░░░██║░░░
╚══════╝╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝╚═════╝░  ╚══════╝╚═╝╚═════╝░░░░╚═╝░░░

*/

#include <iostream>
using namespace std;

// Class Node
class Node {
public:
	int num;	// data
	Node* next_node;	// pointer where the example of the class located in memory to the next node

	Node() {
		num = 0;		// initiallize everything to zero in constructor
		next_node = NULL;
	}

	Node(int num) {		// when creating a new node to keep the information in constructor
		this->num = num;
		this->next_node = next_node;
	}
};

class LinkedList {
	Node* head; // where is the head node in the memory

	public:
		LinkedList() {
			head = NULL;
		}

		void insertNode(int);		// insert a new node
		void deleteNode(int);		// delete node and connect neighbours
		void printList();			// print the list
};

void LinkedList::insertNode(int data) {
	Node* newNode = new Node(data); // creating a new node and adding data to the constructor of a new node

	if (head == NULL) {	// if head of the list is absent
		head = newNode;
		return;	// if we don't have any list yet, the newNode is gonna be the head of the list
	}

	// if we do have a head
	Node* temp = head;
	while (temp->next_node != NULL) {
		temp = temp->next_node;
	} // running to find the end

	temp->next_node = newNode; // assigning at the end of the linked list newNode
}

void LinkedList::deleteNode(int index) {	// index to delete
	Node* temp1 = head, * temp2 = NULL;
	int ListLength = 0;

	// in case list is empty
	if (head == NULL) {
		cout << "List is empty!" << endl;
		return;
	}

	// running through the list and counting its length
	while (temp1 != NULL) {
		temp1 = temp1->next_node;
		ListLength++;
	}

	if (ListLength < index)
	{
		cout << "Index out of range" << endl;
		return;
	}

	temp1 = head; // assigning the temp1 as a head again

	// if index is 1 which is head we move !HEAD! to the right and delete the first node
	if (index == 1) {
		head = head->next_node;
		delete temp1;
		return;
	}

	while (index-- > 1) {
		temp2 = temp1;
		temp1 = temp1->next_node;
	}

	temp2->next_node = temp1->next_node;

	delete temp1;
}

void LinkedList::printList() {
	Node* temp = head;

	if (head == NULL) {
		cout << "Empty list."
			<< endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->num << " ";
		temp = temp->next_node;
	}
}

int main() {

	LinkedList list;
	list.insertNode(5);
	list.insertNode(2);
	list.insertNode(4);

	cout << "Elements of the list: ";
	list.printList();

  return 0;
}
