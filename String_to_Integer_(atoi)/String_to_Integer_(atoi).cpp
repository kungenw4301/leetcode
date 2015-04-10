#include <iostream>
#include <cstring>
using namespace std;
class Solution
{
public:
	String_to_Integer_();
	~String_to_Integer_();

	int atoi(string str){
		int num = 0;
		int sign = 1; //符号位
		const int n = sizeof(str)/sizeof(char);

		int i = 0;
		while(str[i] == ' ' && i < n) i++; //去掉whitespace，此处用 i <= n-1 也行啊

		if(str[i] == '+'){
			i++;	//默认符号位为正`
		}else if(str[i] == '-'){
			sign = -1;
			i++;
		}

		for(; i<n; i++){
			if(str[i] < '0' || str[i] > '9'){
				break;  //如果在ASCII数值上不在digit范围内的无效
			}

            //如果算出num，超过int的范围也是一种思路，但是会导致溢出，需要使用long保存
            //此处每次给num算出一位，这样我们比较INT_MAX 和当前值就好了
			if((num > INT_MAX/10) ||
				 (num == INT_MAX/10 && (str[i] - '0') > INT_MAX % 10) ){
                return  sign == -1 ? INT_MIN : INT_MAX;
			}
            num = num * 10 + (str[i] - '0');
		}
        return num*sign;
	}
};

int main(int argc, char const *argv[])
{
    Solution s();
    string str('+0045');
    int num = s.atoi(str);
    cout << "num : " << num << endl;
    return 0;
}
