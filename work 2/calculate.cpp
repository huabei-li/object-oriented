#include<iostream>
#include<iomanip>
#include<D:\huabei-li\object-oriented\work 2\Cal.h> //��������ڼ����õĺ��� 
using namespace std;
int main()
{
	float n,area;  
	cin >> n;   //����뾶 
	area=CalCircleArea(n);   //���ü���Բ����ĺ��� ������ֵΪ������ 
	cout << setiosflags(ios::fixed) << setprecision(2) << area;  //�ٶ���Ҫ�����λС�� 
	return 0;
}