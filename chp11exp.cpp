#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	char string[80];

	cout << "Enter a string : ";
	cin >> string;

	int len = strlen(string);

	fstream file;
	cout << "\nOpening the 'exp2.cxx' file and storing the string in it\n\n";

	file.open("exp2.cxx", ios::in | ios::out);

	for (int i = 0; i < len; i++)
		file.put(string[i]);

	file.seekg(0);

	char ch;
	cout << "Reading the file contents : ";
	while (file)
	{
		file.get(ch);
		cout << ch;
	}

	return 0;
}