#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// note: i used ATOI function which takes as input the string that is to be converted to an integer (The stdlib.h library must be included for the atoi() function to be executed)

//FUNCTIONS

// this function takes the last two digits of the year
char subString2(char *sub, char *year, int position, int length){
    int c = 0;
    while (c < length) {
      sub[c] = year[position+c-1];
      c++;
    }
    return sub[c] = '\0';
}

// this function takes the first two digits of the year
char subString1(char *year, char *sub1){
    int c = 0;
    int position = 1;
    int length;
    if(strlen(year) == 4){
        length = 2;
    }
    else if (strlen(year) == 3){
        length = 1;
    }
    while (c < length) {
      sub1[c] = year[position+c-1];
      c++;
    }
    return sub1[c] = '\0';
}

// this function returns the century
 char YearToCentury(char *sub, char *year, int position, int length, char *sub1){
    int isub = atoi(sub);
    int isub1 = atoi(sub1);
    if (isub == 01 || isub != 00){
        return printf("%d° secolo\n", isub1+1);
    }
    else{
        return printf("%s° secolo\n", sub1);
    }
 }

// MAIN FUNCTION
int main() {
	
    // variables declaration
    char year[50], sub[50];
    int position, length = 2;
    char sub1[50];
	
    // user input
    printf("Input a year: ");
    scanf("%s", year);
    
    // set starting position for substring functions
    if(strlen(year) == 4){
        position = 3;
    }
    else if (strlen(year) == 3){
        position = 2;
    }
    
    // call functions for substrings
    subString1(year, sub1);
    subString2(sub, year, position, length);
    
    int nyear = atoi(year);

    if( nyear >= 1 && nyear <= 100 ){
        printf("1° secolo\n");
    }
    else {
        YearToCentury(sub, year, position, length, sub1);
    }

}
