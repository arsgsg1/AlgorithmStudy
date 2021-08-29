#include <string>
#include <vector>

using namespace std;
const int MAX=27;

int getIndex(char c){
    if(c>='a'&&c<='z')return c-'a';
    return 26;
}
struct Trie{
    Trie* next[MAX];
    bool finish;
    int cnt;
    Trie(){fill(next,next+MAX,nullptr);finish=false;}
    ~Trie(){for(int i=0; i<MAX; i++)if(next[i])delete next[i];}
    
    void insert(const string& str){
        Trie *temp = this;
        for(int i=0; i<str.size(); i++){
            int idx=getIndex(str[i]);
            if(!temp->next[idx])temp->next[idx]=new Trie();
            temp=temp->next[idx];
        }
        temp->finish=true;
    }
    void find(const string& str, int n){
        if(str.size()==n){
            cnt++;
            return;
        }
        int idx=getIndex(str[n]);
        if(this->next[idx]) this->next[idx]->find(str,n+1);
        if(this->next[26]) this->next[26]->find(str,n+1);
    }
    int getCnt(const string& str){
        Trie *temp = this;
        for(int i=0; i<str.size(); i++){
            int idx=getIndex(str[i]);
            temp=temp->next[idx];
        }
        return temp->cnt;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie *root=new Trie();
    for(auto s : queries)root->insert(s);
    for(auto s : words)root->find(s,0);
    for(auto s : queries)answer.push_back(root->getCnt(s));
    delete root;
    return answer;
}
