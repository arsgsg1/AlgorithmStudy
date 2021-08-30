#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    
    string head_a, head_b;
    int i = 0, j = 0, number_a = 0, number_b = 0;
    
    while (!isdigit(a[i])) head_a += a[i++];
    while (!isdigit(b[j])) head_b += b[j++];
    
    if (head_a != head_b) return head_a < head_b;
    
    while (i < a.size() && isdigit(a[i]))
        number_a = number_a * 10 + a[i++] - '0';
    while (j < b.size() && isdigit(b[j]))
        number_b = number_b * 10 + b[j++] - '0';
    
    return number_a < number_b;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}
