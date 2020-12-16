#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int div;
	div= atoi(argv[1]) - atoi(argv[2]);
	//argument를 입력받은 것을 int형으로 바꿔 뺀다.
	printf("%d\n", div);
	//뺀 값을 출력한다.
	return 0;
}// ./sub과 argument를 입력받아 뺀 값을 출력한다.
