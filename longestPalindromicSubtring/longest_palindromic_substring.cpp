class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        int start = 0, maxLen = 1;
        bool dp[1000][1000] = {false};

        for(int i = 0; i < n; ++i)
            dp[i][i] = true;    //(i, i)只有一个字母，回文

        for(int i = 1; i < n; ++i)
            for(int j = 0; j < i; ++j)
                if(s[j] == s[i] && (j + 1 > i - 1 || dp[j + 1][i - 1])){
                    dp[j][i] = true;
                    int len = i - j + 1;
                    if(len > maxLen)
                        maxLen = len, start = j; //每次检查是否能够更新最长串
                }

        return s.substr(start, maxLen);
    }
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(string s){
        int n = s.length();
        if(n == 0) return "^$";
        string ret = "^";
        for(int i = 0; i < n; ++i){
            //ret += "#" + s[i];    //internal error
            ret += "#" + s.substr(i, 1); //char cannot be added onto string
        }

        ret += "#$";
        return ret;
    }

    string longestPalindrome_manacher(string s){
        string T = preProcess(s);
        int n = T.length();
        int *P = new int[n];
        int C = 0, R = 0;
        for(int i = 1; i < n - 1; ++i){
            int i_mirror = 2 * C - i;   // equals to i' = C - (i-C)
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

            // Attempt to expand palindrome centered at i
            while(T[i + P[i] + 1] == T[i - P[i] - 1]) P[i]++;

            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if(i + P[i] > R){
                C = i;
                R = i + P[i];
            }
        }
        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for(int i = 1; i < n - 1; ++i){
            if(P[i] > maxLen){
                maxLen = P[i];
                centerIndex = i;
            }
        }

        delete[] P;
        return s.substr((centerIndex - 1 - maxLen) / 2, maxLen); //s[i] => T[2*i+1]
    }
};
