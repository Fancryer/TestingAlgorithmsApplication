#include<stdio.h>
#include<stdlib.h>

/*
This function "consumes" pointers
to the start and the end of array
*/
void QsortIter(int*,int);

//void Qsort(int*,int,int);

void part(int*,int,int);
void swap(int* a,int* b){int t=*a;*a=*b;*b=t;}

typedef struct Walls
{
	
}Walls;

int main()
{
	int a=6;
	int arr[]={5,0,-1,3,2,8,4,-90,12,0,-891,7};                                                                   
	int len=sizeof(arr)/sizeof(*arr);
	QsortIter(arr,len);
	for(int i=0;i<len;++i)printf("%d ",arr[i]);
	//part(arr,0,len);
 	return 0;
}

void QsortIter(int* arr,int size)  //int beg, int end)
{
    int i,j,tmp,sep,ptr,beg=0,end=size/2,l=0,r=0;
    int tmp_e[size],e=0;tmp_e[e++]=end;
    int tmp_b[size],b=0;tmp_b[b++]=0;
    while(1)
    {
    	if(e<size/2||b<size/2)
    	{
	    	if(tmp_e[e]-tmp_b[b]>3)
	    	{
	    		tmp_e[e++]=tmp_e[e]/2;
			}
		}
	}
}

/*
void Qsort(int* start,int* end)
{
	if(end-start)return;
	int* tmp=start;
	for(;tmp-1!=end;++tmp)printf("%d ",*tmp);
	int LI=end-start;
	printf("\nLast Index=%d\n",LI);
	Qsort(start,start[LI/2]);
	Qsort(start[LI/2+1],start[LI]);
}
*/

void Qsort(int *arr, int beg, int end)
{
    int i,j,tmp,sep;
    
    if ((end-beg) <= 1) return;
    
    sep=arr[(beg+end)/2];
    
    i=beg;
    j=end;
    
    while (1)
    {
        while (arr[i]<sep) i++;
        while (arr[j]>sep) j--;
        
        if (i<=j)
        {
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i++;
            j--;
        }
        
        if (i>=j) break;
        
    }
    
    Qsort(arr,beg,j);
    Qsort(arr,i,end);
}
