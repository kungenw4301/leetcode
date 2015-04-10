#include <iostream>
using namespace std;
class GenerateParentheses
{
public:
	GenerateParentheses();
	~GenerateParentheses();

	vector<string> generateParenthesis(int n){
		if (n==0)
		{
			return vector<string>(1, "");  //返回一个匿名对象，此种构造方式是将字符串复制n次成为一个vector
		}
		if (n==1)
		{
			return vector<string>(1, "()");
		}

		vector<string> result;

		/*
		*这里非常巧妙,n对合法的括号，可以拆分成若干单元
		* i 对 + n-i-i 对 + "()"
		* 但是开头一定是左括号,故 ( inner ) outer
		*可能觉得有漏洞，因为有 ((()))这种组合,
		* 但能拆成 (inner) + "" ，inner = "(())"
		* 又比如 (()()) = (inner) + "", inner = ()()
		* 故总是能拆成合理的inner+ outer组合
		*/


		for (int i = 0; i < n; ++i)
		{
			for (auto inner: generateParenthesis(i))
			{
				for(auto outer: generateParenthesis(n-1-i)){
					//事实上还可以写成 outer + ( + inner + )，只是位置换了，分解方式不变
					result.push_back("(" + inner + ")" + outer);
				}
			}
		}
		return result;
	}

};
