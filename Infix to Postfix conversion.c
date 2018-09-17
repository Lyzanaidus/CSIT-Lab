#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int lookahead;

int main()
{
    lookahead = getchar();
    expr();
    putchar('\n');

    getch();
    return 0;

}

void expr()
{
    term();
    while(1)
    {
        if(lookahead == '+')
        {
            match('+');
            term();
            putchar('+');
        }
        else if(lookahead == '-')
        {
            match('-');
            term();
            putchar('-');
        }
        else
        {
            break;
        }
    }
}

void term()
{
    if(isdigit(lookahead))
    {
        putchar(lookahead);
        match(lookahead);
    }
    else
    {
        error();
    }
}

void match()
{
    int t;

    if(lookahead == t)
    {
        lookahead = getchar();
    }
    else
    {
        error();
    }
}

void error()
{
    printf("\n\n\t\t\tSyntax Error!!!");
    exit(1);
}




