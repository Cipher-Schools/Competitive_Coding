#include <bits/stdc++.h>
using namespace std; //
// ().first, ().second
class Employee{
    public:
        int id;
        string name;
} ;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first <= p2.first)
        return true;
    else
        return false;
}

vector<pair<int, int>> mergeOveralapping(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    vector<pair<int, int>> result;
    result.push_back(intervals[0]);
    pair<int, int> tempInterval;
    for (int i = 1; i < intervals.size(); i++) {
        tempInterval = result.back();
        if (tempInterval.second >= intervals[i].first) {
            tempInterval.second = max(tempInterval.second, intervals[i].second);
            result.push_back(tempInterval);
        } else {
            result.push_back(tempInterval);
        }
    }

    return result;
}

bool comparator(Employee a, Employee b) {
    if (a.name <= b.name) 
        return true;
    else 
        return false;
}
int main() {
    vector<Employee> emp(10);
    sort(emp.begin(), emp.end(), comparator);
}