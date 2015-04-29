/*
Copyright (C) 2014 Frank_feng, Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma warning (disable:4996)
#include <stdio.h>
int main(void)
{
	puts("Copyright (C) 2014-2015 Frank_feng Inc. All rights reserved.");
	puts("Version:1.3");
	puts("****************************************************************************");
	puts("a.查看     b.次序进行");
	puts("c.跳转进行 d.退出");
	puts("****************************************************************************");
	char input; 
	int sum;//希望的数字的位数
	int count=0;//计算的位数
	int count1;//复制的当前的数字
	int max=1;//最大的数
	fflush(stdin);
	while (scanf("%c", &input) != 1 || (input<'a' || input>'d'))
	{
		fflush(stdin);
		puts("Input a letter and the letter must be a,b,c or d.");
	}
	puts("Input the figure of the number you want.");
	while ((scanf("%d", &sum) != 1) || (sum <= 0))
	{
		puts("The number input must >0");
	}
	for (int i = 0; i < sum; i++)
	{
		max *= 10;
	}
	if (input == 'a')
	{
		int a = 0;
		for (int i = 0; i < max; i++)
		{
			count1 = i;
			if (i>0)
			{
				while (count1 != 0)
				{
					++count;
					count1 /= 10;
				}
			}
			else if (i == 0)
			{
				count = 1;
			}
			count = sum - count;
			if ((a % 299 == 0) && i != 0)
			{
				getch();
			}
			for (int b = 0; b < count; b++)
			{
				printf("0");
			}
			printf("%d\n", i);
			a++;
			count = 0;
		}
	}
	else if (input == 'b')
	{
		FILE*fp;
		fp = fopen("numberrecord.txt", "a+");
		for (int i = 0; i < max; i++)
		{
			count1 = i;
			if (i>0)
			{
				while (count1 != 0)
				{
					++count;
					count1 /= 10;
				}
			}
			else if (i == 0)
			{
				count = 1;
			}
			count = sum - count;
			for (int b = 0; b < count; b++)
			{
				printf("0");
			}
			printf("%d\n", i);
			puts("键入换行符以继续");
			getch();
			for (int b = 0; b < count; b++)
			{
				fprintf(fp, "0");
			}
			fprintf(fp, "%d\n", i);
			count = 0;
			fclose(fp);
			fp = fopen("numberrecord.txt", "a+");
		}
	}
	else if (input == 'c')
	{
		FILE*fp;
		fp = fopen("numberrecord.txt", "a+");
		int i;
		puts("Input the number that you want to jump");
		scanf("%d", &i);
		fflush(stdin);
		for (i; i < max; i++)
		{
			count1 = i;
			if (i>0)
			{
				while (count1 != 0)
				{
					++count;
					count1 /= 10;
				}
			}
			else if (i == 0)
			{
				count = 1;
			}
			count = sum - count;
			for (int b = 0; b < count; b++)
			{
				printf("0");
			}
			printf("%d\n", i);
			puts("键入换行符以继续");
			getch();
			for (int b = 0; b < count; b++)
			{
				fprintf(fp, "0");
			}
			fprintf(fp, "%d\n", i);
			count = 0;
			fclose(fp);
			fp = fopen("numberrecord.txt", "a+");
		}
	}
	getch();
}