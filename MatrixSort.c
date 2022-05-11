#include<stdio.h>
#include<stdlib.h>

int InitDefaultMatrix(int**);
int SortMatrixRows(int**,int,int);
int SortMatrixColumns(int**,int,int);
int SumArray(int*,int);
void swap(int* x,int* y){int z=*x;*x=*y;*y=z;}
void SwapArrays(int* x,int* y,int len){for(int i=0;i<len;++i)swap(&x[i],&y[i]);}
void swap2(int** x,int** y){int* z=*x;*x=*y;*y=z;}

int main()
{
	int** Matrix=(int**)calloc(1,sizeof(int*));
	InitDefaultMatrix(Matrix);
	/*for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)printf("%d\t",Matrix[i][j]);
		printf("\n");
	}*/
	SortMatrixRows(Matrix,10,10);
	/*for(int i=0;i<10;++i)
	{
		printf("\n");for(int j=0;j<10;++j)printf("%d\t",Matrix[i][j]);
		printf("/%d",SumArray(Matrix[i],10));
	}
	printf("\n");*/
	SortMatrixColumns(Matrix,10,10);
	/*
	for(int i=0;i<10;++i)
	{
		printf("\n");for(int j=0;j<10;++j)printf("%d\t",Matrix[i][j]);
	}
	printf("\n");for(int i=0;i<10;++i)printf("----\t");printf("\n");
	for(int i=0;i<10;++i)
	{
		int acc=0;for(int j=0;j<10;++j)acc+=Matrix[j][i];
		printf("%d\t",acc);
	}*/
	free(Matrix);
	return 0;
}

int SortMatrixRows(int** Matrix,int Width,int Height)
{
	double factor=1.2473309;
	int step=Height-1;
	while(step)
	{
		for(int i=0;i+step<Height;++i)
		{
			if(SumArray(Matrix[i],Width)<SumArray(Matrix[i+step],Width))
			{
				swap2(&Matrix[i],&Matrix[i+step]);
			}
		}
		step/=factor;
	}
}

int SortMatrixColumns(int** Matrix,int Width,int Height)
{
	double factor=1.2473309;
	int step=Width-1;
	while(step)
	{
		for(int i=0;i+step<Width;++i)
		{
			int* Column1=(int*)calloc(Height,sizeof(int));
			int* Column2=(int*)calloc(Height,sizeof(int));
			for(int y=0;y<Height;++y)Column1[y]=Matrix[y][i];
			for(int y=0;y<Height;++y)Column2[y]=Matrix[y][i+step];
			if(SumArray(Column1,Height)<SumArray(Column2,Height))
			{
				SwapArrays(Column1,Column2,Height);
				for(int j=0;j<Height;++j)
				{
					Matrix[j][i]=Column1[j];
					Matrix[j][i+step]=Column2[j];
				}
			}
			free(Column1);free(Column2);
		}
		step/=factor;
	}
}

int SumArray(int* Array,int len){int acc=0;for(int i=0;i<len;++i)acc+=Array[i];return acc;}

int InitDefaultMatrix(int** Matrix)
{
	if(!Matrix)return -1;
	free(Matrix);Matrix=(int**)calloc(10,sizeof(int*));
	for(int i=0;i<10;++i)Matrix[i]=(int*)calloc(10,sizeof(int));
	for(int y=0;y<10;++y)
	{
		for(int x=0;x<10;++x){int r=rand()%1000;Matrix[y][x]=r*(r%7?1:-1);}
	}
	return 0;
}
