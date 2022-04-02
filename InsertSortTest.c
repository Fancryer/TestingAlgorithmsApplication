#include<stdio.h>

int InSSort(int*,int);
int PrintArr(int*,int,_Bool);

int main()
{
	int arr[]={5,-3,2,7,1,0};
	int len=sizeof(arr)/sizeof(*arr);
	PrintArr(arr,len,1);
	InSort(arr,len);
	PrintArr(arr,len,0);
	return 0;
}

int InSSort(int* arr,int len)
{
	if(!arr||len<1)return -1;
	int i=1,j,k;
	while(1)
	{
		k=arr[i];
		j=i-1;
		while(j>-1&&arr[j]>k)
		{
			arr[j+1]=arr[j--];
		}
		arr[j+1]=k;
		if(!(++i^len))break;
	}
	return 0;
}

int PrintArr(int* arr,int len,_Bool endl)
{
	if(!arr||len<1)return -1;
	for(int i=0;i<len;++i)printf("%d ",arr[i]);
	if(endl)printf("\n");
	return 0;
}
