//PASCAL'S TRIANGLE
/*
{
    {1},
    {1,1},
    {1,2,1},
    {1,3,3,1},
    {1,4,6,4,1},
    {1,5,10,10,5,1}
}
*/
#include<iostream>
#include<vector>
using namespace std;

void displayTriangle(vector< vector <int>> triangle){
    for(int i=0; i < triangle.size(); i++){
		for(int j=0; j<triangle[i].size(); j++){
			cout<<triangle[i][j]<<"	";
		}
		cout<<endl;
	}
}

vector< vector <int>> generatePascalsTriangle(int numRows){
    vector< vector <int>> triangle;
    if(numRows == 0)
        return triangle;

    vector<int> frow = {1};
    triangle.push_back(frow);
    // displayTriangle(triangle);

    int i, j;
    for(i = 1; i < numRows; i++){
        vector<int> prevRow = triangle[i-1];
        vector<int> currRow;
        currRow.push_back(1);

        for(j = 1; j < i; j++){
            currRow.push_back(prevRow[j-1] + prevRow[j]);
        }

        currRow.push_back(1);
        triangle.push_back(currRow);
    }
    return triangle;
}

int main(){
    int numRows = 6;
    vector< vector <int>> triangle = generatePascalsTriangle(numRows);

    displayTriangle(triangle);
    return 0;
}