#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(0, "");
	double min;
	double max;
	int minor;   // ������ ���������
	int i;       // ����� ��������
	double* Massive; 
	double sum = 0;
	double cel;
	double drob;
	printf("������� ���������� ������������ �����:\n");
	scanf("%d", &minor);
	if (minor <= 0) 
	{
		printf("��������� �������������� ������. ����������, ��������� ������� �����.\n");
		goto stop;
	}
	printf("������� ����������� ������� ��������� ���������:\n");
	scanf("%lf", &min);
	printf("������� ������������ ������� ��������� ���������:\n");
	scanf("%lf", &max);
	if (min > max) 
	{
		printf("��������� �������������� ������.����������, ��������� ������� �����.\n");
		goto stop;
	}
	Massive = (double*)malloc(minor * sizeof(double));// ������������ ������
	if (Massive == 0)
	{
		printf("��������� �������������� ������, ������ �� ������� �������. ���������� ������.\n");
		goto stop;
	}
	for (i = 0; i < minor; i++)
	{
		Massive[i] = 0;
	}
	for (i = 0; i < minor; i++)
	{
		Massive[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;     // ��������� �������������� ����� � ��������� �� min �� max
	}
	for (i = 0; i < minor; i++) 
	{
		drob = modf(Massive[i], &cel);
		drob = drob * 1000000;
		if (drob < minor+1)
		{
			sum = sum - Massive[i];
		}
		else
		{
			sum = sum + Massive[i];
		}
	}
	printf("������� �����: %lf\n", sum);
	free(Massive);
	stop:
	system("pause");  
	
}
