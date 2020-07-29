#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int K){
	int n = num.size();
	stack <char> st;
	
	//pushing elements to stack
	for(char c : num){
		while(!st.empty() && K>0 && st.top()>c){
			st.pop();
			K--;
//			if(!st.empty())
//				cout<<st.top()<<endl;
//			else
//				cout<<"XXXXX"<<endl;
		}
		
		if(!st.empty() || c!='0')
			st.push(c);
			
//		if(!st.empty())
//				cout<<st.top()<<endl;
//		else
//			cout<<"XXXXX"<<endl;
	}
	
	//removing largest values
	while(!st.empty() && K--){
		st.pop();
//		if(!st.empty())
//				cout<<st.top()<<endl;
//		else
//			cout<<"XXXXX"<<endl;
	}
	if(st.empty())
		return "0";
	
	//storing result in string
	while(!st.empty()){
		num[n-1] = st.top();
		st.pop();
		n--;
	}
	return num.substr(n);
}

int main(){
	string num;
	int K;
	cin>>num;
	cin>>K;
	cout<<removeKdigits(num, K);
	return 0;
}
