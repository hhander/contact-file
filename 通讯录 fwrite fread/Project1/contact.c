#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct contact* ps)
{
	/*memset(ps->date, 0, sizeof(ps->date));*/
	ps->date = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->date == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}

void check_capacity(struct contact* ps);

void LoadContact(struct contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, p fRead))
	{
		check_capacity(ps);
		ps->date[ps->size] = tmp;+
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}
void check_capacity(struct contact* ps)
{
	if (ps->capacity == ps->size)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->date, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("����success");
		}
		else
		{
			printf("ʧ��");
		}
	}
}
void Add_contact(struct contact* ps)
{
	check_capacity(ps);

	printf("����������");
	scanf("%s", ps->date[ps->size].name);
	printf("������绰");
	scanf("%s", ps->date[ps->size].tele);
	printf("�������Ա�");
	scanf("%s", ps->date[ps->size].sex);
	printf("������סַ");
	scanf("%s", ps->date[ps->size].addr);
	printf("����������");
	scanf("%d", &ps->date[ps->size].age);
	printf("¼��ɹ�");
	ps->size++;
	/*if (ps->size == MAX)
	{
		printf("ͨѶ¼����");
	}
	else
	{
		printf("����������");
		scanf("%s", ps->date[ps->size].name);
		printf("������绰");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������Ա�");
		scanf("%s", ps->date[ps->size].sex);
		printf("������סַ");
		scanf("%s", ps->date[ps->size].addr);
		printf("����������");
		scanf("%d", &ps->date[ps->size].age);
		printf("¼��ɹ�");
		ps->size++;
	}*/
}

void ShowContact(struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("Ŀ¼Ϊ��");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n", ps->date[i].name, ps->date[i].age, ps->date[i].sex,
				ps->date[i].tele, ps->date[i].addr);
		}
	}
}

int FindName(char name[],struct contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(name, ps->date[i].name))
		{
			return i;
		}
	}
	return -1;

}

void DelContact(struct contact* ps)
{
	printf("����������");
	char name[30];
	scanf("%s", &name);
	int ret = FindName(name,ps);
	if (ret == -1)
	{
		printf("û�������");
	}
	else
	{
		int j = 0;
		for (j = ret; j < (ps->size)-1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("�ɹ�");
	}
}

void Research_contact(struct contact* ps)
{
	printf("�����뱻����������");
	char name[30];
	scanf("%s", &name);
	int pos = FindName(name, ps);
	if (pos == -1)
	{
		printf("���޴���");
	}
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n", ps->date[pos].name, ps->date[pos].age, ps->date[pos].sex,
				ps->date[pos].tele, ps->date[pos].addr);
	}
}

void Modify_contact(struct contact* ps)
{
	printf("�����뱻�����˵�����\n");
	char name[30];
	scanf("%s", &name);
	int pos = FindName(name, ps);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("����������\n");
		scanf("%s", ps->date[pos].name);
		printf("������绰\n");
		scanf("%s", ps->date[pos].tele);
		printf("�������Ա�\n");
		scanf("%s", ps->date[pos].sex);
		printf("������סַ\n");
		scanf("%s", ps->date[pos].addr);
		printf("����������\n");
		scanf("%d", &ps->date[pos].age);
		printf("�޸ĳɹ�\n");
	}

}

int SortbyName(void* a, void* b)
{
	return strcmp((*(struct contact*)a).date->name, (*(struct contact*)b).date->name);
}

int SortbyAge(void* a, void* b)
{
	return (*(struct contact*)a).date->age - (*(struct contact*)b).date->age;
}


void Sort_contact(struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{ 
	printf("�����������밴1,�����������밴2,�����밴0\n");
	int i = 0;
	scanf("%d", &i);
	if (i == 1)
	{
		qsort(ps, ps->size, sizeof(ps->date[0]), SortbyName);
		printf("�޸ĳɹ�\n");
	}
	else if (i == 2)
		{
			qsort(ps, ps->size, sizeof(ps->date[0]), SortbyAge);
			printf("�޸ĳɹ�\n");
		}
	else if (i == 0)
		{
			printf("���سɹ�\n");
		}
	else
		{
			printf("�������\n");
		}
	}
}

void DestroyContact(struct contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}


void SaveContact(struct contact* ps)
{
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("Savecontact::%s", strerror(errno));
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&ps->date[i], sizeof(struct PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}