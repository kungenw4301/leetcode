class Solution{
public:
    vector<vector<string>> findLadders(string start, string end, vector<string> &dict){
        //相当于一个数组，其中的每个元素都是一个邻接表
        unordered_map<string, unordered_set<string>> adjList;
        //看不懂了，如果找到end，插入，找到start，删除，原因呢？
        //这里的奇妙之处在于一开始就将start取出来，然后作为root层从dict中删除
        //而后将end插入dict中，因为不一定包含这个end，但是可以transfer到end
        //需要注意的是vector中是没有find方法的
        if(find(dict.begin(), dict.end(), end) != dict.end()) dict.insert(end);
        if(find(dict.begin(), dict.end(), start) != dict.end()) dict.erase(start);

        unordered_set<string> twoLevels[2]; //当前层和下一层
        twoLevels[0].insert(start);     //起始条件初始化
        int level = 0;  //当前层初始时设置为0

        while(true){
            unordered_set<string> &lastLevel = twoLevels[level % 2];
            unordered_set<string> &nextLevel = twoLevels[(level + 1)%2]; //下一层
            nextLevel.clear(); //每次迭代清除下一层的空间

            for(auto it = lastLevel.begin(); it != lastLevel.end(); ++it){
                unordered_set<string> adj; //每个元素的邻接表，表示一步可得的单词
                getDiff1s(*it, adj, dict); //这个*it解引用从迭代器得到当前word
                adjList[*it] = adj;         //将*it这个字符串上挂上邻接表

                //void insert(InputIterator first, InputIterator last);
                //插入 [first, last) 区间内的element，左闭右开区间
                //下一层单词
                nextLevel.insert(adj.begin(), adj.end());
            }

            if(nextLevel.size() == 0) return vector<vector<string>>(); //没有结果，返回空向量

            //遍历完一层之后再从dict中出去，而不是找到一个就除去
            for(auto it = nextLevel.begin(); it != nextLevel.end(); ++it){
                dict.erase(*it);    //在dict中把整个一层相关的键值对都抹掉
            }

            ++level;        //这一层遍历完了

            if(nextLevel.find(end) != nextLevel.end()) break;   //下一层就找到start到尾的路径了
        }

        vector<vector<string>> result;

        //std::vector<int> second (4,100);                       // four ints with value 100
        vector<string> path(1, start);  //表示vector初始大小为1

        //现在adjList包含所有的最短路径，但是不是每个路径都是有效的
        genResult(0, level, end, path, adjList, result);

        return move(result); //牵涉到C++移动语义，右值引用之类的特性
    }


    //用于产生只改变一个字符所能得到的单词，使用邻接表表示
    void getDiff1s(string s, unordered_set<string> &adjList, const unordered_set<string> &dict){
        for(int i = 0; i<s.length(); i++){
            string strBack(s);
            for (char c = 'a';c<='z';c++)
            {
                strBack[i] = c;
                auto it = dict.find(strBack);

                //判断条件是：strBack存在于dict中，且当前词不同于原词s，且当前词不存在邻接表中
                if (it != dict.end() && *it != s && adjList.find(*it) == adjList.end())
                {
                    adjList.insert(strBack); //加入邻接表
                }
            }
        }
    }


    //产生结果
    void genResult(int level, int targetLen, string end, vector<string> &path, unordered_map<string, unordered_set<string>> &adjList, vector<string> &result){
        string curStr = path[path.size()-1];
        if(level == targetLen){
            if (curStr == end)
            {
                result.push_back(path); //找到一条路径
            }
            return; //递归出口
        }

        for(auto it = adjList[curStr].begin(); it != adjList[curStr].end(); it++){
            path.push_back(*it);
            genResult(level+1, targetLen, end, path, adjList, result);
            path.pop_back(); //为什么要pop_back()? 不理解
        }
    }
};
