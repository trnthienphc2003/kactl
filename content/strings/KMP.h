/**
 * Author: Johan Sannemo
 * Date: 2016-12-15
 * License: CC0
 * Description: pi[x] computes the length of the longest prefix of s that ends at x,
 * other than s[0...x] itself (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */
#pragma once

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

vector <vi> compute_automaton(string &s) {
    s += '#';
    int n = s.size();
    vi p = pi(s);
	vector <vi> aut;
    aut.assign(n, vector<int>(26));
    rep(i, 0, n) {
        rep(c, 0, 26) {
            int j = i;
            while (j > 0 && 'a' + c != s[j])
                j = p[j-1];
            if ('a' + c == s[j])
                j++;
            aut[i][c] = j;
        }
    }
	s.pop_back();
	return aut;
}