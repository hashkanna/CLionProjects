#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    string s;
    cin >> s;
    vector<int> res;
    res=prefix_function(s);
    for (auto i = res.begin(); i != res.end(); ++i)
        cout << *i << ' ';
    return 0;
}
