#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void show(char arr[][3]);
int checking(char arr[][3],char ch);
int main()
{ 
  system("color 02");
    int k=1,ce,po,g,F=0;
    char ch,arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}},name1[30],name2[30];
    cout<<"\n\n\nRUELS:\tYOU CAN PLAY TIC-TAC-TOE GAME AFTER PUTTING POSITION IN MATRIX AS FLOWING \n\t SAME POSITIONS WILL NOT BE TAKEN\n\n";
    show(arr);
    do{
    cout<<"\n\n\t\t~PRESS 1 FOR PLAY WITH COMPUTER\n\t\t ~PRESS 2 FOR 2 PLAYERS";
    cout<<"\n\n\t\t*ENTER YOUR CHOICE PLAY WITH->";
    cin>>g;
    if(g==1)
    {
    cout<<"\n\n\t\tPLEASE ENTER YOUR NAME ->";
    cin>>name2;
    F=1;
    }
    else if(g==2){
      cout<<"\n\n\t\tPLEASE ENTER PLAYER 1 NAME->";
      cin>>name1;
      cout<<"\n\n\t\tPLEASE ENTER PLAYER 2 NAME ->";
      cin>>name2;
      F=1;
    }
    else
    cout<<"\t\tWARNING! ENTER CORRECT CHOICE OTHER ";
    }while(F==0);
    while(k<10)
    {
      if(g==2)
      {    
      (k%2)?cout<<"\t\t"<<name1:cout<<"\t\t"<<name2;
        cout<<"  ENTER POSITION(0-9) FOR GAME INPUT ->";
        cin>>po;
      }
      else
      {
        if(k%2)
        {
          cout<<"\t\t"<<name2<<"   ENTER POSITION(0-9) FOR GAME INPUT ->";
          cin>>po;
        }
        else
        {
             srand(time(0));
             po=rand()%10;
             //cout<<"\n\t\t computer choice place is"<<po<<"\n\n";
        }
      }
       (k%2)?ch=3:ch=30;
         if(po>0&&po<4)
         {
           if(arr[0][po-1]==3||arr[1][po]==30)
           continue;
           else if(po==1)
           arr[0][0]=ch;
           else
           arr[0][po-1]=ch;
         }
         else if(po>3&&po<7)
         {
           if(arr[1][po-4]==3||arr[1][po-4]==30)
           continue;
           else
           arr[1][po-4]=ch;
         }
         else if(po>6&&po<10)
         {
           if(arr[2][po-7]==3||arr[2][po-7]==30)
           continue;
           else
           arr[2][po-7]=ch;
         }
         else
         continue;

         ce=checking(arr,ch);
         show(arr);
          if(ce)
          break;
          k++;
    }
   if(!ce)
   cout<<"\n\t\tMATCH DRAW";
   else
   {
     if(g==1)       
     (k%2)?cout<<"\t\t"<<name2<<" WON THE MATCH":cout<<"\n\t\tYOU ARE LOSER COMPUTER WON THE MATCH";
     else 
     (k%2)?cout<<"\t\t"<<name1<<"  WON THE MATCH":cout<<"\t\t"<<name2<<"  WON THE MATCH";
   }
   return 0;
}
void show(char arr[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    { cout<<"\t\t\t";
        for(j=0;j<3;j++)
        cout<<"  "<<arr[i][j]<<"  ";
        cout<<endl;
    }
    cout<<"\n\t\t____________________________________\n";
}
int checking(char arr[][3],char ch)
{
    for(int i=0;i<3;i++)
  {
    if((arr[i][0]==ch && arr[i][1]==ch) && arr[i][2]==ch)
    {
      arr[i][0]=arr[i][1]=arr[i][2]=22;
     return 1;
    }
    
    if((arr[0][i]==ch && arr[1][i]==ch) && arr[2][i]==ch)
    {
      arr[0][i]=arr[1][i]=arr[2][i]=124;
      return 1;
    }
    
  }
  if(arr[0][0]==ch && arr[1][1]==ch && arr[2][2]==ch)
  {
    arr[0][0]=arr[1][1]=arr[2][2]=92;
    return 1;
  }
  if(arr[0][2]==ch && arr[1][1]==ch && arr[2][0]==ch)
  {
    arr[0][2]=arr[1][1]=arr[2][0]=47;
    return 1;
  }
 return 0;
}
