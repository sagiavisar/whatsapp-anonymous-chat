#include <stdio.h>
#include <string.h>

char* replace_char(char* str, char find, char replace) {
    if (replace == '\0') {
        char *src, *dst;
        for (src = dst = str; *src != '\0'; src++) {
            *dst = *src;
            if (*dst != find) dst++;
        }
        *dst = '\0';
    } else {
        char *current_pos = strchr(str, find);
        while (current_pos) {
            *current_pos = replace;
            current_pos = strchr(current_pos + 1, find);
        }
    }
    return str;
}


void parse_number(char* result, char* country_code, char* phone_number) {
    strcpy(result, country_code);
    strcat(result, replace_char(phone_number, '-', '\0'));
}




int main(int argc, char *argv[]) {
    char base_url[100] = "https://wa.me/";
    char parsed_number[100];
    char phone_number[20], country_code[30];

    printf("Welcome to my WhatsApp Anonymous Chat Link Generator!\n");
    printf("Please input your country code and phone number below to generate a link to an anonymous WhatsApp chat.\n");
    printf("For example: 'https://wa.me/+972123456789'\n\n");
    printf("Enter Country Code (e.g. +972): ");
    scanf("%s", country_code);  
    printf("Enter the rest of the Phone Number (e.g. 123456789): ");
    scanf("%s", phone_number); 

    parse_number(parsed_number, country_code, phone_number);
    strcat(base_url, parsed_number);  
    printf("Final URL: %s\n", base_url);
    return 0;
}


