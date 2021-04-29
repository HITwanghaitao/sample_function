#include "LHS_sample.h"
using namespace std;

vector<double> random_sort(vector<double> array)//随机排序，一维数组
{
	vector<double> r; //用于存储完成排序的容器

	int m = array.size(); //输入数据的长度

	vector<double>::iterator  iter= array.begin(); //容器指针

	//srand(time(NULL)); //随机数种子
	//iter = array.begin();
	int flag;
	int m_change;
	for (int j = 0; j < m; j++)
	{
		iter = array.begin();
		int m_change = array.size();
		//cout << m_change << " ";

		// 类似于抽牌
		//
		flag = floor((double(rand()) / (double(RAND_MAX)+1)) * m_change); //用于生成(0,m_change)内的整数随机数,flag不能等于m_change
		//cout << flag << endl;
		//cout << *(iter + flag) << endl;
		r.push_back(*(iter + flag));
		array.erase(iter + flag);

	}
	//cout << endl;
	return r;
}
vector<vector<double>> random_sort_N_D(vector<vector<double>> d) //随机排序，二维数组，对于列向量内的数据进行排序
{
	int N = d.size();
	int D = d[0].size();
	vector<vector<double>> r(N, vector<double>(D));

	for (int j = 0; j < D; j++)
	{
		vector<double> temp1(N);//待排序数组

		for (int k = 0; k < N; k++)
		{
			temp1[k] = d[k][j];
		}
		vector<double> temp2;//排序完成数组
		temp2 = random_sort(temp1);
		for (int k = 0; k < N; k++)
		{
			r[k][j] = temp2[k];
		}
	}
	/*
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < D; k++)
		{
			cout << r[j][k] << '\t';
		}
		cout << endl;
	}
	 */
	return r;
}

vector<vector<double>> u_lhs(int N, vector<vector<double>> bounds) //内部初始抽样，用于拉丁超立方
{
	if (N == 0)
	{
		throw "Sampling number N can't be zero";
	}
	int D = bounds.size();

	vector<vector<double>> r(N, vector<double>(D));
	for (int j = 0; j < D; j++)
	{
		double left = bounds[j][0];
		double right = bounds[j][1];
		double step = (right - left) / N;
		double change_num;
		for (int k = 0; k < N; k++)
		{
			//double c = 0.5; 抽样点取子区间中间值
			double c = double(rand()) / RAND_MAX; //抽样点取子区间随机值
			change_num = left + (double(k) + c) * step;
			r[k][j] = change_num;
		}
	}
	/*
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < D; k++)
		{
			cout << r[j][k] << '\t';
		}
		cout << endl;
	}
	*/
	return r;
}

vector<vector<double>> lhs(int N, vector<vector<double>> bounds)//拉丁超立方抽样（完整）
{
	vector<vector<double>> r;
	r = u_lhs(N, bounds);
	//cout << "        ********" << endl;
	r = random_sort_N_D(r);
	return r;
}