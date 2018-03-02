# include<iostream>
# include<string.h>
using namespace std;

void cencrypt()
{
    int k,i,t;
    char c[50],p[50];

    cout<<"\n\n\tEnter Plain text :- ";
    cin.getline(p,50,'\n');

    cout<<"\n\n\tEnter Key :- ";
    cin>>k;


    cout<<"\n\tCipher text :- \n\n\t\t"<<c;

    for(i=0;i<strlen(p);i++)
    {
        t=p[i];
        t=t-97;
        t=t+k;
        t=t%26;
        t=t+65;
        c[i]=t;
    }

    c[i]='\0';

}

void cdecrypt()
{
    int k,i,t;
    char c[50],p[50];

    cout<<"\n\n\tEnter Cipher Text :- ";
    cin.getline(c,50,'\n');

    cout<<"\n\n\tEnter Key :- ";
    cin>>k;

    cout<<"\n\tPlain text :- \n\n\t\t"<<p;

    for(i=0;i<strlen(p);i++)
    {
        t=c[i];
        t=t+65;
        t=t%26;
        t=t-k;
        t=t+97;
        p[i]=t;
    }

    c[i]='\0';

}

int main()
{
    char p[50]/*="helloworld"*/,c[50];
    int k,x=2;

    cout<<"\n\n\t\tEncrypt or Decrypt ??? :- ";
    cin>>x;

    if(x==0)
    {
        cencrypt();
    }

    else if(x==1)
    {
        cdecrypt();
    }
}


