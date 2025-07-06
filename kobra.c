/*
 * KOnversão BináRiA
 */

#include <stdio.h>
#include <string.h>

#define MAX 1000

int api(char s[]);
int btoi(char s[]);
int htoi(char s[]);
int otoi(char s[]);
void paraBin(char bin[], int decimal);
void invStr(char str[]);
void getNumber();

int main()
{
	
	char bin[MAX];
	char number[MAX];
	char op;
	int dec;
	
	do{	
		printf("1 - octal to binary\n");
		printf("2 - decimal to binary\n");
		printf("3 - hexadecimal to binary\n");
		printf("4 - binary to decimal\n");
		printf("5 - octal to decimal\n");
		printf("6 - hexadecimal to decimal\n");
		printf("7 - Quit\n");

		// input ##############################################
		op = getchar();
		// se próximo for newline podes ir
		// se não limpa buffer e faz reset a op
		if(getchar() != '\n'){
			op = 0;
			while(getchar() != '\n'){}
		}

		switch(op){
			case '1':
				getNumber(number);
				paraBin(bin,otoi(number));
				printf("Binary: %s\n", bin);
				break;
			case '2':
				getNumber(number);
				dec = api(number);
				paraBin(bin,dec);
				printf("Binary: %s\n", bin);
				break;
			case '3':
				getNumber(number);
				paraBin(bin,htoi(number));
				printf("Binary: %s\n", bin);
				break;
			case '4':
				getNumber(number);
				printf("Decimal: %d\n",btoi(number));
				break;
			case '5':
				getNumber(number);
				printf("Decimal: %d\n",otoi(number));
				break;
			case '6':
				getNumber(number);
				printf("Decimal: %d\n",htoi(number));
				break;
			default:
				break;
		}
	} while(op != '7');
		
	return 0;
}

// Converte string binária para inteiro
int btoi(char s[])
{
	int i, n;
	i = n = 0;
	for(; s[i] >= '0' && s[i] <= '1'; ++i){
		n = 2 * n + (s[i] - '0');
	}
	return n;
}

// Conver string octal para inteiro
int otoi(char s[])
{
	int i, n;
	n = i = 0;

	// lidar com 0 opcional no início da string
	if(s[0] == '0')
		i++;

	for (; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 8 * n + (s[i] - '0');
	return n;
}

// converte string decimal para inteiro
int api(char s[])
{
	int i, n;

	n = 0;
	for ( i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

// converte string hexadecimal para inteiro
int htoi(char s[])
{
	int i , n;
	i = n = 0;
	// deal with optional 0x or 0X at start of string
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	
	for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F') ; ++i){
		if(s[i] == 'a' || s[i] == 'A')
			n = 16 * n + 10;
		else if(s[i] == 'b' || s[i] == 'B')
			n = 16 * n + 11;
		else if(s[i] == 'c' || s[i] == 'C')
			n = 16 * n + 12;
		else if(s[i] == 'd' || s[i] == 'D')
			n = 16 * n + 13;
		else if(s[i] == 'e' || s[i] == 'E')
			n = 16 * n + 14;
		else if(s[i] == 'f' || s[i] == 'F')
			n = 16 * n + 15;
		else
			n = 16 * n + (s[i] - '0');

	}
	return n;
}

// converte inteiro decimal para string binária
void paraBin(char bin[], int decimal){
	
	int r;
	int i = 0;
	do{
		r = decimal % 2;		
		bin[i] = r + 48;
		++i;			
		decimal = decimal / 2;		
	} while(decimal != 0);

	bin[i] = '\0';
	invStr(bin);
}

// inverte string
void invStr(char str[]){
	int i;
	int j = strlen(str) - 1;
	char temp;
	for(i = 0; i < j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}				
}

// recebe string numérica
void getNumber(char n[])
{
	printf("Enter number:");
	char c;
	int i = 0;
	while((c = getchar()) != '\n'){
		n[i] = c;
		++i;
	}
	n[i] = '\0';
}
