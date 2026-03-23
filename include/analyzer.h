#ifndef ANALIZER_H
#define ANALIZER_H

void analyzer(char *ip);

typedef struct {
	char is_valid[100];
	char ip_version[50];
	char ip_type[100];
	int octats;
	char ip_class;
	char subnet_mask[20];
	char broadcast_address[20];
	char ip_range[20];
	char binary[10];
	char is_usable[10];
	char is_loop[10];
	char address[20];
} IP_info;

#endif
