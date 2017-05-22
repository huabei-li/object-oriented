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
	//char language;int n;//题数 
	//char express[15];//表达式
	//double right=0;//正确数的计算 
	//int casenum;//有无括号的随机情况 
	//double answers;//一次程序 最多到达1000题，
	//int inputanswer;//输入的答案
	//char a,b,c,d;//随机整数 
	//char oper1,oper2,oper3;//随机运算符 
	one.scan(one.getLanguage(),one.getN());
	for(i=0;i<one.getN();i++)
	{
		two.random(two.casenum,two.a,two.b,two.c,two.d,two.oper1,two.oper2,two.oper3);
		two.formu(two.casenum,two.a,two.c,two.c,two.d,two.oper1,two.oper2,two.oper3,two.express);
		four.answers=three.CalculateResult(two.express);//储存正确答案 
		if(four.answers==(int)four.answers) //检查是否存在小数 ，结果检验 
		{
			four.judge(one.getLanguage(),four.inputanswer,i,four.answers,four.getRight(),two.express);
		}
		else//如果答案为小数，则重新进行循环 
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
