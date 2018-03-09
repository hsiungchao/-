#include<stdio.h>  
#include<string.h>  
#include<errno.h>  
#include<unistd.h>  
#include<dirent.h>  
#include<sys/types.h>  
#include<sys/stat.h>  
  
extern int errno;  
  
#define MODE (S_IRWXU | S_IRWXG | S_IRWXO)  
  
int mk_dir(char *dir) {  
    DIR *mydir = NULL;  
    if ((mydir= opendir(dir))==NULL) {  //判断目录   
        int ret = mkdir(dir, MODE);       //创建目录  
        if (ret != 0) {  
            return -1;  
        }  
        printf("%s created sucess!/n", dir);  
    } else {  
        printf("%s exist!/n", dir);  
    }  
    return 0;  
}  
  
int mk_all_dir(char *dir) {  
    bool flag = true;  
    char *pDir = dir;  
    while (flag) {  
        char *pIndex = index(pDir, '/');  
        if (pIndex != NULL && pIndex != dir) {  
            char buffer[512] = {0};  
            int msg_size = pIndex - dir;  
            memcpy(buffer, dir, msg_size);  
            int ret = mk_dir(buffer);  
            if (ret < 0) {  
                printf("%s created failed!/n", dir);  
            }  
        } else if (pIndex == NULL && pDir == dir) {  
            printf("dir is not directory!/n");  
            return -1;  
        } else if (pIndex == NULL && pDir != dir) {  
            int ret = mk_dir(dir);  
            if (ret < 0) {  
                printf("%s created failed!/n", dir);  
            }  
            break;  
        }  
        pDir = pIndex+1;  
    }  
    return 0;  
}  
  
int main() {  
    char buffer[512] = {0};  
    printf("please input path mane/n");  
    fgets(buffer, sizeof(buffer), stdin);  
    char *pIndex = index(buffer, '/n');  
    if (pIndex != NULL) {  
        *pIndex = '/0';  
    }  
    printf("check path mane %s/n", buffer);  
    int ret = mk_all_dir(buffer);  
    if (ret < 0) {  
        printf("%s mkdir failed!/n", buffer);  
        return -1;  
    }  
    return 0;  
}  