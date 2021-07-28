#include<iostream>

using namespace std;

char stars[][6] = { "  *  ", " * * ", "*****" };
char board[3500][7000];
 
void func(int n, int y, int x)
{
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                board[y + i][x + j] = stars[i][j];
        return;
    }
    func(n / 2, y, x + 3 * n / 2);
    func(n / 2, y + 3 * n / 2, x);
    func(n / 2, y + 3 * n / 2, x + 3 * n);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    func(n / 3, 0, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2 * n - 1; ++j) {
        cout << (board[i][j] == '*' ? '*' : ' ');
      }
      cout << '\n';
    }
}