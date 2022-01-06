#include"String.h"
#include<cstring>
#include<cstdlib>

namespace mylib
{
	void String::init(const char* s)
	{
		m_str = _strdup(s);
		if (m_str)
		{
			m_length = strlen(m_str);
		}
		else
		{

		}
	}

	String::String()
	{
		init("");
	}

	String::String(char c)
	{
		char s[] = { c,"\0" };
		init(s);
	}

	String::String(const char* s)
	{
		init(s ? s: "");
	}

	String::String(const String& s)
	{
		init(s.m_str);//拷贝构造函数可以访问私有成员
	}

	int String::length()const
	{
		return m_length;
	}

	const char* String::str()const
	{
		return m_str;
	}

	char& String::operator [] (int i)
	{
		if ((0 <= i) && (i < m_length))
		{
			return m_str[i];
		}
		else
		{

		}
	}

	char String::operator [] (int i) const
	{
		return (const_cast<String&>(*this))[i];
	}
	
	bool String::operator == (const String& s) const
	{
		return (strcmp(m_str, s.m_str) == 0);
	}

	bool String::operator == (const char* s) const
	{
		return (strcmp(m_str, s ? s : "")==0);
	}

	bool String::operator != (const String& s) const
	{
		return !(*this == s);
	}

	bool String::operator != (const char* s) const
	{
		return !(*this == s);
	}

	bool String::operator > (const String& s) const
	{
		return (strcmp(m_str, s.m_str) > 0);
	}

	bool String::operator > (const char* s) const
	{
		return (strcmp(m_str, (s ? s : "")) > 0);
	}

	bool String::operator < (const String& s) const
	{
		return (strcmp(m_str, s.m_str) < 0);
	}

	bool String::operator < (const char* s) const
	{
		return (strcmp(m_str, (s ? s : "")) < 0);
	}

	bool String::operator >= (const String& s) const
	{
		return !(*this < s);
	}

	bool String::operator >= (const char* s) const
	{
		return !(*this < s);
	}

	bool String::operator <= (const String& s) const
	{
		return !(*this > s);
	}

	bool String::operator <= (const char* s) const
	{
		return !(*this > s);
	}

	String String::operator + (const String& s) const
	{
		return (*this + s.m_str);
	}

	String String::operator + (const char* s) const
	{
		String ret;
		int len = this->m_length + strlen(s ? s : "");
		char* str = reinterpret_cast<char*>(malloc(len + 1));
		if (str)
		{
			strcpy(str, m_str);
			strcat(str, (s ? s : ""));
			free(ret.m_str);
			ret.m_str = str;
			ret.m_length = len;
		}
		else
		{

		}
		return ret;
	}

	String& String::operator += (const String& s)
	{
		return(*this = *this + s.m_str);
	}

	String& String::operator += (const char* s)
	{
		return (*this = *this + s);
	}

	/*String String::operator - (const String& s) const
	{

	}

	String String::operator - (const char* s) const
	{

	}

	String& String::operator -= (const String& s)
	{

	}

	String& String::operator -= (const char* s)
	{

	}*/

	String& String::operator = (const String& s)
	{
		return(*this=s.m_str);
	}

	String& String::operator = (const char* s)
	{
		if (m_str != s)
		{
			char* str = _strdup(s ? s : "");

			if (str)
			{
				free(m_str);

				m_str = str;
				m_length = strlen(m_str);
			}
			else
			{
				
			}
		}

		return *this;
	}

	String& String::operator = (char c)
	{
		char s[] = { c,"\0" };
		return (*this = s);
	}


	String::~String()
	{
		free(m_str);
	}


}