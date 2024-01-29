#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n%2==1){
		for(int i=0;i<=n/2;i++){
			cout << (n-i-1)*2 << endl;
		}
		for(int i=(n/2)-1;i>=0;i--){
			cout << (n-i-1)*2 << endl;
		}
	}
	else{
		for(int i=0;i<n/2;i++){
			cout << (n-i-1)*2 << endl;
		}
		for(int i=(n/2)-1;i>=0;i--){
			cout << (n-i-1)*2 << endl;
		}
	}
	return 0;
} 



