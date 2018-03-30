# include<iostream>
# include<string.h>
using namespace std;

void monoencrypt(char k[], char p[])
{
    int i,t;
    char c[50];

    /*cout<<"\n\n\tEnter Plain text :- ";
    cin.getline(p,50,'\n');
*/
   cout<<"\n\tCipher text :- \n\t\t";

    for(i=0;i<strlen(p);i++)
    {
        t=p[i];
        //cout<<"\n\n\tp["<<i<<"] = "<<p[i]<<"\t| "<<p[i]-97;
        t=t-97;
        c[i]=k[t];
    }

    c[i]='\0';
    cout<<endl<<c;

}

void monodecrypt(char nk[], char c[])
{
    int i,t;
    char p[50];

    /*cout<<"\n\n\tEnter Plain text :- ";
    cin.getline(p,50,'\n');
*/
   cout<<"\n\tCipher text :- \n\t\t";

    for(i=0;i<strlen(c);i++)
    {
        t=c[i];
        //cout<<"\n\n\tc["<<i<<"] = "<<c[i]<<"\t| "<<c[i]-65;
        t=t-65;
        p[i]=nk[t];
    }

    p[i]='\0';
    cout<<endl<<p;

}



int main()
{
    char p[50]="world",c[50]="NEPAL",k[26]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M',},nk[26];
    int x=2,i,z;

    cout<<"\n\n\t\tEncrypt or Decrypt ??? :- ";
    cin>>x;

    for(i=0;i<26;i++)
    {
       z=k[i]-65;
       nk[z]=i+97;
    }

    if(x==0)
    {
        monoencrypt(k,p);
    }

    else if(x==1)
    {
        monodecrypt(nk,c);
    }
}


