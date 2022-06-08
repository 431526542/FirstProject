#include<iostream>

using namespace std;


struct SalesRec //총 62byte
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

//배열에 각배열 번호의 값을 넣어주고 전부 합한 값을 반환
double GetArraySum(double arr[], int n);
void printSum(double sum);

//분산 구하기
double variance(double arr[], int n);

//두개의 수를 서로 바꾸기
void PrSalesRec(SalesRec& srec);
void SwapValues(int& x, int& y);

//시간 t1에 t2를 더한다.
void AddTime(TimeRec& t1, const TimeRec& t2);

int main()
{
	/*
	double a[50], b[100];
	double sum = 0;

	sum = GetArraySum(a, 50); // 1.함수는 int main먼저시작하고 위에서 아래로 간다. sum은 getarraysum(위)로가서 함수를 처리하고
	                        //3.sum값이 나온다
	printSum(sum);          //4.printsum 함수로 넘어간다
	                        //6.값을 출력해 보인다.
	sum = GetArraySum(b, 100);

	printSum(sum);
	
	////////////////////////////////////
	int a, b = { 0 };
	cout << " 두개의 수를 입력하세요. ";
	cin >> a >> b;
	SwapValues(a, b);
	cout << " a = " << a << " b = " << b << endl;
	

	SalesRec stRec; //62byte
	strcpy_s(stRec.pID, "123456789");
	stRec.dYear = 2022;
	stRec.dMonth = 6;
	stRec.dData = 8;
	strcpy_s(stRec.deliveraddr, "경기도 용인시 수지구 죽전");
	PrSalesRec(stRec);
	*/

	TimeRec time1 = { 2, 20 };
	TimeRec time2 = { 1, 55 };
	cout << time1.hours << " 시간 " << time1.minutes << " 분 + ";
	cout << time2.hours << " 시간 " << time2.minutes << " 분 = ";
	AddTime(time1, time2);
	cout << time1.hours << " 시간 " << time1.minutes << " 분 " << endl;
}

void PrSalesRec(SalesRec& srec)//4byte or 8byte 
{
	cout << " 품목코드 " << srec.pID << endl;
	cout << " 배달일자 " << srec.dYear << " 년 " << endl;
	cout <<" "<< srec.dMonth << " 월 " << srec.dData << " 일 " << endl;
	cout << " 배달주소 : " << srec.deliveraddr << endl;
}

//두개의 수를 서로 바꾸기
void SwapValues(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void printSum(double sum)
{
	cout << " Sum = " << sum << endl; // 5.값을 출력한다.
}

//배열에 각배열 번호의 값을 넣어주고 전부 합한 값을 반환
double GetArraySum(double arr[], int n) //getarraysum이 함수 이름 ()에있는 값은 매개변수
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		sum += arr[i];
	}
	return sum; //2. for 함수가 완료되면 sum으로 다시 돌아감, 반드시 리턴값이 있어야 한다.
}

//분산구하기
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

//시간 t1에 t2를 더한다.
void AddTime(TimeRec& t1, const TimeRec& t2)
{
	t1.minutes += t2.minutes;
	t1.hours += t2.hours + (t1.minutes / 60);
	t1.minutes %= 60;
}