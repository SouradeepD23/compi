// SPECIAL STACK WITH GETMIN() IN O(1) TIME AND O(N) SPACE

#include<bits/stdc++.h>
using namespace std;

class MinStack2{
	
	stack<int> st, min;
	
	public:
	void push(int x){
		st.push(x);
		if(min.empty() || st.top() <= min.top())
			min.push(st.top());
		else
			min.push(min.top());
	}
	
	void pop(){
		if(!st.empty()){
			min.pop();
			st.pop();	
		}
//		else
//			cout<<"STACKS EMPTY";
	}
	
	int top(){
	if(!st.empty())
		return st.top();
	}
	
	int getMin(){
		if(!min.empty())
			return min.top();
	}
};

int main(){
	MinStack2 M;
	cout<<"PUSHING----------------"<<endl;
	M.push(8);
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.push(10);
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.push(6);
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.push(3);
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.push(7);
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	
	cout<<"POPPING----------------"<<endl;
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.pop();
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.pop();
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.pop();
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.pop();
	cout<< M.top() <<"	"<< M.getMin()<<endl;
	M.pop();
//	cout<< M.top() <<"	"<< M.getMin()<<endl;
//	M.pop();
//	cout<< M.top() <<"	"<< M.getMin()<<endl;
}



