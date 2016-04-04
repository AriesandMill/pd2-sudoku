#include"Sudoku.h"
#include<cstdio>
#include<time.h>
using namespace std;
int re=0;
int result=0;
int fu=0;
void Sudoku::giveQuestion()
{
	cout << "3 0 2 0 0 5 6 9 0" << endl;
	cout << "0 4 0 0 9 6 0 3 0" << endl;
	cout << "0 5 0 0 0 8 0 0 0" << endl;
	cout << "1 9 0 0 8 0 7 0 3" << endl;
	cout << "0 0 0 0 0 0 0 0 0" << endl;
	cout << "5 0 7 0 3 0 0 6 1" << endl;
	cout << "0 0 0 8 0 0 0 2 0" << endl;
	cout << "0 8 0 9 6 0 0 7 0" << endl;
	cout << "0 6 5 7 0 0 3 0 9" << endl;
}
void Sudoku::readIn()
{
	cout << "請輸入數字: "<<endl;
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin >> t ;
			arr[i][j]=t;
			temp[i][j]=arr[i][j];
			if(t!=0)
				fu++;
		}
	}
}

void Sudoku::print(int arr[9][9])
{
	 for(int i=0;i<9;i++)
		  {
			    for(int j=0;j<9;j++)
					  {
						     cout<<arr[i][j]<<" ";
							  
							   }
					cout<<endl;
		  }
}
bool Sudoku::check(int arr[9][9],int i,int j,int k)
{
	int m,n;
	  
	  for(n=0;n<9;n++)
		   {
			     if(arr[i][n] == k)
					    return false;
				  }

	   for(m=0;m<9;m++)
		    {
				  if(arr[m][j] == k)
					     return false;
				   }

	    int t1=(i/3)*3,t2=(j/3)*3;
		 for(m=t1;m<t1+3;m++)
			  {
				    for(n=t2;n<t2+3;n++)
						  {
							     if(arr[m][n] == k)
									     return false;
								   }
					 }

		  return true;
}

int Sudoku::Sudo(int arr[9][9],int n)
{
	  int i,j,c,d; 
	  if (re>1)
		    return 2;
	    for(i=0;i<9;i++)
			 {
				   for(j=0;j<9;j++)
					      {
							     temp[i][j]=arr[i][j];
						  }
			 }
		 i=n/9; j=n%9; 
		 if(arr[i][j] != 0) 
		 {
			if(n == 80)  
			{
				re++;
				if(re==1)
			    {
					for(c=0;c<9;c++)
					{
						for(d=0;d<9;d++)
						{
							b[c][d]=temp[c][d]; 
						}	
					}
				}
			 }
			 else    
			Sudo(temp,n+1);
		  }
		     else    
			 {
			    for(int k=1;k<=9;k++)
				{
					bool flag=check(temp,i,j,k);
					if(flag) 
					{
						temp[i][j]=k; 
						if(n == 80)
						{
							re++;
							if(re==1)
							{
								for(c=0;c<9;c++)
								{ 
									for(d=0;d<9;d++)
									{
										b[c][d]=temp[c][d]; 
									}	
								}
							}
						}
					else
					Sudo(temp,n+1);
					temp[i][j]=0; 
			        }   
				}
		      }
		    
}

void Sudoku::solve()
{
	if(fu==2)
	{
		cout << "0" <<endl;
		exit(1);
	}
	if(fu==81)
	{
		cout<<"1"<<endl;
		transform();
		exit(1);
	}
	Sudo(arr,0);
	if(re==1)
	{
		  cout<<re;
		  cout<<endl;
	      print(b);
	}
	  if(re==0)
		    cout<<re;
	   if(re>1)
		   	cout<<re;
	   re=0;
}
void Sudoku::changeNum(int a,int b)
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if (temp[i][j]==a)
				arr[i][j]=b;
			if(temp[i][j]==b)
				arr[i][j]=a;
		}
	}
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			temp[i][j]=arr[i][j];
		}
	}
}

void Sudoku::changeCol(int a,int b)
{
	
	if(a==0&&b==1) for(i=0;i<3;i++) { for(j=0;j<9;j++) {arr[i][j]=temp[i+3][j]; arr[i+3][j]=temp[i][j];}}
	if(a==0&&b==2) for(i=0;i<3;i++) { for(j=0;j<9;j++) {arr[i][j]=temp[i+6][j]; arr[i+6][j]=temp[i][j];}}
	if(a==1&&b==0) for(i=3;i<6;i++) { for(j=0;j<9;j++) {arr[i][j]=temp[i-3][j]; arr[i-3][j]=temp[i][j];}}
	if(a==1&&b==2) for(i=3;i<6;i++) { for(j=0;j<9;j++) {arr[i][j]=temp[i+3][j]; arr[i+3][j]=temp[i][j];}}
	if(a==2&&b==0) for(i=6;i<9;i++) { for(j=0;j<9;j++) {arr[i][j]=temp[i-6][j]; arr[i-6][j]=temp[i][j];}}
	if(a==2&&b==1) for(i=6;i<9;i++) { for(j=0;j<9;j++) {arr[i][j]=temp[i-3][j]; arr[i-3][j]=temp[i][j];}}

}	
void Sudoku::changeRow(int a,int b)
{
	if(a==0&&b==1) for(j=0;j<3;j++) { for(i=0;i<9;i++) {arr[i][j]=temp[i][j+3]; arr[i][j+3]=temp[i][j];}}
	if(a==0&&b==2) for(j=0;j<3;j++) { for(i=0;i<9;i++) {arr[i][j]=temp[i][j+6]; arr[i][j+6]=temp[i][j];}}
	if(a==1&&b==0) for(j=3;j<6;j++) { for(i=0;i<9;i++) {arr[i][j]=temp[i][j-3]; arr[i][j-3]=temp[i][j];}}
	if(a==1&&b==2) for(j=3;j<6;j++) { for(i=0;i<9;i++) {arr[i][j]=temp[i][j+3]; arr[i][j+3]=temp[i][j];}}
    if(a==2&&b==0) for(j=6;j<9;j++) { for(i=0;i<9;i++) {arr[i][j]=temp[i][j-6]; arr[i][j-6]=temp[i][j];}}
 	if(a==2&&b==1) for(j=6;j<9;j++) { for(i=0;i<9;i++) {arr[i][j]=temp[i][j-3]; arr[i][j-3]=temp[i][j];}}
}
void Sudoku::rotate(int n) 
{
	int r=n%4;
	for(l=1;l<=r;l++){
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				temp[i][j]=arr[i][j];
				for(i=0,k=9,t=-1;i<9;i++) 
				{
						k--, t++;
				for(j=0,n=0;j<9;j++)
					{
						arr[n][k] = temp[t][j];
						n++;
					}
				}
					  }
}
void Sudoku::flip(int n)
{
	for (i=0;i<9;i++)
		for (j=0;j<9; j++)
			temp[i][j]=arr[i][j];
		if (n==1)
		for(i=0,k=9,t=-1;i<9;i++) 
		{
			k--, t++;
			if (i==4)	continue;
			for (j=0,n=0;j<9;j++) {
				arr[n][t]=temp[j][k];
				n++;
			}
		}
		if (n == 0)
		for(i=0,k=9,t=-1;i<9;i++) 
		{
			k--, t++;
			if (i==4)	continue;
			for (j=0,n=0;j<9;j++) {
				arr[t][n]=temp[k][j];
				n++;
								  }
		}
		for (i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				temp[i][j]=arr[i][j];
			}
		}
}

void Sudoku::transform()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for (i=0;i<9;i++){
		cout<<endl;
		for (j=0;j<9;j++)
			cout << arr[i][j] << " ";
					 }	
		cout << endl;
} 


