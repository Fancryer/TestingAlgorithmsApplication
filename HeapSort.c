#include<stdio.h>
#include<stdlib.h>

int GetParentIndex(int ChildIndex){return ChildIndex/2;}
int GetLeftChildIndex(int ParentIndex){return ParentIndex*2;}
int GetRightChildIndex(int ParentIndex){return ParentIndex*2+1;}

int* CreatePyramid(int*,int);

int SiftUp(int*,int);
int SiftDown();

int Add2PyrTail(int* pyr,int val)
{
	realloc(pyr,(pyr[0]+1)*sizeof(int));
	pyr[pyr[0]++-1]=val;
}

int swap(int* a,int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main()
{
	//printf("%d %d",GetLeftChildIndex(5),GetRightChildIndex(5));
	int arr[]={7,3,14,2,-1,5};
	int arrlen=sizeof(arr)/sizeof(*arr);
	int* pyr=CreatePyramid(arr,arrlen);
	int pyrlen=arrlen+1;
	printf(" | ");
	for(int i=1;i<pyrlen;++i)printf("%d ",pyr[i]);
	SiftUp(pyr,pyrlen);
	printf(" | ");
	for(int i=1;i<pyrlen;++i)printf("%d ",pyr[i]);
	//realloc(pyr,pyr[0]+++1);
	//pyr[pyr[0]-1]=90;++pyr[0];
	Add2PyrTail(pyr,90);
	Add2PyrTail(pyr,-2);
	SiftDown(pyr,pyr[0]);
	printf(" | ");
	for(int i=1;i<pyr[0]-1;++i)printf("%d ",pyr[i]);
	free(pyr);
	return 0;
}

int SiftUp(int* pyr,int len)
{
	for(int i=2;i<len;++i)
	{
		if(pyr[i/2]<pyr[i])swap(&pyr[i],&pyr[i/2]);
	}
	return 0;
}

int SiftDown(int* pyr,int len)
{
	while(1)
	{
		_Bool c=0;
		for(int i=2;i<pyr[0];++i)
		{
			if(pyr[i]>pyr[i/2])
			{
				swap(&pyr[i],&pyr[i/2]);
				c=1;
			}
		}
		if(!c)break;
	}
	return 0;
}

int* CreatePyramid(int* arr,int len)
{
	int pyrlen=len+1;
	int* Pyramid=(int*)calloc(pyrlen,sizeof(int));
	for(int i=1;i<pyrlen;++i)
	{
		printf("%d ",arr[i-1]);
		if(i!=Pyramid[0])
		{
			Pyramid[i]=arr[i-1];
			if(i*2<=pyrlen)Pyramid[i*2]=arr[i];
			if(i*2+1<=pyrlen)Pyramid[i*2+1]=arr[i+1];
			Pyramid[0]=i+2;
		}
	}
	return Pyramid;
}
