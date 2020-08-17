//
//  SubstitutionCipher.c
//
//
//  Created by Srikar on 15/08/19.
//

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/types.h>
//int max(int count[]){
//	int mx = 0;
//	for(int j=1; j<26; j++) {
//		if (count[j] > count[mx]) {
//			mx = j;
//		}
//	}
//	return mx;
//}

void percent(int count[], float per[]) {
	int sum = 0;
	for(int j=0; j<256; j++) {
		sum += count[j];
	}
	for(int j=0; j<256; j++) {
		per[j] = ((float)count[j]*100)/(float)sum;
	}
	return;
}

void replace(char arr[], int change[], char a, char b) {
	int i=0;
	while(arr[i]!='\0') {
		if(arr[i]==a && change[i] == 0) {
			arr[i] = b;
			change[i] = 1;
		}
		i = i+1;
	}
	return;
}

void sort(int num[], float per[]) {
	int temp;
	float ftemp;
	int i, j;
	for (i=1; i<256; i=i+1) {
		for (j=i; j>0; j=j-1) {
			if (per[j] > per[j-1]) {
				ftemp = per[j];
				per[j] = per[j-1];
				per[j-1] = ftemp;
				temp = num[j];
				num[j] = num[j-1];
				num[j-1] = temp;
			}
			else {
				break;
			}
		}
	}
}

int main()  {
	FILE *in_file = fopen("Substitution.txt", "r");
	FILE *out_file = fopen("rmv_blnk.txt", "a+");
	// putc('\0', in_file);
	char input[100000];
	int change[100000];
	fscanf(in_file, "%[^\0]%*c", input);
	putc('\0', in_file);
	for(int u=0; u<100000; u++) {
		change[u] = 0;
	}
	int count[256];
	for(int i=0; i<256; i++) {
		count[i] = 0;
	}
	char modified[256];
	for(int i=0; i<256; i++) {
		modified[i] = i;
	}

	modified['#'] = ' ';
	modified['O'] = 'e';
	modified['_'] = '.';
	modified['J'] = 'T';
	modified['x'] = 'h';
	modified['S'] = 'a';
	modified['B'] = 'n';
	modified['s'] = 'd';
	modified['V'] = 't';
	modified['A'] = 'r';
	modified['u'] = 's';
	modified['f'] = 'i';
	modified['T'] = 'c';
	modified['E'] = 'g';
	modified['h'] = 'z';
	modified['K'] = 'm';
	modified['Z'] = 'u';
	modified['m'] = 'p';
	modified['N'] = 'y';
	modified['v'] = 'b';
	modified['r'] = 'o';
	modified['L'] = 'w';
	modified['H'] = 'k';
	modified['q'] = 'f';
	modified['w'] = 'C';
	modified['D'] = 'v';
	modified['e'] = 'A';
	modified['g'] = 'I';
	modified['C'] = 'S';
	modified['Y'] = 'U';
	modified['>'] = ',';
	modified['t'] = 'j';
	modified['R'] = 'M';
	modified['p'] = 'x';
	modified['F'] = 'D';
	modified['P'] = 'q';
	modified['U'] = 'E';
	modified['$'] = '-';
	modified['('] = '/';
	modified['a'] = 'G';
	modified['Q'] = 'K';
	modified['\\'] = '(';
	modified['{'] = ')';
	modified['M'] = 'Y';
	modified['c'] = 'O';
	modified['d'] = 'R';
	modified['G'] = 'W';
	modified[':'] = '"';
	modified['y'] = 'B';
	modified[';'] = '\'';
	modified['z'] = 'F';
	modified['o'] = 'P';
	modified['n'] = 'H';
	modified['/'] = '[';
	modified['-'] = ']';
	modified['='] = ':';

	modified['6'] = '1';
	modified['8'] = '2';
	modified['0'] = '3';
	modified['9'] = '5';
	modified['5'] = '6';
	modified['2'] = '7';
	modified['7'] = '8';
	modified['1'] = '9';
	for(int i=0; i<256; i++) {
		replace(input, change, i, modified[i]);
	}
	// replace(input, change, 'O', 'e');
	// replace(input, change, 'S', 'a');
	// replace(input, change, '#', ' ');
	// replace(input, change, 'B', 'n');
	// replace(input, change, 's', 'd');
	// replace(input, change, '_', '.');
	// replace(input, change, 'J', 'T');
	// replace(input, change, 'x', 'h');
	// replace(input, change, 'A', 'r');
	// replace(input, change, 'r', 'i');

	int i = 0;
	while(input[i]!='\0'){
		fprintf(out_file, "%c", input[i]);
		i = i + 1;
	}
	i = 0;
	while(input[i]!='\0') {
		count[input[i]] += 1;
		i = i + 1;
	}
	float per[256];
	for(int i=0; i<256; i++) {
		per[i] = 0;
	}
	percent(count, per);
	int num[256];
	for(int k=1; k<=256;k++) {
		num[k-1] = k;
	}
	sort(num, per);
	for(int k=0; k<256; k++) {
		if (per[k] != 0) {
			printf("%d %c = %f percent\n",k+1, num[k] - 1 , per[k]);
		}
	}
	fclose(in_file);
	fclose(out_file);
}
