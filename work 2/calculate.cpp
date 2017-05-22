#include<iostream>
#include<iomanip>
#include"Cal.h" //用来存关于计算用的函数 
using namespace std;
int main()
{
	float n,area;  
	cin >> n;   //输入半径 
	area=CalCircleArea(n);   //调用计算圆面积的函数 ，返回值为浮点型 
	cout << setiosflags(ios::fixed) << setprecision(2) << area;  //假定需要输出两位小数 
	return 0;
}
