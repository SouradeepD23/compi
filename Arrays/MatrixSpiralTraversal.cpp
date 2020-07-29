//MATRIX SPIRAL TRAVERSAL

#include<iostream>
#include<vector>
using namespace std;

//PRINT MATRIX
void displayMatrix(vector< vector <int>> M){
	int i, j;
	int R = M.size();
	int C = M[0].size();
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			cout<<M[i][j]<<"	";
		}
		cout<<endl;
	}
}

//SPIRAL TRAVERSAL
void spiralTraversal(vector< vector <int>> M){
	int left = 0, right = M[0].size()-1, top = 0, bottom = M.size()-1;
	int dir = 0, i;
	
	while(left <= right && top <= bottom){
		if(dir == 0){
			for(i = left; i <= right; i++){
				cout<<M[top][i]<<" ";
			}
			top++;
		}
		
		if(dir == 1){
			for(i = top; i <= bottom; i++){
				cout<<M[i][right]<<" ";
			}
			right--;
		}
		
		if(dir == 2){
			for(i = right; i >= left; i--){
				cout<<M[bottom][i]<<" ";
			}
			bottom--;
		}
		
		if(dir == 3){
			for(i = bottom; i >= top; i--){
				cout<<M[i][left]<<" ";
			}
			left++;
		}
		
		dir = (dir + 1) % 4;
	}
}

int main(){
	vector< vector<int>> M = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<"ORIGINAL MATRIX:"<<endl;
	displayMatrix(M);
	cout<<"SPIRAL TRAVERSAL:"<<endl;
	spiralTraversal(M);
	return 0;
}
