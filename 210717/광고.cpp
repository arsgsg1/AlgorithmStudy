#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> fail;

void makeFailFunc(vector<int>& fail, int len, const string pat) {
    for(int j = 1; j < len; j++) {
        int i = fail[j - 1];
        while((pat[j] != pat[i + 1]) && (i >= 0))
            i = fail[i];
        if(pat[j] == pat[i + 1])
            fail[j] = i + 1;
        else fail[j] = -1;
    }
}

int main(void) {
    int l;
    string str;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l;
    cin.ignore();

    getline(cin, str);
    fail.assign(l, -1);

    makeFailFunc(fail, l, str);
    cout << l - 1 - fail[l - 1] << '\n';
    return 0;
}