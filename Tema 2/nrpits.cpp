#include <bits/stdc++.h>

using namespace std;
ifstream in("nrpits.in");
ofstream out("nrpits.out");

struct MonotonicStack{
    stack<int> stiva;
    int MonotonicPush(int x){
        int nrpits = 0;
        while(!stiva.empty() && stiva.top() < x){
            if(stiva.size() > 1)
                nrpits++;
            stiva.pop();
        }
        stiva.push(x);
        return nrpits;
    }
    void MonotonicPop(){
        stiva.pop();
    }
};

int main()
{
    int n, x;
    in >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        in >> x;
        a.push_back(x);
    }
    MonotonicStack ms;
    int nr = 0;
    for(int i = 0; i < n; i++){
        nr += ms.MonotonicPush(a[i]);
    }

    out << nr;
    return 0;
}
