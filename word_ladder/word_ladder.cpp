#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class word_ladder
{
public:
    word_ladder();
    ~word_ladder();
    int ladderLength(string start, string end, unordered_set<string> &dict){
        if (start.compare(end) == 0 || start.empty() || end.empty())
        {
            return 0;
        }
        queue<string> words;
        queue<int> distance;

        words.push(start);
        distance.push(1);
        int ret = 0;
        while(!words.empty()){
            string str = words.front();
            words.pop();
            ret = distance.front();
            distance.pop(); //queue.pop() 返回值为void
            for(int i = 0; i<str.size(); ++i){
                for(char c='a'; c<='z'; c++){
                    str[i] = c;
                    string newWord(str);
                    //unordered_set<string>::const_iterator got = dict.find(str);

                    if(dict.find(str) != dict.end()){      //找到这个单词
                        if (newWord.compare(end) != 0)
                        {
                            return ret + 1;
                        }
                        words.push(newWord);
                        distance.push(ret+1); //为什么不直接累计这个计数器呢？因为可能有多种路径
                        dict.erase(newWord); //要最短的
                    }
                }
            }

        }

        return 0; //没有可达路径，其实就是一个
    }

    void print_vec(vctor<string> vec){
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << ",";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    string start("hot");
    string end("dog");
    vector<string> dict;
    dict.add("hot");
    dict.add("dot");
    dict.add("dog");

    word_ladder w;
    int len = w.ladderLength(start, end, dict);
    return 0;
}
