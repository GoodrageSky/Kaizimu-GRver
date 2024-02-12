#include<bits/stdc++.h>
using namespace std;
int wordcnt=114;
//上一个填写题目数量 
string ans[115]; //挨个输入歌名，记得打双引号 
string cur[115];
char lettersguessed[28];
int lttp;
int wordsguessed;
bool created=0;
void createans()
{
	printf("良怒的字母机v0.0.3 BETA\n");
	printf("请输入从problem creator.exe获取的命令：\n");
	scanf("%d",&wordcnt);
	getchar();
	for(int i=1;i<=wordcnt;i++)
	{
		getline(cin,ans[i]);
	}
	printf("输入成功\n");
	created=1;
	return;
}
void initcur()
{
	for(int i=1;i<=wordcnt;i++)
	{
		for(int j=0;j<ans[i].length();j++)
		{
			if(ans[i][j]==' ') cur[i]=cur[i]+' ';
			else cur[i]=cur[i]+'*';
		}
	}
}
void outputprogress()
{
	printf("开字母开始！\n");
	printf("已开字母：");
	for(int i=1;i<=lttp;i++)
	{
		printf("%c",lettersguessed[i]);
		printf(",");
	}
	printf("\n");
	for(int i=1;i<=wordcnt;i++)
	{
		printf("%d.",i);
		cout<<cur[i];
		printf("\n");
	}
	return;
}
bool isalpha(char a)
{
	if (('A'<=a&&'Z'>=a)||('a'<=a&&'z'>=a)) return true;
	return false;
}
bool issamealpha(char a,char b)
{
	if(!isalpha(a)) return 0;
	if(!isalpha(b)) return 0;
	if(a+32==b||b+32==a) return true;
	return false;
}
void open(char c)
{
	lttp++;
	lettersguessed[lttp]=c;
	for(int i=1;i<=wordcnt;i++)
	{
		for(int j=0;j<cur[i].size();j++)
		{
			if(c==ans[i][j]||(issamealpha(c,ans[i][j])))
				cur[i][j]=ans[i][j];
		}
	}
	outputprogress();
	return;
 } 
void correct(int x)
{
	cur[x]=ans[x];
	wordsguessed++;
	outputprogress();
}
int main()
{
	createans();
	if(created)
	{
		initcur();
		outputprogress();
		while(wordsguessed<wordcnt)
		{
			char dec;
			int pls;
			cin>>dec;
			if(dec=='c')
			{
				scanf("%d",&pls);
				correct(pls);
			}
			else if(dec=='o')
			{
				char tobe;
				cin>>tobe;
				open(tobe);
			}
		}
	}
	return 0;
} 
//输入 o 一个字母，表示开字母
//输入c 一个数字，表示第几题做对 
