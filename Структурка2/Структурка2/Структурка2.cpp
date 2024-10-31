//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	char c;
//	int a = sizeof(char)
//	b = a;
//	char* st = (char*)malloc(a), *st2=(char*)malloc(2*a);
//	if (st == NULL)
//	{
//		printf("Ошибка выделения памяти.");
//		return 0;
//	}
//	if (st2 == NULL)
//	{
//		printf("Ошибка выделения памяти.");
//		return 0;
//	}
//	printf("Введите текст: ");
//	c = getchar();
//	while (c != '\n')
//	{
//		if (k == 0)
//		{
//			st[k] = c;
//			k++;
//		}
//		else
//		{
//			if (k % 2 == 0)
//			{
//				free(st);
//				st = (char*)malloc((k + 1) * a);
//				if (st == NULL)
//				{
//					printf("Ошибка выделения памяти.");
//					return 0;
//				}
//				st[k] = c;
//				for (i = 0; i < k; i++)
//				{
//					st[i] = st2[i];
//				}
//				
//				k++;
//
//			}
//			else
//			{
//				free(st2);
//				st2 = (char*)malloc((k + 1) * a);
//				if (st2 == NULL)
//				{
//					printf("Ошибка выделения памяти.");
//					return 0;
//				}
//				st2[k] = c;
//				for (i = 0; i < k; i++)
//				{
//					st2[i] = st[i];
//				}
//				
//				k++;
//			}
//		}
//		c = getchar();
//	}
//	if (k % 2 == 0)
//	{
//		free(st);
//		st = (char*)malloc((k)*a);
//		for (i = 0; i < k; i++)
//			st[i] = st2[i];
//	}
//	for (i = 0; i < k; i++)
//	{
//		if (st[i] == ' ')
//		{
//			count += 1;
//			if (count == 5)
//			{
//				for (int j = count; j > 0; j--)
//					st[i - (j - 1)] = '_';
//			}
//			else if (count > 5)
//				st[i] = '_';
//		}
//
//		else
//		{
//			if (count < 5)
//			{
//				for (int j = count; j > 0; j--)
//				{
//					st[i - j] = 0;
//				}
//			}
//			if (count > max)
//				max = count;
//			count = 0;
//		}
//	}
//	if (count > max)
//		max = count;
//	for (i = 0; i < k; i++)
//		printf("%c", st[i]);
//	printf("\nМаксимум равен %d", max);
//	free(st);
//	free(st2);
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	char c;
//	int a = sizeof(char), k = 0, b, i, count = 0, flag = 0, max = 0;
//	char* st=(char*) calloc(5, a);
//	b = a * 5;
//	if (st == NULL)
//	{
//		printf("Ошибка выделения памяти.");
//		return 0;
//	}
//	printf("Введите текст: ");
//	c = getchar();
//	while (c != '\n')
//	{
//		st[k] = c;
//		if (c == ' ')
//			st[k+1] = ' ';
//		k++;
//		if (k >= b)
//		{
//			if (b == 5)
//				b += 3;
//			else
//				b++;
//			st = (char*)realloc(st, b);
//			if (st == NULL)
//			{
//				printf("Ошибка выделения памяти.");
//				return 0;
//			}
//		}
//		c = getchar();
//	}
//	st = (char*)realloc(st, k+1);
// if (st == NULL)
//		{
//			printf("Ошибка выделения памяти.");
//			return 0;
//		}
//	st[k] = '\0';
//	for (i = 0; i < k; i++)
//	{
//		if (st[i] == ' ')
//		{
//			count += 1;
//			if (count == 5)
//			{
//				for (int j = count; j > 0; j--)
//					st[i - (j - 1)] = '_';
//			}
//			else if (count > 5)
//				st[i] = '_';
//		}
//
//		else
//		{
//			if (count < 5)
//			{
//				for (int j = count; j > 0; j--)
//				{
//					st[i - j] = 0;
//				}
//			}
//			if (count > max)
//				max = count;
//			count = 0;
//		}
//	}
//	if (count > max)
//		max = count;
//	for (i = 0; i < k; i++)
//		printf("%c", st[i]);
//	printf("\nМаксимум равен %d", max);
//	free(st);
//}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	FILE * fl1, *fl2;
	char c;
	int a = sizeof(char), k = 0, i, count = 0, flag = 0,max=0, end=0;
	char* st = (char*)malloc(a);
	if (st == NULL)
	{
		printf("Ошибка выделения памяти.");
		return 0;
	}
	fopen_s(&fl1, "input.txt", "r");
	fopen_s(&fl2, "output.txt", "w");
	c = fgetc(fl1);
	if (c != EOF)
	{
		while (c != '\n')
		{
			st[k] = c;

			k++;
			if (k >= a)
			{
				a += sizeof(char);
				st = (char*)realloc(st, a);
				if (st == NULL)
				{
					printf("Ошибка выделения памяти.");
					return 0;
				}
			}
			c = fgetc(fl1);
		}
	}
	st = (char*)realloc(st, k + 1);
	if (st == NULL)
	{
		printf("Ошибка выделения памяти.");
		return 0;
	}
	st[k] = '\0';
	for (i = 0; i < k; i++)
	{
		if (st[i] == ' ')
		{
			count += 1;
			if (count == 5)
			{
				for (int j = count; j > 0; j--)
					st[i - (j - 1)] = '_';
			}
			else if (count > 5)
				st[i] = '_';
		}

		else
		{
			if (count < 5)
			{
				for (int j = i - count; j < k - count; j++)
				{
					st[j] = st[j + count];
				}
				k = k - count;
				i = i - count;
				end++;
			}
			if (count > max)
				max = count;
			count = 0;
		}
	}
	st = (char*)realloc(st, k - end+3);
	if (count > max)
		max = count;
	count = 0;
	for (i = 0; i < k; i++)
	{
		if (st[i] == ' ')
			count++;
	}
	st = (char*)realloc(st, k - count+1);
	st[k-count] = '\0';
	k = k - count;
	for (i = 0; i < k; i++)
	{
		fprintf(fl2, "%c", st[i]);
	}

	fprintf(fl2,"\nМаксимум равен %d", max);
	fclose(fl1);
	fclose(fl2);
	free(st);
}