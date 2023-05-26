#include <stdio.h>

void user_now(FILE *fp){
	fp = fopen("file.txt", "wt");
	fprintf(fp, "PARK GIL DONG\n22\nparkpark@hotmail.com\n");
	fprintf(fp, "LEE GIL DONG\n23\ngildonglee@naver.com\n");
	fclose(fp);
}

void read_name(FILE *fp){
	char name[100];
	int age;
	char email[100];
	int c=0;

	fp = fopen("file.txt", "r");
	while(!EOF){
	fgets(name, sizeof(name), fp);
	fscanf(fp,"%d %s", &age, email);	
	printf("%s", name); 
	printf("%d\n", age);
	printf("%s\n", email); //find a way to repeat this form
	}
	fclose(fp);	
}

void add_user(){
	FILE * fp = fopen("file.txt", "a");
	char name[255];
	int age;
	char email[255];

	printf("enter user's name: ");
	scanf("%s", name);
	printf("enter user's age: ");
	scanf("%d", &age);
	printf("enter user's email: ");
	scanf("%s", email);

	fprintf(fp, "%s\n%d\n%s", name, age, email);

	fclose(fp);
}

int main(int argc, char*argv[]){
	FILE *fp;
	user_now(fp);
	read_name(fp);
	printf("1. add new user\n");
	printf("2. modify informations\n");
	printf("3. delete user\n");
	printf("4. view all users\n");
	printf("5. quit");
	int num;
	printf("enter a number: ");
	scanf("%d", &num);
	
	switch(num){
		case 1:
			add_user();
			break;
	}
	return 0;
}
