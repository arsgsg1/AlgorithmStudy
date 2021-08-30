/*
1. 선형 탐색 -> 시간초과, 메모리 초과
- 즉시 방 배정을 해야 함.
- 따라서 방을 배정할 때마다 다음 방을 가리키도록 함. -> get_parent
2. 동적 자료구조 vector로 방을 모두 초기화하고 찾는다면 -> 효율성 5, 6, 7 메모리 초과
- 굳이 모든 방을 다 초기화할 필요 없음.
- 배정한 방만 들고 있다가 다음 배정할 방만 리턴해주면 됨.
3. map으로 (배정한 방, 다음번 배정할 방)의 형태로 관리
*/
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> room; //방 번호, 다음 배정 방 번호
ll get_parent(ll x)
{
	if (room.find(x) == room.end())
		return x;
	return room[x] = get_parent(room[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (const auto& num : room_number) {
		ll next = num;
		if (room.find(num) == room.end()) {
			room[num] = next + 1;
			answer.push_back(num);
		}
		else {
			next = get_parent(num);
			room[next] = next + 1;
			answer.push_back(next);
		}
	}
	return answer;
}