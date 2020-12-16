#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char buf[128]; //입력값을 받을 때 사용하도록 한다. 
	
	while(1){
		fgets(buf, sizeof(buf)-1, stdin);//값을 입력받는다. 
		char* ptr = strtok(buf, " "); //실행파일 이름으로 ptr을 받는다.
		char* a = strtok(NULL, " "); 
		argv[1] = a; //argv[1]의 값을 입력값으로부터 받는다.
		char* b = strtok(NULL, " ");
		argv[2] = b; //argv[2]의 값을 입력값으로부터 받는다.
		buf[strlen(buf)-1]='\0'; //exit을 입력할 때 종료할 수 있도록 한다.
		
		if(!strncmp(ptr, "exit", strlen(ptr))){
			return -1;
		} //"exit"을 누르면 myshell을 종료하도록 한다.
		else if(!strncmp(ptr, "./add", strlen(ptr))){
			argv[0]="./add";
			execlp("./add", argv[0], argv[1], argv[2], NULL);
			//execlp는 실행파일을 myshell로 불러와 실행하도록 한다
		} // "./add"를 입력할 경우 add.exe를 실행한다. 
		else if(!strncmp(ptr, "./sub", strlen(ptr))){
			argv[0]="./sub";
			execlp("./sub", argv[0], argv[1], argv[2], NULL);
			printf("print2\n"); // 실행이 잘 되는지 확인하도록 출력한다.
		} // "./sub"를 입력할 경우 sub.exe를 실행한다. 
		else if(!strncmp(ptr, "./fact", strlen(ptr))){
			argv[0]="./fact";
			execlp("./fact", argv[0], argv[1], NULL);
		} // "./fact"를 입력할 경우 fact.exe를 실행한다. 
		else if(!strncmp(ptr, "./div", strlen(ptr))){
			argv[0]="./div";
			execlp("./div", argv[0], argv[1], argv[2], NULL);
		} // "./div"를 입력할 경우 div.exe를 실행한다. 
	}
	return 0;
}

