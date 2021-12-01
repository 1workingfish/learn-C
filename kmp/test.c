#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define MAXSIZE 100
//BF算法
int index_bf(char sstr[], char tstr[])
{
	if ((sstr == 0) || (tstr == 0))
	{
		return -1;
	}
	int i = 0;
	int j = 0;
	int slen = strlen(sstr);
	int tlen = strlen(tstr);
	while ((i < slen) && (j < tlen))
	{
		if (sstr[i] == tstr[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == tlen)
	{
		return i - tlen;
	}
	return -1;
}

//next数组，从0开始
void getnext(char tstr[], int next[])
{
	int i = 0;
	int k = -1;
	next[0] = -1;
	int tlen = strlen(tstr);
	while (i < tlen - 1)
	{
		if ((k == -1) || (tstr[i] == tstr[k]))
		{
			i++;
			k++;
			next[i] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int index_kmp(char sstr[], char tstr[])
{
	int next[MAXSIZE];
	int i = 0;
	int j = 0;
	getnext(tstr, next);
	int slen = strlen(sstr);
	int tlen = strlen(tstr);
	while ((i < slen) && (j < tlen))
	{
		if (j == -1 || sstr[i] == tstr[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= tlen)
	{
		return i - tlen;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char sstr[100]; memset(sstr, 0, sizeof(sstr));
	char tstr[100]; memset(tstr, 0, sizeof(tstr));
	strcpy(sstr, "aabaabcbcabaabc");
	strcpy(tstr, "abaabc");
	//printf("index_bf =%d\n", index_bf(sstr, tstr));
	printf("index_kmp=%d\n", index_kmp(sstr, tstr));
	return 0;
}