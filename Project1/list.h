#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

template <class Data>
class LinkedList
{
private:
	class Node
	{
	public:
		Node(Data data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		~Node() {}

		Data data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	LinkedList()
	{
		reset_list();
		size = 0;
	}
	~LinkedList()
	{
		//clear();
	}

	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}

	void add_first(Data newElem)
	{
		head = new Node(newElem);
		tail = head;
	}

	void push_back(Data newElem)
	{
		if (size == 0) {
			add_first(newElem);
		}
		else {
			tail->next = new Node(newElem, nullptr, tail);
			tail = tail->next;
		}
		size++;
	}

	void push_front(Data newElem)
	{
		if (size == 0) {
			add_first(newElem);
		}
		else {
			head = new Node(newElem, head);
			head->next->prev = head;
		}
		size++;
	}

	void pop_back()
	{
		if (size == 0) return;

		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			Node* current = tail->prev;
			current->next = nullptr;
			delete tail;
			tail = current;
		}
		size--;
	}

	void pop_front()
	{
		if (size == 0) return;

		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			Node* current = head->next;
			current->prev = nullptr;
			delete head;
			head = current;
		}
		size--;
	}

	void insert(Data newElem, size_t index)
	{
		if (index >= size) {
			throw out_of_range("Index is greater than list size");
		}
		else if (index == 0) {
			push_front(newElem);
		}
		else {
			Node* current = head;
			size_t counter = 0;
			while (counter != index - 1) {
				current = current->next;
				counter++;
			}
			current->next = new Node(newElem, current->next, current);
			current = current->next;
			current->next->prev = current;
			current->prev->next = current;
			size++;
		}
	}

	Node* at(size_t index)
	{
		if (index >= size) {
			throw out_of_range("Index is greater than list size");
		}
		else {
			Node* current = head;
			size_t counter = 0;
			while (counter != index) {
				current = current->next;
				counter++;
			}
			return current;
		}
	}

	void remove(size_t index)
	{
		if (index >= size) {
			throw out_of_range("Index is greater than list size");
		}
		else if (index == 0) {
			pop_front();
		}
		else if (index == size - 1) {
			pop_back();
		}
		else {
			Node* current = head;
			size_t counter = 0;
			while (counter != index) {
				current = current->next;
				counter++;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			size--;
		}
	}

	size_t get_size()
	{
		return size;
	}

	void print_to_console()
	{
		Node* current = head;
		while (current->next != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data << " ";
	}

	void clear()
	{
		Node* current = head->next;
		if (current != nullptr) {
			while (current->next != nullptr) {
				delete head;
				head = current;
				current = head->next;
			}
			delete head;
			delete tail;
			size = 0;
		}
	}

	void set(size_t index, Data newElem)
	{
		if (index >= size) {
			throw out_of_range("Index is greater than list size");
		}
		Node* current = head;
		size_t counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		current->data = newElem;
	}

	int find(Data elem)
	{
		if (size != 0) {
			Node* current = head;
			for (size_t i = 0; i < size; i++) {
				if (elem == current->data) {
					return i;
				}
				current = current->next;
			}
		}
		return -1;
	}

	void swap(int index1, int index2) {
		Node* node1 = at(index1);
		Node* node2 = at(index2);
		Data temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}

	bool isEmpty()
	{
		return !size;
	}
};