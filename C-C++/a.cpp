#include <bits/stdc++.h>  
using namespace std; 
FILE *fi,*fo;

int power(int b, int n) 
{ 
	const int mod = 1000000007; 
	if (n == 0) return 1; 
	int p = power(b, n / 2) % mod; 
	p = (p * p) % mod; 
	if (n & 1) p = (p * b) % mod; 
	return p; 
} 

long long o(vector<int> a) 
{ 
	unordered_map<int, int> max_map; 
	int mod = 1000000007; 
	int prime[10000]; 
	//cout<<"asdasd"<<endl;
	prime[0] = prime[1] = 1; 
	for (int i = 2; i < 10000; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * 2; j < 10000; j += i)
				if (prime[j] == 0) prime[j] = i;
			prime[i] = i; 
		} 
	}

	for (int i = 0; i < a.size(); i++)
	{ 
		int num = a[i]; 
		unordered_map<int, int> temp; 

		while (num > 1)
		{
			int factor = prime[num]; 
			temp[factor]++; 
			num /= factor; 
		} 

		for (auto it : temp) max_map[it.first] = max(max_map[it.first], it.second); 
	} 

	long long ans = 1; 
	for (auto it : max_map) ans = (ans * power(it.first, it.second)) % mod;
	return ans; 
}

int main()
{
	fo=freopen("a.out","w",stdout);
	vector<int> a={1,2,3,4,5,6};
	//cout<<o(a);
	fprintf(fo,"%lld",o(a));
	cout<<"asdasd";

	return 0;
}