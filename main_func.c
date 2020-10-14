  #include<stdio.h>
  #include<stdlib.h>
  #include<time.h>   
  #include "cache_model.h"
 int printRandoms(int lower, int upper) //Random Number Generator for part A of Q1
  {
 
          int num = (rand() % (upper-lower+1)) + lower;
         return num;
  }
  int main()
  {
          int lower = 0, upper = 65535; //Highest and lowest possible values for memory address
          int testing;
          srand(time(0));
	  cm_disable_cache();  // commented out when performing experiments with cache enabled
	  //cm_enable_cache(); // commented out when perofrming experiments with cache disabled
	  int i;
	  int total=0;
	  int address = 0;
	  int count_11 = 0;
	  int count_1 = 0;
	  int count_17 = 0;
	  for (int i = 0; i<1000; i++)
	  {
	
		int rand = printRandoms(1,100);
		if (rand <= 60) //Simulate probablily of next address following current one 
		{
			address += 1;
		}
		else if ((rand > 61) && (rand <=95)) // Simulate Probability that the next address is not sequential but is within forty words of the current one. 
		{
			address = printRandoms(address,address+80);
		}
		else //Simulates probability that we obtain a random far address
		{
			address = printRandoms(0,65535); // Upper bound of address since we are dealing with sixteen bits.
		}
		address = printRandoms(lower,upper); // This line of code is for part a, when we are dealing with reading random addresses. Commented out for part b
		cm_do_access(address);
		int access = cm_get_last_access_cycles();
		printf("%d",access);
		printf("\n");
		total = total + access; // Sums up the total value (in access cycles), used to calculate expectation value of experiment
		if (access == 1)
		{
			count_1 +=1; // Increments by one every time one access cycle is recorded.

		}
		if(access == 11)
		{
			count_11 +=1; // Increments by one every time eleven access cycles are recorded.
		}
		if(access == 17)
		{
			count_17 +=1; // Increments by one every time seventeen access cycles are recorded.
		}
		//printf("%d",rand);
		//printf("\n");
	  }
	  double av = (double)total;
	  double average = av/1000; // Expectation value of experiment
	  printf("%f",average);
	  printf("\n");
	  printf("# of data values for 1: %d",count_1);//Number of times one access cycle was completed in a trial
	  printf("\n");
	  printf("# of data values for 11: %d",count_11);//Number of times eleven access cycles were completed in a trial.
	  printf("\n");
	  printf("# of data values for 17: %d",count_17);//Number of times seventeen access cycles were completed in a trial.
	  printf("\n");
          return 0;
  }
