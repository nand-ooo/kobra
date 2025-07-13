#include <stdio.h>
//#include "db.h"
#include <unistd.h>
#include <getopt.h>
#include <string.h>

#define VALID_ARGUMENT_COUNT 4

int handle_argument(char arg[]);
void handle_options(int argc, char *argv[]);
void print_required_argument_error(char *argv);
void print_help();
void trim(char line[]);

const char * version = "kobra version 0.1.0";

int main( int argc, char *argv[] ) 
{
	if(argc < 2) {
		print_help();
	}

	handle_options(argc, argv);

	int i = optind;
	int result;
	char *value;
	char *basefrom;
	char *baseto;

	value = argv[i++];
	basefrom = argv[i++];
	baseto = argv[i];
	printf("i: %d\n", i);
	
	/*
	for(i = optind; i < argc; i++) {
		
		int argval = handle_argument(argv[i]);
		switch(argval) {
			case 'k':
				if(i + 1 < argc) {
					i++;
					printf("Who does it open for?\n");
					getline(&username, &line_size, stdin);
					trim(username);
					pass = getpass("Insert the password:");
					save_password(argv[i], pass, username);
				} else {
					print_required_argument_error(argv[i]);
				}
				break;
			case 's':
				if(i + 1 < argc) {
					i++;
					char * arr[100];
					int total = get_passwords(argv[i], arr);
					for(int j = 0; j < total; j++){
						if(j % 2 == 1)
							putchar('\t');
						printf("%s", arr[j]);
						if(j % 2 == 1)
							putchar('\n');
					}

				} else {
					char * arr[100];
					int total = list_passwords(arr);
					for(int j = 0; j < total; j++){
						printf("%s\n", arr[j]);
					}
				}
				break;
			case 'c':
				if(i + 1 < argc) {
					i++;
					printf("Who does it open for?\n");
					getline(&username, &line_size, stdin);
					trim(username);
					pass = getpass("Insert the new password:");
					result = update_password(argv[i], username, pass);
					if(result)
						printf("No password found.\n");

				} else {
					print_required_argument_error(argv[i]);
				}
				break;
			case 'r':
				if(i + 1 < argc) {
					i++;
					printf("Who does it open for?\n");
					getline(&username, &line_size, stdin);
					trim(username);
					result = delete_password(argv[i], username);
					if(result)
						printf("No password found.\n");
				} else {
					print_required_argument_error(argv[i]);
				}
				break;
			default:
				printf("Invalid argument: %s\n", argv[i]);
				break;
		}
	}
	*/
	return 0;
}

void print_required_argument_error(char *argv)
{
	printf("The argument '%s' requires an argument.\n", argv);
}

void print_help()
{
	printf("usage: kobra [--version] [--help] <value> <basefrom> <baseto>\n\n");
}

void handle_options(int argc, char *argv[])
{
	int opt;
	static struct option long_options[] = {
		{ "version", no_argument, 0, 'v'},
		{ "help", no_argument, 0, 'h'}
	};	

	while((opt = getopt_long(argc, argv, "vh",long_options, 0)) != -1) {
		switch(opt){
			case 'v': 
				printf("%s\n", version);
				break;
			case 'h':
				print_help();
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	}
}

int handle_argument(char arg[])
{
	struct argument {
               const char *name;
               int         val;
	};


	static struct argument arguments[] = {
		{ "keep", 'k'},
		{ "show", 's'},
		{ "change", 'c'},
		{ "remove", 'r'},
	};

	int i;
	for(i = 0; i < VALID_ARGUMENT_COUNT; ++i) {
		if(!strcmp(arguments[i].name, arg)) {
			return arguments[i].val;
		}
	}
	return -1;
}

void trim(char line[])
{
	int len;
	len = strlen(line);
	line[len - 1] = '\0';
}
