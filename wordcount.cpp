
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int count = 0; // 记录字符或者单词总数

    if (argc < 3)
    {
        printf("请提供正确的参数：-c 或 -w 文件名\n");
        return 1;
    }

    if ((file = fopen(argv[2], "r")) == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) // 统计字符总数
    {
        char character;
        while ((character = fgetc(file)) != EOF)
        {
            count++;
        }
        printf("字符数=%d\n", count);
    }
    else if (strcmp(argv[1], "-w") == 0) // 统计单词总数
    {
        char word[1024];
        while (fscanf(file, "%s", word) != EOF)
        {
            count++;
        }
        printf("单词数=%d\n", count);
    }

    fclose(file);
    return 0;
}
