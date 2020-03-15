#include<iostream>
using namespace std;
#define MOD 1000000007
typedef long long ll;

class Stack
{
	int arr[50], top, capacity;
public:
	Stack();
	inline bool empty();
	inline bool full();
	void push(int);
	void pop();
	int peek();
};

Stack::Stack() {
	top = -1;
	capacity = 50;
}

inline bool Stack::empty() {
	return top == -1;
}

inline bool Stack::full() {
	return ((top + 1) == capacity);
}


void Stack::push(int data) {
	if (!full()) {
		arr[++top] = data;
	}
	else {
		cout << "Stack overflow\n";
	}
}

void Stack::pop() {
	if (!empty()) {
		top--;
	}
	else {
		cout << "Stack underflow\n";
	}
}

int Stack::peek() {
	if (!empty()) {
		return arr[top];
	}
	else {
		return -1;
	}
}


class queue {
	Stack s1;
public:
	int front();
	void push(int);
	void pop();
};

int queue::front() {
	return s1.peek();
}

void queue::push(int data) {
	Stack temp;
	while(!s1.empty()) {
		temp.push(s1.peek());
		s1.pop();
	}	
	temp.push(data);
	while (!temp.empty()) {
		s1.push(temp.peek());
		temp.pop();
	}
}

void queue::pop() {
	s1.pop();
}


int main() {
    queue q;
    int c = 4;
    while (true) {
    	cout << "Enter...\n";
    	cout << "1. To Push\n";
    	cout << "2. To Pop\n";
    	cout << "3. To view front\n";
    	cout << "4. To exit\n";
    	cin >> c;
    	if (c == 4) {
    		break;
    	}

    	switch(c) {
    		case 1:
    			int data;
    			cout << "Enter the data\n";
    			cin >> data;
    			q.push(data);
    			break;
    		case 2:
    			q.pop();
    			break;
    		case 3:
				int ans = q.front();
				if (ans != -1) {
    				cout << ans << "\n";
				}
				else {
					cout << "Empty queue\n";
				}
    			break;
    	}
    }

    return 0;
}