// NextPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
	void nextPermutation(vector<int> &num){
		int pivot = num.size() - 1;  //�ҵ������һ������
		while (pivot != 0 && num[pivot - 1] >= num[pivot]){
			cout << "pivot->" << pivot << endl;
			--pivot;     //���������ҵ���һ�������Ԫ��
		}

		cout << "17->" << pivot << endl;
		if (pivot == 0)
		{
			//��ʱ��num[0]>num[1]>...,����
			//reverse(num.begin(), num.end());
			this->reverse(0, num.size() - 1, num);
			return;
		}

		//���е��ˣ���num[pivot-1]<num[pivot]
		--pivot; //�õ�����ֵ����

		//���������ҵ�һ������num[pivot]������ǡǡ�ǽϴ�������С��һ��
		int i;
		for (i = num.size() - 1; i > pivot && num[i] <= num[pivot]; --i);
		//do nothing ,�������ˣ�����num[i]>num[pivot]
		swap(num[pivot], num[i]); //����pivot��changeNumber
		this->print_vec(num);

		//���ˣ����� num[pivot]<num[pivot+1],num[i]>num[pivot],
		//����֮��֤num[pivot]֮���Ԫ������
		//6,8,7,4,3,2
		//[6],8,[7],4,3,2
		//7,8,6,4,3,2
		//û�н���֮ǰ���Ѿ��ҵ�pivot��change
		//��������num[pivot+1]->num[change]������num[pivot]����Ϊpivot�ǵ�һ������
		//change���Ǵ��������һ������pivot����
		//ͬʱ��num[change]->num[end]����С��pivot������Ҳ����֤����
		//reverse(num.begin() + pivot + 1, num.end());  //sortҪ����һ��Iterator,ʹ��reverse()Ҳ��
		this->reverse(pivot + 1, num.size() - 1, num);
	}

	void swap(int& a, int& b){
		a = a^b;
		b = a^b;
		a = a^b;
	}

	void reverse(int low, int high, vector<int>& num){
		for (int i = low, j = high; i < j; ++i, --j){
			swap(num[i], num[j]);
		}
	}


	void print_vec(vector<int> &num){

		for (auto it = num.begin(); it != num.end(); ++it){
			cout << *it << ",";
		}
		cout << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> num = { 1, 2 , 3, 4};
	num = { 1, 1 };
	s.nextPermutation(num);
	s.print_vec(num);
	return 0;
}

