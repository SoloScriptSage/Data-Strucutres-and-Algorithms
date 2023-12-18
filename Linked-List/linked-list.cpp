#include <bits/stdc++.h>


using namespace std;


class Node{
public:
    int num;
    Node* next_node;

    Node(){
        num = 0;
        next_node = NULL;
    }

    Node(int num){
        this->num = num;
        this->next_node = NULL;
    }

};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void insertNode(int);
    void deleteNode(int);
    void sortList();
    void printList();
};

void LinkedList::insertNode(int data){
    Node* newNode = new Node(data);     // new node with data inserted

    if(head==NULL){
        head=newNode; return;}      // if head doesn't exist, newnode is gonna be the head of the linked list

    // in case we have head of the linkedlist

    Node* temp = head;

    while(temp->next_node != NULL){
        temp = temp->next_node;
    }

    temp->next_node = newNode;
}

void LinkedList::deleteNode(int index){
    Node* _head = head, *temp2 = NULL;
    int ll = 0;


    if(head==NULL){
        cout << "list is empty" << endl;
    }

    // in case head exists
    while(_head != NULL){
        _head = _head->next_node; // trying to find the last node
        ll++;
    }

    if(ll < index){
        cout << "index out of range" << endl;
    }


    /* before the sequence of stupid checks */

    _head = head; // the first head

    if(index == 1){
        Node* temp = head;
        head = head->next_node;
        delete temp;
        return;
    }

    while(index-- > 1){
        temp2 = _head;
        _head = _head->next_node;
    }

    temp2->next_node = _head->next_node;

    delete _head;

}


void LinkedList::printList(){
    Node* temp = head;

    if(head==NULL){
        cout << "head doesn't exist" << endl;
        return;
    }

    int i = 0;

    while(temp != NULL){

        cout << ++i << " " << temp->num;
        if(temp->next_node != NULL){
            cout << " -> ";
        }
        temp = temp->next_node;
    }
}

void LinkedList::sortList(){
    if(head==NULL || head->next_node==NULL)
    {
        cout << "nothing to swap or there's no values to sort" << endl;
        return;
    }

    bool swapped;
    Node* current;
    Node* lastSorted = NULL;

    do{
        swapped = false;
        current = head;

        while(current->next_node != lastSorted){

            if(current->num > current->next_node->num){

                int temp = current->num;

                current->num = current->next_node->num;
                current->next_node->num = temp;

                swapped = true;
            }

            current = current->next_node;
        }
        lastSorted = current;
    }while(swapped);
}

int n, number;

int main() {

    LinkedList lli;

    cout << "nodes-amount: ";
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> number;
        lli.insertNode(number);
    }

    cout << "usual-list: "; lli.printList(); cout << endl;
    cout << "sorted-list: "; lli.sortList(); lli.printList();

    return 0;

}
