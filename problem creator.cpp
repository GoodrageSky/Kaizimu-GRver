#include<bits/stdc++.h>
using namespace std;
#define wordcnt 8
vector<string>words;
void disp()
{
	printf("�����ڵ���Ŀ�ǣ�\n");
	for(int i=0;i<words.size();i++)
	{
		printf("%d. ",i+1);
		cout<<words[i].c_str()<<endl;
	}
	printf("�Ƿ����������x��ʾ����\n");
	printf("����a�����Ŀ\n");
	printf("����e�޸���Ŀ\n");
	printf("����dɾ����Ŀ\n");
	return; 
}
void final()
{
	printf("�뽫���¼��������ճ������kaizimu custom.exe�\n");
	
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
	printf("��ŭ�Ŀ���ĸ����� v0.0.2 BETA\n");
	disp(); 
	while(dec!='x')
	{
		
		int pls;
		cin>>dec;
		if(dec=='a')
		{
			printf("�����������\n");
			getchar();
			string s;
			getline(cin,s);
			words.push_back(s);
			disp();
		}
		else if(dec=='e')
		{
			printf("�������޸ĵ���Ŀ��ţ�\n");
			cin>>pls;
			printf("�������޸ĺ�ĸ�����\n");
			getchar();
			string s;
			getline(cin,s);
			words[pls-1]=s;
			disp();
		}
		else if(dec=='d')
		{
			printf("������ɾ������Ŀ��ţ�\n");
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
