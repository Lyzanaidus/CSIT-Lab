# include<iostream>
# include<string.h>
# include<conio.h>
using namespace std;

int is_present(char x,char km[5][5])
{
    char y=x;
    cout<<"\n\n\t-> This is [ispresent]\n\t\tArguments :- x = "<<y<<"\t| km[5][5].\n";
    getch();

    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(x==km[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

void Insert(char x,char km[][5])
{
    char y=x;
    cout<<"\n\n\t-> This is [Insert]\n\t\tArguments :- x = "<<y<<"\t| km[5][5].\n";
    getch();

    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(km[i][j]!='\0')
            {
                km[i][j]=x;
            }
        }
    }
}


void createkm(char k[],char km[5][5])
{
    cout<<"\n\n\t-> This is [createkm]\n\t\tArguments :- km[5][5].\n";
    getch();

    int i;
    char j;

    for(i=0;i<strlen(k);i++)
    {
        cout<<"\n\n\t\t\t->k["<<i<<"] = "<<k[i];
        if(!is_present(k[i],km))
        {
            cout<<"\n\n\t\t\t->"<<k[i]<<" is_present";
            Insert(k[i],km);
        }
    }

    for(j='A';j<='Z';j++)
    {
        cout<<"\n\n\t\t\t->j = "<<j;
        cout<<"\n\n\t\t\t->j+1 = "<<j++;
        if(!is_present(j,km))
        {
            cout<<"\n\n\t\t\t->"<<j<<" is_present";
            Insert(j,km);
        }
        if(j='I')
        {
            j++;
        }
    }
}

void dispkm(char km[5][5])
{
    cout<<"\n\n\t-> This is [dispkm]\n\t\tArguments :- km[5][5].\n";
    getch();

    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<"\t"<<km[i][j];
        }
        cout<<"\n\n";
    }
}

void initkm(char km[5][5])
{
    cout<<"\n\n\t-> This is [initkm]\n\t\tArguments :- km[5][5].\n";
    getch();

    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            km[i][j]='\0';
        }
    }
}

int main()
{
    char p[]="hello how are you",c[50],k[]="POKHARA",km[5][5];

    cout<<"\n\n\t-> This is [main]\n\t\tArguments :- \0";
    initkm(km);
    dispkm(km);
    getch();
    createkm(k,km);
    dispkm(km);

    getch();
}
