#include<stdio.h>
struct job
{
    int job_name, arrival, waiting, turntime, prio, burstcopy, bursttime;
}
queue_1[10], queue_2[10];
int main()
{	struct job temp;
   	int i,time=0,x,z,b=0,largest,totaljob,c=0,k,pf2=0,totaljob2,n,position,j,f=0,y;
float waitingtime=0,turnaround= 0,average_waiting_time,average_turnaround;
printf("\n Please enter the total number of processes you want to have (enter a number):\t");
    	scanf("%d", &totaljob);
   	n=totaljob;
    for(i=0;i<totaljob;i++)
    {
    	printf("\nPlease name the process (enter a number):\t");
        	scanf("%d",&queue_1[i].job_name);
        	printf("\nPlease enter the details for processor %d:\n\t",queue_1[i].job_name);
        	printf("Please enter the arrival time of this process:\t");
        	scanf("%d",&queue_1[i].arrival);
        	printf("Please enter the burst time of this process:\t");
        	scanf("%d",&queue_1[i].bursttime);
        	queue_1[i].burstcopy=queue_1[i].bursttime;
        	printf("Please enter the priority of this process:\t");
        	scanf("%d",&queue_1[i].prio);
}
    	printf("\nPlease enter the Time Quantum for fixed priority queue processes:");
    	scanf("%d",&x);
    	printf("\nPlease enter the Time Quantum for round robin queue processes:");
    	scanf("%d",&z);
    	printf("\n\n\tThe Process\t|\tThe Turnaround Time\t|\tThe Waiting Time\n\n");
    for(i=0;i<totaljob;i++)
    {
        	position=i;
        	for(j=i+1;j<totaljob;j++)
        	{
            	if(queue_1[j].arrival<queue_1[position].arrival)
                	position=j;
        	}
        	temp=queue_1[i];
        	queue_1[i]=queue_1[position];
        	queue_1[position]=temp;
    }
    	time=queue_1[0].arrival;
    for(i=0;totaljob!=0;i++)
    {
    	while(c!=x)
    	{
    		c++;
    		if(queue_1[i].arrival<=time)
    		{
    			for(j=i+1;j<totaljob;j++)
    			{
    			if(queue_1[j].arrival==time && queue_1[j].prio<queue_1[i].prio)
    				{
    					queue_2[pf2]=queue_1[i];
						pf2++;
    					for(k=i; k<totaljob-1;k++)
    						queue_1[k]=queue_1[k+1];
    					totaljob--;
						c=0;
    					i=j-1;
    					j--;
				}
			}
		}
		time++;
		queue_1[i].bursttime--;
		if(queue_1[i].bursttime==0)
		{
			queue_1[i].turntime=time-queue_1[i].arrival;
			queue_1[i].waiting=queue_1[i].turntime-queue_1[i].burstcopy;
printf("\t\t%d\t|\t\t%d\t\t|\t\t%d\n",queue_1[i].job_name,queue_1[i].turntime,queue_1[i].waiting);
			waitingtime+=time-queue_1[i].waiting; 
    			turnaround+=time-queue_1[i].turntime;
    			for(k=i;k<totaljob-1;k++)
    				queue_1[k]=queue_1[k+1];i--;
    			totaljob--;
				c=x;break;
			}
		}
		c=0;
		if(queue_1[i].bursttime!=0)
		{
			queue_2[pf2]=queue_1[i];
			pf2++;
			for(k=i;k<totaljob-1;k++)
    			queue_1[k]=queue_1[k+1];
    		totaljob--;
		}
			if(i==totaljob-1)
				i=-1;
	}
	
	totaljob2 = pf2;
	for(c=0;totaljob2!=0;) 
	{ 
		if(queue_2[c].bursttime<=z&&queue_2[c].bursttime>0) 
    		{ 
    			time+=queue_2[c].bursttime; 
    			queue_2[c].bursttime=0; 
    			f=1; 
    		} 
    	else if(queue_2[c].bursttime>0) 
    	{ 
    		queue_2[c].bursttime-=z; 
    		time+=z; 
    	} 
    	if(queue_2[c].bursttime==0 && f==1) 
    	{ 
    		totaljob2--; 
    		queue_2[c].turntime=time-queue_2[c].arrival;
		queue_2[c].waiting=queue_2[c].turntime-queue_2[c].burstcopy; 
	printf("%d\t|\t%d\t|\t%d\n",queue_2[c].job_name,queue_2[c].turntime,queue_2[c].waiting); 
    		turnaround+=time-queue_2[c].arrival; 
    		waitingtime+=time-queue_2[c].arrival-queue_2[c].burstcopy;
    		for(k=c; k<totaljob2;k++)
    			queue_2[k]=queue_2[k+1];c--;
    		f=0; 
    	} 

    	if(c==totaljob2-1) 
      		c=0; 
    	else 
    		c++; 
    	}
    	printf("\nThe Average Waiting Time is = %f\n", waitingtime/n); 
    	printf("The Average Turnaround Time is = %f" ,turnaround/n);   
}

