#include <iostream>
#include <cstring>
#include <stack>
#include <time.h> 
#include <stdlib.h>
#include"calculate.h"
using namespace std;
int main()
{
	int i,j,k;
	interaction one;
	formula two;
	calformula three;
	Judge four;
	//char language;int n;//���� 
	//char express[15];//���ʽ
	//double right=0;//��ȷ���ļ��� 
	//int casenum;//�������ŵ������� 
	//double answers;//һ�γ��� ��ൽ��1000�⣬
	//int inputanswer;//����Ĵ�
	//char a,b,c,d;//������� 
	//char oper1,oper2,oper3;//�������� 
	one.scan(one.getLanguage(),one.getN());
	for(i=0;i<one.getN();i++)
	{
		two.random(two.casenum,two.a,two.b,two.c,two.d,two.oper1,two.oper2,two.oper3);
		two.formu(two.casenum,two.a,two.c,two.c,two.d,two.oper1,two.oper2,two.oper3,two.express);
		four.answers=three.CalculateResult(two.express);//������ȷ�� 
		if(four.answers==(int)four.answers) //����Ƿ����С�� ��������� 
		{
			four.judge(one.getLanguage(),four.inputanswer,i,four.answers,four.getRight(),two.express);
		}
		else//�����ΪС���������½���ѭ�� 
		{
			i=i-1;
			for(j=0;j<=9;j++)
			{
			two.express[j]='\0';
			}
			continue;
		}	
	}	
	one.LanguageAndPrint(one.getLanguage(),4);
	four.CorrectRate(four.getRight(),i);
	return 0;
}
