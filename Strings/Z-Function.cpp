//Source: https://cp-algorithms.com/string/z-function.html

//basically z[i] = k, means first k characters of string concide with k characters starting from s[i];

/*
Example :-
"abacaba" - [0, 0, 1, 0, 3, 0, 1]
here z[4] = 3; //0 based indexing
means first 3 characters from s[4] = first 3 character from s[0];
*/

vector<int> z_function(string &s)
{
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

/*
Example
Problem :  https://codeforces.com/contest/432/problem/D
solution : https://codeforces.com/contest/432/submission/75147854
*/
