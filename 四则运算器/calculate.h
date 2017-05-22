class interaction
{
	public:
		interaction();
		void scan(char language,int n);//起始界面交互
		void LanguageAndPrint(char language,int a);//语言选择 和输出 
		char getLanguage();
		int getN();
	private:
		char language;//语言 
		int n,a;	//题数 
};
class formula
{
	public:
		formula();
		char change(int x);//随机数转变成运算符 
		char RandomNumber();//随机数生成 
		char RandomOperation() ;//随机符号生成 
		void random(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3);//题目元素生成
		void formu(int casenum,char a,char b,char c,char d,char oper1,char oper2,char oper3,char express[]);//生成算式
		char a,b,c,d,oper1,oper2,oper3,express[];
		int casenum;
};
class calformula
{
	public:
		calformula();
		int IsOperator(char c);//比较前后两个运算符的优先级
		int Priority(char oper1,char oper2);//根据运算符和两个操作数进行运算
		double calculate(double a,int oper,double b);//计算部分表达式的值
		double CalculateResult(char express[]);//计算整体的值 
};
class Judge
{
	public:
		Judge();
		void judge(char language,int inputanswer,int i,int answers,int right,char express[]);//判断 
		void CorrectRate(double right,int i);//正确率 
		int inputanswer,answers;
		double getRight();
	private:
		double right;//正确数	
};
