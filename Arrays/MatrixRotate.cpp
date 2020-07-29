//ROTATE MATRIX 90 DEGREE CLOCKWISE

#include<bits/stdc++.h>
using namespace std;

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

void rotateMatrix(vector< vector <int>> M){
	int i, j, temp;
	int R = M.size();
	int C = M[0].size();
	
	//TRANSPOSE
	for(i=0; i<R; i++){
		for(j=i; j<C; j++){
			temp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = temp;
		}
	}
	cout<<"TRANSPOSED MATRIX:"<<endl;
	displayMatrix(M);
	
	
	//FLIP HORIZONTALLY ---------check flipping
	for(i=0; i<R; i++){
		for(j=0; j<C/2; j++){
			temp = M[i][j];
			M[i][j] = M[i][C-j-1];
			M[i][C-1-j] = temp;
		}
	}
	
	cout<<"ROTATED MATRIX:"<<endl;
	displayMatrix(M);
	
}

int main(){
	vector< vector<int>> M = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<"ORIGINAL MATRIX:"<<endl;
	displayMatrix(M);
	rotateMatrix(M);
	return 0;
}
