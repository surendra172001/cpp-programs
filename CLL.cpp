#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
	node() {
		data = 0;
		next = NULL;
	}
};

node* get_node(int data) {
	node *new_node = new node();
	new_node->data = data;
	return new_node;
}

class CLL {
	int length;
	node *head, *end;
	void null_insert(int);
public:
	CLL();

	node *get_head();
	void insert_head(int);
	void insert_end(int);
	void insert(int, int);
	void print_list();
	int len();
	void primary_delete();
	void s_delete();
	void e_delete();
	void k_delete(int);
	void empty_list(int);

	~CLL();
};


CLL::CLL() {
	length = 0;
	head = end = NULL;
}

inline node* CLL::get_head() {
	return head;
}

void CLL::null_insert(int data) {
	length++;
	node *p = get_node(data);
	head = p;
	end = head;
	head->next = head;
}


void CLL::insert_head(int data) {
	if (head != NULL) {
		length++;
		node *p = get_node(data);
		end->next = p;
		p->next = head;
		head = p;
	}
	else {
		null_insert(data);
	}
}

void CLL::insert_end(int data) {
	
	if (head != NULL) {
		length++;
		node *p = get_node(data);
		p->next = head;
		end->next = p;
		end = p;
	}
	else {
		null_insert(data);
	}	
}

void CLL::insert(int data, int k) {
	if (head != NULL) {
		node *f = NULL, *t = head;

		for (int i = 0; i < k; i++) {
			f = t;
			t = t->next;
		}
		
		node *p = get_node(data);
		p->next = f->next;
		f->next = p;

		if (t == head) {
			end = end->next;
		}
		length++;
	}
	else {
		null_insert(data);
	}
}


void CLL::print_list() {
	if (head != NULL) {
		node *temp = head;
		while (temp->next != head) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << "\n";
	}
}

int CLL::len() {
	return length;
}



void CLL::primary_delete() {
	delete head;
	head = NULL;
}




void CLL::s_delete() {
	if (head != NULL) {
		if (head == end) {
			primary_delete();
		}
		else {
			node *t = head;
			head = head->next;
			end->next = head;
			delete t;
			length--;
		}
	}
}




void CLL::e_delete() {
	if (head != NULL) {
		if (head == end) {
			primary_delete();
		}
		else {
			node *f = head;
			while (f->next != end) {
				f = f->next;
			}
			node *t = end;
			end = f;
			end->next = head;
			delete t;
			length--;
		}
	}
}



void CLL::k_delete(int k) {
	if (head != NULL) {
		if (k == 1 || head == end) {
			s_delete();
		}
		else {
			length--;
			node *f = NULL, *t = head;
			for (int i = 0; i < k - 1; i++) {
				f = t;
				t = t->next;
			}
			f->next = t->next;
			if (t == end) {
				end = f;
			}
			delete t;
			t = NULL;
		}
	}
}



void CLL::empty_list(int k) {
	if (head != NULL) {
		while (head != NULL) {
			if (head == end || k == 1) {
				cout << head->data << "\n";
				s_delete();
			}
			else {
				length--;
				node *f = NULL, *t = head;
				for (int i = 0; i < k - 1; i++) {
					f = t;
					t = t->next;
				}
				f->next = t->next;
				if (t == end) {
					end = f;
				}
				delete t;
				t = NULL;
				// print_list();
			}
		}
	}
}



CLL::~CLL() {
	if (head != NULL) {
		node *temp = head;
		while (temp != end) {
			node *t = temp;
			temp = temp->next;
			delete t;
			end->next = temp;
		}
		delete end;
	}
}




int main() {

	CLL l1;
	int n;
	cin >> n;
	int data;
	for (int i = 0; i < n; i++) {
		cin >> data;
		l1.insert_head(data);
	}

	// cout << l1.len() << "\n";
	// l1.print_list();

	// cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	cin >> data;
	// 	l1.insert_end(data);		
	// }
	

	// cout << l1.len() << "\n";
	// l1.print_list();


	// cin >> n;
	int k;
	// for (int i = 0; i < n; i++) {
	// 	cin >> data >> k;
	// 	l1.insert(data, k);		
	// }
	

	// cout << l1.len() << "\n";
	// l1.print_list();


	// cin >> n;
	// for (int i = 0; i < n; i++) {
	// 	cin >> k;
	// 	l1.s_delete();
	// 	cout << l1.len() << "\n";
	// 	l1.print_list();		
	// }

	// cin >> n;
	// while (l1.get_head()) {
	// 	cin >> k;
	// 	l1.k_delete(k);
	// 	cout << l1.len() << "\n";
	// 	l1.print_list();		
	// }

	cin >> k;
	l1.empty_list(k);
    return 0;
}