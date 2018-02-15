//#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"") //���ؿ���̨
#include <stdio.h>
#include <time.h>  //����Ҫ�õ�clock����
#include <windows.h>
#include <omp.h>
#define N 500000
#define TIME 10000

void funtion(int* i, int* INTcalt, double* FLOARTcalt);

int main(void)
{
	MessageBox(NULL,L"��� ȷ�� ��ʼ���ԣ�",L"CPU������V1.1",MB_OK|MB_ICONWARNING);
	printf("���ڲ���...���Ժ�...\n\n");

	register int i = 0,mulINT = 0,sinINT = 0;
	register double multi = 2.0,single = 2.0,time;
	//���̼߳���
	time = clock();
	#pragma omp parallel reduction(+:i,mulINT,multi)
	{
		while (clock() - time < TIME)
		{
			funtion(&i, &mulINT, &multi);
		}
	}

	//���̼߳���
	i = 0;
	time = clock();
	while (clock() - time < TIME)
	{
		funtion(&i, &sinINT, &single);
	}

	system("cls");
	printf("====================== ���Ĵ������÷� =====================\n");
	printf("=> �߳����� %d T\n\n",omp_get_num_procs());
	printf("=> ���̣߳� %.0f Marks\n",multi + mulINT);
	printf(" [ �������㣺 %d Marks , ���������㣺 %.0f Marks ]\n\n",mulINT,multi);

	printf("=> ���̣߳� %.0f Marks\n",single + sinINT);
	printf(" [ �������㣺 %d Marks , ���������㣺 %.0f Marks ]\n\n",sinINT,single);

	printf("�߳�Ч�ʱ� �� %.2f X\n",(multi+mulINT) / (single+sinINT));
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