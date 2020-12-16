#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int sum;
	sum = atoi(argv[1]) + atoi(argv[2]);
	//argument를 입력받은 것을 int형으로 바꿔 더한다.
	printf("%d\n", sum);
	//더한 값을 출력한다.
	return 0;
}// ./add과 argument를 입력받아 더한 값을 출력한다.
