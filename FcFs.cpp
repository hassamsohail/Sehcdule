#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
int initalvalueofcpu = 0;
int indexmin[4];
string process[4] = {"p1", "p2", "p3", "p4"};
int arrival_Time[4] = {0, 1, 5, 6};
int Burst_Time[4] = {2, 2, 3, 4};
int Complete_Time[4];
int TurnAround_Time[4];
int Waiting_Time[4];
void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void Findingindex(int SecondArival[], int arrival_Time[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int K = 0; K < 4; K++)
        {
            if (SecondArival[i] == arrival_Time[K])
            {
                indexmin[i] = K;
            }
        }
    }
}
void FindCompleteTime(int SecondArival[])
{
    for (int i = 0; i < 4;)
    {
        if (initalvalueofcpu == arrival_Time[indexmin[i]] || initalvalueofcpu >= arrival_Time[indexmin[i]])
        {
            initalvalueofcpu = initalvalueofcpu + Burst_Time[indexmin[i]];
            Complete_Time[indexmin[i]] = initalvalueofcpu;
            i++;
        }
        else
        {

            initalvalueofcpu++;
        }
    }
}
void Display(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        /* code */
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void FindTurnaroundTime()
{
    for (int i = 0; i < 4; i++)
    {
        /* code */
        TurnAround_Time[i] = Complete_Time[i] - arrival_Time[i];
    }
}
void FindWaitingTime()
{
    for (int i = 0; i < 4; i++)
    {
        /* code */
        Waiting_Time[i] = TurnAround_Time[i] - Burst_Time[i];
    }
}
void DisplayFinal()
{  
    cout<<setw(13)<<"Process"<<setw(13)<<"Arival_Time"<<setw(13)<<"Burst_Time"<<setw(13)<<" Complete_Time"<<setw(13)<<" Turnaround TIme"<<setw(13)<<"Waiting Time"<<setw(13)<<endl;
    for (int i = 0; i < 4; i++)
    {
    cout<<process[i]<<setw(10)<<arrival_Time[i]<<setw(10)<<Burst_Time[i]<<setw(13)<<Complete_Time[i]<<setw(13)<<TurnAround_Time[i]<<setw(13)<<Waiting_Time[i]<<setw(13)<<endl;
        
    }
}
int main()
{
    int SecondArival[4];
    for (int i = 0; i < 4; i++)
    {
        SecondArival[i] = arrival_Time[i];
    }
    selectionSort(SecondArival, 4);
    Findingindex(SecondArival, arrival_Time);
    FindCompleteTime(SecondArival);
    FindTurnaroundTime();
    FindWaitingTime();
    DisplayFinal();
}