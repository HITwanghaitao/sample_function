#pragma once
#pragma warning(disable:4996)
#include<vector>
#include<cmath>
#include<iostream>
#include <algorithm>
#include<vector>
#include<random>
#include<fstream>
# include <cstdlib>
# include <iomanip>
# include <ctime>
# include <cstring>
#include <iomanip>       //C++������ȿ�����Ҫ
#include <string>

using namespace std;

double gaussrand();//��׼��̬�ֲ�
double gaussrand_u_sigma(double u, double sigma);//�����ض�u,sigma��̬�ֲ�
vector<vector<double>> norm_sample(int N, vector<vector<double>> bounds);//��̬�ֲ�������ÿ�в�������һ���ֲ�