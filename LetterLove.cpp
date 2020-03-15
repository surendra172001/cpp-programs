#include<bits/stdc++.h>
using namespace std;

void getOccurence(string myString)
{
    string myLetter = "asp";
    map< char, int > letterCount;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < myString.length(); j++)
            if (myLetter[i] == myString[j])
                letterCount[myLetter[i]]++;

    for (int i = 0; i < 3; i++)
        cout << letterCount[myLetter[i]] << " ";
    cout << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    string myString;
    cin >> myString;
    getOccurence(myString);
    return 0;
}