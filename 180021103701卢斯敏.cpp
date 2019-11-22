#include <iostream> 

using namespace std;
void MatrixChain(int *p,int n,int m[7][7],int s[7][7])
{//p为矩阵维数，n为矩阵个数，
//二维数组m的最优解，二维数组s记录断开位置 
	for(int i=1;i<=n;i++){
		m[i][i]=0;//填对角线，初始化为0 
	}
	for(int r=2;r<=n;r++){//r为段长
		for(int i=1;i<=n-r+1;i++){//i是段的起点 
			int j=i+r-1;//j是段的终点 
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;//在i处断开，初始化 
			for(int k=i+1;k<j;k++){//在k处分裂，遍历各种k的情况 
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){//如果当前方案更好，则刷新m[i][j]的记录 
					m[i][j]=t;
					s[i][j]=k;
				}
			}    
		}
	}
}

//找出s数组中记录的最优断开位置
//输出计算A[i][j]的最优计算次序 
void Traceback(int i,int j,int s[7][7])
{
		if(i==j)
		   return;
		Traceback(i,s[i][j],s);//调用函数 
		Traceback(s[i][j]+1,j,s);//调用函数 
		cout<<"Multiply A"<<i<<","<<s[i][j];
		cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;//输出最优计算次序 
		
}

int main() {
   
    int p[ ] = {30,35,15,5,10,20,25};// 输入矩阵维数 
    int n=6;
    int m[7][7];
    int s[7][7];
    MatrixChain(p, n, m, s);//调用函数 
    Traceback(1, 6, s);//调用函数 
}




