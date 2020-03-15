#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> mp;
    string str;
    getline (cin, str);
    string s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {   
            mp[s]++;
            s="";
        }else{
            s.push_back(str[i]);
        }
    }
    mp[s]++;
    bool b=false;
    for(auto it=mp.begin();it!=mp.end();it++)
    {  
        if(it->second>1)
        {
            cout<<it->first<<" "<<it->second<<endl;
            b=true;
        }
        
    }
    if(b==false)
    {
        cout<<"-1"<<endl;
    }
	return 0;
}