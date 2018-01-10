#pragma once
class book {
private:
	char name[50];	//book's name
	char writer[10];	//writer
	char borrower[10];
	int id; 
	int borr_num;
	int store;	//现存量
	int total;	//总存量
	int pub_time;
	float price;
	char publish[50];	//出版社
public:
	book();	//book构造函数
	int book1();	//书籍管理界面函数
	int book_add();		//增加书籍函数
	int book_del();		//删除书籍函数
	int book_mod();		//修改书籍函数
	int book_out();		//借出书籍
	int book_in();		//借入书籍
	int book_name();	//按书名搜索书籍函数
	int book_id();
	int book_pub();
	int book_time();
	int book_writer();
	int search_book();
	int search();
};

class reader {
private:
	char name[10];
	int num;	//学号
	char grade[10];		//年级
	char clas[10];		//班级
	char sex[10];
	char book_name[50];
	char date[10];
	int avai_days;
public:
	int read1();		//读者管理界面函数
	int reader_add();	//增加读者函数
	int reader_del();
	int reader_mod();
	int reader_name();
	int reader_num();
	int search_reader();
	char *getname();
	int getnum();
	char *getgrade();
	char *getclas();
	char *getsex();
	char *getbook_name();
	char *getdate();
	int getavaiday();
	int setname(char *);
	int setnum(int);
	int setgrade(char *);
	int setclas(char *);
	int setsex(char *);
	int setbook_name(char*);
	int setdate(char *);
	int setavaiday(int);



};
