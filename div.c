#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int a, b;
	a = atoi(argv[1])/atoi(argv[2]);
	//몫을 계산하여 a에 입력한다.
	b = atoi(argv[1])%atoi(argv[2]);
	//나머지를 계산하여 b에 입력한다.
	printf("share : %d\n", a);
	//몫을 출력한다.
	printf("rest : %d\n", b);
	//나머지를 출력한다.
	return 0;
}// ./div과 argument를 입력받아 나눈 값과 나머지를 출력한다.
