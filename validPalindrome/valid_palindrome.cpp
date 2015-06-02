class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        //Applies an operation sequentially to the elements of one (1) or two (2) ranges and stores the result in the range that begins at result.
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(start < end){
            while(start < end && !isAlpha(s[start])) start++;
            while(start < end && !isAlpha(s[end])) end--;
            if(s[start] != s[end])  break;  //如果不等，则不是回文
            start++;
            end--;
        }
            if(start >= end) return true;
            else return false;
    }

    //alphanumeric
    bool isAlpha(char c){
        if(c >= 'a' && c <= 'z') return true;
        if(c >= '0' && c <= '9') return true;
        return false;
    }
};
