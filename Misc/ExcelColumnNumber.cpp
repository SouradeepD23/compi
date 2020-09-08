/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

column  column number
  A  ->  1
  B  ->  2
  C  ->  3
  ...
  Z  ->  26
  AA ->  27
  AB ->  28 
*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int excelColNum(string s){
  int res = 0, i, t, n = s.length()-1;
  for(i = n; i >=0; i--){
    t = lround((s[i] - 'A' + 1) * pow(26, n-i)); //lround() is required because of inaccuracy of pow()
    cout<< t << endl;
    res += t;
  }
  return res;
}
 

int main(){
  string s = "CDA";
  cout<< "COLUMN NAME : " << s << endl;
  cout<< "COLUMN NUMBER : " << excelColNum(s) << endl;
}