#include"fun.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define BUFSIZE 100 

char buf[BUFSIZE];/*buffer for ungetch*/
int bufp = 0;/*nex free position in buffer*/


void sdelt(char s[], char t[])//from s[] delete t[]
{
	int i, j,k;
	i = j = k = 0;
	while (t[i] != '\0')//find the end of t
	{ 
		while (s[j] != '\0')
		{
			if (s[j] != t[i])
				s[k++] = s[j];
			j++;
		}

		i++;
	
	}
		
			
	/*for (i = 0; t[i] != '\0'; i++)
		for (j=k=0; s[j] != '\0';j++)
			if (s[j] != t[i])
				s[k++] = s[j];
				*/
	s[k] = '\0';

}

void sdelc(char s[], int c)//from s[] delete c
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';

}

int getchsite(char s[], char t[])//return the situation of c
{
	int i, j, num;
	for (j = 0; t[j] != '\0';j++)
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == t[j])
			{
				num = i;
				s[i] = '\0';
			}

		}
	return num;

}

void printf_bit(int num)
{
	if (num == 0);
	else
	{
		printf("%d",num&0x1);
		printf_bit(num >> 1);
	}	
}


unsigned setbits(unsigned x, unsigned y, int p, int n)
{
	
	unsigned result;
	unsigned nx = x&~((~(~0 << n)) << (p + 1 - n));					//clear the target part to 0
	unsigned ny = ((y >> (p + 1 - n))&~(~0 << n)) << (p + 1 - n); //get the target part and then roll to the target site
	result = nx | ny;
	return result;
	
	//return ((x&~((~(~0 << n)) << (p + 1 - n))) | (((y >> (p + 1 - n))&~(~0 << n)) << (p + 1 - n)));
}

unsigned invert(int x,int p,int n)
{
	unsigned target,tempx,y;
	y = x;
	target = ((~x>>(p+1-n))&~(~0<<n))<<(p+1-n); //get the target part and then roll to the target site
	tempx = y&~((~(~0 << n)) << (p + 1 - n));						  //clear the target part to 0
	return (target | tempx);

}

int strend(char *s, char *t)
{
	//int step = sizeof(s) - sizeof(t);
	int step = strlen(s) - strlen(t);
	char *stemp = s + step;
	while (*stemp++ == *t++)
		if (*stemp == '\0')
			return 1;
	return 0;


}

void strnmcpy(char *s,char *t,int n)
{

	//while (*s++ = *t++);
	char *stemp = s + strlen(s);//record the end char address of s
	if (strlen(t) >= n)
		//for (; n&&(*stemp = *t) != '\0'; stemp++, t++, n--);
	    while (n--&&(*stemp++ = *t++) != '\0');

}
/**/

int get(void) /*get a */
{
	return (bufp > 0) ? buf[bufp--] : getchar();

}

void ungetch(int c) /*push a character back on input*/
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

int getword(char *word, int lim)/*get a (possibly pushed-back) character */
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c == getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}
	for (; --lim>0;w++)
		if (!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];

}

/*binsearch:find x in v[0]<=v[1] <=[2] <=....v[n-1]*/
int binsearch(int x, int v[], int n)
{
	int high, mid, low;
	low = 0;
	high = n - 1;
	while (low <=high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x>v[mid])
			low = mid + 1;
		else
			return mid;/*found match*/
	}
	return -1;/*no match*/
}