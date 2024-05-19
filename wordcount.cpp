
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int count = 0; // ��¼�ַ����ߵ�������

    if (argc < 3)
    {
        printf("���ṩ��ȷ�Ĳ�����-c �� -w �ļ���\n");
        return 1;
    }

    if ((file = fopen(argv[2], "r")) == NULL)
    {
        printf("�޷����ļ�\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) // ͳ���ַ�����
    {
        char character;
        while ((character = fgetc(file)) != EOF)
        {
            count++;
        }
        printf("�ַ���=%d\n", count);
    }
    else if (strcmp(argv[1], "-w") == 0) // ͳ�Ƶ�������
    {
        char word[1024];
        while (fscanf(file, "%s", word) != EOF)
        {
            count++;
        }
        printf("������=%d\n", count);
    }

    fclose(file);
    return 0;
}
