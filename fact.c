#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int i, fact = 1;
	i = atoi(argv[1]);
	//입력받은 argument를 int형으로 바꾼다.
	while(i>0){
		fact = fact*i;
		i = i - 1;
	}//팩토리얼을 계산한다.
	printf("%d\n", fact);
	//계산한 팩토리얼을 출력한다.
	return 0;
}// ./fact와 argument를 입력받아 팩토리얼을 계산하여 출력한다.
