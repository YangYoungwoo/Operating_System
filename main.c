#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>


void main(int argc, char** argv){
	char buf[BUFSIZ];
	char i;
	int fd = -1;
	char B[10] = "B";
	char A[10] = "A";
	char* x="1";
	char* y="0";
	char C[10];
	char X[10];
	printf("A/B\n");
	scanf("%s", &X);
	//get A or B using scanf

	if(strcmp(X, B)==0){//compare if input is B
		scanf("%s",&C); //get 0 or 1 using scanf
		if(strcmp(C, x)==0){//compare if input is 1
			printf("gpio set: %s\n", x);
			fd =open("/dev/ledtest", O_RDWR);
			printf("fd: %d\n", fd);
			write(fd, x, 1, NULL);
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 1, NULL);
			printf("read: %s \n", buf);
		}//when input is 1 turn on led
		else{
			printf("gpio set: %s\n", y);
			fd =open("/dev/ledtest", O_RDWR);
			printf("fd: %d\n", fd);
			write(fd, y, 1, NULL);
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 1, NULL);
			printf("read: %s \n", buf);
		}//when input is 0 turn off led
	}
	if(strcmp(X, A)==0){//compare if input is A
		for(i=0;i<3;i++){
			printf("gpio set: %s\n", x);
			fd =open("/dev/ledtest", O_RDWR);
			printf("fd: %d\n", fd);
			write(fd, x, 1, NULL);
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 1, NULL);
			printf("read: %s \n", buf);
			//turn on the led
			usleep(500000);//wait for 0.5second
			printf("gpio set: %s\n", y);
			fd =open("/dev/ledtest", O_RDWR);
			printf("fd: %d\n", fd);
			write(fd, y, 1, NULL);
			memset(buf, 0, BUFSIZ);
			read(fd, buf, 1, NULL);
			printf("read: %s \n", buf);
			//turn off the led
			usleep(500000);
		}//repeat 3 times for turn on and off led
	}
	close(fd);//close fd
}
