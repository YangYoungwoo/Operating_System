#include <stdio.h>
#include <pthread.h>// pthread를 위하여 사용
#include <stdlib.h> // exit과 atoi를 위하여 사용

volatile int k; // 입력받은 값을 선언하기 위한 지역변수

void * add_thread(void *argv){
	int i;
	for(i=0; i<1000; i++){
		k = k+1;
	}
	pthread_exit(0);
}//thread를 생성하였을 때 1000번을 더할 수 있도록 하는 함수

void * sub_thread(void *argv){
	int i;
	for(i=0; i<1000; i++){
		k = k-1;
	}
	pthread_exit(0);
}//thread를 생성하였을 때 1000번을 뺄 수 있도록 하는 함수

int main(int argc, char* argv[])
{
	k = atoi(argv[1]);//지역변수에 입력한 argument를 선언한다.
	pthread_t ptr1, ptr2; //thread를 입력하기 위한 주소값
	int i, j;
	for(j=0;j<30;j++){
		for(i=0; i<5000; i++){
			pthread_create(&ptr1, NULL, add_thread, (void *)k);

			pthread_create(&ptr2, NULL, sub_thread, (void *)k);

		}//add와 sub thread를 5000개를 생성하기위한 for문 사용
		printf("%d\n", k); // 출력값을 위한 printf
		
		pthread_join(ptr1,NULL);//thread가 끝나기 전에 main함수가 종료되지 않도록 한다. 

		pthread_join(ptr2,NULL);//thread가 끝나기 전에 main함수가 종료되지 않도록 한다. 

	}//결과를 30번 출력하기 위하여 사용한 for
	return 0;
}
