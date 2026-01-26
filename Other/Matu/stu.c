#define _CRT_SECURE_NO_WARNINGS 1
#define SPACE ' '

#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[21];
	int sex;
	int birth;
	float height;
	int grade[2];
}Stu;

typedef struct summary {
	int average[2];
	int max[2];
	int maxnum[2];
	Stu* maxperson[2];
	int min[2];
}Sum;

void data_deal(const Stu* stus, const int num, Sum* ttl)
{
	for (int access = 1, l = 0; ; access++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < num; i++)
			{
				if (access == 1)
					ttl->average[j] += stus[i].grade[j],
					ttl->max[j] = (ttl->max[j] > stus[i].grade[j]) ? ttl->max[j] : stus[i].grade[j],
					ttl->min[j] = (ttl->min[j] < stus[i].grade[j]) ? ttl->min[j] : stus[i].grade[j];
				if (access == 2)
					if (ttl->max[j] == stus[i].grade[j])
						ttl->maxnum[j]++;
				if (access == 3)
					if (ttl->max[j] == stus[i].grade[j])
						(ttl->maxperson[j])[l++] = stus[i];
			}
			if (access == 3)
				l = 0;
		}
		for (int k = 0; k < 2; k++)
		{
			if (access == 1)
				ttl->average[k] /= num;
			if (access == 2)
				ttl->maxperson[k] = (Stu*)malloc(sizeof(Stu) * ttl->maxnum[k]);
			if (access == 3)
				goto out;
		}
	}
out:
	;
}

void prt_stu(int num, Stu* stu)
{
	for (int i = 0; i < num; i++)
		printf("%s %d %d %.2f %d %d\n", stu[i].name, stu[i].sex, stu[i].birth, stu[i].height, stu[i].grade[0], stu[i].grade[1]);
}

void prt_sum(Sum* ttl)
{
	printf("C_average:%d\n", ttl->average[0]);
	printf("C_max:%d\n", ttl->max[0]);
	prt_stu(ttl->maxnum[0], ttl->maxperson[0]);
	printf("C_min:%d\n", ttl->min[0]);
	printf("Calculus_average:%d\n", ttl->average[1]);
	printf("Calculus_max:%d\n", ttl->max[1]);
	prt_stu(ttl->maxnum[1], ttl->maxperson[1]);
	printf("Calculus_min:%d\n", ttl->min[1]);
}

int main()
{
	Stu* stus = NULL;
	Sum ttl;
	for (int i = 0; i < 2; i++)
	{
		ttl.average[i] = 0;
		ttl.max[i] = ttl.maxnum[i] = 0;
		ttl.min[i] = 100;
	}
	int num = 0;
	scanf("%d", &num);
	stus = (Stu*)malloc(sizeof(Stu) * num);
	if (stus == NULL)
		return -1;
	for (int i = 0; i < num; i++)
	{
		while (getchar() != ' ');
		scanf("%[^ ]%d%d%f%d%d", stus[i].name, &stus[i].sex, &stus[i].birth, &stus[i].height, stus[i].grade, stus[i].grade + 1);
	}
	data_deal(stus, num, &ttl);
	prt_sum(&ttl);
	free(stus);
	free(ttl.maxperson[0]);
	free(ttl.maxperson[1]);
	return 0;
}