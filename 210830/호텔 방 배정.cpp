/*
1. ���� Ž�� -> �ð��ʰ�, �޸� �ʰ�
- ��� �� ������ �ؾ� ��.
- ���� ���� ������ ������ ���� ���� ����Ű���� ��. -> get_parent
2. ���� �ڷᱸ�� vector�� ���� ��� �ʱ�ȭ�ϰ� ã�´ٸ� -> ȿ���� 5, 6, 7 �޸� �ʰ�
- ���� ��� ���� �� �ʱ�ȭ�� �ʿ� ����.
- ������ �游 ��� �ִٰ� ���� ������ �游 �������ָ� ��.
3. map���� (������ ��, ������ ������ ��)�� ���·� ����
*/
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> room; //�� ��ȣ, ���� ���� �� ��ȣ
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