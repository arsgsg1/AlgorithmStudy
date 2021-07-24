#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void readStr(const char* p, int length, int* ary) {
  ++p;
  for (int i = 0; i < length; ++i) {
    int buf = 0;
    while ('0' <= *p && *p <= '9') {
      buf  = buf * 10 + (*p - 48);
      ++p;
    }
    ++p;
    ary[i] = buf;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt;
  cin >> cnt;

  while (cnt--) {
    int ary[100001] = { 0, };
    string command, str;
    int length;
    bool isReverse = false;
    
    cin >> command >> length;
    cin >> str;
    readStr(str.c_str(), length, ary);

    bool isError = false;
    int* st = ary;
    int* end = ary + length - 1;
    for (char c : command) {
      if (c == 'D') {
        if (st > end) {
          isError = true;
          break;
        } else {
          if (isReverse == true) {
            --end;
          } else {
            ++st;
          }
        }
      } else if (c == 'R') {
        isReverse = !isReverse;
      }
    }

    if (isError == true) {
      cout << "error";
    } else {
      cout << '[';
      while (st <= end) {
        if (isReverse == true) {
          cout << *end;
          if (st < end) cout << ',';
          --end;
        } else {
          cout << *st;
          if (st < end) cout << ',';
          ++st;
        }
      }
      cout << ']';
    }
    cout << '\n';
  }

  return 0;
}