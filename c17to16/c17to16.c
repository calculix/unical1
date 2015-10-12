#include <stdio.h>
#include <string.h>

#define STRLEN 200

void main(int argc, char **argv)
{
FILE *f1, *f2;
char str [STRLEN];
int i, l, space, spaces;

//printf("argc=%i\n", argc);
if (argc!=3)
    {
    printf("usage c17to16 infile outfile\n");
    return;
    }
//printf("argv[1]=%s\n", argv[1]);
f1=fopen(argv[1],"r");
if (f1==NULL) {printf("can't open infile\n"); return; }
f2=fopen(argv[2],"w");
if (f2==NULL) {printf("can't open outfile\n"); return; }

while (!feof(f1))
	{
	str[0]=0;
	fgets(str,STRLEN,f1);
	printf("str=%s\n", str);
	l=strlen(str);
	spaces=0;
	space=0;
	for (i=0;i<l;i++)
	    {
	    if (str[i]==' ') {space=i; spaces++;}
	    }
	if (spaces>=15) str[space]='\n';
	printf("str2=%s\n", str);
	fputs(str,f2);
	}

fclose(f1);
fclose(f2);
}
