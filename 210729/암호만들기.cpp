#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define VOWEL          0
#define CONSONANT      1
using namespace std;

int l, c;
int nv, nc;
unordered_map<char, int> ch;
vector<char> arr;
vector<char> ans;

void print_ans() {
    if(nv >= 1 && nc >= 2) {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << '\n';
    }
}

void push_ans(char c) {
    ans.push_back(c);
    if(ch[c] == VOWEL)
        nv++;
    else if(ch[c] == CONSONANT)
        nc++;
}

void pop_ans() {
    char c = ans[ans.size() - 1];
    ans.pop_back();
    if(ch[c] == VOWEL)
        nv--;
    else if(ch[c] == CONSONANT)
        nc--;
} 

void dfs(int idx, int depth) {
    if(arr.size() - idx < l - depth) 
        return;
    else {
        push_ans(arr[idx]);
        if(depth == l - 1) {
            print_ans();
            pop_ans();
            return;
        }

        for(int i = idx + 1; i < arr.size(); i++) 
            dfs(i, depth + 1);
        pop_ans();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 26; i++) {
        char c = char('a' + i);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            ch[c] = VOWEL;
        else ch[c] = CONSONANT;
    }

    cin >> l >> c;
    cin.ignore(0);
    for(int i = 0; i < c; i++) {
        char x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++) {
        nv = 0; nc = 0;
        vector<char>().swap(ans);
        dfs(i, 0);
    }
    return 0;
}