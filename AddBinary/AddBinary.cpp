#include <iostream>
using namespace std;
class AddBinary
{
public:
	AddBinary();
	~AddBinary();
	string addBinary(string a, string b){
		string result;
		const size_t n = a.size()>b.size() ? a.size():b.size();
		reverse(a.begin(), a.end());    //倒转过来加更符合习惯，否则就要for从后往前
		reverse(b.begin(), b.end());
		int carry = 0; //进位保存在这里，满2进1
		for (size_t i = 0; i < n; ++i)  //size_t是unsigned int 的一个alias
		{
			//如果当前string没有遍历到最后，则提取一个
			//a[i]-'0' 利用ASCii码相减得到相应的数值，非常巧妙；
			//如果超出了较短的string，则返回int 0；
			const int ai = i<a.size() ? a[i]-'0' : 0;
			const int bi = i<b.size() ? b[i]-'0' : 0;
			const int val = (ai + bi + carry)%2; //直接取余数得到，无非结果是0,1,2=2/2+2%2
			carry = (ai+bi+carry)/2; //取商得到进位
			result.insert(result.begin(), val+'0'); //insert在begin之前，就是在头插入，再次利用ascii码转换整数到字符串；
		}

		if (carry == 1)
		{
			result.insert(result.begin(), '1'); //最后加了多出一位，再次插入
		}

		return result;
	}
};
