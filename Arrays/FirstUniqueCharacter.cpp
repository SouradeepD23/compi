#include<iostream>
#include<string>
#include<vector>
using namespace std;

int firstUniqueChar(string s){
    vector<int> count(26,0);
    int idx = 0;
    for(char c : s){
        count[c-'a']++;
    }

    for(char c : s){
        if(count[c-'a'] == 1)
            return idx;
        idx++;
    }

    return -1;
}

int main(){
    string s = "asdawasasprqeeadsdawqweadaxdasdad";
    cout<< firstUniqueChar(s) << endl;
    return 0;
}