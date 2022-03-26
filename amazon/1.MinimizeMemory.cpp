#include <vector>
#include <iostream>
using namespace std;

#define max(x, y) x > y ? x: y

int mimimizeMemory(vector<int>  proceess, int m) 
{
    int totalMem = 0;
    int n = proceess.size();

    if (n < m) {
        return -1;
    }

    int maxDel = 0;
    int tmpMaxDel = 0;

    for (int i = 0; i < n; i++) { 
        if (i < m) {
            maxDel += proceess[i];
            tmpMaxDel = maxDel;
        } else { 
            tmpMaxDel += proceess[i] - proceess[i-m];
            maxDel = max(maxDel, tmpMaxDel);
        }
        totalMem += proceess[i];
    }

    return  totalMem - maxDel;
}

int main() { 
    
    vector<int> process = {10, 4, 8, 1};
    int m = 2;


    cout<< mimimizeMemory(process, m)<<endl;
    return 0;

}