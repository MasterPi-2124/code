#include<string.h>
#include<stdio.h>
#include<ctype.h>
FILE *fi,*fo;
struct Name
{
	char a[200];
};

void erase(char s[],int i)
{
	memmove(&s[i], &s[i + 1], strlen(s) - i);
}
 
void standardization (char a[1000])
{
	int n=strlen(a);
	int i=0;
	while (a[0]==' ') erase(a,0);
	while (a[strlen(a)-1]==' ') erase(a,strlen(a)-1);
	if (!strlen(a)) printf("");
	else
		while (i<strlen(a)-1)
		{
			if (a[i]==' ' && a[i+1]==' ') erase(a,i);
			else i++;
		}
	i=0;
	while (i<strlen(a))
	{
		a[i]=toupper(a[i]);
		i++;
	}
}

void sort(char s1[150], char s2[150],int i1,int i2)
{
	
}

typedef struct
{
	char ten[150];
}hoten;

int main()
{
    fi=fopen("a.inp","r");
    fo=fopen("a.out","w");
	int n,i;
	fscanf(fi,"%d",&n);
	/*int x=strcmp(s,r);
	printf("%d",x);*/
	Name a[n];
	char tach[150];
	getchar();
	for (i=0;i<n;i++)
	{
		fscanf(fi,"%[^\n]s",a[i].ten);
		chuanhoa(a[i].ten);
	}
	for (int i=0;i<n;i++) 
	{
		int j;
		for (j=i+1;j<n;j++)
	    sapxep(a[i].ten , a[j].ten,0,0);
	}
	for (i=0;i<n;i++) 
	{
		fprintf(fo,"(%d) %s\n", i+1, a[i]);
	}
	return 0;
	
}