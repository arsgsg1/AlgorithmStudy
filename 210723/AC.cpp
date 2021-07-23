#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#define NONE    -1
using namespace std;

int t, n;
int front, rear;
string cmd, input;
deque<string> parsed;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    cin.ignore();
    for(int tc = 0; tc < t; tc++) {
        front = NONE;
        rear = NONE;
        parsed.clear();
        getline(cin, cmd);
        cin >> n;
        cin.ignore();
        getline(cin, input);
        input = input.substr(1, input.size() - 2);

        if(input.size() > 0) {
            string tmp;
            for(int i = 0; i < input.length(); i++) {
                if(input[i] != ',') 
                    tmp += input[i];
                else {
                    parsed.push_back(tmp);
                    tmp.clear();
                }
            }
            parsed.push_back(tmp);

            front = 0;
            rear = parsed.size() - 1;
        }   //  if > 0 - end

        bool error = false;
        for(int i = 0; i < cmd.size(); i++) {
            if(cmd[i] == 'R') swap(front, rear);
            else if(cmd[i] == 'D') {
                if(front == NONE && rear == NONE) {
                    error = true;
                    cout << "error" << '\n';
                    break;
                }
                else if(front == rear) 
                    front = rear = NONE;
                else {
                    if(front > rear)
                        front--;
                    else front++;
                }
            }
        }
        if(error) continue;

        cout << "[";
        if(front != NONE || rear != NONE) {
            if(front <= rear) {
                for(int i = front; i <= rear; i++) {
                    cout << parsed[i];
                    if(i != rear) cout << ",";
                }
            }
            else {
                for(int i = front; i >= rear; i--) {
                    cout << parsed[i];
                    if(i != rear) cout << ",";
                }
            }
        }
        cout << "]\n";

    }   //  for tc - end

    return 0;
}