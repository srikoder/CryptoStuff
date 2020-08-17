#include <stdio.h>

void extract(char input[], int key_size, int offset) {
  int i=0;
  int j=0;
  while(input[i] != '\0') {
    if((i-offset)%key_size == 0){
      input[j] = input[i];
      j = j + 1;
    }
    i = i + 1;
  }
  input[j] = '\0';
}

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

int modulo(int x, int y) {
    int temp = x%y;
    if(temp>=0) {
      return temp;
    }
    else {
      return y+temp;
    }
}


int main()  {
  int key_size;
  int offset;
  scanf("%d", &key_size);
  for(offset=0; offset<key_size; offset++) {
	FILE *in_file = fopen("Vignere_blnk.txt", "r");
	FILE *out_file = fopen("Vignere_part.txt", "a+");
	char input[100000];
	fscanf(in_file, "%[^\0]%*c", input);
  extract(input, key_size, offset);

  int i = 0;
  int count[256];
	for(int i=0; i<256; i++) {
		count[i] = 0;
	}
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
	// for(int k=0; k<256; k++) {
	// 	if (per[k] != 0) {
	// 		printf("%d %c = %f percent\n",k+1, num[k] - 1 , per[k]);
	// 	}
	// }
  printf("%c", modulo(num[0] - 1 - 'e', 26) + 'a' - 1);

  i = 0;
  while(input[i]!='\0'){
		fprintf(out_file, "%c", input[i]);
		i = i + 1;
	}
  fclose(in_file);
  fclose(out_file);
}
printf("\n");
}
