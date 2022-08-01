//code here




































































































#include <iostream>
using namespace std;


void turn_arround_time(int n, int process[], int a_t[],  int b_t[], int comp_time[])
{
   int t_a_t[n];
   for(int i = 0; i < n; i++)
      {
         t_a_t[i] = comp_time[i] - a_t[i];
      }
    
    int wait_time[n];
    for(int i = 0; i < n; i++)
      {
         wait_time[i] = t_a_t[i] - b_t[i];
      }
    
       cout<<"\nProcesses \tArrival time \tBurst time \tComplete time \tTurn A.time \twait time : \n";
        for(int i = 0; i < n; i++)
           {
             cout<<process[i]<<"\t\t"<<a_t[i]<<"\t\t"<<b_t[i]<<"\t\t"<<comp_time[i]<<"\t\t"<<t_a_t[i]<<"\t\t"<<wait_time[i]<<endl;
            
           }
} 





void complete_time(int n, int process[], int a_t[], int b_t[])
{
    int max;
    max = a_t[0];
    for(int i = 0; i < n; i++)
       {
          if(max < a_t[i])
            {
             max = a_t[i];
            }
       }
    
    int comp_time[n];
    int sum = 0, number;
    bool check = false;
     for(int i = 0; i <= max; i++)
        {
           for(int k = 0; k < n; k++)
              {
                 if(i == a_t[k])
                 {
                   sum = sum + b_t[k];
                   comp_time[k] = sum;
                   number = comp_time[k];
                 }
                 else
                 {
                    check = true;
                 }
                 
              } 
            if(check == true)
            {
               if(i >= number)
               sum = sum + 1;
            }
            check = false;
        }
        
        
 
        turn_arround_time(n, process, a_t, b_t, comp_time);        

}



int main()
{
   int process[] = { 1, 2, 3, 4, 5};
   int n;
   n = sizeof process / sizeof process[0];
   int arrival_time[] = { 3, 5, 0, 5, 4};
   int burst_time[] = { 4, 3, 2, 1, 3};
    
    complete_time( n, process, arrival_time, burst_time);
}