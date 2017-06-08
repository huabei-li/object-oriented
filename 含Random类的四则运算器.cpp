#include <iostream>
#include <cstring>
#include <stack>
#include <time.h> 
#include <stdlib.h>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
template <class T>
void StackClear(stack<T> &s)			//���ջ
{
	while(!s.empty())
		s.pop();
}
/*
�ж϶�ȡ�����ַ��Ƿ��������
*/
int IsOperator(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '=':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}
/*
�Ƚ�ǰ����������������ȼ�
(Ϊ���жϷ��㣬����һ���Ⱥš�=����Ϊ���ʽ�Ķ����)
oper1>=oper2����1
oper1<oper2����-1
oper1��oper2�ֱ�Ϊ�������ŷ���0
*/
int Priority(char oper1,char oper2)
{
	int pri;
	switch(oper2)
	{
		case '+':
		case '-':
			if(oper1=='(' || oper1=='=')
				pri=-1;
			else
				pri=1;
			break;
		case '*':
		case '/':
			if(oper1=='*' || oper1=='/' || oper1==')')
				pri=1;
			else
				pri=-1;
			break;
		case '('://���ȼ�С 
				pri=-1;
			break;

		case ')':
			if(oper1=='(')
				pri=0;		 //�����������
			else
				pri=1;
			break;
		case '=':
			if(oper1=='=')
				pri=0;		//�Ⱥ���ԣ�����0
			else
				pri=1;
			break;
	}
	return pri;
}
/*
�����������������������������
*/
double calculate(double a,int oper,double b)
{
	switch(oper)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/':
			if (b!=0)
				return a/b;
			else
				return 0.1;//��0��������س�С����Ȼ����ɸѡ��Ŀʱɾ�� 

	}
}
/*
������ʽ��ֵ��
��ʼ������ջ��һ��������ջ��һ�������ջ��
�������ұ���ÿһ���ַ���������������ѭ�����ԭ�����£�
��1������������ֱ��ѹ������ջ����
��2�������������+-* /��ʱ����������ջΪ�գ���ֱ�ӷŵ�������ջ�������򣬼���3����
��3����������ջ��Ԫ�ص����ȼ��ȵ�ǰ����������ȼ�С����ֱ��ѹ��ջ��������ִ�в��裨4����
��4����������ջ�����������ֲ�����������ջ����������������㣬��������ѹ������ջ�����ظ���2���ͣ�3��
	 ֱ����ǰ�������ѹ�������ջ����
��5�����������š�����ʱ��ֱ��ѹ�������ջ����
��6�����������š�����ʱ�����ε���������ջ�����������������ջ������������֣�ֱ�������Ĳ�����Ϊ�����š�
*/
double CalculateResult(char express[])
{
	double a,b;				//����������
	char opera;				//�����
	char c;					//�ַ�����
	char x;					//x������ȡ�����ջջ���������
	stack<char> oper;
	stack<double> data;	//�����ջջ�����������������ջ
	int j=0;
	int i=0;
	oper.push('=');			//�Ƚ������(=)���������ջ
	c = express[i++];
	double num=0;
	while(c!='=' || x!='=')			//ѭ��������ʽ�е�ÿ���ַ�
	{
		if(IsOperator(c))	//���������
		{
			num = 0; 				//��ջ֮�����ĳһ�����������ݴ�ֵ
			switch(Priority(x,c))
			{
				case -1:	//��ǰ�����c����ǰһ�����x
					//cout << "o----" << c << endl;
					oper.push(c);		//��ǰ�������ջ
					c=express[i++];		//ȡ���ʽ��һ�ַ�
					break;
				case 0:					//���ţ��Ⱥţ����
					oper.pop();		//�������벿�ֳ�ջ��������
					c=express[i++];		//ȡ���ʽ��һ�ַ�
					break;
				case 1:						//��ǰ�����cС�ڵ���ǰһ�����x
					opera = oper.top();		//��ջ֮ǰȡ��ջ��Ԫ��
					oper.pop();				//�������ջ
					b = data.top();
					data.pop();
					a = data.top();
					data.pop();				//������������ջ
					double t = calculate(a,opera,b);	//������
					if(t!=(int)t) 		//�����0�ٳ������� 
					return 0.1;
					else 
					data.push(t);		//����������ջ
					break;
			}
		}
		else if(c>='0' && c<='9')	//��������������ַ� ��ջ
		{
			num=c-'0';
			data.push(num);
			c=express[i++];
		}
		x = oper.top();		//��ȡ�����ջ����Ԫ��
	}
		num = data.top();	
		StackClear(oper);
		StackClear(data);		//�������ջ
		return 	num;	//��������ջջ��Ԫ�أ���Ϊ������
}

void LanguageAndPrint(char c,int a)//����ѡ�� 
{
	string s;
	int sb;
	ifstream inf;	//��ȡ�ļ� 
	if(c=='C')
		inf.open("c://Users//Administrator//Desktop//CAL//Chinese.txt");//������Դ·�� 
	if(c=='E')
		inf.open("c://Users//Administrator//Desktop//CAL//English.txt");
	if(c=='J')
		inf.open("c://Users//Administrator//Desktop//CAL//Japanese.txt");
	if(c=='F')
		inf.open("c://Users//Administrator//Desktop//CAL//French.txt");
	if(c=='G')
		inf.open("c://Users//Administrator//Desktop//CAL//German.txt");
	switch(a)//�ж���������ı��� 
	{
		case 1:	getline(inf,s,'\n'); 
			   	cout <<s<<endl;
				getline(inf,s,'\n');
				cout <<s<<endl; 
				getline(inf,s,'\n'); 
				cout <<s;
				break;
		case 2:	for(sb=0;sb<4;sb++)
				getline(inf,s,'\n'); 
			   	cout <<s;
				break;
		case 3:	for(sb=0;sb<5;sb++)
				getline(inf,s,'\n'); 
			   	cout <<s<<endl;
				break;
		case 4:	for(sb=0;sb<6;sb++)
				getline(inf,s,'\n'); 
			   	cout <<s;
				break;
	}
	inf.close();//�ر��ļ�	
}
void scan(char language,int n)//����
{
	cout<<"��ѡ��������:"<<endl;
	cout<<"C.����	E.English	J.Japanes	F.Franch	G.German" <<endl;
	cin >> language;
	LanguageAndPrint(language,1);
	cin >> n;
}
class Random
{
	public:
		Random() { }
		void random() { }
		~Random() { }
};
class RandomNumber: public Random
{
	int num;
	public:
		RandomNumber() {		}
		int random()
		{
			srand((unsigned)time(NULL));
			num=rand()%10+48;
			return num;
		}
		~RandomNumber() {		}
};
class RandomOperator: public Random
{
	char oper;
	public:
		Randomoperation() {	}
		char random()
		{
			srand((unsigned)time(NULL));
			switch(rand()%4)
			{
				case 0:oper= '+';
				case 1:oper= '-';
				case 2:oper= '*';
				default:oper= '/';
			}
			return oper;
		}
		~Randomoperation() {	}
};
/*char change(int x)//�����ת�������� 
{
	switch(x)
	{
		case 0:return '+';
		case 1:return '-';
		case 2:return '*';
		default:return '/';
	}
}
char RandomNumber()
{
	srand((unsigned)time(NULL));//��������ͬ�������
	return rand()%10+48;
}
char RandomOperation()
{
	srand((unsigned)time(NULL));//��������ͬ�������
	return change(rand()%4);
}
void random(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3)
{
	srand((unsigned)time(NULL));//��������ͬ�������
	a=RandomNumber();
	b=RandomNumber();
	c=RandomNumber();
	d=RandomNumber();
	oper1=RandomOperation();
	oper2=RandomOperation();
	oper3=RandomOperation();
	casenum=rand()%6;//�������
}*/
void formula(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3,char express[])//������ʽ���� 
{
	switch(casenum)
		{
			case 0://��������� 
			express[0]=a;
			express[1]=oper1;
			express[2]=b;
			express[3]=oper2;
			express[4]=c;
			express[5]=oper3;
			express[6]=d;
			express[7]='=';break;
			case 1://(a o1 b)o2 c o3 g = ?
			express[0]='(';
			express[1]=a;
			express[2]=oper1;
			express[3]=b;
			express[4]=')';
			express[5]=oper2;
			express[6]=c;
			express[7]=oper3;
			express[8]=d;
			express[9]='=';	break;
			case 2://(a o1 b o2 c) o3 d = ?
			express[0]='(';
			express[1]=a;
			express[2]=oper1;
			express[3]=b;
			express[4]=oper2;
			express[5]=c;
			express[6]=')';
			express[7]=oper3;
			express[8]=d;
			express[9]='=';	
			break;
			case 3://a o1 ( b o2 c) o3 d = ?
			express[0]=a;
			express[1]=oper1;
			express[2]='(';
			express[3]=b;
			express[4]=oper2;
			express[5]=c;
			express[6]=')';
			express[7]=oper3;
			express[8]=d;
			express[9]='=';
			break;
			case 4://a o1 (b o2 c o3 d) = ?
			express[0]=a;
			express[1]=oper1;
			express[2]='(';
			express[3]=b;
			express[4]=oper2;
			express[5]=c;
			express[6]=oper3;
			express[7]=d;
			express[8]=')';
			express[9]='=';
			break;
			default://a o1 b o2 (c o3 d) =?
			express[0]=a;
			express[1]=oper1;
			express[2]=b;
			express[3]=oper2;
			express[4]='(';
			express[5]=c;
			express[6]=oper3;
			express[7]=d;
			express[8]=')';
			express[9]=	'=';
		}
}


void CorrectRate(int right,int i)
{
	cout << right/i <<endl;
}
void judge(char language,int inputanswer,int i,int answers,int right,char express[])
{
	cout << i+1 <<".  "<<express ;
	cin >> inputanswer;
	if(inputanswer==answers) 
	{
		right++;//��ȷ��++
		LanguageAndPrint(language,3);	
	} 
	else 
	{
		LanguageAndPrint(language,2);
		cout << answers<<endl; 
	}
	for(int j=0;j<=9;j++)//�����ʽ���±�Ϊ�� 
	{
		express[j]='\0';
	}
}
int main()
{
	int i,j,k;
	char language;int n;//���� 
	char express[15];//���ʽ
	double right=0;//��ȷ���ļ��� 
	int casenum;//�������ŵ������� 
	double answers;//һ�γ��� ��ൽ��1000�⣬
	int inputanswer;//����Ĵ�
	char a,b,c,d;//������� 
	char oper1,oper2,oper3;//�������� 
	RandomNumber a1;
	RandomOperator op1;
	a=a1.RandomNumber::random();
	b=a1.RandomNumber::random();
	c=a1.RandomNumber::random();
	d=a1.RandomNumber::random();
	oper2=op1.RandomOperator::random();
	oper3=op1.RandomOperator::random();
	scan(language,n);
	for(i=0;i<n;i++)
	{
		void random(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3);
		void formula(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3,char express);
		answers=CalculateResult(express);//������ȷ�� 
		if(answers==(int)answers) //����Ƿ����С�� ��������� 
		{
			judge(language,inputanswer,i,answers,right,express);
		}
		else//�����ΪС���������½���ѭ�� 
		{
			i=i-1;
			for(j=0;j<=9;j++)
			{
			express[j]='\0';
			}
			continue;
		}	
	}	
	LanguageAndPrint(language,4);
	CorrectRate(right,i);
	return 0;
}
