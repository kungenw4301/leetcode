class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;   //当做栈来使用
        assert(path[0] == '/'); //默认是从根目录开始

        int i = 0;
        while(i < path.size()){
            while(path[i] == '/' && i < path.size()) ++i;   //跳过 '////',直到不是'/'
            if(i == path.size()) break; //不能return，如果stack不为空就还要组装路径

            int start = i;  //本dir的第一个非'/'字符
            while(path[i] != '/' && i < path.size()) ++i; //找到dir的边界
            int end = i - 1;
            string element = path.substr(start, end - start + 1); //从start到end一共end-start+1个字符

            if(element == ".."){
                if(stack.size() > 0)
                    stack.pop_back();   //如果中间有/../则跳到上一层目录，故出栈
            }else if(element != "."){
                stack.push_back(element);  //如果这个元素师'.'表示当前路径，不作处理，非点号，压入下一层
            }
        }

        if(stack.size() == 0) return "/";   //例如////.//home/.././///
        string simPath;
        for(int i = 0; i < stack.size(); ++i)
            simPath += '/' + stack[i];  //例如: '/' + home + '/' + wang;

        return simPath;
    }
};
