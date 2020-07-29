#include<bits/stdc++.h>
using namespace std;

bool parenthesisCheck(string expr){
	int i;
	stack<char> st;
	for(char c : expr){
		if(c=='(' || c=='{' || c=='['){
			st.push(c);
			continue;
		}
		
		if(st.empty())
			return false;
		
		switch(c){
			case ')':
				if(st.top()!='(')
					return false;
				else{
					st.pop();
					continue;
				}
			
			case '}':
				if(st.top()!='{')
					return false;
				else{
					st.pop();
					continue;
				}
				
			case ']':
				if(st.top()!='[')
					return false;
				else{
					st.pop();
					continue;
				}
		}
	}
	
	return st.empty();
}

int main(){
	string expr;
	cin>>expr;
	cout<<parenthesisCheck(expr);
}
