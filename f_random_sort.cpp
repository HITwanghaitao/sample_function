#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

vector<double> random_sort(vector<double> array)//随机排序
{
	vector<double> r; //用于存储完成排序的容器

	int m = array.size(); //输入数据的长度
	
	vector<double>::iterator  iter; //容器指针

	srand(time(NULL)); //随机数种子
	for (int j = 0; j < m; j++)
	{
		iter = array.begin();
		int m_change = array.size();
		
		//for (int k = 0; k < m_change; k++)
		//{
		//	cout << array[k] << " ";
		//}
		//cout << endl;
		// 类似于抽牌
		int flag = floor((double(rand()) / RAND_MAX) * m_change); //用于生成[0,m_change]内的整数随机数
		//cout << *(iter + flag) << endl;
		r.push_back(*(iter + flag));
		array.erase(iter + flag);
	}
	return r;
}
int main()
{
	//测试
	vector<double> d = { 1,2,3,4,5,6,7,8,9,10 };
	vector<double> r;
	r = random_sort(d);
	for (int j = 0; j < r.size(); j++)
	{
		cout << r[j] << " ";
	}
	cout << endl;
}
