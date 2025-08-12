#include <iostream>
#include <cstring>

#define BUF_SIZE 1024

char* concatenate(char* str1, char* str2){
    int size1 = strnlen(str1, BUF_SIZE);
    int size2 = strnlen(str2, BUF_SIZE);

    char* res = new char[size1+size2+1];
    int k = 0;
    for (int i = 0; i<size1; i++){
        res[k] = str1[i];
        k++;
    }
    for (int i = 0; i<size2; i++){
        res[k] = str2[i];
        k++;
    }
    res[size1+size2] = '\0';
    return res;
}

char* reverse(char* str1){
    int size = strnlen(str1, BUF_SIZE);
    char* res = new char[size+1];
    for (int i = 0; i<size; i++){
        res[size-i-1] = str1[i];
    }
    res[size] = '\0';
    return res;
}

char* deleteVowels(char* str){
    char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    int size = strlen(str);
    char* res = new char[size];
    int k = 0;
    for (int i = 0; i<size; i++){
        bool isVowel = false;
        for (int j = 0; j<strlen(vowels); j++){
            if (str[i] == vowels[j]){
                isVowel = true;
                break;
            }
        }
        if (!isVowel){
            res[k] = str[i];
            k++;
        }
    }
    res[k+1] = '\0';
    return res;
}

void destroyString(char* str){
    delete[] str;
}

bool less(char a, char b){
    return (a<b);
}

void sort(char* str){
    int size = strnlen(str, BUF_SIZE);
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-i-1; j++){
            if (less(str[j+1], str[j])){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

void upperCaseToLowerCase(char* str){
    int size = strnlen(str, BUF_SIZE);
    for (int i = 0; i<size; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        } 
    }
}

int main(){
    char str[] = "abdce";
    char* ans = deleteVowels(str);
    std::cout << ans << std::endl;
    sort(ans);
    std::cout << ans << std::endl;
    destroyString(ans);
    char capital[] = "BBCda";
    std::cout << "Uppercase: " << capital << std::endl;
    upperCaseToLowerCase(capital);
    std::cout << "Lowercase: " << capital << std::endl;
    
}
