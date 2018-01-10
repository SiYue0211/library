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
	cout << "请按下任何键 ";
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
	system("cls");	//清屏
	cout << "            **********************************************         " << endl;
	cout << "            * ☆★☆        欢迎来到图书管理系统       ☆★☆ *\n" << endl;
	cout << "            **********************************************         " << endl;
	return 0;

}

book::book()
{
	system("color 17");
	reader read;
menu:
	page_title();
	cout << "                                   ★主菜单★  " << endl << endl << endl;
	cout << "                               * * * * * * * * * * * " << endl;
	cout << "                               *    1.借    书     * " << endl << endl;
	cout << "                               *    2.还    书     * " << endl << endl;
	cout << "                               *    3.书籍管理     * " << endl << endl;
	cout << "                               *    4.读者管理     * " << endl << endl;
	cout << "                               *    5.搜    索     * " << endl << endl;
	cout << "                               *    0.退    出     * " << endl;
	cout << "                               * * * * * * * * * * *" << endl << endl;
	cout << "                      请输入你的选择:";
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
		cout << "\n错误，请再输入一遍！" << endl;
	}
	goto menu;

}

int book::book1()
{
	system("cls");
	page_title();
	cout << "                                   ☆管理☆" << endl << endl << endl;
	cout << "                               * * * * * * * * * * *" << endl;
	cout << "                               *    1.增加书籍     * " << endl << endl;
	cout << "                               *    2.注销书籍     * " << endl << endl;
	cout << "                               *    3.修改书籍     * " << endl << endl;
	cout << "                               *    0.返    回     *" << endl;
	cout << "                               * * * * * * * * * * * " << endl << endl;
	cout << "                     请输入你的选择:";
	switch (_getch())
	{
	case '1':book_add(); break;
	case '2':book_del(); break;
	case '3':book_mod(); break;
	case '0':return_back(); break;
	default:system("cls");
		cout << "\n错误，请再输入一遍！" << endl;
	}
	return 0;
}

int book::book_add()
{
	FILE *bfg;
	int i, n;
	page_title();
	cout << "                              ☆增加书籍☆" << endl;
	cout << ">>>请输入书的信息<<<" << endl;
	fopen_s(&bfg, "books", "a+");
	if (bfg == NULL)
		cout << "文件出错" << endl;
	for (n = 0; n < SIZE; n++)
	{
		fread(&books[n], sizeof(books[n]), 1, bfg);
		if (books[n].id == 0)
			break;
	}
	fclose(bfg);
	do
	{
		cout << "请输入一个新的书号（书号从1001开始，但必须不同于已存在的书号）:";
		cin >> books[n].id;
		for (i = 0; i < SIZE; i++)
		{
			if (books[n].id == books[i].id&&n != i)
			{
				cout << "\n这个书号已经存在. " << endl;
				break;
			}
		}
	} while (books[n].id == books[i].id);
	cout << "书名: ";
	cin >> books[n].name;
	cout << "作者: ";
	cin >> books[n].writer;
	cout << "价格: ";
	cin >> books[n].price;
	cout << "总存量: ";
	cin >> books[n].total;
	cout << "现存量: ";
	cin >> books[n].store;
	cout << "出版社: ";
	cin >> books[n].publish;
	cout << "出版时间: ";
	cin >> books[n].pub_time;
	cout << "借书人: ";
	cin >> books[n].borrower;
	cout << "借书者学号: ";
	cin >> books[n].borr_num;
	fopen_s(&bfg, "books", "wb");
	for (n = 0; n < SIZE; n++)
		fwrite(&books[n], sizeof(books[n]), 1, bfg);
	fclose(bfg);
	cout << "\n该书已经添加.\n" << endl;
	return 0;


}

int book::book_del()
{
	FILE *bfg;
	int i, id, s;
	int MAX_BOOKS;
	page_title();
	cout << "                               ☆注销旧书☆" << endl;
	fopen_s(&bfg, "books", "a+");
	if (bfg == 0)
	{
		cout << "无法打开文件;" << endl;
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
		cout << "书名: " << books[i].name << endl;
		cout << "书号: " << books[i].id << endl;
		cout << "作者: " << books[i].writer << endl;
		cout << "价格: " << books[i].price << endl;
		cout << "总存量: " << books[i].total << endl;
		cout << "现存量: " << books[i].store << endl;
		cout << "出版社: " << books[i].publish << endl;
		cout << "出版时间: " << books[i].pub_time << endl;
		cout << "读者: " << books[i].borrower << endl;
		cout << "读者学号: " << books[i].borr_num << endl;
		cout << "**********************************************************" << endl;
	}
	cout << "\n请输入书号：";
	cin >> id;
	for (i = 0, s = -1; i < MAX_BOOKS; i++)
	{
		if (books[i].id == id)
		{
			cout << "书名: " << books[i].name << endl;
			cout << "书号: " << books[i].id << endl;
			cout << "作者: " << books[i].writer << endl;
			cout << "价格: " << books[i].price << endl;
			cout << "总存量: " << books[i].total << endl;
			cout << "现存量: " << books[i].store << endl;
			cout << "出版社: " << books[i].publish << endl;
			cout << "出版时间: " << books[i].pub_time << endl;
			cout << "读者: " << books[i].borrower << endl;
			cout << "读者学号: " << books[i].borr_num << endl;
			cout << "**********************************************************" << endl;
			cout << "请问是否确定注销此书(1为是,0为否): ";
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
				cout << "未注销！" << endl;
				return 0;
			}
		}
	}
	if (s == -1)
	{
		cout << "该书不存在！" << endl;
	}
	fopen_s(&bfg, "books", "wb");
	if (bfg == 0)
	{
		cout << "无法打开文件！";
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
	cout << "                               ☆修改书籍☆" << endl;
	fopen_s(&bfg, "books", "rb");
	if (bfg == 0)
	{
		cout << "无法打开文件" << endl;
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
		cout << "书名:" << books[i].name << endl;
		cout << "书号: " << books[i].id << endl;
		cout << "作者: " << books[i].writer << endl;
		cout << "价格: " << books[i].price << endl;
		cout << "总存量: " << books[i].total << endl;
		cout << "现存量: " << books[i].store << endl;
		cout << "出版社: " << books[i].publish << endl;
		cout << "出版时间: " << books[i].pub_time << endl;
		cout << "读者: " << books[i].borrower << endl;
		cout << "读者学号: " << books[i].borr_num << endl;
		cout << "**********************************************************" << endl;
	}
	cout << "请输入书号:";
	cin >> id;
	for (i = 0, s == 0; i < MAX_BOOKS; i++)
	{
		if (books[i].id == id)
		{
			cout << "书名:" << books[i].name << endl;
			cout << "书号: " << books[i].id << endl;
			cout << "作者: " << books[i].writer << endl;
			cout << "价格: " << books[i].price << endl;
			cout << "总存量: " << books[i].total << endl;
			cout << "现存量: " << books[i].store << endl;
			cout << "出版社: " << books[i].publish << endl;
			cout << "出版时间: " << books[i].pub_time << endl;
			cout << "读者: " << books[i].borrower << endl;
			cout << "读者学号: " << books[i].borr_num << endl;

			cout << "**********************************************************" << endl;
			cout << "是否确定修改该书籍(1为是,0为否):";
			cin >> s;
			if (s == 1)
			{
				page_title();
				cout << ">>>请重新输入书籍的信息:<<<" << endl;
				do
				{
					cout << endl << "请输入一个新的书号（学号从1001开始，但必须不同于已存在的书号）：";
					cin >> books[i].id;
					for (n = 0; n < SIZE; n++)
					{
						if (books[i].id == books[n].id&&n != i)
						{
							cout << "该书号已存在. " << endl; break;
						}
					}
				} while (books[i].id == books[n].id);
				cout << "书名: ";
				cin >> books[i].name;
				cout << "作者: ";
				cin >> books[i].writer;
				cout << "价格: ";
				cin >> books[i].price;
				cout << "总存量: ";
				cin >> books[i].total;
				cout << "现存量: ";
				cin >> books[i].store;
				cout << "出版社: ";
				cin >> books[i].publish;
				cout << "出版时间: ";
				cin >> books[i].pub_time;
				cout << "借书人: ";
				cin >> books[i].borrower;
				cout << "借书者学号: ";
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
		cout << "该书不存在！" << endl;
	}
	fopen_s(&bfg, "books", "wb");
	if (bfg == 0)
	{
		cout << "无法打开文件" << endl;
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
	cout << "                                    ☆管理☆\n" << endl << endl << endl;
	cout << "                               * * * * * * * * * * *" << endl;
	cout << "                               *    1.增加读者     *" << endl << endl;
	cout << "                               *    2.注销读者     *" << endl << endl;
	cout << "                               *    3.修改读者     *" << endl << endl;
	cout << "                               *    0.返    回     *" << endl;
	cout << "                               * * * * * * * * * * *" << endl << endl;
	cout << "                     请输入你的选择:";
	switch (_getch())
	{
	case'1':reader_add(); break;
	case'2':reader_del(); break;
	case'3':reader_mod(); break;
	case'0':return_back(); break;
	default:system("cls");
		cout << "\n错误，请再输入一遍!\n";
	}
	return 0;

}

int reader::reader_add()
{
	FILE *sfg;
	int i, n;
	page_title();
	cout << "                              ☆增加读者☆" << endl;
	cout << ">>>请输入读者的信息<<< " << endl;
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
		cout << "请输入一个新的学号（学号从1001开始，但必须不同于已存在的学号）:";
		cin >> stud[n].num;
		for (i = 0; i <= n; i++)
		{
			if (stud[i].num == stud[n].num && n != i)
			{
				cout << endl << "这个学号已经存在！" << endl;
				break;
			}
		}
	} while (stud[n].num == stud[i].num);
	cout << "名字: ";
	cin >> stud[n].name;
	cout << "年级: ";
	cin >> stud[n].grade;
	cout << "班级: ";
	cin >> stud[n].clas;
	cout << "性别: ";
	cin >> stud[n].sex;
	cout << "书名: ";
	cin >> stud[n].book_name;
	cout << "借书日期: ";
	cin >> stud[n].date;
	cout << "可借天数: ";
	cin >> stud[n].avai_days;
	fopen_s(&sfg, "students", "wb");
	for (n = 0; n < AMOUNT; n++)
	{
		fwrite(&stud[n], sizeof(stud[n]), 1, sfg);
	}
	fclose(sfg);
	cout << endl << "该读者已添加." << endl;
	_getch();
	return 0;

}

int reader::reader_del()        //定义删除读者的函数
{
	FILE *sfp;
	int i, num, s, n;
	page_title();
	cout << "                              ☆注销读者☆" << endl;
	fopen_s(&sfp, "students", "rb");
	if (sfp == 0)
	{
		cout << "无法打开文件. ";
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
	cout << endl << "请输入学号: ";
	cin >> num;
	for (i = 0, s == -1; i < AMOUNT; i++)
	{
		if (stud[i].num == num)
		{
			cout << "名字: " << stud[i].name << endl;
			cout << "学号: " << stud[i].num << endl;
			cout << "年级: " << stud[i].grade << endl;
			cout << "班级: " << stud[i].clas << endl;
			cout << "性别: " << stud[i].sex << endl;
			cout << "书名: " << stud[i].book_name << endl;
			cout << "借书日期: " << stud[i].date << endl;
			cout << "可借天数: " << stud[i].avai_days << endl;
			cout << "********************************************************** " << endl;
			cout << "是否确定注销该读者(1为是,0为否): ";
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
				cout << "该读者不存在.";
			}
		}
	}
	fopen_s(&sfp, "students", "wb");
	if (sfp == 0)
	{
		cout << "无法打开文件. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fwrite(&stud[i], sizeof(stud[i]), 1, sfp);
	}
	fclose(sfp);
	_getch();
	return 0;
}

int reader::reader_mod()            //定义修改读者的函数
{

	FILE *sfp;
	int i, num, s, n;
	page_title();
	cout << "                              ☆修改读者☆" << endl;
	fopen_s(&sfp, "students", "rb");
	if (sfp == 0)
	{
		cout << "无法打开文件. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fread(&stud[i], sizeof(stud[i]), 1, sfp);
	}
	fclose(sfp);
	cout << endl << "请输入学号: ";
	cin >> num;
	for (i = 0, s == -1; i < AMOUNT; i++)
	{
		if (stud[i].num == num)
		{
			cout << "名字:" << stud[i].name << endl;
			cout << "学号: " << stud[i].num << endl;
			cout << "年级: " << stud[i].grade << endl;
			cout << "班级: " << stud[i].clas << endl;
			cout << "性别: " << stud[i].sex << endl;
			cout << "书名: " << stud[i].book_name << endl;
			cout << "借书日期: " << stud[i].date << endl;
			cout << "可借天数: " << stud[i].avai_days << endl;

			cout << "********************************************************** " << endl;
			cout << "是否确定修改该读者(1为是,0为否): ";
			cin >> s;
			if (s == 1)
			{
				page_title();
				cout << ">>>请重新输入读者的信息.<<<" << endl;
				do
				{
					cout << "请输入一个新的学号（学号从1001开始，但必须不同于已存在的学号）：";
					cin >> stud[i].num;
					for (n = 0; n < AMOUNT; n++)
					{
						if (stud[i].num == stud[n].num&&n != i)
						{
							cout << "该学号已存在." << endl; break;
						}
					}
				} while (stud[i].num == stud[n].num);
				cout << "名字: ";
				cin >> stud[i].name;
				cout << "年级: ";
				cin >> stud[i].grade;
				cout << "班级: ";
				cin >> stud[i].clas;
				cout << "性别: ";
				cin >> stud[i].sex;
				cout << "书名: ";
				cin >> stud[i].book_name;
				cout << "借书日期: ";
				cin >> stud[i].date;
				cout << "可借天数: ";
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
		cout << "该读者不存在. " << endl;
	}
	fopen_s(&sfp, "students", "wb");
	if (sfp == 0)
	{
		cout << "无法打开文件. ";
	}
	for (i = 0; i < AMOUNT; i++)
	{
		fwrite(&stud[i], sizeof(stud[i]), 1, sfp);
	}
	fclose(sfp);
	_getch();
	return 0;
}

int book::book_out()                      //定义借书函数
{
	FILE *bfp, *sfp;
	int MAX_STUDENTS, MAX_BOOKS;
	int id, i, s, num, avaiday, p;
	char dates[10];
	page_title();
	cout << "                                  ☆借书☆\n";
	cout << "请输入书号:";
	cin >> id;
	fopen_s(&bfp, "books", "rb");
	if (bfp == 0)
		cout << "无法打开文件.\n";
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
			cout << "                                ☆书的信息☆\n";
			cout << "书名: " << books[i].name << endl;
			cout << "书号: " << books[i].id << endl;
			cout << "作者: " << books[i].writer << endl;
			cout << "价格: " << books[i].price << endl;
			cout << "总存量: " << books[i].total << endl;
			cout << "现存量: " << books[i].store << endl;
			cout << "出版社: " << books[i].publish << endl;
			cout << "出版时间: " << books[i].pub_time << endl;
			cout << "读者: " << books[i].borrower << endl;
			cout << "读者学号: " << books[i].borr_num << endl;

			cout << "**********************************************************\n";
			fopen_s(&sfp, "students", "rb");
			if (sfp == 0)
			{
				cout << "students 文件打开失败" << endl;
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
			cout << "请输入借阅人学号:";
			cin >> num;
			for (s = 0; s < MAX_STUDENTS; s++)
			{
				if (stud[s].getnum() == num)
				{
					if (books[s].store != 0)
					{
						cout << "请输入可借的天数:\n";
						cin >> avaiday;
						stud[s].setavaiday(avaiday);
						cout << "请输入借书日期:\n";
						cin >> dates;
						stud[s].setdate(dates);
						books[i].store--;
						stud[s].setbook_name(books[i].name);
						strcpy_s(books[i].borrower, 10, stud[s].getname());
						cout << "你已经成功借书！" << endl;
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
						cout << "该书馆藏已经全部被借走" << endl;
						break;
					}
				}
			}
			if (MAX_STUDENTS == s && stud[MAX_STUDENTS - 1].getnum() != num)
			{
				cout << "不存在该学生！" << endl;
			}
			break;
		}
	}
	if (i == MAX_BOOKS)
	{
		cout << "不存在该书信息" << endl;
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
	cout << "                                ☆还书☆\n";
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
BEFORE:cout << "请输入学生学号:";
	cin >> num;
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		if (stud[i].getnum() == num)
		{
			cout << "名字:" << stud[i].getname() << endl;
			cout << "学号: " << stud[i].getnum() << endl;
			cout << "年级: " << stud[i].getgrade() << endl;
			cout << "班级: " << stud[i].getclas() << endl;
			cout << "性别: " << stud[i].getsex() << endl;
			cout << "书名: " << stud[i].getbook_name() << endl;
			cout << "借书日期: " << stud[i].getdate() << endl;
			cout << "可借天数: " << stud[i].getavaiday() << endl;
			cout << "********************************************************** " << endl;
		AGAIN:cout << "请输入还书编号：";
			cin >> id;
			fopen_s(&bfp, "books", "rb");
			if (bfp == 0)
			{
				cout << "无法打开books文件" << endl;
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
					cout << "成功还书！" << endl;
					break;
				}
			}
			if (j == MAX_BOOKS)
			{
				cout << "还书编号输入错误，请重新输入：" << endl;
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
		cout << "该学号学生不存在，请重新输入\n";
		goto BEFORE;
	}

	fopen_s(&sfp, "students", "wb");
	if (sfp == 0)
		cout << "打开文件students失败" << endl;
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

