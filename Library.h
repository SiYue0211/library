#pragma once
class book {
private:
	char name[50];	//book's name
	char writer[10];	//writer
	char borrower[10];
	int id; 
	int borr_num;
	int store;	//�ִ���
	int total;	//�ܴ���
	int pub_time;
	float price;
	char publish[50];	//������
public:
	book();	//book���캯��
	int book1();	//�鼮������溯��
	int book_add();		//�����鼮����
	int book_del();		//ɾ���鼮����
	int book_mod();		//�޸��鼮����
	int book_out();		//����鼮
	int book_in();		//�����鼮
	int book_name();	//�����������鼮����
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
	int num;	//ѧ��
	char grade[10];		//�꼶
	char clas[10];		//�༶
	char sex[10];
	char book_name[50];
	char date[10];
	int avai_days;
public:
	int read1();		//���߹�����溯��
	int reader_add();	//���Ӷ��ߺ���
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
