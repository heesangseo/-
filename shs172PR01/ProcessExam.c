#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>
#include<time.h>


int main(){
	int num =0;
	FILE *trace; 
	trace = fopen("trace.txt","w");
	time_t cultime;
	pid_t pid1;


	for(num;num<10;num++){
		pid1=fork(); //make child processor
		if(pid1==0)
			break; //if child processor, go out for loop
		else if(pid1==-1)
			num--; //if fork() is failed, recount
		wait(0);
		printf("Child has fininshed: PID = %d\n",pid1);	 //In parent processor, print child PID
		fprintf(trace,"Child has fininshed: PID = %d\n",pid1);
		
	}
	
	
	if(pid1==0){ //if child processor, print PID of child and Count and PID of parent, Current time
		for(int i=1;i<=100;i++){
			time(&cultime);
			printf("[PID = %d, Count = #%d, PPID = %d] datetime = %s",getpid(),i,getppid(),ctime(&cultime));
			fprintf(trace,"[PID = %d, Count = #%d, PPID = %d] datetime = %s",getpid(),i,getppid(),ctime(&cultime));
		}
	}
	fclose(trace);
	return 0;
}
