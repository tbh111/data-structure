#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100010;

std::vector<int> ans,temp;
int k,x,n;
int maxSquare = -1;
int A[maxn];

void DFS(int index,int nowK,int sum,int square){
	if(nowK == k && sum == x){
		if(square>maxSquare){
			maxSquare = square;
			ans = temp;
		}
		return;
	}
	if(index == n || nowK > k || sum>x)
		return;
	temp.push_back(A[index]);
	DFS(index+1,nowK+1,sum+A[index],square+A[index]*A[index]);
	temp.pop_back();
	DFS(index+1,nowK,sum,square);

}
int main(){

}