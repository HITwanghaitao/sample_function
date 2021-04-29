#pragma once
#include<vector>
#include <iostream>
using namespace std;

vector<double> random_sort(vector<double> array);//随机排序，一维数组
vector<vector<double>> random_sort_N_D(vector<vector<double>> d); //随机排序，二维数组，对于列向量内的数据进行排序

vector<vector<double>> u_lhs(int N, vector<vector<double>> bounds); //内部初始抽样，用于拉丁超立方
vector<vector<double>> lhs(int N, vector<vector<double>> bounds); //拉丁超立方抽样（完整）

