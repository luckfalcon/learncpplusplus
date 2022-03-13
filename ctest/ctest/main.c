#include<stdio.h> //ctrl+K then ctrl+C/U
#include<stdlib.h>
#include<limits.h>
#include<float.h>
#include<string.h>
#include<stddef.h>
#include<ctype.h>
#include"fun.h"

#define f_right(x,n) (x)>>(n)
#define f_left(x,n) (x)<<(n)
#define SECUREFREE(p) if(p)			\
						{			\
						free(p);	\
						(p)=NULL;	\
						}
#define printf_int(n) printf("%d\n",(n))
#define printf_str(str) printf("str = %s\n",str)
#define type_size(type) printf("%d\n",sizeof(type))

int main(int argc, char *argv[])
{
	//while (--argc > 0)
	//	//printf("%s%s", ++argv, (argc > 1) ? " " : "");
	//	printf((argv > 1) ? "%s " : "%s", *++argv);
	//printf("\n");

	/*
	char *s = "helloworld";
	char *t = "ld";

	char *p = strstr(s, t);
	if (p)
		printf("%s\n", p);
	else
		printf("%d\n",(p==NULL));
	*/

	/*温度转换
	int fahr;
	int celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 / 9.0 * (fahr - 32); 
		printf("%3d\t%3d\n",fahr,celsius);
		fahr = fahr + step;
	}
	*/

	/*统计空格，回车，制表位的个数
	int ch,space=0, tab=0 ,n=0;
	while ((ch = getchar()) != EOF)
	{
		if (ch =='\n')
		++n;
		if (ch == '\t')
			++tab;
		if (ch == ' ')
			++space;
	}
	printf("space=%d\ntab=%d\nn=%d\n", space, tab, n);
	for (cnt = 0; getchar() != EOF;++cnt);
	printf("%d\n",cnt);
	*/
	
	/*将输入打印至输出，并将连续空格合并为一个空格输出
	char ch, space = 0, cnt = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ')
		{
			++space;
			if (space == 1)
				putchar(' ');
			continue;

		}
		else
		{
			putchar(ch);
			space = 0;
		}
	}
	*/

	/*将输入复制到输出，并替换制表位为\t，反斜杠为\\,回退为\b

	int ch, cnt = 0;
	while ((ch = getche()) != EOF) //getche()输入立刻回显.无缓冲区
		if (ch == '\t')
			printf("\\t");
		else if (ch == '\b')
		{
			printf("\\b");
			++cnt;
		}
			
		else if (ch == '\\')
			printf("\\\\");
		else
			putchar(ch);
			*/

	/*统计字符数cnt，行数cn，单词数cw，单词序列是指其中不包含换行符，制表位，空格的字符序列
	int c, cnt, cn, cw, state,IN = 1, OUT = 0;
	cn = cnt = cw = 0;
	state = OUT;
	while (c = getchar() != EOF)
	{
		++cnt;
		if (c == '\n')
			++cn;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++cw;
		}
		
	}
	printf("%d %d %d\n", cnt, cn, cw);
	*/

	/*以每行一个单词打印输入
	int c;
	while ((c = getchar  ()) != EOF)
	{
		putchar(c);
		putchar('\n');
	}
	*/

/*统计各种数字出现的次数
int c,i,nwhite, nothers;
int ndigit[10];
nwhite = nothers = 0;
for (i = 0; i < 10; ++i)
{
	ndigit[i] = 0;
}
while ((c = getchar()) != EOF)
	if (c >= '0' && c <= '9')
		++ndigit[c-'0'];
	else if (c == ' ' || c == '\n' || c == '\t')
		++nwhite;
	else
		++nothers;

printf("digits count:\n");
for (i = 0; i < 10; ++i)
	printf("%d times is: %2d\n",i, ndigit[i]);
printf("white space=%2d \n others = %4d\n", nwhite, nothers);
*/

/*count the frequecy of small letter

int c, i, j, others, letter_cnt[26];

others = 0;

for (i = 0; i < 26; ++i)//init letter count
	letter_cnt[i] = 0;

while ((c = getchar()) != EOF)
{
	if (c >= 'a'&&c <= 'z')
		++letter_cnt[c - 'a'];
	else
		++others;
}
for (i = 0,j='a'; i < 26&&j<='z'; ++i,++j)//show the result on the screen
	printf("%c is:%d\n", j, letter_cnt[i]);
*/

/*
int c, n_line, n_row,state;
state = 0;//0 is word,1 is not word
n_line = n_row = 0;
while ((c = getchar()) != EOF)
{
	if (c == '\n')
		++n_line;
	if (c == ' ' || c == '\n' || c == '\t')
		state = 1;

}
*/

/*
int c,N;
N = 0;
while ((c = getchar()) != EOF)
{
	++N;
}
*/

//printf the char max num
//printf("char_max=%d\nchar_min=%d\n", CHAR_MAX,CHAR_MIN);

/*test the diffrence between sizeof string and stren string
char s[10];
int i;
for (i = 0; i < 9; ++i)
	s[i] = 'a';
s[9] = '\0';
printf("%d\n", sizeof(s));
printf("%d\n", strlen(s));
*/

/*enum 枚举
	enum month{JAN=1,FEB,MAR,APR,MAY,JUN,JUlY,AUG,SEP,OCT,NOV,DEC};
		printf("%d月\n", FEB);
		*/

/*
char s[100],t[10];
int num,flag;
flag = scanf("%s%s", s,t);
printf("s = %s\nt = %s\nflag = %d\n", s, t,flag);
num = getchsite(s, t);
printf("num = %n\n", num);

*/
/*
//in y form p to end choose n,  replace tin x from p to end choose n.
//long x, y, p, n,nx,ny,nxy;
int p, n;
unsigned x, y,res;
x = 1375, y = 120, p = 5, n = 3;

printf("x bits is:\n");
print_bit(x);
printf("\ny bits is:\n");
print_bit(y);
printf("\nx later is ;\n");
res = setbits(x,y,p,n);

//res = ((x&~((~(~0 << n)) << (p + 1 - n))) | (((y >> (p + 1 - n))&~(~0 << n)) << (p + 1 - n)));
printf("%d\n", res);


nx = x&~((~(~0 << n)) << (p + 1 - n));
ny = ((y >> (p + 1 - n))&~(~0 << n)) << (p + 1 - n);
nxy = nx | ny;

printf("nx = %d\nny=%d\nnxy=%d\n", nx,ny,nxy);
*/

/*
//invert the choose part
unsigned x = 1371,resx;
int n = 3, p = 5;
resx = invert(x, p, n);
printf("%d\n",resx);
*/

//printf("%g\n",3.1415926578);
//int *p = (int*)malloc(4*sizeof(int));
//securefree(p);

/*
//test program 
//copy n char in t to s
char s[50] ="";
char *t = "123";
int n = 2;
printf_int(strlen(s));

//printf("%d\n",strend(s,t));
//printf_int(strend(s,t));

printf_str(s);
strnmcpy(s, t, n);
//strcpy(s,t);
printf_str(s);
*/

//memset();//重置申请内存值

size_t *x;
//type_size();
isspace();
isalpha();
isalnum();
	return 0;
}