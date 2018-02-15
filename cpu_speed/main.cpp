//#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"") //隐藏控制台
#include <stdio.h>
#include <time.h>  //后面要用到clock函数
#include <windows.h>
#include <omp.h>
#define N 500000
#define TIME 10000

void funtion(int* i, int* INTcalt, double* FLOARTcalt);

int main(void)
{
	MessageBox(NULL,L"点击 确定 开始测试！",L"CPU计数器V1.1",MB_OK|MB_ICONWARNING);
	printf("正在测试...请稍后...\n\n");

	register int i = 0,mulINT = 0,sinINT = 0;
	register double multi = 2.0,single = 2.0,time;
	//多线程计算
	time = clock();
	#pragma omp parallel reduction(+:i,mulINT,multi)
	{
		while (clock() - time < TIME)
		{
			funtion(&i, &mulINT, &multi);
		}
	}

	//单线程计算
	i = 0;
	time = clock();
	while (clock() - time < TIME)
	{
		funtion(&i, &sinINT, &single);
	}

	system("cls");
	printf("====================== 您的处理器得分 =====================\n");
	printf("=> 线程数： %d T\n\n",omp_get_num_procs());
	printf("=> 多线程： %.0f Marks\n",multi + mulINT);
	printf(" [ 整数运算： %d Marks , 浮点数运算： %.0f Marks ]\n\n",mulINT,multi);

	printf("=> 单线程： %.0f Marks\n",single + sinINT);
	printf(" [ 整数运算： %d Marks , 浮点数运算： %.0f Marks ]\n\n",sinINT,single);

	printf("线程效率比 ： %.2f X\n",(multi+mulINT) / (single+sinINT));
	printf("==========================================================\n");

	system("pause");
	return 0;
}


void funtion(int* i, int* INTcalt, double* FLOARTcalt)
{
	(*i)++;
	if (*i > N)
	{
		(*INTcalt) += 2;
		(*INTcalt)--;
		(*INTcalt) *= 1;
		(*FLOARTcalt) /= 1.001;
		(*i) = 0;
	}
	(*FLOARTcalt) += 0.000002;
	(*FLOARTcalt) /= 1;
	(*INTcalt) *= 1;
}