#include<stdio.h>
int main(){

	int i , n , tq , t=0,completed=0;
printf("Enter the number of processes :");
scanf("%d",&n);

	int at[n],bt[n],wt[n],tat[n],rt[n];

for(i=0;i<n;i++){
printf("ENter the time of Arriveal and the time of the BURST P%d :" , i+1 );
	scanf("%d %d",&at[i],&bt[i]);
	rt[i]=bt[i];
} 	
printf("Enter the Qantum Number");
scanf("%d",&tq);


while(completed != n){
int done=1;
for (i=0;i<n;i++){
if(at[i] <=t && rt[i] >0){
done=0;
if(rt[i] > tq){
t += tq;
rt[i] -= tq;
}

else {
		t += rt[i];
		tat[i]= t-at[i];
		wt[i]=tat[i]-bt[i];
		rt[i]=0;
		completed ++;

}


}
}
if(done) 
t++;
}

printf("\nP\tAT\tBT\tWT\tTAT\n");
for(i=0 ; i<n ; i++)
printf("\nP%d\t%d\t%d\t%d\t%d\n " , i+1,at[i],bt[i],wt[i],tat[i]);

return 0;
}
