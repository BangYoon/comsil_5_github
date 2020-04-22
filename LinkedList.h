#include <iostream>
using namespace std;

// Linked List Node -> template 사용
template <class T>
class Node {
public:
	T data;
	Node *link;
	Node(T element) {
	        data = element;
		link = 0;
	}
};

// Linked List Class -> template 사용
template <class T>
class LinkedList {
protected:
	Node<T> *first;
	int current_size;
public:
	LinkedList() {
		first = 0;
		current_size = 0;
	};

	int GetSize() { return current_size; };  //노드 개수 반환 
	
        void Insert(T element) {  //맨앞 원소 삽입
		Node<T> *newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;
	};

        virtual bool Delete(T &element){  //맨뒤 원소 삭제
                //마지막 노드 리턴하고 메모리에서 할당 해제
		if (first == 0) return false;
		Node<T> *current = first, *previous = 0;
		while (1) {  //마지막 노드까지 찾아가는 반복문
			if (current->link == 0) {  //find end node
				if (previous) previous->link = current->link;
				else first = first->link;
				break;
			}
			previous = current;
			current = current->link;
		}
		element = current->data;
		delete current;
		current_size--;
		return true;
	};

	void Print() {  //리스트 출력
		Node<T> *current_node = first;
		int idx = 1;

		if (current_size == 0) {  //list 비어있는 경우
			cout << "출력할 Node가 없습니다." << endl;
		}
		else {	
			while (current_node != NULL) {  //node가 없을때까지 반복
				if (idx == current_size) {
					cout << "[" << idx << "|" << current_node->data << "]" << endl;
				}
				else {  
					cout << "[" << idx << "|" << current_node->data << "]->";
					idx++;
				}
				current_node = current_node->link;
			}
		}
	};
};
