//FIND ALL UNIQUE QUADRUPLETS IN ARRAY SUCH THAT THEIR SUM = A GIVEN VALUE

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector< int>> fourSum(vector<int> A, int N){
    vector< vector< int>> res;
    int i, j, left, right, sum;

    sort(A.begin(), A.end());

    for(i = 0; i < A.size() - 3; i++){
        if(i != 0 && A[i] == A[i-1])
            continue;
        
        for(j = i + 1; j < A.size() - 2; j++){
            if(j != (i + 1) && A[j] == A[j-1])
                continue;
            left = j + 1;
            right = A.size() - 1;
            while(left < right){
                sum = A[i] + A[j] + A[left] + A[right];
                if(sum < N)
                    left++;
                else if(sum > N)
                    right--;
                else{
                    res.push_back({A[i], A[j], A[left], A[right]});
                    left++;
                    right--;

                    while(left < right && A[left] == A[left - 1]){
                        left++;
                    }

                    while(left < right && A[right] == A[right + 1]){
                        right--;
                    }
                }
            }
        }
    }

    return res;
}

int main(){
    int i, j;
    vector<int> A = {1, 0, -1, 0, -2, 2};
    int N = 0;
    vector< vector< int>> res = fourSum(A, N);
    cout<< "{" << endl;
    for(i = 0 ; i < res.size(); i++){
        cout<< "{";
        for(j = 0; j < 4; j++){
            cout<< res[i][j];
            if(j != 3)
                cout<<" ,";
        }
        cout<< "}";
        if(i != res.size() - 1 )
            cout<<",";
        cout<< endl;
    }
    cout<< "}" ;
}