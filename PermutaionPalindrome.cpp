#include <bits/stdc++.h>
using namespace std;

inline char getChar(int i)
{
    return (char)(97 + i);
}

void getPermutationPalindrome(string s)
{
    map< char, vector<int> > Indexes;
    for (int i = 0; i < s.length(); i++)
    {
        Indexes[s[i]].push_back(i);
    }

    int odd_count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (Indexes[getChar(i)].size() % 2 != 0)
            odd_count++;
    }

    if (odd_count >= 2)
    {
        cout << -1 << " " << endl;
        return;
    }

    int output[s.length()], start = 0, end = s.length() - 1;

    for (int i = 0; i < 26; i++)
    {
        char current_char = getChar(i);
        for (int j = 0; j < Indexes[current_char].size(); j += 2)
        {
            if ((Indexes[current_char].size() - j) == 1)
            {
                output[s.length() / 2] = Indexes[current_char][j];
                continue;
            }
            output[start] = Indexes[current_char][j];
            output[end] = Indexes[current_char][j + 1];
            start++;
            end--;
        }
    }

    for (int i = 0; i < s.length(); i++)
        cout << output[i] << " ";
    cout << endl;
}

int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        getPermutationPalindrome(str);
    }
    return 0;
}