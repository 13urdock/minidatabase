#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void user_now(FILE *fp){
	fp = fopen("file.txt", "wt");
	fprintf(fp, "PARK GIL DONG\n22\nparkpark@hotmail.com\n");
	fprintf(fp, "LEE GIL DONG\n23\ngildonglee@naver.com\n");
	fclose(fp);
}

void view_user(){
	char line[255];
	FILE *fp;

	fp = fopen("file.txt", "r");
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s / ", line);
		fgets(line, sizeof(line), fp);
		printf("%s / ", line);	 
		fgets(line, sizeof(line), fp);
		printf("%s\n", line);
		fgets(line, sizeof(line), fp);
		printf("%s\n", line);
	}
	fclose(fp);

}

void add_user(){
	FILE * fp = fopen("file.txt", "a");
	char famname[20], name1[20], name2[20];
	int age;
	char email[255];
	char c;

	printf("enter user's name: ");
	scanf("%s %s %s", famname, name1, name2);
	printf("enter user's age: ");
	scanf("%d", &age);
	printf("enter user's email: ");
	scanf("%s", email);
	fprintf(fp, "%s %s %s\n%d\n%s\n", famname, name1, name2, age, email);

	fclose(fp);
	printf("do you want to add more user?(y/n)");
	scanf("%c", &c);
	if( c == 'y')
		add_user();
	else if (c == 'n')
		return;
}

int main(int argc, char*argv[]){
	FILE *fp;
	printf("1. 신규회원 저장\n");
	printf("2. 회원 삭제\n");
	printf("3. 모든 회원 리스트\n");
	printf("4. 종료\n");
	int num;
	printf("입력하세요.: ");
	scanf("%d", &num);
	
	switch(num){
		case 1:
			add_user();
			break;/*
		case 2:
			delete_user();
			break;*/
		case 3:
			view_user();
			break;/*
		case 4:
			printf("end session");
			break;*/
	}
	
	return 0;
}
