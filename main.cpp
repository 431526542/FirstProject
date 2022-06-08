#include<iostream>

using namespace std;


struct SalesRec //�� 62byte
{
	char pID[10]; //10byte
	int dYear, dMonth, dData; //3*4=12byte
	char deliveraddr[40]; //40byte
};

struct TimeRec
{
	int hours;
	int minutes;
};

//�迭�� ���迭 ��ȣ�� ���� �־��ְ� ���� ���� ���� ��ȯ
double GetArraySum(double arr[], int n);
void printSum(double sum);

//�л� ���ϱ�
double variance(double arr[], int n);

//�ΰ��� ���� ���� �ٲٱ�
void PrSalesRec(SalesRec& srec);
void SwapValues(int& x, int& y);

//�ð� t1�� t2�� ���Ѵ�.
void AddTime(TimeRec& t1, const TimeRec& t2);

int main()
{
	/*
	double a[50], b[100];
	double sum = 0;

	sum = GetArraySum(a, 50); // 1.�Լ��� int main���������ϰ� ������ �Ʒ��� ����. sum�� getarraysum(��)�ΰ��� �Լ��� ó���ϰ�
	                        //3.sum���� ���´�
	printSum(sum);          //4.printsum �Լ��� �Ѿ��
	                        //6.���� ����� ���δ�.
	sum = GetArraySum(b, 100);

	printSum(sum);
	
	////////////////////////////////////
	int a, b = { 0 };
	cout << " �ΰ��� ���� �Է��ϼ���. ";
	cin >> a >> b;
	SwapValues(a, b);
	cout << " a = " << a << " b = " << b << endl;
	

	SalesRec stRec; //62byte
	strcpy_s(stRec.pID, "123456789");
	stRec.dYear = 2022;
	stRec.dMonth = 6;
	stRec.dData = 8;
	strcpy_s(stRec.deliveraddr, "��⵵ ���ν� ������ ����");
	PrSalesRec(stRec);
	*/

	TimeRec time1 = { 2, 20 };
	TimeRec time2 = { 1, 55 };
	cout << time1.hours << " �ð� " << time1.minutes << " �� + ";
	cout << time2.hours << " �ð� " << time2.minutes << " �� = ";
	AddTime(time1, time2);
	cout << time1.hours << " �ð� " << time1.minutes << " �� " << endl;
}

void PrSalesRec(SalesRec& srec)//4byte or 8byte 
{
	cout << " ǰ���ڵ� " << srec.pID << endl;
	cout << " ������� " << srec.dYear << " �� " << endl;
	cout <<" "<< srec.dMonth << " �� " << srec.dData << " �� " << endl;
	cout << " ����ּ� : " << srec.deliveraddr << endl;
}

//�ΰ��� ���� ���� �ٲٱ�
void SwapValues(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void printSum(double sum)
{
	cout << " Sum = " << sum << endl; // 5.���� ����Ѵ�.
}

//�迭�� ���迭 ��ȣ�� ���� �־��ְ� ���� ���� ���� ��ȯ
double GetArraySum(double arr[], int n) //getarraysum�� �Լ� �̸� ()���ִ� ���� �Ű�����
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		sum += arr[i];
	}
	return sum; //2. for �Լ��� �Ϸ�Ǹ� sum���� �ٽ� ���ư�, �ݵ�� ���ϰ��� �־�� �Ѵ�.
}

//�л걸�ϱ�
double variance(double arr[], int n)
{
	double sum = 0, sqSum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		sqSum += arr[i] * arr[i];
	}
	double result = sqSum / n - sum / (n * n);
	return result;
}

//�ð� t1�� t2�� ���Ѵ�.
void AddTime(TimeRec& t1, const TimeRec& t2)
{
	t1.minutes += t2.minutes;
	t1.hours += t2.hours + (t1.minutes / 60);
	t1.minutes %= 60;
}