#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINE 100//�����ļ��ڿɶ������
char str[200];//��ȡ���ַ���
char url[20];//�ļ�λ��
int len; //�ַ���

void getString();
void getCharNums();
void getWordNums();

int main(int argc, char const *argv[])
{    
	strcat(url,argv[2]);
	getString();
	switch(argv[1][1]){
		case 'c':
			getCharNums();
			break;
		case 'w':
			getWordNums();
			break;
		default: 
			printf("please try it again with other params!");
			break;
	}
    return 0;
}

//���ļ�����ȡ�ַ���
void getString()
{
	char buf[MAX_LINE];  /*������*/
	FILE *fp;            /*�ļ�ָ��*/
	len = 0;           /*���ַ�����*/
	if((fp = fopen(url,"r")) == NULL)
	{
		perror("fail to read");
		exit (1) ;
	}
	while(fgets(buf,MAX_LINE,fp) != NULL)
	{
		len += strlen(buf);
		strcat(str,buf);
	}
}

void getCharNums()
{
	printf("this file contains %d characters in total!\n",len);
}

void getWordNums()
{	
	int others = 0;
	int i =0;
	for(;i<len;i++)
	{
		//printf("%c",str[i]);
		if(i!=len-1)
		{
			//�ܿ�'s
			if(str[i]=='\'')
				continue;
			if(str[i]=='\n'||str[i]==','||str[i]=='.'||str[i]==' '||str[i]=='!'||str[i]=='?')
			{
				others++;
			}
		}
	}
	printf("\n this file contains %d words in total!\n",others+1);
}
