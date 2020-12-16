#include <stdio.h>
#include <string.h> //strcmp를 사용하기위해 선언하였습니다.
#include <stdlib.h> //malloc을 사용하기 위해 함수를 선언하였습니다.

typedef struct _SPointer{
	char number[10];
	char name[10];
	struct _SPointer *next;
}SPointer; //학번과 이름을 구조체로 정의하였습니다.

SPointer *S_Pointer; //링트크드리스 연결을 위해 첫 포인터를 주었습니다.

void Make_List(void){
	SPointer *current, *pre; //링크드리스를 이용하기 위해 두가지 포인터를 주었습니다.
	
	current = (SPointer *)malloc(sizeof(SPointer)); //동적메모리 할당을 위하여 malloc 함수를 사용하였습니다.
	strcpy(current->number, "1234");
	strcpy(current->name, "Kim");
	current->next = NULL;
	pre = current; //pre를 사용하여 current를 이어주는데 사용하였습니다.

	S_Pointer = current; // 첫 값을 기억하도록 첫 포인터로 기록했습니다.

	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "2345");
	strcpy(current->name, "Lee");
	current->next = NULL;
	pre->next = current;
	pre = current;

	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "3456");
	strcpy(current->name, "Yang");
	current->next = NULL;
	pre->next = current;
	pre = current;

	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "4567");
	strcpy(current->name, "Choi");
	current->next = NULL;
	pre->next = current;
	
	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "5678");
	strcpy(current->name, "Park");
	current->next = NULL;
	pre->next = current;
	pre = current;
	
	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "6789");
	strcpy(current->name, "Ji");
	current->next = NULL;
	pre->next = current;
	pre = current;
	
	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "7890");
	strcpy(current->name, "Seo");
	current->next = NULL;
	pre->next = current;
	pre = current;
	
	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "8901");
	strcpy(current->name, "Noh");
	current->next = NULL;
	pre->next = current;
	pre = current;
	
	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "9012");
	strcpy(current->name, "Yoon");
	current->next = NULL;
	pre->next = current;
	pre = current;
	
	current = (SPointer *)malloc(sizeof(SPointer));
	strcpy(current->number, "0123");
	strcpy(current->name, "Han");
	current->next = NULL;
	pre->next = current;
} //단일연결리스트를 이용하여 10명의 학생과 학번을 입력하였습니다.

void Ptrresult(void){
	char i[10]; //학번 또는 이름을 입력받기위해 char 값을 주었습니다.
	SPointer *check; //입력받은 값과 비교하기 위해 포인터 값을 주었습니다.
	
	Make_List(); //학번과 이름을 기록한 리스트를 가져왔습니다.
	check = S_Pointer; //값을 확인하기 위해 리스트의 첫 값으로 이동하였습니다.
	
	printf("검색: ");
	scanf("%s", i); //사용자에게 학번 또는 이름을 입력을 받도록 하였습니다.
	for( ; check !=NULL; check = check->next){
		if(strcmp(check->name, i)==0){
			printf("--> %s\n", check->number); //같은 이름을 가지고 있는 학생의 학번이 나오도록 printf를 사용하였습니다.
			break; // 이름이 매칭되었을 때 더 이상 돌아가지 않도록 하였습니다.
		} //if문을 만들어서 배열에서 이름을 찾아서 매칭시키고 학번을 출력하도록 만들었습니다.
		if(strcmp(check->number, i)==0){
			printf("--> %s\n", check->name); //같은 학번을 가지고 있는 학생의 이름이 나오도록 printf를 사용하였습니다.
			break; // 학번이 매칭되었을 때 더 이상 반복되지 않도록 하였습니다.
		} //if문을 사용하여 배열에서 학번을 찾아서 매칭시키고 학번을 출력하도록 만들었습니다.
	} //for문을 사용하여 check가 NULL이 될 때까지 비교하였습니다.
	if(check == NULL) //if문을 모두 완료 하였을 때도 결과가 나오지 않았을 때 오류임을 표현하였습니다.
	printf("틀린 입력입니다.\n"); //오류일때 '틀 입력입니다.'를 출력하기위해 printf를 사용하였습니다.
} //이름을 검색하면 학번이 나오고 학번을 검색하면 이름이 나오도록 하였습니다. 또한 다른 입력을 하였을 땐 잘못된 입력이라고 입력이 되도록하였습니다.

int main(){
	Ptrresult(); //학번과 이름을 검색해서 결과를 나오도록 하는 함수를 main()과 연결하였습니다.
	
	return 0; //정상적인 종료를 위해 사용하였습니다.
}
