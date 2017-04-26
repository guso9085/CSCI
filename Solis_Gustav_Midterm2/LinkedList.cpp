#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *next;
	Node *previous;
	Node(int k, Node *n, Node *p){
		key = k;
		next = n;
		previous = p;
	}
};

class LinkedList{
	private:
		Node *head;
		Node *search(int value){
		}

	public:

		LinkedList(){head = NULL;};

		void getName()
		   {
			cout<<"Gustav Solis";
		   }

		void addNode(int value, int newVal){
				bool found = false;
				Node *temp = head;
				Node *add = new Node(newVal, NULL, NULL);

				if (head == NULL){
					head = add;
					return;
				}

				while (temp != NULL){
						if (temp -> key == value){
							if(temp -> next == NULL){
								temp -> next = add;
								add -> previous = temp;
								add -> next = NULL;
								found = true;
								return;
							}
							else {
								Node *Next = temp -> next;
								temp -> next -> previous = add;
								temp -> next = add;
								add -> previous = temp;
								add -> next = Next;
								found = true;
								return;
							}
						}
						temp = temp -> next;
			 	}

				if (found == false){
					add -> next = head;
					head -> previous = add;
					head = add;
				}
		}

	  Node *getHead(){
				return head;
	  }


		void printList(){
			Node *x = head;
			while(x != NULL){
				cout<<x->key<<endl;
				x = x->next;
			}
		}
};
