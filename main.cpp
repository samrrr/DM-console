#include "MegaLib.h"
#include "windows.h"

using namespace std;
#define PAUSE system("pause");

void getxy(int &_x, int &_y);
void gotoxy(int xpos, int ypos);
bool testAll();
char *input_string(int size);
char *input_string_number(int _size,bool _can_negative);
int input_number();

char status[100];

void put_head()
{
	puts("-------------------------------���������� ������� �������----------------------");
}

void cls()
{
	system("cls");
	put_head();
	puts(status);
}


BigNat input_nat(char name)
{
	string s;//�������� ����� � ��������� ����
	char* ss;

	printf("%c:", name);

	ss = input_string_number(500, 0);
	s = ss;
	free(ss);

	return s;
}

BigInt input_int(char name)
{
	string s;//�������� ����� � ��������� ����
	char* ss;

	printf("%c:", name);

	ss = input_string_number(500, 1);
	s = ss;
	free(ss);

	return s;
}

BigRat input_rat(char name)
{
	string s_a;//�������� ��������� � ��������� ����
	string s_b;//�������� ����������� � ��������� ����
	BigRat c;
	char* ss;

	printf("%c(���������):", name);

	ss = input_string_number(500, 1);
	s_a = ss;
	free(ss);

	printf("%c(�����������):", name);

	ss = input_string_number(500, 0);
	s_b = ss;
	free(ss);

	c = BigRat(BigInt(s_a),BigNat(s_b));

	return c;
}

BigPol input_pol(char name)
{
	string s_a;
	BigPol c;
	char* ss;

	printf("%c:", name);

	ss = input_string(5000);
	s_a = ss;
	free(ss);

	c = BigPol(s_a);

	return c;
}

void put_result(string s)
{
	if (s.length() > 1000)
	{
		FILE *f;

		f = fopen("txt.txt", "a");

		if (f == NULL)
		{
			f = fopen("txt.txt", "w");
		}
		else
		{
			fprintf(f, "\n\n");
		}

		fprintf(f, "%s",s.data());

		fclose(f);
		printf("����� ������� � txt.txt");
	}
	else
		printf("%s",s.data());
}

void menu_nat()
{
	int menu;//��������� ����� ����
	BigNat a, b, c;
	BigInt c1;

	strcpy(status, "����������� ����� � 0");
	do
	{
		cls();
		puts("1-��������");
		puts("2-���������");
		puts("3-���������");
		puts("4-�������");
		puts("5-������� �� �������");
		puts("0-������� � �������");
		menu = input_number();
		cls();


		switch (menu)
		{
		case 1:
			puts("a+b");
			a = input_nat('a');
			b = input_nat('b');
			c = a + b;
			put_result(a.ToString() + "+" + b.ToString() + "=" + c.ToString());
			puts("");
			break;
		case 2:
			puts("a-b");
			a = input_nat('a');
			b = input_nat('b');
			if (a >= b)
			{
				c = a - b;

				put_result(a.ToString() + "-" + b.ToString() + "=" + c.ToString());
				puts("");
			}
			else
			{
				puts("����� �� ���������� �����. ����� ������� ��������� ��� ����� �����.");

				c1 = (BigInt)a - (BigInt)b;

				printf("a-b=");
				c1.Put();
				puts("");
			}
			break;
		case 3:
			puts("a*b");
			a = input_nat('a');
			b = input_nat('b');
			c = a * b;

			put_result(a.ToString() + "*" + b.ToString() + "=" + c.ToString());
			puts("");
			break;
		case 4:
			puts("a/b");
			a = input_nat('a');
			b = input_nat('b');
			if (b != 0)
			{
				c = a / b;

				printf("a/b=");
				c.Put();
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 5:
			puts("a mod b");
			a = input_nat('a');
			b = input_nat('b');
			if (b != 0)
			{
				c = a % b;

				put_result(a.ToString() + " mod " + b.ToString() + "=" + c.ToString());
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 0:
			break;
		default:
			puts("��� ������ ������ ����");
			break;
		}
		if (menu != 0)
			PAUSE
	} while (menu != 0);
}

void menu_int()
{
	int menu;//��������� ����� ����
	BigInt a, b, c;

	strcpy(status, "����� �����");
	do
	{
		cls();
		puts("1-��������");
		puts("2-���������");
		puts("3-���������");
		puts("4-�������");
		puts("5-������� �� �������");
		puts("0-������� � �������");
		menu = input_number();
		cls();


		switch (menu)
		{
		case 1:
			puts("a+b");
			a = input_int('a');
			b = input_int('b');
			c = a + b;

			put_result(a.ToString() + "+(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 2:
			puts("a-b");
			a = input_int('a');
			b = input_int('b');
			c = a - b;

			put_result(a.ToString() + "-(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 3:
			puts("a*b");
			a = input_int('a');
			b = input_int('b');
			c = a * b;

			put_result(a.ToString() + "*(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 4:
			puts("a/b");
			a = input_int('a');
			b = input_int('b');
			if (b != 0)
			{
				c = a / b;

				put_result(a.ToString() + "+(" + b.ToString() + ")=" + c.ToString());
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 5:
			puts("a mod b");
			a = input_int('a');
			b = input_int('b');
			if (b > 0)
			{
				c = a % b;

				put_result(a.ToString() + " mod (" + b.ToString() + ")=" + c.ToString());
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 0:
			break;
		default:
			puts("��� ������ ������ ����");
			break;
		}
		if (menu != 0)
			PAUSE
	} while (menu != 0);
}

void menu_rat()
{
	BigRat a, b, c;
	int menu;//��������� ����� ����

	strcpy(status, "������������ �����");
	do
	{
		cls();
		puts("1-��������");
		puts("2-���������");
		puts("3-���������");
		puts("4-�������");
		puts("0-������� � �������");
		menu = input_number();
		cls();


		switch (menu)
		{
		case 1:
			puts("a+b");
			a = input_rat('a');
			b = input_rat('b');
			c = a + b;
			put_result(a.ToString() + "+(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 2:
			puts("a-b");
			a = input_rat('a');
			b = input_rat('b');
			c = a - b;

			put_result(a.ToString() + "-(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 3:
			puts("a*b");
			a = input_rat('a');
			b = input_rat('b');
			c = a * b;

			put_result(a.ToString() + "*(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 4:
			puts("a/b");
			a = input_rat('a');
			b = input_rat('b');
			if (b != 0)
			{
				c = a / b;

				put_result(a.ToString() + "/(" + b.ToString() + ")=" + c.ToString());
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 0:
			break;
		default:
			puts("��� ������ ������ ����");
			break;
		}
		if (menu != 0)
			PAUSE
	} while (menu != 0);
}

void menu_pol()
{
	int menu;//��������� ����� ����
	BigPol a, b, c;

	strcpy(status, "�������� � ������������� �������������");
	do
	{
		cls();
		puts("1-��������");
		puts("2-���������");
		puts("3-���������");
		puts("4-�������");
		puts("5-������� �� �������");
		puts("0-������� � �������");
		menu = input_number();
		cls();


		switch (menu)
		{
		case 1:
			puts("a+b");
			a = input_pol('a');
			b = input_pol('b');
			
			c = a + b;

			put_result(a.ToString() + "+(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 2:
			puts("a-b");
			a = input_pol('a');
			b = input_pol('b');


			c = a - b;

			put_result(a.ToString() + "-(" + b.ToString() + ")=" + c.ToString());
			puts("");
			break;
		case 3:
			puts("a*b");
			a = input_pol('a');
			b = input_pol('b');
			
			c = a * b;

			put_result(a.ToString() + "*(" + b.ToString() + ")=" + c.ToString());

			puts("");
			break;
		case 4:
			puts("a/b");
			a = input_pol('a');
			b = input_pol('b');

			if (b != (string)"0")
			{
				c = a / b;

				put_result(a.ToString() + "/(" + b.ToString() + ")=" + c.ToString());
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 5:
			puts("a%b");
			a = input_pol('a');
			b = input_pol('b');
			if (b != (string)"0")
			{
				c = a % b;

				put_result(a.ToString() + " mod (" + b.ToString() + ")=" + c.ToString());
				puts("");
			}
			else
				puts("������� �� 0");
			break;
		case 6:
			puts("������� ���������:");
			puts("x+5");
			puts("23x2+1");
			puts("144");
			puts("1/2x2+x+1");
			puts("-10/13x2-1/13x-100/13");
			break;
		case 0:
			break;
		default:
			puts("��� ������ ������ ����");
			break;
		}
		if (menu != 0)
			PAUSE
	} while (menu != 0);
}

void menu_oth()
{
	int menu;
	strcpy(status, "������ ��������");
	do
	{
		cls();
		puts("1-NOD");
		puts("2-NOK");
		puts("3-POLY NOK");
		puts("4-a^b");
		puts("5-a^b mod c");
		puts("6-Diff(POLY)");
		puts("7-ax+by=c (��� ����� �����)");
		puts("0-������� � �������");
		menu = input_number();
		cls();
		switch (menu)
		{
		case 1:
		{
				  BigNat a, b, c;

				  puts("NOD(a,b)");
				  a = input_nat('a');
				  b = input_nat('b');
				  c = NOD(a, b);
				  printf("NOD(a,b)=");
				  c.Put();
				  puts("");
		}
			break;

		case 2:
		{
				  BigNat a, b, c;

				  puts("NOK(a,b)");
				  a = input_nat('a');
				  b = input_nat('b');
				  c = NOD(a, b);
				  printf("NOK(a,b)=");
				  c.Put();
				  puts("");
		}
			break;
		case 3:
		{
				  BigPol a, b, c;
				  puts("NOD(a,b) (��� ���������)");
				  a = input_pol('a');
				  b = input_pol('b');
				  c = POLY_NOD(a, b);
				  printf("NOD(a,b)=");
				  c.Put();
				  puts("");
		}
			break;
		case 4:
		{
				  BigNat a, c;
				  int b;

				  puts("a^b");
				  a = input_nat('a');
				  do{
					  printf("b:");
					  b = input_number();
					  if (b <= 0)
					  {
						  puts("������ ������� ������ 0");
						  PAUSE
					  }
				  } while (b <= 0);
				  c = pow(a,b);

				  put_result(a.ToString() + " ^ (" + ((BigNat)b).ToString() + ")=" + c.ToString());

				  puts("");

		}
			break;
		case 5:
		{
				  BigNat a, c,res;
				  int b;

				  puts("a^b mod c");
				  a = input_nat('a');

				  do{
					  printf("b:");
					  b = input_number();
					  if (b <= 0)
					  {
						  puts("������ ������� ������ 0");
						  PAUSE
					  }
				  } while (b <= 0);

				  do{
					  c = input_nat('c');
					  if (b <= 0)
					  {
						  puts("������ ������� c>0");
						  PAUSE
					  }
				  } while (b <= 0);

				  res = powmod(a, b,c);

				  put_result(a.ToString() + " ^ (" + ((BigNat)b).ToString() + ") mod "+c.ToString()+"=" + res.ToString());
				  puts("");

		}
			break;
		case 6:
		{
				  BigPol a, c;
				  puts("diff(a) (��� ��������)");
				  a = input_pol('a');
				  c = c.deg(a);
				  printf("diff(a)=");
				  c.Put();
				  puts("");
		}
			break;
		case 7:
		{
				  BigInt a, b, c;
				  puts("ax+by=c (��� ����� �����)");
				  a = input_int('a');
				  b = input_int('b');
				  c = input_int('c');
				  diaf(a, b, c);
				  puts("");
		}
			break;
		case 0:
			break;
		default:
			puts("��� ������ ������ ����");
			break;
		}
		if (menu != 0)
			PAUSE
	} while (menu != 0);

}

int main()
{
	setlocale(0,"RU");

	/** /

	POLY_NOD((string)"x2-1",(string)"x-1").Put();
	PAUSE

	/**/

	int menu;//��������� ����� ����

	do
	{
		strcpy(status,"������� ����");
		cls();
		puts("1-�������� � ������������ �������");
		puts("2-�������� � ������ �������");
		puts("3-�������� � ������������� �������");
		puts("4-�������� � ����������");
		puts("5-������ ��������");
		puts("0-�����");

		menu = input_number();

		switch (menu)
		{
		case 1:
			menu_nat();
			break;
		case 2:
			menu_int();
			break;
		case 3:
			menu_rat();
			break;
		case 4:
			menu_pol();
			break;
		case 5:
			menu_oth();
			break;
		case 0:
			break;
		default:
			puts("��� ������ ������ ����");
			PAUSE
			break;
		}
	} while (menu != 0);

	/*
	a = BigRat((BigInt)"4144433443435452341242521214241212441241", (BigNat)"2");

	b = BigRat((BigInt)"523423524623512354235232342342342352363261", (BigNat)"2");

	c = BigRat((BigInt)"1", (BigNat)"6");

	a.Put();
	puts("");
	b.Put();
	puts("");

	(a+b).Put();
	puts("");



	*/

}


char my_getch()
{
	char ch;//��� ������� ������.
	do
	{
		ch = _getch();
		if (ch == '\r')
			ch = '\n';
		else
		if (ch == '\0' || ch == -32)
			_getch();
		else
		if (ch == '\t')
			ch = ' ';
	} while (ch >= -128 && ch <= -17 || ch == '\0' || ch == -32);
	return ch;
}

//������� ��� ����� ������

char *input_string(int size)
{
	char *s;       //��������� �� ������ ������ �������� ������
	int length = 1;//����� ������
	char ch;       //�������� ������
	s = NULL;
	do
	{
		ch = my_getch();
		switch (ch)
		{
		case 27:
			break;
		case '\b':
			if (length > 1)
			{
				printf("\b \b");
				length--;
				s = (char *)realloc(s, sizeof(char)*length);
			}
			break;
		case '\n':
			if (length > 1)
			{
				while (s[length - 2] == ' ')
				{
					length--;
					s = (char *)realloc(s, sizeof(char)*length);
				}
				s[length - 1] = 0;
			}
			break;
		default:
			if (length <= size && (ch != ' ' || length > 1))
			{
				s = (char *)realloc(s, sizeof(char)*(length + 1));
				printf("%c", ch);
				s[length - 1] = ch;
				length++;
			}
			break;
		}
	} while (ch != '\n' || length == 1);
	printf("\n");

	return s;
}

//������� ��� ����� ������ �����

int input_number()
{
	int number;    //�������� �����	
	char *s;       //��������� �� ������ ������ �������� ������
	int length = 1;//����� ������
	char ch;       //�������� ������


	s = NULL;
	do
	{
		ch = my_getch();
		switch (ch)
		{
		case 27:
			break;
		case '\b':
			if (length > 1)
			{
				printf("\b \b");
				length--;
				s = (char *)realloc(s, sizeof(char)*length);
			}
			break;
		case '\n':
			if (length>1)
				s[length - 1] = 0;
			break;
		default:
			if ((ch >= '0' && ch <= '9' || ch == '-' && length == 1) && length <= 7)
			{
				s = (char *)realloc(s, sizeof(char)*(length + 1));
				printf("%c", ch);
				s[length - 1] = ch;
				length++;
			}
			break;
		}
	} while (ch != '\n' || length == 1 || length == 2 && *s == '-');
	number = atoi(s);
	free(s);
	printf("\n");
	return number;
}

//������� ��� ����� ������ �������� �����

char *input_string_number(int _size, bool _can_negative)
{
	char *s;       //��������� �� ������ ������ �������� ������
	int length = 1;//����� ������
	char ch;       //�������� ������
	s = NULL;
	do
	{
		ch = my_getch();
		switch (ch)
		{
		case 27:
			break;
		case '\b':
			if (length > 1)
			{
				printf("\b \b");
				length--;
				s = (char *)realloc(s, sizeof(char)*length);
			}
			break;
		case '\n':
			if (length > 1)
			{
				while (s[length - 2] == ' ')
				{
					length--;
					s = (char *)realloc(s, sizeof(char)*length);
				}
				s[length - 1] = 0;
			}
			break;
		default:
			if ((ch >= '0' && ch <= '9' || ch == '-' && length == 1 && _can_negative) && length <= _size)
			{
				s = (char *)realloc(s, sizeof(char)*(length + 1));
				printf("%c", ch);
				s[length - 1] = ch;
				length++;
			}
			break;
		}
	} while (ch != '\n' || length == 1);
	printf("\n");

	return s;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; 
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void getxy(int &_x,int &_y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD coord;

	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		_x = csbi.dwCursorPosition.X;
		_y = csbi.dwCursorPosition.Y;
	}
	else
	{
		_x = 0;
		_y = 0;
	}
}