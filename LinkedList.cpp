/*--- LinkedList.cpp --------------------------------------------------
This implementation file contains the definitions of LinkedList.

Node(): The Node class constructor initializes a Node's data members.
size(): Retrieves the number of nodes in the list.
LinkedList() : Constructs an empty LinkedList object.
display():Display a list.
ostream &operator<<():Overloaded the insertion operator for LinkedList object.
insert():Insert a value into a LinkedList at a given index.
erase(): Removes a value from a LinkedList at a given index.
~LinkedList():Destroys a LinkedList object.
LinkedList(const LinkedList& origList):Construct a copy of a LinkedList object.
const LinkedList & operator=():Assign a copy of a LinkedList object to the
current object.
copy():Construct a copy of a LinkedList object.


Student Name: Nicol Salgado
Course:CSCI 1107

---------------------------------------------------------------------*/
#include <iostream>
#include<new>
using namespace std;

#include "LinkedList.h"

LinkedList::LinkedList() : first(0), mySize(0) {};
/* -------------------------------------------------------------------
Constructs an empty LinkedList object.
---------------------------------------------------------------------*/
int LinkedList::size()const{
	return mySize;
};
/* -------------------------------------------------------------------
Constructs an empty LinkedList object.
---------------------------------------------------------------------*/
void LinkedList::display(ostream &out)const {
	Node *ptr = first;
	for (; ptr != NULL;) {
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}
/* -------------------------------------------------------------------
Display a list.
---------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const LinkedList &intList) {
	intList.display(out);
	return out;
}
/* -------------------------------------------------------------------
Overloaded the insertion operator for the LinkedList object.
---------------------------------------------------------------------*/
void LinkedList::insert(ElementType dataValue) {
	NodePointer nPtr = new(nothrow) Node(dataValue);
	// empty list
	if (first == NULL) {
		first = nPtr;
	}
	// not empty list
	else {
		NodePointer curPtr = first;
		NodePointer predPtr = NULL;
		for (; curPtr != NULL && curPtr->data < dataValue;) {
			predPtr = curPtr;
			curPtr = curPtr->next;
		}
		nPtr->next = curPtr;
		if (predPtr == NULL)
			first = nPtr;
		else
			predPtr->next = nPtr;
		mySize++;
	}
}
/* -------------------------------------------------------------------
Insert a value into a LinkedList at a given index.
---------------------------------------------------------------------*/
void LinkedList::erase(ElementType dataValue) {
	NodePointer curPtr = first;
	NodePointer predPtr = NULL;

	for (; curPtr != NULL && curPtr->data < dataValue;) {
		predPtr = curPtr;
		curPtr = curPtr->next;
	}
	if(curPtr != NULL && curPtr->data == dataValue) {
		if (predPtr == NULL)
			first = curPtr->next;
		else
			predPtr->next = curPtr->next;
		delete curPtr;
	}
	else 
		cout << "The item value " << dataValue << " is not on the list." << endl;
}
/* -------------------------------------------------------------------
Removes a value from a LinkedList at a given index.
---------------------------------------------------------------------*/
LinkedList::~LinkedList() {
	Node *ptr = first;
	for (; ptr != NULL;) {
		first = ptr->next;
		delete ptr;
		ptr = first;
	}
	if (first == NULL)
		cout << "list destroyed." << endl;
	else
		cout << "list NOt destroyed" << endl;
}
/* -------------------------------------------------------------------
Destroys a LinkedList object.
---------------------------------------------------------------------*/
LinkedList::LinkedList(const LinkedList& origList) {
	copy(origList);
}
/* -------------------------------------------------------------------
Construct a copy of a LinkedList object.
---------------------------------------------------------------------*/
const LinkedList & LinkedList::operator=(const LinkedList& origList) {
	if (this == &origList)
		cout << "Checked self-assignment." << endl;
	else
		this->~LinkedList();

		copy(origList);

	return *this;
}
/* -------------------------------------------------------------------
Assign a copy of a LinkedList object to the current object.
---------------------------------------------------------------------*/
void LinkedList::copy(const LinkedList& origList) {
	if (origList.mySize == NULL)
		first = NULL;
	else {
		NodePointer origptr = origList.first;
		NodePointer lastptr = new Node(*origptr);
		first = lastptr;
		origptr = origptr->next;
		for (; origptr != NULL;) {
			lastptr->next = new(nothrow)Node(*origptr);
			lastptr = lastptr->next; //move lastPtr forward
			origptr = origptr->next; //move to next node in list
		}
	}
}
/* -------------------------------------------------------------------
Construct a copy of a LinkedList object.
---------------------------------------------------------------------*/
void LinkedList::reverserList() {
	NodePointer curPtr = first;
	NodePointer predPtr = NULL;
	NodePointer nPtr;

	while (curPtr != NULL) {
		nPtr = curPtr->next;
		curPtr->next = predPtr;
		predPtr = curPtr;
		curPtr = nPtr;
	}
	first = predPtr;
}
/* -------------------------------------------------------------------
Construct a copy of a LinkedList object.
---------------------------------------------------------------------*/