#include<stdio.h>
#include<stdlib.h>

#include<math.h>
#include<limits.h>
 int main()
{
 int i,j,n=5,ns=100,f[6]={0},x[100],of[25],ef[25],tf;
 float p=.4,q,u,mx=0,vx=0,am,thvx,pdf[25],tp,chic,chit;
 
 for(i=0;i<ns;i++)
 {
  x[i]=0;
  for(j=0;j<n;j++)
  {
   u=rand()/(float)RAND_MAX;
   if(u<=p)
   x[i]++;
  }
 }
 for(i=0;i<ns;i++)
 {
  mx=mx+x[i];
  vx=vx+x[i]*x[i];
 }
 mx=mx/ns;
 vx=vx/ns-mx*mx;
 printf("Random sample fron binomial(%d,%.2f)",n,p);
 for(i=0;i<ns;i++)
 printf("%d ",x[i]);
 printf("\nMean=%.2f\nVariance=%.2f",mx,vx);
 am=n*p;
 thvx=n*p*(1-p);
 printf("\nTheoretical Variance=%.2f\nTheoretical mean=%.2f",thvx,am);
 scanf("%d",&n);
 for(i=0;i<=n;i++)
  {
   scanf("%d",&x[i]);
   for(i=0;i<n;i++)
   printf("\nFrequency Table\n");
   printf("\n%d\t%d",i,f[i]);
   scanf("%d",&n);
   for(i=0;i<=n;i++);
   scanf("%d",&of[i]);
   tf=am=0;
   for(i=0;i<=n;i++)
   {
    if(tf==of[i])
      am+=of[i];
   }
   am=am/tf;
   p=am/n;
   q=1-p;
   tp=p/q;
   pdf[0]=pow(q,n);
   ef[0]=pdf[0]*tf+0.5;
   for(i=0;i<n;i++)
   {
    pdf[i+1]=(n-i)*tp*pdf[i]/(i+1);
    ef[i+1]=pdf[i+1]*tf+0.5;
   }
   printf("%d%d%d\n",i,of[i],ef[i]);
   for(i=0;i<n;i++)
   scanf("%d%d",&of[i],&ef[i]);
   scanf("%f",&chit);
   chic=0;
   for(i=0;i<n;i++)
   {
    tp=of[i]-ef[i];
    chic=chic+tp*tp/ef[i];
   }
   if(chic<chit)
   printf("ACCEPTED");
   else
   printf("REJECTED");
}
}

