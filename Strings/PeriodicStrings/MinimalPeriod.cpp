#include <iostream>
#include <vector>
using namespace std;

#define MaxL 1000

//https://official.contest.yandex.com/helloindia2018/contest/7845/problems/I/

string str;

bool isRepeat (int l)
{
    int round = str.length () / l;

    if ( round * l != str.length () ) return false;

    string sub = str.substr (0, l);
    int start = 0;

    while ( round-- ) {
        if ( sub != str.substr (start, l) ) return false;
        start += l;
    }

    return true;
}

int main ()
{ while(cin >> str) {
        bool blank = false;
//    cin >> str;
        int len = str.length() / 2;
        int res;

        if (blank) printf("\n");
        blank = true;
        bool printed = false;
        for (int i = 0; i < len; i++) {
            if (isRepeat(i + 1)) {
                res = i + 1;
                printed = true;
                break;
            }
        }

        if (!printed) {
            res = str.length();


            string new_string = str.substr(0, res);

            int new_res = res;
            for (int i = 1; i < new_string.length(); i++) {
                if (new_string.substr(i, res - i) == new_string.substr(0, res - i)) {
                    new_res = i;
                    break;
                }
            }
            string res_string = new_string.substr(0, new_res);
            cout << res_string << endl;
//            cout << res << endl;
        } else {
            cout << str.substr(0,res) << endl;
        }

//        return 0;
    }
}