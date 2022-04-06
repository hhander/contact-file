#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max_name 20
#define max_tele 15
#define max_sex 10
#define max_addr 30
#define MAX 1000
#define DEFAULT_SZ 3

enum option
{
	Quit,
	Add,
	Del,
	Research,
	Modify,
	Show,
	Sort,
	Save
};


typedef struct PeoInfo
{
	char name[20];
	char tele[15];
	char sex[10];
	char addr[30];
	int age;
}PeoInfo;

typedef struct contact
{
	struct PeoInfo* date;
	int capacity;
	int size;
}contact;

void InitContact(struct contact* ps);
void Add_contact(struct contact* ps);
void ShowContact(struct contact* ps);
void DelContact(struct contact * ps);
void Research_contact(struct contact* ps);
void Modify_contact(struct contact* ps);
void Sort_contact(struct contact* ps);
void DestroyContact(struct contact* ps);
void SaveContact(struct contact* ps);
void LoadContact(struct contact* ps);
