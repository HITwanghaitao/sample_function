#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

vector<double> random_sort(vector<double> array)//�������
{
	vector<double> r; //���ڴ洢������������

	int m = array.size(); //�������ݵĳ���
	
	vector<double>::iterator  iter; //����ָ��

	srand(time(NULL)); //���������
	for (int j = 0; j < m; j++)
	{
		iter = array.begin();
		int m_change = array.size();
		
		//for (int k = 0; k < m_change; k++)
		//{
		//	cout << array[k] << " ";
		//}
		//cout << endl;
		// �����ڳ���
		int flag = floor((double(rand()) / RAND_MAX) * m_change); //��������[0,m_change]�ڵ����������
		//cout << *(iter + flag) << endl;
		r.push_back(*(iter + flag));
		array.erase(iter + flag);
	}
	return r;
}
int main()
{
	//����
	vector<double> d = { 1,2,3,4,5,6,7,8,9,10 };
	vector<double> r;
	r = random_sort(d);
	for (int j = 0; j < r.size(); j++)
	{
		cout << r[j] << " ";
	}
	cout << endl;
}