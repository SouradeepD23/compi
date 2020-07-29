// SPECIAL STACK WITH GETMIN() IN O(1) TIME AND O(1) SPACE

#include<bits/stdc++.h>
using namespace std;

class MinStackUlt{
	
	stack<int> st;
	int min;
	
	public:
	
	bool empty(){
		return st.empty();
	}
	
	void push(int x){
		if(st.empty()){
			st.push(x);
			min = x;
		}
		else if(x >= min)
			st.push(x);
		else{
			st.push(2*x-min);
			min = x;
		}
	}
	
	void pop(){
		if(!st.empty()){
			if(st.top() >= min)
				st.pop();
			else{
				min = 2*min-st.top();
				st.pop();
			}
		}
//		else
//			cout<<"STACKS EMPTY";
	}
	
	int top(){
	if(!st.empty()){
		if(st.top() < min)
			return min;
		else
			return st.top();
		}
	}
	
	int getMin(){
		return min;
	}
};

int main(){
	MinStackUlt M;
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



