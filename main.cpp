#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "LHS_sample.h"
#include <ctime>

using namespace std;

int main()
{
	//测试	
	
	srand(1000);
	clock_t startTime, endTime;
	startTime = clock();//计时开始
	//cout << RAND_MAX << endl;
	int N = 50;
	for (int j = 1; j < N; j++)
	{
		vector<vector<double>> r;
		vector<vector<double>> bounds = { {0.2,0.6},{1.5, 2.5},{30,50},{20,50},{1.0,1.3} }; //抽样区间
		r = lhs(j, bounds);
		cout << "over:" << j << endl;
	}
	endTime = clock();//计时结束
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	
}