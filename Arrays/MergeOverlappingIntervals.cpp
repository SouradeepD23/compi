//MERGE OVERLAPPING SUB-INTERVALS

#include<iostream>
#include<vector>
#include<utility> //for pair<>
#include<algorithm>

using namespace std;

vector< pair <int, int>> mergeIntervals(vector< pair <int, int>> intervals){
    vector< pair <int, int>> res;
    int i, j = 0;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].first <= res[j].second){
            res[j].second = (intervals[i].second > res[j].second) ? intervals[i].second : res[j].second;
        }
        else{
            res.push_back(intervals[i]);
            j++;
        }
        
    }
    return res;
}

int main(){
    vector< pair <int, int>> intervals = {{5, 7}, {1, 3}, {2, 4}, {6, 9}};
    vector< pair <int, int>> mergedIntervals = mergeIntervals(intervals);
    int i;
    for(i = 0; i < mergedIntervals.size() - 1; i++){
        cout<< "(" << mergedIntervals[i].first <<", " << mergedIntervals[i].second << "), ";
    }
    cout<< "(" << mergedIntervals[i].first <<", " << mergedIntervals[i].second << ")" << endl;
    return 0;
}