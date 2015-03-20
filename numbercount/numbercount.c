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
	puts("Version:1.2");
	puts("****************************************************************************");
	puts("a.查看     b.次序进行");
	puts("c.跳转进行 d.退出");
	puts("****************************************************************************");
	char input;
	fflush(stdin);
	while (scanf("%c", &input) != 1 || (input<'a' || input>'d'))
	{
		fflush(stdin);
		puts("Input a letter and the letter must be a,b,c or d.");
	}
	if (input == 'a')
	{
		for (int i = 0; i < 1000; i++)
		{
			printf("%d\n", i);
		}
	}
	else if (input == 'b')
	{
		FILE*fp;
		fp = fopen("numberrecord.txt", "a+");
		for (int i = 0; i < 1000; i++)
		{
			if (i <= 9)
			{
				printf("00");
			}
			else if (i > 9 && i <= 99)
			{
				printf("0");
			}
			printf("%d\n", i);
			puts("键入换行符以继续");
			getch();
			if (i <= 9)
			{
				fprintf(fp, "00%d\n", i);
			}
			else if (i > 9 && i <= 99)
			{
				fprintf(fp, "0%d\n", i);
			}
			else
			{
				fprintf(fp, "%d\n", i);
			}

			fclose(fp);
			fp = fopen("numberrecord.txt", "a+");
		}
		fclose(fp);
	}
	else if (input == 'c')
	{
		int jump;
		scanf("%d",&jump);
		fflush(stdin);
		FILE*fp;
		fp = fopen("numberrecord.txt", "a+");
		for (; jump < 1000; jump++)
		{
			if (jump <= 9)
			{
				printf("00");
			}
			else if (jump > 9 && jump <= 99)
			{
				printf("0");
			}
			printf("%d\n", jump);
			puts("键入换行符以继续");
			getch();
			if (jump <= 9)
			{
				fprintf(fp, "00%d\n", jump);
			}
			else if (jump > 9 && jump <= 99)
			{
				fprintf(fp, "0%d\n", jump);
			}
			else
			{
				fprintf(fp, "%d\n", jump);
			}
			fclose(fp);
			fp = fopen("numberrecord.txt", "a+");
		}
		fclose(fp);
	}
	getch();
}