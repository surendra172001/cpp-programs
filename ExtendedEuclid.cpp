#include <bits/stdc++.h>
using namespace std;


struct Triplet {
	int x, y, gcd;
};

Triplet extendedEuclid(int a, int b) {
	Triplet ans;
	if (b == 0) {
		ans.x = 1;
		ans.y = 0;
		ans.gcd = a;
		return ans;
	}

	Triplet ans1 = extendedEuclid(b, a%b);
	ans.x = ans1.y;
	ans.y = ans1.x - (a/b)*ans1.y;
	ans.gcd = ans1.gcd;
	return ans;
}

int main() {
	int a, b;
	cin >> a >> b;

	Triplet ans = extendedEuclid(a, b);

	cout << ans.x << "\n";
	cout << ans.y << "\n";
	cout << ans.gcd << "\n";

	return 0;
}

/*

revise
Euclid algo
Diophantine eqn
Extended Euclid
finding multicative modulod

*/

/*

Harry laughed again, though he was not sure whether or not 
George was joking. He imagined trying to conceal from Hermione 
that he had received T’s in all his O.W.L.s and immediately resolved 
to work harder from now on. 
“You lot had an inspected lesson yet?” Fred asked them. 
“No,” said Hermione at once, “have you?” 
“Just now, before lunch,” said George. “Charms.” 
“What was it like?” Harry and Hermione asked together. 
Fred shrugged. 
“Not that bad. Umbridge just lurked in the corner making notes on 
a clipboard. You know what Flitwick’s like, he treated her like a guest, 
didn’t seem to bother him at all. She didn’t say much. Asked Alicia a 
couple of questions about what the classes are normally like, Alicia 
told her they were really good, that was it.” 
“I can’t see old Flitwick getting marked down,” said George, “he 
usually gets everyone through their exams all right.” 
“Who’ve you got this afternoon?” Fred asked Harry. 
“Trelawney —” 
“A T if ever I saw one —” 
“— and Umbridge herself.” 
“Well, be a good boy and keep your temper with Umbridge today,” 
said George. “Angelina’ll do her nut if you miss any more Quidditch 
practices.” 
But Harry did not have to wait for Defense Against the Dark Arts

Harry laughed again, though he was not sure whether or not 
George was joking. He imagined trying to conceal from Hermione 
that he had recieved T's in all his O.W.L.s and immediately resolved
to work harder from now on.
"You lot had an inspected lesson yet?" Fred asked them.
"No," said Hermione at once, "have you?"
"Just now," before lunch," said George. "Charm."
"What was it like?" Harry and Hermione asked together.
Fred shrugged.


"Not that bad. Umbridge just lurked in the corner making notes on
a clipboard. You know what Flitwick's like, he treared her like a guest,
didn't seem to bother him at all. She didn't say much. Asked Alicia a
couple of questions about what the classes are normally like, Alicia
told her they were really good, th"










*/