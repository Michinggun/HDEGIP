/* @HDEGIPMission1
 *	Michael Ingga Gunawan
 *	Michinggun@gmail.com
*/

#include <stdio.h>
#include <string.h>

int sqr(int x){
	return x*x;
}

int result[100];
int s=0;
int ctr=0;
// Calculate a sum of squares of some integers and put it in an array of result
void calculate(int *arr,int in[],int size){
	if(s==size){
		s=0;
	}else{
		arr[ctr]=arr[ctr]+sqr(in[s]);
		s++;
		calculate(arr,in,size);
	}
}

int k=0;
int l=0;
// convert array of character from input to an array of integer
int toIntArray(int *array,char in[],int j,char temp[],int limit){
	if(j==strlen(in)+1){
		l=0;
		return 1;
	}else if(in[j]!=' ' && in[j]!='\0'){
		int len = strlen(temp);
		temp[len] = in[j];
		j++;
		toIntArray(array, in, j, temp, limit);
	}else{
		if (atoi(temp)>=-100 && atoi(temp)<=100){
			if (atoi(temp)>=0 && l<=limit-1){
				array[k]=atoi(temp);
				k++;
			}
			char p[256]="";
			j++;
			l++;
			toIntArray(array, in, j, p, limit);	
		}
		else{
			return 0;
		}
	}
}

int sz=0;
// Print the result of calculated input
void printResult(int *arr, int size){
	if (sz==size-1){
		printf("%d\n", arr[sz]);
	}else{
		printf("%d\n", arr[sz]);
		sz++;
		printResult(arr,size);
	}
}

int arr[100];
char input[256];
char trash[256];
//Receive the N input test cases
void inputInt(int total){
	int X;
	if (ctr==total){
		printResult(result,ctr);
	}
	else{
		scanf("%d",&X);
		scanf("%c",&trash);
		if (X>0 && X<=100){
			scanf("%[^\n\t]s",input);
			char tmp[256]="";
			int checkY = toIntArray(arr,input,0,tmp,X);
			// calculate
			result[ctr]=0;
			calculate(result,arr,k);
			ctr++;
			k=0;
			if (checkY==0){
				printf("Please input Yn ( -100 <= Yn <= 100 )!\n");
				return;
			}
		}
		else{
			printf("Please input X ( 0 < X <= 100 )!");
			return;
		}
		inputInt(total);
	}
}



//main program
int main(){
	int N;
	scanf("%d",&N);
	if(N>=1 && N<=100){
		inputInt(N);
	}
	else{
		printf("Please input N ( 1 <= N <= 100 )!");
	}

}
