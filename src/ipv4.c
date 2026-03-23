#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/ipv4.h"
#include "../include/utils.h"

int is_ipv4(char *ip) { 
	
	int dots = 0;
	char *ptr;
	int num;

	ptr = strtok(ip, ".");

	if (ptr == NULL) return 0;

	while (ptr) {
		if (!is_number) return 0;
		if (strcmp(ptr, "0.0.0.0\n") == 0) return 0;
		num = atoi(ptr);
		if(num < 0 || num > 225) return 0;
		
		ptr = strtok(NULL, ".");
		if (ptr != NULL) dots++;	
	}

	return dots == 3;
}
