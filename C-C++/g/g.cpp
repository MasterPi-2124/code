#include<iostream>
using namespace std;
void printArray(int a[],int n){
	for (int i = 0;i < n;i++){
		cout << a[i];
	}
	cout << "\n";
}
void Try(int a[],int i,int n){
	for (int j = 0;j <= 1;j++){
		a[i] = j;
		if(i == n - 1){
		      printArray(a,n);	
		}
		else {
			Try(a,i + 1,n);
		}
	}
}
int main(){
	int a[100];
	int n;
	cin >> n;
	Try(a,0,n);
	return 0;
}