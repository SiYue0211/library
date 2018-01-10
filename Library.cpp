#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define SIZE 100
#define AMOUNT 50
#include "Library.h"
using namespace std;

book books[SIZE];
reader stud[AMOUNT];

int return_back()
{
	cout << "�밴���κμ� ";
	_getch();
	return 0;
}

char *reader::getname()
{
	return name;
}

int reader::getnum()
{
	return num;
}

char *reader::getgrade()
{
	return grade;
}

char *reader::getclas()
{
	return clas;
}

char *reader::getsex()
{
	return sex;
}

char *reader::getbook_name()
{
	return book_name;
}

char *reader::getdate()
{
	return date;
}

int reader::getavaiday()
{
	return avai_days;
}

int reader::setname(char *names)
{
	strcpy_s(name, 10, names);
	return 0;
}

int reader::setnum(int nums)
{
	num = nums;
	return 0;
}

int reader::setgrade(char * grades)
{
	strcpy_s(grade, 10, grades);
	return 0;
}

int reader::setclas(char *clases)
{
	strcpy_s(clas, 10, clases);
	return 0;
}

int reader::setsex(char *sexs)
{
	strcpy_s(sex, 10, sexs);
	return 0;
}

int reader::setbook_name(char *book_names)
{
	strcpy_s(book_name, 50, book_names);
	return 0;
}

int reader::setdate(char *dates)
{
	strcpy_s(date, 10, dates);
	return 0;
}

int reader::setavaiday(int avaiday)
{
	avai_days = avaiday;
	return 0;
}

int page_title()
{
	system("cls");	//����
	cout << "            **********************************************         " << endl;
	cout << "            * ����        ��ӭ����ͼ�����ϵͳ       ���� *\n" << endl;
	cout << "            **********************************************         " << endl;
	return 0;

}

book::book()
{
	system("color 17");
	reader read;
menu:
	page_title();
	cout << "                                   �����˵���  " << endl << endl << endl;
	cout << "                               * * * * * * * * * * * " << endl;
	cout << "                               *    1.��    ��     * " << endl << endl;
	cout << "                               *    2.��    ��     * " << endl << endl;
	cout << "                               *    3.�鼮����     * " << endl << endl;
	cout << "                               *    4.���߹���     * " << endl << endl;
	cout << "                               *    5.��    ��     * " << endl << endl;
	cout << "                               *    0.��    ��     * " << endl;
	cout << "                               * * * * * * * * * * *" << endl << endl;
	cout << "                      ���������ѡ��:";
	switch (_getch())
	{
	case '1':book_out(); break;
	case '2':book_in(); break;
	case '3':book1(); break;
	case '4':read.read1(); break;
	case '5':search(); break;
	case '0':exit(0); break;
	default:system("cls");
		page_title();
		cout << "\n������������һ�飡" << endl;
	}
	goto menu;

}

int book::book1()
{
	system("cls");
	page_title();
	cout << "                                   ������" << endl << endl << endl;
	cout << "                               * * * * * * * * * * *" << endl;
	cout << "                               *    1.�����鼮     * " << endl << endl;
	cout << "                               *    2.ע���鼮     * " << endl << endl;
	cout << "                               *    3.�޸��鼮     * " << endl << endl;
	cout << "                               *    0.��    ��     *" << endl;
	cout << "                               * * * * * * * * * * * " << endl << endl;
	cout << "                     ���������ѡ��:";
	switch (_getch())
	{
	case '1':book_add(); break;
	case '2':book_del(); break;
	case '3':book_mod(); break;
	case '0':return_back(); break;
	default:system("cls");
		cout << "\n������������һ�飡" << endl;
	}
	return 0;
}

int book::book_add()
{
	FILE *bfg;
	int i, n;
	page_title();
	cout << "                              �������鼮��" << endl;
	cout << ">>>�����������Ϣ<<<" << endl;
	fopen_s(&bfg, "books", "a+");
	if (bfg == NULL)
		cout << "�ļ�����" << endl;
	for (n = 0; n < SIZE; n++)
	{
		fread(&books[n], sizeof(books[n]), 1, bfg);
		if (books[n].id == 0)
			break;
	}
	fclose(bfg);
	do
	{
		cout << "������һ���µ���ţ���Ŵ�1001��ʼ�������벻ͬ���Ѵ��ڵ���ţ�:";
		cin >> books[n].id;
		for (i = 0; i < SIZE; i++)
		{
			if (books[n].id == books[i].id&&n != i)
			{
				cout << "\n�������Ѿ�����. " << endl;
				break;
			}
		}
	} while (books[n].id == books[i].id);
	cout << "����: ";
	cin >> books[n].name;
	cout << "����: ";
	cin >> books[n].writer;
	cout << "�۸�: ";
	cin >> books[n].price;
	cout << "�ܴ���: ";
	cin >> books[n].total;
	cout << "�ִ���: ";
	cin >> books[n].store;
	cout << "������: ";
	cin >> books[n].publish;
	cout << "����ʱ��: ";
	cin >> books[n].pub_time;
	cout << "������: ";
	cin >> books[n].borrower;
	cout << "������ѧ��: ";
	cin >> books[n].borr_num;
	fopen_s(&bfg, "books", "wb");
	for (n = 0; n < SIZE; n++)
		fwrite(&books[n], sizeof(books[n]), 1, bfg);
	fclose(bfg);
	cout << "\n�����Ѿ����.\n" << endl;
	return 0;


}

int book::book_del()
{
	FILE *bfg;
	int i, id, s;
	int MAX_BOOKS;
	page_title();
	cout << "                               ��ע�������" << endl;
	fopen_s(&bfg, "books", "a+");
	if (bfg == 0)
	{
		cout << "�޷����ļ�;" << endl;
	}
	for (i = 0; i < SIZE; i++)
	{
		fread(&books[i], sizeof(books[i]), 1, bfg);
		if (books[i].id == 0)
		{
			MAX_BOOKS = i;
			break;
		}
	}
	fclose(bfg);
	for (i = 0; i < MAX_BOOKS; i++)
	{
		cout << "����: " << books[i].name << endl;
		cout << "���: " << books[i].id << endl;
		cout << "����: " << books[i].writer << endl;
		cout << "�۸�: " << books[i].price << endl;
		cout << "�ܴ���: " << books[i].total << endl;
		cout << "�ִ���: " << books[i].store << endl;
		cout << "������: " << books[i].publish << endl;
		cout << "����ʱ��: " << books[i].pub_time << endl;
		cout << "����: " << books[i].borrower << endl;
		cout << "����ѧ��: " << books[i].borr_num << endl;
		cout << "**********************************************************" << endl;
	}
	cout << "\n��������ţ�";
	cin >> id;
	for (i = 0, s = -1; i < MAX_BOOKS; i++)
	{
		if (books[i].id == id)
		{
			cout << "����: " << books[i].name << endl;
			cout << "���: " << books[i].id << endl;
			cout << "����: " << books[i].writer << endl;
			cout << "�۸�: " << books[i].price << endl;
			cout << "�ܴ���: " << books[i].total << endl;
			cout << "�ִ���: " << books[i].store << endl;
			cout << "������: " << books[i].publish << endl;
			cout << "����ʱ��: " << books[i].pub_time << endl;
			cout << "����: " << books[i].borrower << endl;
			cout << "����ѧ��: " << books[i].borr_num << endl;
			cout << "**********************************************************" << endl;
			cout << "�����Ƿ�ȷ��ע������(1Ϊ��,0Ϊ��): ";
			cin >> s;
			if (s == 1)
			{
				for (; i < SIZE; i++)
				{
					books[i] = books[i + 1];
				}
			}
			else if (s == 0)
			{
				cout << "δע����" << endl;
				return 0;
			}
		}
	}
	if (s == -1)
	{
		cout << "���鲻���ڣ�" << endl;
	}
	fopen_s(&bfg, "books", "wb");
	if (bfg == 0)
	{
		cout << "�޷����ļ���";
	}
	for (i = 0; i < SIZE; i++)
	{
		fwrite(&books[i], sizeof(books[i]), 1, bfg);
	}
	fclose(bfg);
	_getch();
	return 0;
}

int book::book_mod()
{
	FILE *bfg;
	int i, id, s, n;
	int MAX_BOOKS;
	page_title();
	cout << "                               ���޸��鼮��" << endl;
	fopen_s(&bfg, "books", "rb");
	if (bfg == 0)
	{
		cout << "�޷����ļ�" << endl;
	}
	for (i = 0; i < SIZE; i++)
	{
		fread(&books[i], sizeof(books[i]), 1, bfg);
		if (books[i].id == 0)
		{
			MAX_BOOKS = i;
			break;
		}
	}
	fclose(bfg);
	for (i = 0; i < MAX_BOOKS; i++)
	{
		cout << "����:" << books[i].name << endl;
		cout << "���: " << books[i].id << endl;
		cout << "����: " << books[i].writer << endl;
		cout << "�۸�: " << books[i].price << endl;
		cout << "�ܴ���: " << books[i].total << endl;
		cout << "�ִ���: " << books[i].store << endl;
		cout << "������: " << books[i].publish << endl;
		cout << "����ʱ��: " << books[i].pub_time << endl;
		cout << "����: " << books[i].borrower << endl;
		cout << "����ѧ��: " << books[i].borr_num << endl;
		cout << "**********************************************************" << endl;
	}
	cout << "���������:";
	cin >> id;
	for (i = 0, s == 0; i < MAX_BOOKS; i++)
	{
		if (books[i].id == id)
		{
			cout << "����:" << books[i].name << endl;
			cout << "���: " << books[i].id << endl;
			cout << "����: " << books[i].writer << endl;
			cout << "�۸�: " << books[i].price << endl;
			cout << "�ܴ���: " << books[i].total << endl;
			cout << "�ִ���: " << books[i].store << endl;
			cout << "������: " << books[i].publish << endl;
			cout << "����ʱ��: " << books[i].pub_time << endl;
			cout << "����: " << books[i].borrower << endl;
			cout << "����ѧ��: " << books[i].borr_num << endl;

			cout << "**********************************************************" << endl;
			cout << "�Ƿ�ȷ���޸ĸ��鼮(1Ϊ��,0Ϊ��):";
			cin >> s;
			if (s == 1)
			{
				page_title();
				cout << ">>>�����������鼮����Ϣ:<<<" << endl;
				do
				{
					cout << endl << "������һ���µ���ţ�ѧ�Ŵ�1001��ʼ�������벻ͬ���Ѵ��ڵ���ţ���";
					cin >> books[i].id;
					for (n = 0; n < SIZE; n++)
					{
						if (books[i].id == books[n].id&&n != i)
						{
							cout << "������Ѵ���. " << endl; break;
						}
					}
				} while (books[i].id == books[n].id);
				cout << "����: ";
				cin >> books[i].name;
				cout << "����: ";
				cin >> books[i].writer;
				cout << "�۸�: ";
				cin >> books[i].price;
				cout << "�ܴ���: ";
				cin >> books[i].total;
				cout << "�ִ���: ";
				cin >> books[i].store;
				cout << "������: ";
				cin >> books[i].publish;
				cout << "����ʱ��: ";
				cin >> books[i].pub_time;
				cout << "������: ";
				cin >> books[i].borrower;
				cout << "������ѧ��: ";
				cin >> books[i].borr_num;
			}
			else if (s == 0)
			{
				return 0;
			}
		}

	}
	if (s == -1)
	{
		cout << "���鲻���ڣ�" << endl;
	}
	fopen_s(&bfg, "books", "wb");
	if (bfg == 0)
	{
		cout << "�޷����ļ�" << endl;
	}
	for (i = 0; i < SIZE; i++)
	{
		fwrite(&books[i], sizeof(books[i]), 1, bfg);
	}
	fclose(bfg);
	_getch();
	return 0;


}

int reader::read1()
{
	system("cls");
	page_title();
	cout << "                                    ������\n" << endl << endl << endl;
	cout << "                               * * * * * * * * * * *" << endl;
	cout << "                               *    1.���Ӷ���     *" << endl << endl;
	cout << "                               *    2.ע������     *" << endl << endl;
	cout << "                               *    3.�޸Ķ���     *" << endl << endl;
	cout << "                               *    0.��    ��     *" << endl;
	cout << "                               * * * * * * * * * * *" << endl << endl;
	cout << "                     ���������ѡ��:";
	switch (_getch())
	{
	case'1':reader_add(); break;
	case'2':reader_del(); break;
	case'3':reader_mod(); break;
	case'0':return_back(); break;
	default:system("cls");
		cout << "\n������������һ��!\n";
	}
	return 0;

}

int reader::reader_add()
{
	FILE *sfg;
	int i, n;
	page_title();
	cout << "                              �����Ӷ��ߡ�" << endl;
	cout << ">>>��������ߵ���Ϣ<<< " << endl;
	fopen_s(&sfg, "students", "a+");
	for (n = 0; n < AMOUNT; n++)
	{
		fread(&stud[n], sizeof(stud[n]), 1, sfg);
		if (stud[n].num == 0)
			break;
	}
	fclose(sfg);
	for (i = 0; i < n; i++)
	{
		cout << stud[i].num << endl;
	}
	do
	{
		cout << "������һ���µ�ѧ�ţ�ѧ�Ŵ�1001��ʼ�������벻ͬ���Ѵ��ڵ�ѧ�ţ�:";
		cin >> stud[n].num;
		for (i = 0; i <= n; i++)
		{
			if (stud[i].num == stud[n].num && n != i)
			{
				cout << endl << "���ѧ���Ѿ����ڣ�" << endl;
				break;
			}
		}
	} while (stud[n].num == stud[i].num);
	cout << "����: ";
	cin >> stud[n].name;
	cout << "�꼶: ";
	cin >> stud[n].grade;
	cout << "�༶: ";
	cin >> stud[n].clas;
	cout << "�Ա�: ";
	cin >> stud[n].sex;
	cout << "����: ";
	cin >> stud[n].book_name;
	cout << "��������: ";
	cin >> stud[n].date;
	cout << "�ɽ�����: ";
	cin >> stud[n].avai_days;
	fopen_s(&sfg, "students", "wb");
	for (n = 0; n < AMOUNT; n++)
	{
		fwrite(&stud[n], sizeof(stud[n]), 1, sfg);
	}
	fclose(sfg);
	cout << endl << "�ö��������." << endl;
	_getch();
	return 0;

}

int reader::reader_del()        //����ɾ�����ߵĺ���
{
	FILE *sfp;
	int i, num, s, n;
	page_title();
	cout << "                              ��ע�����ߡ�" << endl;
	fopen_s(&sfp, "students", "rb");
	if (sfp == 0)
	{
		cout << "�޷����ļ�. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fread(&stud[i], sizeof(stud[i]), 1, sfp);
		if (stud[i].num == 0)
			break;
	}
	fclose(sfp);
	for (n = 0; n < i; n++)
	{
		cout << stud[n].num << endl;
	}
	cout << endl << "������ѧ��: ";
	cin >> num;
	for (i = 0, s == -1; i < AMOUNT; i++)
	{
		if (stud[i].num == num)
		{
			cout << "����: " << stud[i].name << endl;
			cout << "ѧ��: " << stud[i].num << endl;
			cout << "�꼶: " << stud[i].grade << endl;
			cout << "�༶: " << stud[i].clas << endl;
			cout << "�Ա�: " << stud[i].sex << endl;
			cout << "����: " << stud[i].book_name << endl;
			cout << "��������: " << stud[i].date << endl;
			cout << "�ɽ�����: " << stud[i].avai_days << endl;
			cout << "********************************************************** " << endl;
			cout << "�Ƿ�ȷ��ע���ö���(1Ϊ��,0Ϊ��): ";
			cin >> s;
			if (s == 1)
			{
				for (; i < AMOUNT; i++)
					stud[i] = stud[i + 1];
			}
			else if (s == 0)
			{

				return 0;
			}
			if (s == -1)
			{
				cout << "�ö��߲�����.";
			}
		}
	}
	fopen_s(&sfp, "students", "wb");
	if (sfp == 0)
	{
		cout << "�޷����ļ�. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fwrite(&stud[i], sizeof(stud[i]), 1, sfp);
	}
	fclose(sfp);
	_getch();
	return 0;
}

int reader::reader_mod()            //�����޸Ķ��ߵĺ���
{

	FILE *sfp;
	int i, num, s, n;
	page_title();
	cout << "                              ���޸Ķ��ߡ�" << endl;
	fopen_s(&sfp, "students", "rb");
	if (sfp == 0)
	{
		cout << "�޷����ļ�. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fread(&stud[i], sizeof(stud[i]), 1, sfp);
	}
	fclose(sfp);
	cout << endl << "������ѧ��: ";
	cin >> num;
	for (i = 0, s == -1; i < AMOUNT; i++)
	{
		if (stud[i].num == num)
		{
			cout << "����:" << stud[i].name << endl;
			cout << "ѧ��: " << stud[i].num << endl;
			cout << "�꼶: " << stud[i].grade << endl;
			cout << "�༶: " << stud[i].clas << endl;
			cout << "�Ա�: " << stud[i].sex << endl;
			cout << "����: " << stud[i].book_name << endl;
			cout << "��������: " << stud[i].date << endl;
			cout << "�ɽ�����: " << stud[i].avai_days << endl;

			cout << "********************************************************** " << endl;
			cout << "�Ƿ�ȷ���޸ĸö���(1Ϊ��,0Ϊ��): ";
			cin >> s;
			if (s == 1)
			{
				page_title();
				cout << ">>>������������ߵ���Ϣ.<<<" << endl;
				do
				{
					cout << "������һ���µ�ѧ�ţ�ѧ�Ŵ�1001��ʼ�������벻ͬ���Ѵ��ڵ�ѧ�ţ���";
					cin >> stud[i].num;
					for (n = 0; n < AMOUNT; n++)
					{
						if (stud[i].num == stud[n].num&&n != i)
						{
							cout << "��ѧ���Ѵ���." << endl; break;
						}
					}
				} while (stud[i].num == stud[n].num);
				cout << "����: ";
				cin >> stud[i].name;
				cout << "�꼶: ";
				cin >> stud[i].grade;
				cout << "�༶: ";
				cin >> stud[i].clas;
				cout << "�Ա�: ";
				cin >> stud[i].sex;
				cout << "����: ";
				cin >> stud[i].book_name;
				cout << "��������: ";
				cin >> stud[i].date;
				cout << "�ɽ�����: ";
				cin >> stud[i].avai_days;

			}
			else if (s == 0)
			{

				return 0;
			}
		}

	}
	if (s == -1)
	{
		cout << "�ö��߲�����. " << endl;
	}
	fopen_s(&sfp, "students", "wb");
	if (sfp == 0)
	{
		cout << "�޷����ļ�. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fwrite(&stud[i], sizeof(stud[i]), 1, sfp);
	}
	fclose(sfp);
	_getch();
	return 0;
}

int book::book_out()                      //������麯��
{
	FILE *bfp, *sfp;
	int MAX_STUDENTS, MAX_BOOKS;
	int id, i, s, num, avaiday, p;
	char dates[10];
	page_title();
	cout << "                                  ������\n";
	cout << "���������:";
	cin >> id;
	fopen_s(&bfp, "books", "rb");
	if (bfp == 0)
		cout << "�޷����ļ�.\n";
	for (i = 0; i < SIZE; i++)
	{
		fread(&books[i], sizeof(books[i]), 1, bfp);
		if (books[i].id == 0)
		{
			MAX_BOOKS = i;
			break;
		}
	}
	fclose(bfp);

	for (i = 0; i < MAX_BOOKS; i++)
	{
		if (id == books[i].id&&books[i].id != 0)
		{
			system("cls");
			page_title();
			cout << "                                �������Ϣ��\n";
			cout << "����: " << books[i].name << endl;
			cout << "���: " << books[i].id << endl;
			cout << "����: " << books[i].writer << endl;
			cout << "�۸�: " << books[i].price << endl;
			cout << "�ܴ���: " << books[i].total << endl;
			cout << "�ִ���: " << books[i].store << endl;
			cout << "������: " << books[i].publish << endl;
			cout << "����ʱ��: " << books[i].pub_time << endl;
			cout << "����: " << books[i].borrower << endl;
			cout << "����ѧ��: " << books[i].borr_num << endl;

			cout << "**********************************************************\n";
			fopen_s(&sfp, "students", "rb");
			if (sfp == 0)
			{
				cout << "students �ļ���ʧ��" << endl;
			}
			for (s = 0; s < AMOUNT; s++)
			{
				fread(&stud[s], sizeof(stud[s]), 1, sfp);
				if (stud[s].getnum() == 0)
				{
					MAX_STUDENTS = s;
					break;
				}
			}
			for (s = 0; s < MAX_STUDENTS; s++)
			{
				cout << stud[s].getnum() << endl;
			}
			cout << "max_students=" << MAX_STUDENTS << endl;
			fclose(sfp);
			cout << "�����������ѧ��:";
			cin >> num;
			for (s = 0; s < MAX_STUDENTS; s++)
			{
				if (stud[s].getnum() == num)
				{
					if (books[s].store != 0)
					{
						cout << "������ɽ������:\n";
						cin >> avaiday;
						stud[s].setavaiday(avaiday);
						cout << "�������������:\n";
						cin >> dates;
						stud[s].setdate(dates);
						books[i].store--;
						stud[s].setbook_name(books[i].name);
						strcpy_s(books[i].borrower, 10, stud[s].getname());
						cout << "���Ѿ��ɹ����飡" << endl;
						fopen_s(&sfp, "students", "wb");
						for (p = 0; p < MAX_STUDENTS; p++)
						{
							fwrite(&stud[p], sizeof(stud[p]), 1, sfp);
						}
						fclose(sfp);
						fopen_s(&bfp, "books", "wb");
						for (p = 0; p < MAX_BOOKS; p++)
						{
							fwrite(&books[p], sizeof(books[p]), 1, sfp);
						}
						fclose(bfp);
						break;
					}
					else if (books[i].store == 0)
					{
						cout << "����ݲ��Ѿ�ȫ��������" << endl;
						break;
					}
				}
			}
			if (MAX_STUDENTS == s && stud[MAX_STUDENTS - 1].getnum() != num)
			{
				cout << "�����ڸ�ѧ����" << endl;
			}
			break;
		}
	}
	if (i == MAX_BOOKS)
	{
		cout << "�����ڸ�����Ϣ" << endl;
	}
	_getch();
	return 0;
}

int book::book_in()
{
	FILE *sfp, *bfp;
	int i, j, id, num;
	int MAX_BOOKS, MAX_STUDENTS;
	page_title();
	cout << "                                ����\n";
	fopen_s(&sfp, "students", "rb");
	for (i = 0; i < SIZE; i++)
	{
		fread(&stud[i], sizeof(stud[i]), 1, sfp);
		if (stud[i].getnum() == 0)
		{
			MAX_STUDENTS = i;
			break;
		}
	}
	fclose(sfp);
BEFORE:cout << "������ѧ��ѧ��:";
	cin >> num;
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		if (stud[i].getnum() == num)
		{
			cout << "����:" << stud[i].getname() << endl;
			cout << "ѧ��: " << stud[i].getnum() << endl;
			cout << "�꼶: " << stud[i].getgrade() << endl;
			cout << "�༶: " << stud[i].getclas() << endl;
			cout << "�Ա�: " << stud[i].getsex() << endl;
			cout << "����: " << stud[i].getbook_name() << endl;
			cout << "��������: " << stud[i].getdate() << endl;
			cout << "�ɽ�����: " << stud[i].getavaiday() << endl;
			cout << "********************************************************** " << endl;
		AGAIN:cout << "�����뻹���ţ�";
			cin >> id;
			fopen_s(&bfp, "books", "rb");
			if (bfp == 0)
			{
				cout << "�޷���books�ļ�" << endl;
				return 0;
			}
			for (j = 0; j < SIZE; j++)
			{
				fread(&books[j], sizeof(books[j]), 1, bfp);
				if (books[j].id == 0)
				{
					MAX_BOOKS = j;
					break;
				}
			}
			for (j = 0; j < MAX_BOOKS; j++)
			{
				if (books[j].id == id)
				{
					books[j].borr_num = NULL;
					strcpy_s(books[j].borrower, 10, "NONE");
					books[j].store++;
					stud[i].setavaiday(0);
					stud[i].setbook_name("NONE");
					stud[i].setdate("NONE");
					cout << "�ɹ����飡" << endl;
					break;
				}
			}
			if (j == MAX_BOOKS)
			{
				cout << "����������������������룺" << endl;
				goto AGAIN;
			}
			
			fopen_s(&bfp, "books", "rb");
			for (j = 0; j < SIZE; j++)
			{
				fwrite(&books[j], sizeof(books[j]), 1, bfp);
			}
			fclose(bfp);
			break;
		}
	}
	if (i == MAX_STUDENTS)
	{
		cout << "��ѧ��ѧ�������ڣ�����������\n";
		goto BEFORE;
	}

	fopen_s(&sfp, "students", "wb");
	if (sfp == 0)
		cout << "���ļ�studentsʧ��" << endl;
	for (j = 0; j < AMOUNT; j++)
	{
		fwrite(&stud[j], sizeof(stud[j]), 1, sfp);
	}
	fclose(sfp);

	_getch();
	return 0;
}

int book::search()
{
	return 0;
}
int main()
{
	book b1;
	system("pause");
	return 0;
}

