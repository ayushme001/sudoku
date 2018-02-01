/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: AT
 * Sudoku program
 * Created on 29 January, 2018, 10:10 PM
 */


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define N 9

/*
int checkRC(int [][],int, int, int, int);
int checkBC(int [][],int, int, int, int);
void print(int[][]);
*/

int checkRC(int grid[N][N],int x, int y, int v, int flag)
{
    int i,j;
   /* x=x-1;
    y=y-1;*/
    flag=0;
    
            for(i=0;i<N;i++)
            {
                if(grid[x][y]!=0)
                {
                 printf("you cannot enter this value here \n");
                    ++flag;   
                }
                else if(grid[x][i]==v || grid[i][y]==v)
                {
                    printf("you cannot enter this value here \n");
                    ++flag;
                   // break;
                }
                else if(v==0)
                {
                    printf("you cannot enter a zero \n");
                    ++flag;
                    //break;
                    

                }
                if(flag!=0)
                break;
            }
    
            
    
        return flag;
}

 int checkBC(int grid[N][N],int x, int y, int v,int flag)
{
    int a=0,b=0,c=0,d=0,i,j;
    flag=0;
   /* x=x-1;
    y=y-1;*/
    while(a!=0 && b!=0)
    {
        if((x)%3==0)
        {
            a=x-2;
            b=x;
        }
        else if((x+1)%3==0)
        {
            a=x-1;
            b=x+1;
        }
        else if((x+2)%3==0)
        {
            a=x;
            b=x+2;
        }
    }

   

     while(c!=0 && d!=0)
    {
        if((y)%3==0)
        {
            c=y-2;
            d=y;
        }
        else if((y+1)%3==0)
        {
            c=y-1;
            d=y+1;
        }
        else if((y+2)%3==0)
        {
            c=y;
            d=y+2;
        }
    }

    for(i=a;i<=b;i++)
    {
        for(j=c;j<=d;j++)
        {
            if(grid[i][j]==v)
            {
                printf("this value cannot be entered here \n");
                ++flag;
             }
             if(flag!=0)
                break;
        }
        if(flag!=0)
            break;
    }
  return flag;
  }
 
 
 /*void print(int a[N][N])
 {
     int i,j;
     for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                {
                    printf("%d " " ",a[i][j]);

                    if(j%3==0)
                    printf(" | ");
                }       
            printf("\n");
            if(i%3==0)
            printf(" ------------------ ");
    }

 }*/
 
 
void RandomNumberGenerator(const int nMin,const int nMax,const int  nNumOfNumsToGenerate, int *nRandonNumber)
    {
       
        for (int i = 0; i < nNumOfNumsToGenerate; i++)
        {   
            *nRandonNumber = rand()%(nMax-nMin) + nMin;   
        }
      
    }

 
 
 int main()
 {
        int c1=0,c2=0,count=0,flag=0,i,j,v,x,y,p,q,r=0;
                    int grid[N][N] = {0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0,
                                      0,0,0, 0,0,0, 0,0,0};
        srand(time(NULL));
        RandomNumberGenerator(1,6,1,&r);
        //printf("hi");3
        printf("\n%d \n",r);
        
                   
                        int grid1[N][N] ={{0,0,0, 0,0,3, 2,9,0},
                                          {0,8,6, 5,0,0, 0,0,0},
                                          {0,2,0, 0,0,1, 0,0,0},
                                          {0,0,3, 7,0,5, 1,0,0},
                                          {9,0,0, 0,0,0, 0,0,8},
                                          {0,0,2, 9,0,8, 3,0,0},
                                          {0,0,0, 4,0,0, 0,8,0},
                                          {0,4,7, 1,0,0, 0,0,0},
                                          {1,3,0, 0,0,0, 4,0,0}};;

                    
                        int grid2[N][N]= {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
       
                        int grid3[N][N]={{0, 0, 4, 0, 0, 0, 6, 3, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {5, 0, 0, 0, 0, 0, 0, 9, 0},
                                        {0, 0, 0, 5, 6, 0, 0, 0, 0},
                                        {4, 0, 3, 0, 0, 0, 0, 0, 1},
                                        {0, 0, 0, 7, 0, 0, 9, 0, 0},
                                        {3, 0, 0, 1, 0, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 2, 0, 0, 4, 1, 0}};

                        int grid4[N][N]={{1, 2, 3, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 1, 2, 3},
                                               {0, 0, 0, 1, 2, 3, 0, 0, 0},
                                               {2, 3, 1, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 2, 3, 1},
                                               {0, 0, 0, 2, 3, 1, 0, 0, 0},
                                               {3, 1, 2, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 0, 0, 0, 3, 1, 2},
                                               {0, 0, 0, 3, 1, 2, 0, 0, 0}};

       
                        int grid5[N][N]={ { 0, 0, 0, 0, 0, 0, 0, 1, 2 },
                                         { 0, 0, 0, 0, 3, 5, 0, 0, 0 },
                                         { 0, 0, 0, 6, 0, 0, 0, 7, 0 },
                                         { 7, 0, 0, 0, 0, 0, 3, 0, 0 },
                                         { 0, 0, 0, 4, 0, 0, 8, 0, 6 },
                                         { 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                                         { 0, 0, 0, 1, 2, 0, 0, 0, 0 },
                                         { 0, 8, 0, 0, 0, 0, 0, 4, 0 },
                                         { 0, 5, 0, 0, 0, 0, 6, 0, 0 } };
                        
                        int grid6[N][N]={{3, 1, 6, 5, 7, 8, 4, 9, 2},
                                        {5, 2, 9, 1, 3, 4, 7, 6, 8},
                                        {4, 8, 7, 6, 2, 9, 5, 3, 1},
                                        {2, 6, 3, 4, 1, 5, 9, 8, 7},
                                        {9, 7, 4, 8, 6, 3, 1, 2, 5},
                                        {8, 5, 1, 7, 9, 2, 6, 4, 3},
                                        {1, 3, 8, 9, 4, 7, 2, 5, 6},
                                        {6, 9, 2, 3, 5, 1, 8, 7, 4},
                                        {0, 4, 5, 2, 8, 6, 3, 1, 9}};

                        
                        //r=6;
        if(r==1)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    grid[i][j]=grid1[i][j];
                }
            }
        }
        else if(r==2)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    grid[i][j]=grid2[i][j];
                }
            }
        }
        else if(r==3)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    grid[i][j]=grid3[i][j];
                }
            }
        }
        else if(r==4)
        {
        for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    grid[i][j]=grid4[i][j];
                }
            }    
        }
        else if(r==5)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    grid[i][j]=grid5[i][j];
                }
            }
        }
        else if(r==6)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    grid[i][j]=grid6[i][j];
                }
            }
        }
                        
        do
        {
            count=0;
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    printf("%3d",grid[i][j]);
                    if(grid[i][j]==0)
                        count++;
                }
                printf("\n");
            }
            if(count!=0)
            {
                printf("enter place to enter value - ");
                scanf("%d%d",&x,&y);
                printf("enter value - ");
                scanf("%d",&v);
                /*p=x;
                q=y;
                */
                --x;
                --y;

                c1=checkRC(grid,x,y,v,flag);
                c2=checkBC(grid,x,y,v,flag);
                
                
                       

                if(c1==0 && c2==0)
                {
                    
                    grid[x][y]=v;
                    ++x;
                    ++y;
                   
                }
            
            }
        }while(count!=0);
        
        printf("\n     congratulation!!! \n\n");
        /*for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    printf("%3d",grid[i][j]);
                    
                    
                }
                printf("\n");
            }*/
           // print(grid);
 
 
    return (0);
}

 
