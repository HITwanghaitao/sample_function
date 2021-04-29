#include "LHS_sample.h"
using namespace std;

vector<double> random_sort(vector<double> array)//�������һά����
{
	vector<double> r; //���ڴ洢������������

	int m = array.size(); //�������ݵĳ���

	vector<double>::iterator  iter= array.begin(); //����ָ��

	//srand(time(NULL)); //���������
	//iter = array.begin();
	int flag;
	int m_change;
	for (int j = 0; j < m; j++)
	{
		iter = array.begin();
		int m_change = array.size();
		//cout << m_change << " ";

		// �����ڳ���
		//
		flag = floor((double(rand()) / (double(RAND_MAX)+1)) * m_change); //��������(0,m_change)�ڵ����������,flag���ܵ���m_change
		//cout << flag << endl;
		//cout << *(iter + flag) << endl;
		r.push_back(*(iter + flag));
		array.erase(iter + flag);

	}
	//cout << endl;
	return r;
}
vector<vector<double>> random_sort_N_D(vector<vector<double>> d) //������򣬶�ά���飬�����������ڵ����ݽ�������
{
	int N = d.size();
	int D = d[0].size();
	vector<vector<double>> r(N, vector<double>(D));

	for (int j = 0; j < D; j++)
	{
		vector<double> temp1(N);//����������

		for (int k = 0; k < N; k++)
		{
			temp1[k] = d[k][j];
		}
		vector<double> temp2;//�����������
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

vector<vector<double>> u_lhs(int N, vector<vector<double>> bounds) //�ڲ���ʼ��������������������
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
			//double c = 0.5; ������ȡ�������м�ֵ
			double c = double(rand()) / RAND_MAX; //������ȡ���������ֵ
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

vector<vector<double>> lhs(int N, vector<vector<double>> bounds)//����������������������
{
	vector<vector<double>> r;
	r = u_lhs(N, bounds);
	//cout << "        ********" << endl;
	r = random_sort_N_D(r);
	return r;
}