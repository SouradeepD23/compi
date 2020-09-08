//FIND LARGEST SUBSTRING WITH UNIQUE CHARACTERS
//For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6. 

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int findUniqueSubstring(string S){
    int n = S.length();
    int maxlen = 0;

    unordered_map<char, int> lastIdx;

    int i = 0, j, t;

    for(j = 0; j < n; j++){
        t = (lastIdx[S[j]] + 1);

        i = (i > t) ? i : t;

        maxlen = (maxlen > (j - i + 1)) ? maxlen : (j - i + 1);

        lastIdx[S[j]] = j;
    }

    return maxlen;

}

int main(){
    string S = "ABDEFGABEF";
    cout<< "LENGTH OF LARGEST SUBSTRING WITH UNIQUE CHARACTERS : " << findUniqueSubstring(S) << endl;
    return 0;
}