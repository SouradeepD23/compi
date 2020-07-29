// SPECIAL STACK WITH GETMIN() IN O(1) TIME AND O(N) SPACE

#include<bits/stdc++.h>
using namespace std;

class MinStack1{
	
	stack<int> st, min;
	
	public:
	void push(int x){
		if(min.empty() || x < min.top())
			min.push(x);
	st.push(x);
	}
	
	void pop(){
		if(!st.empty()){
			if(st.top()==min.top())
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
	MinStack1 M;
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



