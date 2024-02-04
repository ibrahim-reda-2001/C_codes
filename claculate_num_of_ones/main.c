#include<stdio.h>
// this function return number of ones in digit number 
int calc_num_of_ones(int num){
	
	int counter =0;
	while(num!=0){
	num&=(num-1);
counter++;	
	}
	return counter;
}

int main(void){
	
	int x;
	printf("Enter the number \n");
		fflush(stdin),fflush(stdout);
	scanf("%d",&x);
	int counter=calc_num_of_ones(x);
	printf("the number of ones equal : %d  \n",counter);
	
	
	
return 0;}