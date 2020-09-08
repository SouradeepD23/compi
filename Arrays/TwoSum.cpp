//FIND PAIR OF INDEXES (i,j) IN ARRAY A[] SUCH THAT A[i] + A[j] = GIVEN VALUE

//use hash-map for O(n) time

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum (vector<int> A, int N){
    unordered_map<int, int> m;
    int t;
    for(int i = 0; i < A.size(); i++){
        t = N - A[i];
        if(m.find(t) != m.end())
            return {i, m[t]};
        else
            m.insert(make_pair(A[i], i)); //make_pair needed for insert in map
    }
    return {-1, -1};
}

int main(){
    vector<int> A = {1, 4, 45, 6, 10, -8};
    int N = 16;
    vector<int> res = twoSum(A, N);
    cout<<" i = " << res[0] << endl;
    cout<<" j = " << res[1] << endl;
    return 0;
}