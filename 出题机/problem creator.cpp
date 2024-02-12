#include<bits/stdc++.h>
using namespace std;
#define wordcnt 8
vector<string>words;
void disp()
{
	printf("您现在的题目是：\n");
	for(int i=0;i<words.size();i++)
	{
		printf("%d. ",i+1);
		cout<<words[i].c_str()<<endl;
	}
	printf("是否结束？输入x表示结束\n");
	printf("输入a添加题目\n");
	printf("输入e修改题目\n");
	printf("输入d删除题目\n");
	return; 
}
void final()
{
	printf("请将以下几行命令复制粘贴输入kaizimu custom.exe里：\n");
	
	printf("%d\n",words.size());
	for(int i=0;i<words.size();i++)
	{
		cout<<words[i].c_str()<<endl;
	}
	return;
	
}
int main()
{
	char dec='\0';
	printf("良怒的开字母出题机 v0.0.2 BETA\n");
	disp(); 
	while(dec!='x')
	{
		
		int pls;
		cin>>dec;
		if(dec=='a')
		{
			printf("请输入歌名：\n");
			getchar();
			string s;
			getline(cin,s);
			words.push_back(s);
			disp();
		}
		else if(dec=='e')
		{
			printf("请输入修改的题目编号：\n");
			cin>>pls;
			printf("请输入修改后的歌名：\n");
			getchar();
			string s;
			getline(cin,s);
			words[pls-1]=s;
			disp();
		}
		else if(dec=='d')
		{
			printf("请输入删除的题目编号：\n");
			cin>>pls;
			words.erase(words.begin()+pls-1,words.begin()+pls); 
			disp();
		}
		else if(dec=='x')
		{
			final();
			break;
		}
	}
	return 0;
} 
