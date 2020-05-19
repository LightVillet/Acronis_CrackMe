#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ввиду отсутствия в С встроенных динамически изменяемой памяти приходится
//Довольствоваться ограничением большим числом
#define MAX_LENGTH 1024

int main()
{
	char * login = malloc(MAX_LENGTH * sizeof(char));
	int pass = 0;
	int len, i;
	printf("Input login: ");
	scanf("%s", login);
	//В случае, если мы знаем, что пользователь введёт только буквы из A-Z
	//или a-z (что подразумевалось скорее всего), то считывание без 
	//ограничений все-таки можно сделать с помощью
	//scanf("%m[A-Za-z]", &login);
	len = strlen(login);
	for (i = 0; i < len; i++)
	{
		if (login[i] < 'A')
		{
			printf("Invalid login!\n");
			return -1;
		}
		if (login[i] > 'Z')
			login[i] -= 0x20;
		pass += login[i];
	}
	pass ^= 0x5678;
	pass ^= 0x1234;
	printf("Password: %d\n", pass);
	return 0;
}
