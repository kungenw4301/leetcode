class Solution{
public:
    //回文构词法，将一个单词的字母打乱顺序得到另一个单词
    //对于这些anagrams，所使用的字母都是一样的，但是顺序不同
    //将单词内的字母按照字典序排列之后，如果相同就是anagram
    vector<string> anagrams(vector<string> &strs){
        unordered_map<string, vector<string>> group;
        for(const auto &s: strs){
            string key = s;
            sort(key.begin(), key.end());   //将这个单词的字母排序
            group[key].push_back(s);    //用排序序列做key，value用s来组成
        }

        vector<string> result;
        //对于每一个成员，判断key对应的vector中元素多于一个，就是存在回文构词
        for(auto it = group.cbegin(); it != group.cend(); ++it){    //v.cbegin()就是const Iterator
            if(it->second.size()>1){    //unordered_map 成员引用方式 it->first就是key，it->second即值
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        return result;
    }
};
