#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
class Sudoku
{
	public:
	void giveQuestion(); //創造一個數獨
	void readIn(); //讀取一個數獨宮格
	void print(int arr[9][9]);
	bool check(int a[9][9],int i,int j,int k);
	int Sudo(int arr[9][9],int n);
	void solve(); //判斷讀取的數獨是否能解並解開
	void changeNum(int a,int b);//整個題目的任兩數字完全對調
	void changeRow(int a,int b);//換三個九宮格的一整行
	void changeCol(int a,int b);//換三個九宮格的一整列
	void rotate(int n);//將數獨順時針轉90*n度
	void flip(int n);//n=0 垂直翻轉 n!=0 水平翻轉
	void transform(); //印出變換的數獨題目
	int temp[9][9];
	private:
	int i,j,k,n,t,l,num;
	int re;
	int result;
	int arr[9][9],b[9][9];
};	
