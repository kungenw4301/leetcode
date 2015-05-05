class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string > result;
        string ip;
        DFS(s, 0, 0, ip, result);
        return result;
    }

    /**
     * 深度优先搜索
     * @param s      [description]
     * @param start  本次开始的位置，指向字符串的指针
     * @param step   已经切割的ip地址段数，0,1,2,3,4
     * @param result 保存合法解
     */
    void DFS(string s, size_t start, size_t step, string ip,  vector<string > &result){
        if(start == s.size() && step == 4){ //递归出口，刚好切割到末尾，一个合法解
            ip.resize(ip.size() - 1);   //因为最后的循环会在末尾多加一个'.'
            result.push_back(ip);
            return;
        }


        //剪枝工作，加快效率，不剪枝的话就会超时
        //
        if(s.size() - start > (4 - step) * 3) return;   //每步划分过小，剩余太多，剪
        if(s.size() - start < 4 - step) return; //例如step == 2, 最后还剩不到两个,剪
        if(step >= 4) return;   //剪枝效果显著

        int num = 0;
        for(size_t i = start; i < start + 3; ++i ){
            num = num * 10 + (s[i] - '0');    //上一次的值拼上当前char的值

            if(num <= 255){
                ip += s[i]; //拼出来的值合法，拼上去
                DFS(s, i + 1, step + 1, ip + '.', result);
            }

            if(num == 0) break; //如果遇到0了，赶紧跳出，否则就会出现01.01这种0前缀，不合法
        }
    }
};
