#include <strings.h>
#include <ctype.h>
#include "../include/ipv6.h"

int is_ipv6(char *ip) {
	int colons = 0;

	for (int i = 0; ip[i]; i++) {
		if(ip[i] == ':') colons++;
		else if (!isxdigit(ip[i])) return 0;
	}

	return colons == 5;
}
