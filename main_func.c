 #include<stdio.h>
   #include<stdlib.h>
   #include<time.h>
   #include "cache_model.h"
  int ipow(int base, int exp)
   {
           int result = 1;
          for (;;)
         {
                 if (exp & 1)
                        result *=base;
                  exp>>=1;
                  if (!exp)
                         break;
                 base *=base;
        }
         return result;
 }
 int printRandoms(int lower, int upper)
  {
 
          int num = (rand() % (upper-lower+1)) + lower;
         return num;
  }
  int main()
  {
          int lower = 0, upper = (ipow(2,16)-1);
          int testing;
          srand(time(0));
          cm_do_access(printRandoms(lower,upper));
          return 0;
  }
                                                                                                                     ~              
