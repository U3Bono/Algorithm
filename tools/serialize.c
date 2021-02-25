#include "../include/tools/serialize.h"

char flag[20] = "slz_";

int write_table(void *node_list, int length, char *file_name)
{
    FILE *fp;
    char *fn = safe_strcat(flag, file_name);
    if ((fp = fopen(fn, "wb")) != NULL)
    {
        fwrite(node_list, 1, length, fp);
    }
    else
    {
        printf("file open error!\n");
        return 0;
    }
    free(fn);
    return fclose(fp);
}

int add_table(void *node_list, int length, char *file_name)
{
    FILE *fp;
    char *fn = safe_strcat(flag, file_name);
    if ((fp = fopen(fn, "ab")) != NULL)
    {
        fwrite(node_list, 1, length, fp);
    }
    else
    {
        printf("file open error!\n");
        return 0;
    }
    free(fn);
    return fclose(fp);
}

int read_table(void *node_list, int start, int length, char *file_name)
{
    FILE *fp;
    char *fn = safe_strcat(flag, file_name);
    if ((fp = fopen(fn, "rb")) != NULL)
    {
        fseek(fp, start, 0);
        fread(node_list, 1, length, fp);
    }
    else
    {
        printf("file open error!\n");
        return 0;
    }
    free(fn);
    return fclose(fp);
}