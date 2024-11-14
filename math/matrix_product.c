#include<stdio.h>

void matrix_product(int n,int m,int k,double A[n][m],double B[m][k],double result[n][k]);//行列積計算
void input(int n,int m,double A[n][m]); //行列入力
void init(int n,int m,double A[n][m]); //行列0初期化
void output(int n,int m,double result[n][m]); //行列出力

int main(void)
{
  int n,m,k; //N*M行列 * M*K行列 -> N*K行列
  printf("input n,m,k: \n");
  scanf("%d%d%d",&n,&m,&k);
  
  //A*B = result
  double A[n][m];
  double B[m][k];
  double result[n][k];

  printf("A: \n");
  input(n,m,A);

  printf("B: \n");
  input(m,k,B);
  
  init(n,k,result);

  matrix_product(n,m,k,A,B,result);

  output(n,k,result);
}

void matrix_product(int n,int m,int k,double A[n][m],double B[m][k],double result[n][k])
{
  for(int i=0;i<n;i++)
    {
      for(int l=0;l<k;l++)
	{
	  for(int j=0;j<m;j++)
	    {
	      result[i][l]+=A[i][j]*B[j][l];
	    }
	}
    }
  
  return;
}

void input(int n,int m,double A[n][m])
{
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
	{
	  printf("input [%d][%d]: ",i,j);
	  scanf("%lf",&A[i][j]);
	}
    }
  return;
}

void init(int n,int k,double result[n][k])
{
  for(int i=0;i<n;i++)
    {
      for(int k=0;k<n;k++)
	{
	  result[i][k]=0;
	}
    }
  return;
}

void output(int n,int m,double result[n][m])
{
  printf("result: \n");
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
	{
	  printf("[%d][%d]= %lf\n",i,j,result[i][j]);
	}
    }
}
