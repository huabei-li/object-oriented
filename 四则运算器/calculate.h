class interaction
{
	public:
		interaction();
		void scan(char language,int n);//��ʼ���潻��
		void LanguageAndPrint(char language,int a);//����ѡ�� ����� 
		char getLanguage();
		int getN();
	private:
		char language;//���� 
		int n,a;	//���� 
};
class formula
{
	public:
		formula();
		char change(int x);//�����ת�������� 
		char RandomNumber();//��������� 
		char RandomOperation() ;//����������� 
		void random(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3);//��ĿԪ������
		void formu(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3,char express[]);//������ʽ
		char a,b,c,d,oper1,oper2,oper3,express[];
		int casenum;
};
class calformula
{
	public:
		calformula();
		int IsOperator(char c);//�Ƚ�ǰ����������������ȼ�
		int Priority(char oper1,char oper2);//�����������������������������
		double calculate(double a,int oper,double b);//���㲿�ֱ��ʽ��ֵ
		double CalculateResult(char express[]);//���������ֵ 
};
class Judge
{
	public:
		Judge();
		void judge(char language,int inputanswer,int i,int answers,int right,char express[]);//�ж� 
		void CorrectRate(double right,int i);//��ȷ�� 
		int inputanswer,answers;
		double getRight();
	private:
		double right;//��ȷ��	
};
