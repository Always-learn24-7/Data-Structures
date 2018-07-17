//Simple program to illustrate use of Hash Table for calculating frequencies of each character in a string;

using namespace std;
#include<bits/stdc++.h>
int f[26]={0};      //Hash_Table for storing Frequency;

int hash_function(char c)   //Hash_function;
{
    return c-'a';
}
int main()
{
    string s={"abacdec"};
    for(int i=0;i,s.length();i++)
    {
        f[hash_function(s[i])]++;           //increasing frequency of each character in string;
    }
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i]<<"-->"<<f[hash_function(s[i])]<<"\n";    //duplicate characters will occur;
    }

    //using map STL;
    map<char,int> m;        //Hash_Table;
    for(int i=0;i<s.length();i++)
        m[s[i]]++;          //increasing frequency of each character;
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<"-->"<<it->second<<"\n";       //distinct characters;
}
