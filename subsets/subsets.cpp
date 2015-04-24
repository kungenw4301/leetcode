class Solution{
public:
    vector<vector<int>> subsets(vector<int> &S){
        vector<vector<int>> result; //存储结果
        vector<int> sub;
        sort(S.begin(), S.end());   //要求输出要有序
        const size_t n = S.size();  //求组合的时候需要用到

        for(size_t i = 0; i < 1 << n; ++i){ //1左移n位，得到全部子集数2^n，每个数字对应一个子集
            for(size_t j = 0; j < n; ++j){
                if (i & 1 << j)     //1依次左移1,2,3，...,j位再和i按位与，得到该位此次是否取
                {
                    sub.push_back(S[j]);    //如果在i的位向量中第j位存在，则加入一个子集中
                }
            }
            result.push_back(sub);
            sub.clear();    //如果不清除，则会一直增长，出错
        }

        return result;
    }
};
