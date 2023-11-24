//Scenario
//Write a program that asks for the IP address in a human readable form, creates three substrings, and prints them.
//These substrings are created from parts 3, 2, and 1 of the last part of the IP address.
//These substrings should be created with the use of pointers or array indexing(whichever you prefer).If a given string doesn't have three dots, then the program should print the message: Error: not a valid address..
//Your program should also check if a given string consists only of digits and dots, and that there are no more than three digits in each block.You don't have to check if the numbers are smaller than 256.
//Note: You can use the isdigit function, but you can also write your own code to check whether or not a character is a digit.
//Your version of the program must print the same result as the expected output.
//
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Sample input
//255.255.255.255
//
//Expected output
//Last 3 parts: 255.255.255
//Last 2 parts : 255.255
//Last 1 part : 255
//
//Sample input
//127.0.0.1
//
//Expected output
//Last 3 parts: 0.0.1
//Last 2 parts : 0.1
//Last 1 part : 1
//
//Sample input
//255.2555.255.255
//
//Expected output
//Error : not a valid address.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char ip[100];
	int dcnt = 0, swe = 0;
	printf("Please enter an ip:\n");
	scanf_s("%s", ip, sizeof(ip));
	for (int i = 0, cnt = 0; i < strlen(ip); i++) {
		if ((isdigit(ip[i]) || ip[i] == '.')) {
			if (ip[i] == '.') {
				dcnt++;
				if (cnt == 0 || i == strlen(ip) - 1) { swe = 1; break; }
				else { cnt = 0; continue; };
			}
			if (cnt >= 3) { swe = 1; break; }
		}

		else { swe = 1; break; }
		cnt++;

	}
	if (dcnt != 3) swe = 1;
	if (swe) printf("Error: Not a valid adress");
	else {
		printf("Last 3 parts: ");
		for (int i = 0, sw = 0; i < strlen(ip); i++) {
			if (!sw && ip[i] == '.') sw++;
			else if (sw) printf("%c", ip[i]);
		}
		printf("\nLast 2 parts: ");
		for (int i = 0, sw = 0; i < strlen(ip); i++) {
			if (sw < 2 && ip[i] == '.') sw++;
			else if (sw>=2) printf("%c", ip[i]);
		}
		printf("\nLast 1 part : ");
		for (int i = 0, sw = 0; i < strlen(ip); i++) {
			if (sw < 3 && ip[i] == '.') sw++;
			else if (sw>=3) printf("%c", ip[i]);
		}
	}
		return 0;
}
//
//Please enter an ip :
//94.156.168.166
//Last 3 parts : 156.168.166
//Last 2 parts : 156168166
//Last 1 part : 156168166
