#include <stdio.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/analyzer.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

int main() {

	char ip[100];
	char quit[2] = "n";
	// clear the screan before everything
	clear_screen();

	banner();

	while(true) {	
	printf(YELLOW "Enter IP_address:\n" RESET);
	printf(CYAN ">>> " RESET);
	fgets(ip, sizeof(ip), stdin);

	analyzer(ip);
	
	/*while(true) {
		printf("Do you wanna Quit? (y/N):) ");
		fgets(quit,sizeof(quit),stdin);
		quit[strcspn(quit, "\n")] = '\0';

		if(strcmp(quit, "") == 0 || strcmp(quit, "n") == 0 || strcmp(quit, "N") == 0) break;
		else if (strcmp(quit, "Y") == 0 || strcmp(quit, "y") == 0) return 0;
		else {
			printf("Invalid Input!\n");
			continue;
		}
			}*/
	}

	return 0;
}

