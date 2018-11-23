#include<iostream>
#include<cstring>

namespace my{
	class string
	{
		unsigned int leng;
		char* buff;
	public:
		string(char* text) : leng(strlen(text)), buff(text){}

		string operator+(const char* add)
		{
			//길이 늘리기
			char* t = new char[leng + strlen(add) + 1];
			t[0] = 0;
			//문자열 붙이기
			strcat(t, buff);
			strcat(t, add);

			return t;
		}

		string operator+(const string add)
		{
			//길이 늘리기
			char* t = new char[leng + strlen(add.buff) + 1];
			t[0] = 0;
			//문자열 붙이기
			strcat(t, buff);
			strcat(t, add.buff);

			return t;
		}

		void operator+=(const string add){

			char* t = new char[leng + strlen(add.buff) + 1];
			t[0] = 0;

			strcat(t, buff);
			strcat(t, add.buff);

			delete buff;
			buff = t;
		}
		bool operator==(string asd)
		{
			return !strcmp(buff, asd.buff);
		}

		friend std::ostream& operator<<(std::ostream& out, my::string text);
		friend string operator+(char* asd, my::string add);

		string operator*(unsigned int i)
		{
			string a = "";
			for (int j = 0; j < i; j++)
				a = a + buff;
			return a;
		}

	};
}

std::ostream& my::operator<<(std::ostream& out, my::string text)
{
	out << text.buff ;
	return out;
}

my::string my::operator+(char* asd, my::string add)
{
	return string(asd) + add;
}

int main(){

	my::string s1 = "Hello"; // s1 = "Hello"
	my::string s2 = s1 + " World"; // s2 = "Hello World"
	s1 = s1 + s2; // s1 = "HelloHello World"
	s1 += "Hello"; // s1 = "HelloHello WorldHello"
	std::cout << s1 << std::endl;


	std::cout << s1 + "Hello" << std::endl; // "HelloHello WorldHello WorldHello"
	my::string s3 = "Hi " + s1;
	std::cout << s3 << std::endl; // s3 = "HiHelloHello World Hello World"

	if (s1 == s1)
	std::cout << "same" << std::endl;
	else
	std::cout << "diff" << std::endl;

	std::cout << s1 * 2 << std::endl;
}