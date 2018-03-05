#include<stdio.h>
#include<conio.h>

void sort(float a[], int n)
{
	int i,j;
	float t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}

int main()
{
	FILE *fp,*fks,*fcs;
	float r[200],dp[200],dm[200],Xo,Do,Dt=5.25,Xt=16.9,sum=0.0,cl=0.0,cu=0.1,lp,lm;
	int x[200],i,j,n,Oi[10]={0},Ei[10],m=101;

	fp=fopen("rand.txt","w");
	printf("\n\tEnter no of random numbers needed :- ");
	scanf("%d",&n);
	printf("\n\tEnter seed values r[0] and r[1] :- ");
	scanf("%f %f",&r[0],&r[1]);

	x[0]=r[0]*100;
	x[1]=r[1]*100;
	fprintf(fp,"%.2f %.2f ",r[0],r[1]);

    printf("\n\n\tThe random numbers are :- \n");
    printf("\n\t\t%.2f ",r[0]);
    printf("\n\t\t%.2f ",r[1]);

	for(i=2;i<n;i++)
	{
		x[i]=((x[i-1]+x[i-2])%m);
        r[i]=(float) x[i]/100;
		printf("\n\t\t%.2f ",r[i]);
		fprintf(fp,"%.2f ",r[i]);
	}
	fclose(fp);


	if(n<20)
	{
		fks=fopen("ks.txt","w");

		sort(r,n);

		for(i=1;i<=n;i++)
        {
            dp[i-1]=(i/n)-r[i];
            if(dp[i]<0)
			{
			    dp[i]=0;
            }

            dm[i-1]=r[i]-((i-1)/n);
            if(dm[i]<0)
            {
                dm[i]=0;
            }
        }

			lp=dp[0];
            lm=dm[0];


        lp=dp[0];
        lm=dm[0];

        for(i=0;i<n;i++)
        {
            if(dp[i]>lp)
            {
                lp=dp[i];
            }

            if(dm[i]>lm)
            {
                lm=dm[i];
            }
        }

        if(lp>lm)
        {
            Do=lp;
        }
        else
        {
            Do=lm;
        }


		printf("\n\n\t\t\tKolmogorov-Smirnov Test\n");
		fprintf(fks,"Kolmogorov-Smirnov Test\n");

        printf("\n\tS.N\tArray\t\tD+\t\tD-\n");
        for(i=0;i<n;i++)
        {
            printf("\n\t%d\t%f\t%f\t%f",i+1,r[i],dp[i],dm[i]);
            fprintf(fks,"\t%d\t%.2f\t%.2f\t%.2f\n",i+1,r[i],dp[i],dm[i]);
        }

        printf("\n\n\tD0 = Maximum of (D+ and D-) = Maximum of (%f and %f) = %f",lp,lm,Do);
		fprintf(fks,"\n\n\tD0 = Maximum of (D+ and D-) = Maximum of (%f and %f) = %f",lp,lm,Do);

		printf("\n\n\tDt= %.2f",Dt);
		fprintf(fks,"\n\n\tDt= %.2f",Dt);

		if(Do<=Dt)
		{
			printf("\n\nSince %.2f <= %.2f,the generated random values are uniformly distributed.", Do, Dt);
			fprintf(fks,"\n\nSince %.2f <= %.2f,the generated random values are uniformly distributed.", Do, Dt);
		}
		else
		{
			printf("\n\nSince %.2f > %.2f,the generated random values are not uniformly distributed.", Do, Dt);
			fprintf(fks,"\n\nSince %.2f > %.2f,the generated random values are not uniformly distributed.", Do, Dt);
		}

		fclose(fks);
	}

	else
	{
		fcs=fopen("cs.txt","w");

		for(i=0;i<10;i++)
		{
		    Ei[i]=n/10;
		}

		for(i=0;i<n;i++)
		{
			if(r[i]>=0.0&&r[i]<=0.1)
				Oi[0]++;
			else if(r[i]>0.1&&r[i]<=0.2)
				Oi[1]++;
			else if(r[i]>0.2&&r[i]<=0.3)
				Oi[2]++;
			else if(r[i]>0.3&&r[i]<=0.4)
				Oi[3]++;
			else if(r[i]>0.4&&r[i]<=0.5)
				Oi[4]++;
			else if(r[i]>0.5&&r[i]<=0.6)
				Oi[5]++;
			else if(r[i]>0.6&&r[i]<=0.7)
				Oi[6]++;
			else if(r[i]>0.7&&r[i]<=0.8)
				Oi[7]++;
			else if(r[i]>0.8&&r[i]<=0.9)
				Oi[8]++;
			else
				Oi[9]++;
		}

		for(i=0;i<10;i++)
		{
			sum=sum+(Oi[i]-Ei[i])*(Oi[i]-Ei[i]);
		}

		Xo=(float) sum/Ei[0];

		printf("\n\n\t\t\tChi Square Test\n");
		fprintf(fcs,"Chi Square Test\n");

		printf("i  class      Oi[i]  Ei[i]  (Oi[i]-Ei[i])^2  (Oi[i]-Ei[i])^2/Ei\n");
		fprintf(fcs,"i  class      Oi[i]  Ei[i]  (Oi[i]-Ei[i])^2  (Oi[i]-Ei[i])^2/Ei\n");

		for(i=0;i<10;i++)
		{
			printf("%d  %.1f-%.1f\t%d\t%d\t%d\t\t%.2f\n",i+1,cl,cu,Oi[i],Ei[i],(Oi[i]-Ei[i])*(Oi[i]-Ei[i]),(float)((Oi[i]-Ei[i])*(Oi[i]-Ei[i]))/Ei[0]);
			fprintf(fcs,"%d  %.1f-%.1f\t%d\t%d\t%d\t\t%.2f\n",i+1,cl,cu,Oi[i],Ei[i],(Oi[i]-Ei[i])*(Oi[i]-Ei[i]),(float)((Oi[i]-Ei[i])*(Oi[i]-Ei[i]))/Ei[0]);
			cl=cl+0.1;
			cu=cu+0.1;
		}

		printf("\n\nXo= %.2f",Xo);
		fprintf(fcs,"\n\nXo= %.2f",Xo);

		printf("\nXt= %.2f",Xt);
		fprintf(fcs,"\nXt= %.2f",Xt);

		if(Xo<=Xt)
		{
			printf("\n\nSince %.2f <= %.2f,the generated random values are uniformly distributed.", Xo, Xt);
			fprintf(fcs,"\n\nSince %.2f <= %.2f,the generated random values are uniformly distributed.", Xo, Xt);
		}

		else
		{
			printf("\n\nSince %.2f > %.2f,the generated random values are not uniformly distributed.", Xo, Xt);
			fprintf(fcs,"\n\nSince %.2f > %.2f,the generated random values are not uniformly distributed.", Xo, Xt);
		}

		fclose(fcs);
	}
	getch();
}


