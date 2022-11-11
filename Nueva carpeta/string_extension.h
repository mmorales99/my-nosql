#ifndef STREXT_H
#define STREXT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "custom.h"
#include "error.h"

bool isNullOrEmpty(const string str){
    if( str is null ) return true;
    return strlen(str) is 0;
}

bool isEOL(const char str){
    return str == '\0';
}

string substr_sii(const string origin, const int from, const int to){
    if(origin is null)
        return null;
    if(from < 0 or to < 0)
        return null;
    if(from > to)
        return null;
    int total_chars = to - from;
    string newStr = (string)calloc(total_chars+1,(sizeof(char)*total_chars)+1);
    int i = 0;
    for (i = 0; i < total_chars; i++){
        newStr[i] = origin[i + from];
    }
    newStr[total_chars] = '\0';
    return newStr; // posible perdida de memoria, cambiar a paso por referencia?
}

string trim_left(const string str){
    char c;
    int i = 0;
    while (!isEOL(str[i]) and i < strlen(str) and str[i] is ' ')
        i++;
    return substr_sii(str, i, strlen(str)); // posible perdida de memoria, cambiar a paso por referencia?
}

string trim_right(const string str){
    char c;
    int i = strlen(str);
    while (i > 0 and (str[i] is ' ' or str[i] is '\0'))
        i--;
    return substr_sii(str, 0, i+1); // posible perdida de memoria, cambiar a paso por referencia?
}

string trim(const string str){
    return trim_right(trim_left(str)); // posible perdida de memoria, cambiar a paso por referencia?
}

bool isInString(const char contained, const string container){
    if(container is null)
        return false;
    bool isContained = false;
    int i = 0, max_container = strlen(container);
    while(i < max_container and !isContained){
        isContained = contained == container[i++];
    }
    return isContained;
}

string* tokenize_ss(const string str, int* total, const string sep, const string ignore){ // probar a poner los tokens por referencia, ahorrar memoria?
    if(isNullOrEmpty(str))
        return null;
    string s = trim(str);
    int token_chars = 0, token_number = 0, str_acc = 0, ig_acc = 0;
    char c;
    string token = null;
    string* tokens = null;
    do{
        c = s[str_acc++];
        if(isInString(c,ignore)){
            ig_acc++;
            if(ig_acc is 2){
                ig_acc = 0;
            }
        }
        if(token is null){
            token = (string)calloc(1,sizeof(token));
            if(token is null)
                thorw_fatal_error("Error while tokenize a string. No more memory could be allocated.");
        }
        else if(!isInString(c,ignore)){
            token = (string)realloc(token,sizeof(char)*(token_chars+1));
            if(token is null)
                thorw_fatal_error("Error while tokenize a string. No more memory could be allocated.");
        }
        if (isInString(c,sep) and ig_acc is 0){
            if(!isNullOrEmpty(token)){
                token[token_chars] = '\0';
                if(tokens is null)
                    tokens = (string*)calloc(1,sizeof(token));
                else
                    tokens = (string*)realloc(tokens,sizeof(token)*(token_number+1));
                if(tokens is null)
                    thorw_fatal_error("Error while tokenize a string. No more memory could be allocated.");
                tokens[token_number] = (string)calloc(token_chars,sizeof(string)*token_chars);
                strcpy(tokens[token_number],token);
                token_number++;
            }
            free(token);
            token = null;
            token_chars = 0;
        }else if(!isInString(c,ignore))
            token[token_chars++] = c;
    } while (!isEOL(c) and str_acc < strlen(s));
    if(token not null)
        free(token);
    if(total not null)
        *total = token_number;
    return tokens;
}

const string DEFAULT_SEP = " \n\r\0";
const string DEFAULT_ING = "\'\"";

string* tokenize(const string str, int* total)
{
    if(isNullOrEmpty(str))
        return null;
    return tokenize_ss(str, total, DEFAULT_SEP, DEFAULT_ING);
}
char toUpper(const char c)
{
    const char OFFSET = 'a' - 'A';
    return (c >= 'a' && c <= 'z') ? c - OFFSET : c;
}
string stringUpper(string str)
{
    if(str is null or strlen(str) is 0)
        return str;
    int i = 0;
    for (i;i<strlen(str);i++)
    {
        str[i] = toUpper(str[i]);
    }
    return str;
}
char toLower(const char c)
{
    const char OFFSET = 'a' - 'A';
    return (c >= 'A' && c <= 'Z') ? c + OFFSET : c;
}
string stringLower(string str)
{
    if(str is null or strlen(str) is 0)
        return str;
    int i = 0;
    for (i;i<strlen(str);i++)
    {
        str[i] = toLower(str[i]);
    }
    return str;
}

bool stringContains(const string str, const string container)
{
    if(str is null or container is null or
        strlen(str) is 0 or strlen(container) is 0)
        return false;
    bool check = false;
    char c = str[0];
    int i = 0, j = 0;
    for (i;i<(strlen(container)-strlen(str));i++){
        if(toUpper(container[i]) == toUpper(c)){
            do{
                check = toUpper(container[i + j]) == toUpper(str[j]);
            }while( ++j < strlen(str) and check not false);
            j = 0;
            if(check) break;
        }
    }
    return check;
}

bool equals(const string str1, const string str2){
    if(str1 is null or str2 is null)
        return false;
    return strcmp(str1,str2) is 0;
}

#endif