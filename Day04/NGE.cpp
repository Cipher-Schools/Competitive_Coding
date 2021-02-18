#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(vector<int> arr)
{
    int N = arr.size();
    map<int, int> mymap;
    stack<int> S;
    for (int i = N - 1; i >= 0; i--)
    {
        if (S.empty())
        {
            S.push(arr[i]);
            mymap[arr[i]] = -1;
        }
        else
        {
            if (arr[i] <= S.top())
            {
                mymap[arr[i]] = S.top();
            }
            else
            {
                while (!S.empty() || S.top() < arr[i])
                {
                    S.pop();
                }

                if (S.empty())
                {
                    mymap[arr[i]] = -1;
                }
                else
                {
                    mymap[arr[i]] = S.top();
                }
            }
            S.push(arr[i]);
        }
    }

    for (auto itr = mymap.begin(); itr != mymap.end(); itr++) {
        cout << itr->first << " ---> " << itr->second << endl;
    }
}
int main()
{
}