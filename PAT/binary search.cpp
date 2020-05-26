#include<cstdio>
#include<algorithm>
using namespace std;

int binary_search(int A[],int x,int right,int left){
	
	while(left<=right){
		int mid = (right+left)/2;
		if(A[mid]==x)
			return mid;
		else if(A[mid]>x){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return -1;
}
int main(){
	int arr[10] = {34,52,62,14,6,32,63,634,351,1263};
	sort(arr,arr+10);
	printf("%d\n%d\n",binary_search(arr,32,9,0),binary_search(arr,777,9,0));
}