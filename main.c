#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[]) {
    
    struct Sysinfo {
        char krnl_name[100];
        char krnl_version[100];
        char netwrk_name[100];
        char os[100];
    }sysinfo;

    char * list_of_cmds[4] = {
        "uname -s > DATA.TXT", // Kernal name
        "uname -r >> DATA.TXT", // Kernal version
        "uname -n >> DATA.TXT", // Network hostname
        "uname -o >> DATA.TXT"}; // Operating system

    for(int i=0;i<4;i++) {
        char * cmd = list_of_cmds[i];
        system(cmd);
    }
    
    
    FILE *data;
    data = fopen("DATA.TXT", "r");
    
    if (data == NULL) {
        return -1;
    }
    
    fgets(sysinfo.krnl_name,255,data);
    fgets(sysinfo.krnl_version,255,data);
    fgets(sysinfo.netwrk_name,255,data);
    fgets(sysinfo.os,255,data); 
    
    printf("Kernal Name: %s\n"
          "Kernal Version: %s\n"
          "Host Hostname: %s\n"
          "Os: %s",sysinfo.krnl_name,sysinfo.krnl_version,
          sysinfo.netwrk_name,sysinfo.os);
    
    fclose(data); 
    return 0;
}
