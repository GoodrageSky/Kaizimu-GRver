#include<bits/stdc++.h>
using namespace std;
int wordcnt=114;
//��һ����д��Ŀ���� 
string ans[115]; //��������������ǵô�˫���� 
string cur[115];
char lettersguessed[28];
int lttp;
int wordsguessed;
bool created=0;
void createans()
{
	printf("��ŭ����ĸ��v0.0.3 BETA\n");
	printf("�������problem creator.exe��ȡ�����\n");
	scanf("%d",&wordcnt);
	getchar();
	for(int i=1;i<=wordcnt;i++)
	{
		getline(cin,ans[i]);
	}
	printf("����ɹ�\n");
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
	printf("����ĸ��ʼ��\n");
	printf("�ѿ���ĸ��");
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
//���� o һ����ĸ����ʾ����ĸ
//����c һ�����֣���ʾ�ڼ������� 
