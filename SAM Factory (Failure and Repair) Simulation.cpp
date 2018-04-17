#include<iostream>
#include<conio.h>
using namespace std;

#define max 500

int Q[max];
int qf=-1,qr=-1;

int qfull()
{
    //cout<<"\n\n\t\t\t\tThis is <qfull>.";
    //cout<<"\n\t\t\t\tArguments :- <None>";
    if (qr==max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int qempty()
{
    //cout<<"\n\n\t\t\t\tThis is <qfull>.";
    //cout<<"\n\t\t\t\tArguments :- <None>";
    if (qf==-1 && qr==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(int x)
{
    if(qfull())
    {
        cout<<"\n\n\t\t\tError!!! [Queue is Full]\n";
        return;
    }
    else if (qempty())
    {
        qf = qr = 0;
    }
    else
    {
        qr = (qr+1);
    }
    Q[qr] = x;
    //cout<<"\n\n\t\t"<<x<<" Enqueued at "<<qr+1;
}

void Dequeue()
{
    if(qempty())
    {
        cout<<"Error!!! [Queue is Empty]";
        return;
    }
    else
    {
        qf = (qf+1);
    }
    //cout<<"\n\n\t\t"<<Q[qf-1]<<" Dequeued at "<<qf-1;
}

void disq()
{
    int i;
    if (qempty())
    {
        cout<<"Error!!! [Queue is Empty]";
        return;
    }
    else
    {
        for (i = qf; i <= qr; i++)
        {
            cout<<Q[i]<<" | ";
        }
    }
}



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

        f = failure(r);             //
        fc=fc+f;

        //cout<<"\n\n\n\t\tDay :- "<<d<<" | Failures = "<<f;

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
            //cout<<"\n\t\t M["<<fcc<<"] : Repair = "<<rep<<" days";

            for(j=1;j<=rep;j++)
            {
                Enqueue(fcc);
            }

        }
        Dequeue();
        cout<<"\n\n "<<d<<" : >>";
        disq();
    }
    cout<<"\n\n\tTotsl Failures = "<<fc;

    getch();

}
