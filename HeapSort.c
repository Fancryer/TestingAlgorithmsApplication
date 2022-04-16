#include<stdio.h>
#include<stdlib.h>

//int GetParentIndex(int ChildIndex){return ChildIndex/2;}
//int GetLeftChildIndex(int ParentIndex){return ParentIndex*2;}
//int GetRightChildIndex(int ParentIndex){return ParentIndex*2+1;}

int* CreatePyramid(int*,int);
int Pyramid2Array(int*,int*);

int SiftUp(int*);
int SiftDown(int* pyr);

int Add2PyrTail(int* pyr,int val,int* inclen)
{
	realloc(pyr,(pyr[0]+1)*sizeof(int));
	pyr[pyr[0]++-1]=val;++*inclen;
}

int swap(int* a,int* b){int tmp=*a;*a=*b;*b=tmp;}

int main()
{
	//printf("%d %d",GetLeftChildIndex(5),GetRightChildIndex(5));
	int arr[]={7,3,14,2,-1,5};
	int arrlen=sizeof(arr)/sizeof(*arr);
	int* darr=(int*)calloc(8,sizeof(int));for(int i=0;i<6;i++)darr[i]=arr[i];
	int* pyr=CreatePyramid(arr,arrlen);
	int pyrlen=arrlen+1;
	printf("Default array: | ");for(int i=1;i<pyrlen;++i)printf("%d ",pyr[i]);
	printf("|\n\nCreated pyramid: | ");for(int i=1;i<pyrlen;++i)printf("%d ",pyr[i]);
	SiftUp(pyr);
	printf("|\n\nUp-sifted pyramid: | ");for(int i=1;i<pyrlen;++i)printf("%d ",pyr[i]);
	Add2PyrTail(pyr,90,&arrlen);Add2PyrTail(pyr,-2,&arrlen);
	SiftDown(pyr);
	printf("|\n\nDown-sifted pyramid with 2 new elems: | ");for(int i=1;i<=pyr[0];++i)printf("%d ",pyr[i]);
	Pyramid2Array(pyr,darr);
	printf("|\n\nSorted array: |");
	for(int i=0;i<arrlen-1;++i)printf("%d ",darr[i]);
	printf("|");
	free(pyr);
	return 0;
}

int SiftUp(int* pyr)
{
	for(int i=2;i<pyr[0]+1;++i)
	{
		if(pyr[i/2]<pyr[i])swap(&pyr[i],&pyr[i/2]);
	}
	return 0;
}

int SiftDown(int* pyr)
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
		if(i!=Pyramid[0])
		{
			Pyramid[i]=arr[i-1];
			if(i*2<=pyrlen)
			{
				Pyramid[i*2]=arr[i];Pyramid[0]=i+2;
			}
			if(i*2+1<=pyrlen)
			{
				Pyramid[i*2+1]=arr[i+1];Pyramid[0]=i+2;
			}
		}
	}
	return Pyramid;
}

int Pyramid2Array(int* pyr,int* arr)
{
	int i=0;
	while(pyr[0])
	{
		arr[i++]=pyr[1];
		//printf("\n[%d]\n",pyr[1]);
		swap(&pyr[1],&pyr[pyr[0]]);
		SiftDown(pyr);
		--pyr[0];
	}
}
