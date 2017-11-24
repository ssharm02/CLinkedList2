#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Assignment 2 by Sarthak Sharma Add integers to a linked list, display their square during print out
//if the user enters alphabetical characters or special character, the program cl

//define the data structure of a single element (node)
typedef struct node {
	int num;//define the members of the node
 	struct node *next;//pointer to the next node 
}Node, *NodePtr; //define node pointer 

//define the linked list
typedef struct {
	NodePtr first,np,last; //np needed to traverse, last is optional
}LinkedList;

//job of function is to find address and allocated to node and return 
//address to the main
NodePtr makeNode(int n) {
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np->num=n;//build a node for the value
	np->next=NULL;//assume null for now
	return np;//returns the address

}

//functions prints list of positive numbers and their squares
void printList(NodePtr np) {
	//np is the address
	//send address of the first element and it will print the rest
	
	while(np!=NULL) {//if pointer is null it is at the end of the list as long as there is a node
		if(np->num >= 1) {
	//to get the square of the number in the node create another variable and multiply with whatever is in the node
	int num2 = np->num * np->num;
	printf("\n %d \t %d \n", np->num, num2);
	np=np->next; //go on to the next node
		}
	}
}


int main() {

	
	int n; //the number that goes into the node
	int count; // counter for display
	int initialNum;//start the program logic

	LinkedList ll;//call the linked list method
	ll.first=NULL; //first node set to null

	//read the first number from the user
	printf("Please enter the count of input integers: \n");

	if (scanf("%d", &initialNum)!=1 || initialNum <= 1)  {
	printf("The count of the integers must be two or more \n");
		return(0);
	}

	while (initialNum != 0) {
		count++;	
		printf("Enter integer #: %d ",count);
		if(scanf("%d", &n)!=1) {
			return(0);
		}
		
		//create new node for the integer on my hand
		ll.np=makeNode(n);
		//make first pointer to point to this node
		if (ll.first==NULL)
			ll.first=ll.np;
		else
			//make the current last points to this node
			ll.last->next=ll.np;
			//update the last pointer 
			ll.last=ll.np;
			//decrease the counter
			initialNum--;
		
	}//end of while loop
	
	//Call the print function to print all positive numbers and their squares
	printf("The positive numbers entered and their squares are: \n");
	printList(ll.first);

}//end of main
