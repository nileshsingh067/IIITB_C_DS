#include<stdio.h>
#include<stdlib.h>
/*Find Rank Randomise Linear time Las Vagous kind of sollution*/
int partation(int *arr,int i,int j);
int findrank(int *arr,int i,int j,int r);
int getpivote(int i,int j);
int main(){
	int sum,i,j,n,rank;
	printf("Enter the size of array\t");
	scanf("%d",&n);
	printf("Enter Rank\t");
	scanf("%d",&rank);
	j=n-1;
	int arr[n];
	for(int k=0;k<n;k++){
		arr[k]=rand()%100;
	}
	printf("Input Array is : \n");
	for(int k=0;k<n;k++){
                printf("%d\t",arr[k]);
        }
	printf("\n");
	/*printf("Partation :%d\n ",partation(arr,0,j));
        for(int k=0;k<n;k++){
                printf("%d\t",arr[k]);
        }*/
	int num=findrank(arr,0,j,rank);
	/*if(num>-1)*/printf("\nElement Id : %d\n",num);
	/*else printf("\nElement Not Found !!\n");*/


}
int getpivote(int i,int j){
	return i+(rand()%(j-i+1));
}
int findrank(int *arr,int i,int j,int r){
	if(i<=j){
	int pivote=getpivote(i,j);
	int tmp=arr[j];
	arr[j]=arr[pivote];
	arr[pivote]=tmp;
	int k=partation(arr,i,j);
	//printf("\nRank %d  Element Id : %d\n",(j-k+1),arr[k]);
	if(r==(j-k+1)){/*printf("\nElement Id : %d\n",arr[k]);*/ return arr[k];}
	else if((j-k+1)>r)findrank(arr,k,j,r);
	else findrank(arr,i,k-1,r-(j-k+1));
	}else{return -1;}

}
int partation(int *arr,int p,int r){
	int x=arr[r];
	int i=p-1;
	for(int k=p;k<r;k++){
		if(arr[k]<=x){
			i++;
			int tmp=arr[i];
			arr[i]=arr[k];
			arr[k]=tmp;
		}
	}
	int temp=arr[++i];
	arr[i]=x;
	arr[r]=temp;
	return i;
}
