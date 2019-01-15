#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() {
	//initialize empty list with data in head as SIZE
	head = new IntNode(0);
	tail = new IntNode(-1);

	//head and tail pointing at eachother
	head->next = tail;
	head->prev = tail;
	tail->next = head;
	tail->prev = head;
}

IntList::~IntList() {
	int SIZE = head->data;

	for (int i = 0; i < SIZE; i++) {
		this->pop_back();
	}
	
	delete tail;
	delete head;
}

void IntList::push_front(int nData) {
	IntNode* nNode = new IntNode(nData);
	IntNode* tmp = NULL;

	tmp = head->next;
	head->next = nNode;
	nNode->next = tmp;
	nNode->prev = head;
	tmp->prev = nNode;
	
	//increase SIZE counter
	head->data++;
}

void IntList::pop_front() {
	IntNode* tmp = NULL;
	curr = head->next;

	tmp = curr->next;
	curr->next = NULL;
	curr->prev = NULL;
	head->next = tmp;

	delete curr;
	
	//decrease SIZE counter
	head->data--;
}

void IntList::push_back(int nData) {
	IntNode* nNode = new IntNode(nData);
	IntNode* tmp = NULL;
	
	tmp = tail->prev;
	tail->prev = nNode;
	nNode->prev = tmp;
	nNode->next = tail;
	tmp->next = nNode;

	//increase SIZE counter
	head->data++;
}

void IntList::pop_back() {
	IntNode* tmp = NULL;
	
	curr = tail->prev;
	tmp = curr->prev;
	curr->next = NULL;
	curr->prev = NULL;
	tmp->next = tail;
	tail->prev = tmp;

	delete curr;

	//decrease SIZE counter
	head->data--;
}

bool IntList::empty() const{
	if (head->data == 0) {
		return true;
	}
	else{
		return false;
	}
}

std::ostream & operator<<(std::ostream &out, const IntList &rhs)
{
	IntNode* tmp = NULL;
	tmp = rhs.head->next;

	for (int i = 0; i < rhs.head->data; i++) {
		out << tmp->data;

		if (tmp != rhs.tail->prev){
			out << " ";
		}

		tmp = tmp->next;
	}
	
	return out;
}

void IntList::printReverse() const{
	IntNode* tmp = NULL;
	tmp = tail->prev;

	for (int i = 0; i < head->data; i++) {
		cout << " " << tmp->data;
		tmp = tmp->prev;
	}
	//std::cout << std::endl;

}

void IntList::print() {
	curr = head->next;

	for (int i = 0; i < head->data; i++) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}


