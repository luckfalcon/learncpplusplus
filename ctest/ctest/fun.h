#ifndef _FUN_
#define _FUN_

#define print_bit(n) (n)?(printf("%d",n&0x1),printf_bit(n>>1)):(printf("\0"))//printf binary

//#define setbits( x,p, n, y) (((x)&~(~(~0 << (n)) << ((p)-(n)+1)))&((((y) >> ((p) - (n) + 1))&~(~0 << (n))) << ((p)-(n)+1))))


void sdelt(char s[], char t[]);//from s delete t

void sdelc(char s[], int c);

int getchsite(char s[], char t[]);

void printf_bit(int n);

unsigned setbits(unsigned x, unsigned y, int p, int n);//use the same part of y to replace the same part of x. 

unsigned invert(int x, int p, int n);

int strend(char *s, char *t); //judge if *t is at the end of *s, is return 1,no return 0

void strnmcpy(char *s, char *t, int n);//copy the first n in t to  s
/*some function on char*/
int get(void);

void ungetch(int c);

int getword(char *word, int lim);

#endif