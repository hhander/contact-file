#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu()
{
	printf("******************************\n");
	printf("*****  1. Add       2.Del  ***\n");
	printf("*****  3. Research  4.Modify**\n");
	printf("*******5. Show      6.Sort  **\n");
	printf("*******7. Save      0.Quit  **\n");
	printf("******************************\n");
}



int main()
{
	struct contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("������");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
		{
			Add_contact(&con);
			break;
		}
		case Del:
		{
			DelContact(&con);
			break;
		}
		case Research:
		{
			Research_contact(&con);
		    break;
		}
		case Modify:
		{
			Modify_contact(&con);
			break;
		}
		case Show:
		{
			ShowContact(&con);
			break;
		}
		case Sort:
		{
			Sort_contact(&con);
			break;
		}
		case Quit:
		{
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳��ɹ�");
		     break;
		}
		case Save:
		{
			SaveContact(&con);
			break;
		}
		default :
		{
			printf("�������");
			break;
		}
		}

	} while (input);
	return 0;
}