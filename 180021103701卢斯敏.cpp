#include <iostream> 

using namespace std;
void MatrixChain(int *p,int n,int m[7][7],int s[7][7])
{//pΪ����ά����nΪ���������
//��ά����m�����Ž⣬��ά����s��¼�Ͽ�λ�� 
	for(int i=1;i<=n;i++){
		m[i][i]=0;//��Խ��ߣ���ʼ��Ϊ0 
	}
	for(int r=2;r<=n;r++){//rΪ�γ�
		for(int i=1;i<=n-r+1;i++){//i�Ƕε���� 
			int j=i+r-1;//j�Ƕε��յ� 
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;//��i���Ͽ�����ʼ�� 
			for(int k=i+1;k<j;k++){//��k�����ѣ���������k����� 
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){//�����ǰ�������ã���ˢ��m[i][j]�ļ�¼ 
					m[i][j]=t;
					s[i][j]=k;
				}
			}    
		}
	}
}

//�ҳ�s�����м�¼�����ŶϿ�λ��
//�������A[i][j]�����ż������ 
void Traceback(int i,int j,int s[7][7])
{
		if(i==j)
		   return;
		Traceback(i,s[i][j],s);//���ú��� 
		Traceback(s[i][j]+1,j,s);//���ú��� 
		cout<<"Multiply A"<<i<<","<<s[i][j];
		cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;//������ż������ 
		
}

int main() {
   
    int p[ ] = {30,35,15,5,10,20,25};// �������ά�� 
    int n=6;
    int m[7][7];
    int s[7][7];
    MatrixChain(p, n, m, s);//���ú��� 
    Traceback(1, 6, s);//���ú��� 
}




