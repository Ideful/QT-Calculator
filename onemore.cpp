// #include <iostream>
// #include <vector>
// #include <functional>

// std::string GetDataFromDB() {
//     return "data from DB";
// }

// std::string GetDataFromWebServer() {
//     return "data from server";
// }

// std::string GetDataFromQWE() {
//     return "data from QWE";
// }

// void ShowInfo(std::string (*foo)()) {
//     std::cout<<"\n"<<foo()<<std::endl;
// }

// int main() {
//     ShowInfo(GetDataFromQWE);
//     ShowInfo(GetDataFromDB);
//     ShowInfo(GetDataFromWebServer);
// }


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void check(char *a, char *b, int (*cmp) (const char *, const char *));
int numcmp (const char *a, const char *b) ;

int main(void){
    char s1[80], s2 [80];
    gets (s1);
    gets (s2);
    if(isalpha(*s1))
    check (s1, s2, strcmp);
    else
    check(s1, s2, numcmp);
    return 0;
}

void check(char *a, char *b, int (*cmp) (const char *,const char *)) {
    printf("Testing for equality.\n");
    if(!(*cmp) (a, b)) printf ("Equal");
    else printf("Hot equal");
}

int numcmp (const char *a, const char *b) {
    if(atoi(a)==atoi(b)) return 0;
    else return 1;
}