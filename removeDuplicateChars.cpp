/*
#include<bits/stdc++.h>
using namespace std;

string RemoveDuplicates(string Str)
{
    string newStr;
    unordered_map<char, int> exists;
    for (int i = 0; i < Str.length(); i++)
    {
        if (exists[Str[i]] == 0)
        {
            newStr += Str[i];
            exists[Str[i]]++;
        }
    }
    return newStr;
}

int main()
{
    string myStr;
    cin >> myStr;
    myStr = RemoveDuplicates(myStr);
    cout << myStr << endl;
    return 0;
}
kkk
*/

#include <bits/stdc++.h>  
using namespace std;  
char* removeDuplicates(char *str,int n){ 
  unordered_map<char,int> exists; 
  int index = 0;  
  for(int i=0;i<n;i++){ 
    if(exists[str[i]]==0) 
    { 
      str[index++] = s[i]; 
      exists[str[i]]++; 
    } 
  } 
  return str; 
} 
  
//driver code 
int main(){ 
  char s[] = "geeksforgeeks"; 
  int n = sizeof(s)/sizeof(s[0]); 
  cout<<removeDuplicates(s,n)<<endl; 
  return 0; 
} 