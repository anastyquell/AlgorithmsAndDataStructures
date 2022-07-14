#include <iostream>
#include <Windows.h>
#include "List.h"

namespace ASD {

	template <typename T>
	class List {
	public:
		class Node {
		public:
			Node(T v, Node* n = 0, Node* p = 0) { value = v; next = n; prev = p; }
			T value;
			Node* prev, * next;
		};
	private:
		Node* head, * tail;
		int count;
	public:
		List() { head = tail = 0; count = 0; }
		~List() {
			RemoveAll();
		}
		Node* GetHead() { return head; }
		Node* GetTail() { return tail; }
		int GetCount() { return count; }

		List& RemoveAll() {
			Node* t = head, * t1;
			while (t) {
				t1 = t;
				t = t->next;
				delete t1;
			}
			head = tail = 0;
			count = 0;
			return *this;
		}

		List& AddTail(T v) {
			Node* t = new Node(v, 0, tail);

			if (!head) {
				head = tail = t;
			}
			else {
				tail->next = t;
				tail = t;
			}
			count++;
			return *this;
		}


		List& AddHead(T v) {
			Node* t = new Node(v, head, 0);

			if (!tail) {
				head = tail = t;
			}
			else {
				head->prev = t;
				head = t;
			}
			count++;
			return *this;
		}

		void RemoveAt(int i) {
			Node* t = (*this)[i];
			if (t) {
				if (t->prev) {
					t->prev->next = t->next;
				}
				if (t->next) {
					t->next->prev = t->prev;
				}
				if (head == t) {
					head = t->next;
				}
				if (tail == t) {
					tail = t->prev;
				}
				delete t;
			}
		}
	};
}