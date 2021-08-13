#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;
int Q, num;     //  Q : query 개수, num : 상인 마리 수, 
LL ans;         //  ans : 정답
unordered_map<string, int> names;
vector<vector<int> > infos;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    infos.assign(Q, vector<int>());

    for(int i = 0; i < Q; i++) {
        int opt, n;     //  opt : 1 or 2, n : 1일 경우 습득한 정보 개수, 2일 경우 구매할 정보 개수
        string name;    //  상인 이름
        int seller_num; //  상인 번호

        cin >> opt;
        cin >> name;
        cin >> n;

        if(opt == 1) {  //  정보 습득
            if(names.find(name) == names.end())    //  처음 나타나는 이름일 경우
                names[name] = num++;    //  상인 이름, 번호 등록
            
            seller_num = names[name];   //  해당 상인 번호 찾음

            for(int j = 0; j < n; j++) {    //  정보의 개수만큼 정보 입력받아서 저장
                int info;
                cin >> info;
                infos[seller_num].push_back(info);  //  해당 상인의 vector에 저장
            }
            sort(infos[seller_num].begin(), infos[seller_num].end());  //  오름차순으로 정렬
        }
        else if(opt == 2) { //  정보 구매
            if(names.find(name) == names.end()) //  그딴 상인 없을 경우
                continue;

            seller_num = names[name];

            for(int j = 0; j < n; j++) {    //  가치가 큰 n개의 정보를 구매함
                if(!infos[seller_num].empty()) {
                    ans += (infos[seller_num].back());  //  가장 뒤에 있는 것을 더함
                    infos[seller_num].pop_back();   //  가장 뒤에 있는 것을 제거
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}