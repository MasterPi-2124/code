#include<bits/stdc++.h>  
using namespace std; 
FILE *fi,*fo;


string Sum(string s1, string s2) 
{ 
    if (s1.length() > s2.length()) 
        swap(s1, s2); 
    string s = ""; 
    int n1 = s1.length(), n2 = s2.length(); 
    reverse(s1.begin(), s1.end()); 
    reverse(s2.begin(), s2.end()); 
  
    int c=0; 
    for (int i=0; i<n1; i++) 
    {  
        int res = (s1[i]-'0')+(s2[i]-'0')+c; 
        s.push_back(res%10 + '0');  
        c=res/10; 
    } 

    for (int i=n1; i<n2; i++) 
    { 
        int res = (s2[i]-'0')+c; 
        s.push_back(res%10 + '0'); 
        c=res/10; 
    } 

    if (c) 
        s.push_back(c+'0'); 

    reverse(s.begin(), s.end()); 
  
    return s; 
}

string o(string num)
{
    int n = num.length(); 
    if (n==0) return "0";
    string pre;
    pre = num[0]; 
    string res=pre;
    string c="0";

    for (int i = 1; i < n; i++)
    {
        int numi = num[i]-'0'; 
        numi=numi*(i+1);
        string sss= to_string(numi);
        pre=pre+"0";
        c = Sum(sss,pre); 
        res = Sum(res,c);
        pre=c;
    } 
    
    while (res[0]=='0')
    {
        res.erase(res.begin());
    }
    if(res.length()==0) return "0";
    return res;
}

int main()
{
	fo=freopen("a.out","w",stdout);
	string a="00";
	cout<<o(a);
	return 0;
}