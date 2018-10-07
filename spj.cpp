#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void check_valid(const string &s) {
	//cout << s.size() << endl;
    if (s.size() <= 0 || s.size() > 100) quitf(_wa, "invalid length");
    for (int i = 0; i < s.size(); ++i)
        if ( !(s[i]>='a'&&s[i]<='z')) quitf(_wa, "invalid characters");
}

int get_unstablity(vector<string> s) {
	int n = (int) s.size();
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < (int)s[i].length(); j++) {
			ret += (s[i][j] != s[i][j - 1]);
		}
	}
	return ret;
}

int get_similarity(vector<string> s) {
	int n = (int) s.size();
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (char x: s[i]) {
				for (char y: s[j]) {
					if (x == y) {
						ret ++;
					}
				}
			}
		}
	}
	return ret;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(1, 100);
    vector <string> s = ouf.readLines(n,0);
    for (int i = 0; i < n; i++) {
    	check_valid(s[i]);
    }
    ouf.seekEof();
    int value1 = get_unstablity(s);
    int value2 = get_similarity(s);
    if (value1 != value2) {
    	quitf(_wa, "unstablity is not equal to similarity");
    }
    quitf(_ok, "Accepted");

	return 0;
}
