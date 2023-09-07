#include<stdio.h>
#include <math.h>

double power(long long base, long double exp){

	long double result =1;
    long double foobase =2;
	for(exp; exp > 0; exp--){

		result = result *  foobase;
		//result +=(float) 1;

printf("R: %Lf \n",result);
	}

	//result = pow(2,exp);

	return result;
}


int main(){

	int tc;
	long long num;
	long long N = 0;
	char op;
	scanf("%d", &tc);

	for(int x = 0; x < tc; x++){
		scanf(" %c %f", &op, &num);
		/*if(power(2,num) == 0 ){
			if(op == '+'){
				N = N+1;
			}else{
				N = N-1;
			}
		}else{
			if(op == '+'){
				N = power(2, num) + N;
			}else{
				N = N - power(2, num);
			}
		}*/
		if(op == '+'){
				N = power(2, num) + N;
			}else{
				N = N - power(2, num);
        }
        printf("Result: %f\n",N);
		if(N == 0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}



	return 0;
}




