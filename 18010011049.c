#include <stdio.h>
#include <stdlib.h>

char stack[100];
int sira=-1;

void bas()
{
    printf("\n--------\nStack Durumu:\n");
    int i=0;
    for(i=sira;0<=i;i--)
    {
        printf("%c\n",stack[i]);
    }
    printf("-------\n");
}

void ekle(char x)
{
    sira++;
    stack[sira]=x;
}

char cek()
{
    if(sira==-1)
    {
        return -1;
    }
    else
    {
        sira--;
        return stack[sira+1];
    }

}

int oncelik(char x)
{
    if(x=='(')
    {
        return 0;
    }
    if(x=='+')
    {
        return 1;
    }
    if(x=='-')
    {
        return 1;
    }
    if(x=='*')
    {
        return 2;
    }
    if(x=='/')
    {
        return 2;
    }
    return 0;

}

int main()
{
    char *c=(char*)malloc(sizeof(char)*99);
    char x;
    printf("Infix ifadeyi giriniz:\n");
    scanf("%s",c);
    while(*c != '\0')
    {
        if(*c=='0' || *c=='1' || *c=='2' || *c=='3' || *c=='4' || *c=='5' || *c=='6' || *c=='7' || *c=='8' || *c=='9')
        {
            char a=*c;
            printf("%c ",a);
        }
        else if(*c=='(')
        {
            char a=*c;
            ekle(a);
        }
        else if(*c == ')')
        {
            while((x=cek())!='(')
            {
                printf("%c ",x);
            }
            bas();
        }

        else
        {
            while(oncelik(stack[sira]) >= oncelik(*c))
            {
                char a=cek();
                printf("%c ",a);
                bas();
            }
            ekle(*c);
            bas();
        }
        c++;
    }




    return 0;
}
