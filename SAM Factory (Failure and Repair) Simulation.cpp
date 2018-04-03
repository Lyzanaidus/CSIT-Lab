#include<iostream>
#include<conio.h>
using namespace std;

int random(int r, int a)
{
    //cout<<"\n\n\t\t\t\tThis is <random>.";
    //cout<<"\n\t\t\t\tArguments :- a = "<<a<<"    |r = "<<r<<"    |Returned : "<<(a*r)%101;
    return ((a*r)%101);
}

int failure(int p)
{
    //cout<<"\n\n\t\t\t\tThis is <failure>.";
    //cout<<"\n\t\t\t\tArguments :- p = "<<p;

    if(p<=50)
    {
        //cout<<"\n\n\t\t\t\tThis is <failure>.";
        //cout<<"\n\t\t\t\tCase 1 :- (p<=50) Activated.";
        return 0;
    }
    else if(p<=80)
    {
        //cout<<"\n\n\t\t\t\tThis is <failure>.";
        //cout<<"\n\t\t\t\tCase 2 :- (p<=80) Activated.";
        return 1;
    }
    else if(p<=95)
    {
        //cout<<"\n\n\t\t\t\tThis is <failure>.";
        //cout<<"\n\t\t\t\tCase 3 :- (p<=95) Activated.";
        return 2;
    }
    else if(p<=100)
    {
        //cout<<"\n\n\t\t\t\tThis is <failure>.";
        //cout<<"\n\t\t\t\tCase 4 :- (p<=100) Activated.";
        return 4;
    }
}

int repair(int p)
{
    //cout<<"\n\n\t\t\t\tThis is <repair>.";
    //cout<<"\n\t\t\t\tArguments :- p = "<<p;

    if(p<=50)
    {
        //cout<<"\n\n\t\t\t\tThis is <repair>.";
        //cout<<"\n\t\t\t\tCase 1 :- (p<=50) Activated.";
        return 1;
    }
    else if(p<=75)
    {
        //cout<<"\n\n\t\t\t\tThis is <repair>.";
        //cout<<"\n\t\t\t\tCase 2 :- (p<=75) Activated.";
        return 2;
    }
    else if(p<=90)
    {
        //cout<<"\n\n\t\t\t\tThis is <repair>.";
        //cout<<"\n\t\t\t\tCase 3 :- (p<=90) Activated.";
        return 3;
    }
    else if(p<=100)
    {
        //cout<<"\n\n\t\t\t\tThis is <repair>.";
        //cout<<"\n\t\t\t\tCase 4 :- (p<=100) Activated.";
        return 7;
    }

}

int main()
{
    int d,D,a,f,fc=0,fcc=0,r,rr=51,rep;

    cout<<"\n\n\tEnter no of days :- ";
    cin>>D;
    cout<<"\n\n\tEnter your roll no :- ";
    cin>>r;

    a=r/3;
    for(d=1;d<=D;d++)
    {
        //a=5;//r/3;
        r=random(r,a);
        //cout<<"\n\n\t\t\t\tThis is <random> returned.";
        //cout<<"\n\t\t\t\tReturned : "<<r;

        f = failure(r);
        fc=fc+f;

        cout<<"\n\n\n\t\tDay :- "<<d<<" | Failures = "<<f;

        int i,j;

        for(i=1;i<=f;i++)
        {
            fcc++;
            //a=2;
            rr=random(rr,a);
            //cout<<"\n\n\t\t\t\tThis is <random> returned.";
            //cout<<"\n\t\t\t\tReturned : "<<r;

            rep = repair(rr);
            for(j=1;j<=rep;j++)
            {
                //pop(sc);
            }
            cout<<"\n\t\t M["<<fcc<<"] : Repair = "<<rep<<" days";

        }
    }
    cout<<"\n\n\tTotsl Failures = "<<fc;

    getch();

}
