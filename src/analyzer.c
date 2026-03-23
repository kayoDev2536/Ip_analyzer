#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../include/analyzer.h"
#include "../include/ipv4.h"
#include "../include/ipv6.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"


void analyze_ipv4(char *ip);
void print_info();

IP_info ip_info;

void analyzer(char *ip) {
	
	char ip_copy[100];
	strcpy(ip_copy, ip);
	strcpy(ip_info.address, ip);

       	if(is_ipv4(ip_copy) == 1) {	
		analyze_ipv4(ip_copy);
		strcpy(ip_info.is_valid,"valid");
		strcpy(ip_info.ip_version, "Ipv4");

	} else if(is_ipv6(ip_copy)) {
		strcpy(ip_info.ip_version, "Ipv6");
	} else {
		strcpy(ip_info.is_valid, "invalid");	
	}

	print_info();
}

void print_info() {

	 printf("🟢 Address: ");
	 if(strcmp(ip_info.is_valid, "valid") == 0) {
	 	printf(GREEN);
		printf("%s", ip_info.address);
		printf(RESET);
	   } else {
	   	printf(RED);
		printf("%s", ip_info.address);
		printf(RESET);
	   } 

	sleep(1);
	printf("🟢 Validity: ");
	(strcmp(ip_info.is_valid, "valid") == 0) ? printf(GREEN "valid\n" RESET) : printf(RED "invalid\n"  RESET);

	sleep(1);
	 printf("🟢 Ip_Class: %c\n", ip_info.ip_class);
        
	sleep(1);
	 printf("🟢 Ip_version: %s\n", ip_info.ip_version);
       
	sleep(1);
	 printf("🟢 Subnet-Mask: %s\n", ip_info.subnet_mask);
        
	sleep(1);
	 printf("🟢 Is_usable: ");
        (strcmp(ip_info.is_usable, "Yes") == 0) ? printf(GREEN "Yes\n" RESET) : printf(RED "No\n"  RESET);

	sleep(1);
	 printf("🟢 Is_loop: ");
        (strcmp(ip_info.is_loop, "Yes") == 0) ? printf(GREEN "Yes\n" RESET) : printf(RED "No\n"  RESET);

	sleep(1);
	 printf("🟢 Is_broadcastAddress: ");
        (strcmp(ip_info.broadcast_address, "Yes") == 0) ? printf(GREEN "Yes\n" RESET) : printf(RED "No\n"  RESET);

}

void analyze_ipv4(char *ip) {

	char temp[100];
	strcpy(temp,ip);

	int parts[4];
	int i = 0;

	char *ptr = strtok(temp, ".");
	while (ptr) {
		parts[i++] = atoi(ptr);
		ptr = strtok(NULL, ".");
	}
	
	int first = parts[0];
	////// CLASS
	if(first >= 0 && first <= 127) {
		ip_info.ip_class = 'A';
		strcpy(ip_info.subnet_mask, "225.0.0.0");
		strcpy(ip_info.ip_range, "1.0.0.0 - 126.255.255.255");
	}
	
	else if(first <=191) {
		ip_info.ip_class = 'B';
		strcpy(ip_info.subnet_mask, "255.255.0.0");
		strcpy(ip_info.ip_range, "128.0.0.0 - 191.255.255.255");
	}
	else if(first <= 223) {
		ip_info.ip_class = 'C';
		strcpy(ip_info.subnet_mask, "255.255.255.0");
		strcpy(ip_info.ip_range, "192.0.0.0 - 223.255.255.255)");
	}
	else printf("Not Standard class\n");

	///// PRIVATE
	if(first == 10 ||first == 172 && parts[0] >= 16 && parts[1] <= 31 || (first == 192 && parts[1] == 168)) strcpy(ip_info.ip_type, "Private");
	else strcpy(ip_info.ip_type, "Public");

	//// LOOPBACK
	if(first == 127) {
		strcpy(ip_info.is_loop, "Yes");
		strcpy(ip_info.is_usable, "No");
	}
	else {
		strcpy(ip_info.is_usable, "Yes");
		strcpy(ip_info.is_loop, "No"); 
	}

	///// BINAry
	// todo
	
	//// Broadcast
	if (first == 225 && parts[1] == 225) {
		strcpy(ip_info.is_usable, "No");       
		strcpy(ip_info.broadcast_address, "Yes");
	}
	else {
		strcpy(ip_info.broadcast_address, "No"); }
}
