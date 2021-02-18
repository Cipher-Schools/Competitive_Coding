#include <bits/stdc++.h>
using namespace std;

void getMaxInQueue(queue<int> q)
{
    int max = 0;
    while (!q.empty())
    {
        if (q.front() > max)
            max = q.front();
        q.pop();
    }
 
    cout << max << " ";
    return;
}
 
void slidingWindowMaximum(vector<int>& arr, int K)
{
    int size = arr.size();
    queue<int> q;
 
    for (int i = 0; i < size; i++)
    {
         
        if (i < K) 
            q.push(arr[i]);
        else
        {
            getMaxInQueue(q);
            q.pop();
            q.push(arr[i]);
        }
    }
    getMaxInQueue(q);
    return;
}
int main() {

}