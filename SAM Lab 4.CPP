#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
	struct date d;
	FILE *fp;
	int yr,j,n;
	float Y,G,T,I,C;
	clrscr();
	getdate(&d);
	yr=d.da_year;
	printf("Enter no. of years to simulate:");
	scanf("%d",&n);
	printf("Enter National income for %d: ", yr-1);
	scanf("%f",&Y);
	printf("Enter Expected National expenditure for %d: ", yr);
	scanf("%f",&G);
	clrscr();
	fp=fopen("nat_eco","w");
	printf(".::Distributed Lag Model::.\n");
	printf("\nNational Economy Simulation for %d years\n",n);
	printf("National Income for %d: %.2f\n",yr-1,Y);
	printf("Expected National Expenditure of %d: %.2f\n",yr,G);
	printf("Simulation Results for %d Years\n",n);
	printf("SN\tYear\tY\tG\tT\tI\tC\n");
	fprintf(fp,".::Distributed Lag Model::.\n");
	fprintf(fp,"\nNational Economy Simulation for %d years\n",n);
	fprintf(fp,"National Income for %d: %.2f\n",yr-1,Y);
	fprintf(fp,"Expected National Expenditure of %d: %.2f\n",yr,G);
	fprintf(fp,"Simulation Results for %d Years\n",n);
	fprintf(fp,"SN\tYear\tY\tG\tT\tI\tC\n");
	for(j=1;j<=n;j++)
	{
		T=0.2*Y;
		I=2+0.1*Y;
		C=20+0.7*(Y-T);
		Y=G+I+C;
		printf("%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",j,yr,Y,G,T,I,C);
		fprintf(fp,"%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",j,yr,Y,G,T,I,C);
		G=G+5;
		yr=yr+1;
	}
	fclose(fp);
	getch();
}





