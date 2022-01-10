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

	bool String::equal(const char* l, const char* r, int len) const
	{
		bool ret = true;

		for (int i = 0; i < len && ret; i++)
		{
			ret = ret && (l[i] == r[i]);
		}

		return ret;
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

	bool String::startWith(const char* s) const
	{
		bool ret = (s!=NULL);
		if (ret)
		{
			int len = strlen(s);
			ret = (len < m_length) && (equal(m_str, s, len));
		}
		return ret;
	}

	bool String::startWith(const String& s) const
	{
		return startWith(s.m_str);
	}

	bool String::endOf(const char* s) const
	{
		bool ret = (s != NULL);
		if (ret)
		{
			int len = strlen(s);
			char* str = m_str + (m_length - len);
			ret = (len < m_length) && (equal(str, s, len));
		}
		return ret;
	}

	bool String::endOf(const String& s) const
	{
		return endOf(s.m_str);
	}

	String& String::insert(int i, const char* s)
	{
		bool ret = (s != NULL) && (s != "\0");
		if (ret)
		{
			if ((0 <= i) && (i <= m_length))
			{
				int len = strlen(s);
				char* str = reinterpret_cast<char*>(malloc(len + m_length + 1));
				if (str)
				{
					strncpy(str, m_str, i);
					strncpy(str + i, s, len);
					strncpy(str + i + len, m_str + i, m_length - i);

					str[m_length + len] = '\0';

					free(m_str);
					m_str = str;
					m_length = m_length + len;
				}
			}
		}
		else
		{

		}
		return *this;
	}

	String& String::insert(int i, const String& s)
	{
		return insert(i,s.m_str);
	}

	String& String::trim()
	{
		int b = 0;
		int e = m_length - 1;
		while (m_str[b] == ' ')b++;
		while (m_str[e] == ' ' && e >= 0)e--;
		if (b == 0)
		{
			m_str[e + 1] = '\0';
			m_length = e + 1;
		}
		else
		{
			for (int i = 0, j = b; i <= e; i++,j++)
			{
				m_str[i] = m_str[j];
			}
			m_str[e - b + 1] = '\0';
			m_length = e - b + 1;
		}
		return *this;
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

	int* String::make_pmt(const char* p)
	{
		int len = strlen(p);
		int* ret = static_cast<int*>(malloc(sizeof(int) * len));
		if (ret != NULL)
		{
			int ll = 0;
			ret[0] = 0;
			for (int i = 1; i < len; i++)
			{
				while ((ll > 0) && (p[ll] != p[i]))
				{
					ll = ret[ll - 1];
				}
				if (p[ll] == p[i])
				{
					ll++;
				}
				ret[i] = ll;//ll既是最大字符串长度还是前缀末尾
			}
		}
		return ret;
	}
	int String::pmt(const char* s, const char* p)
	{
		int ret = -1;
		int sl = strlen(s);
		int pl = strlen(p);
		int* pmt = make_pmt(p);
		if ((pmt != NULL) && (pl > 0) && (sl >= pl))
		{
			for (int i = 0, j = 0; i < sl; i++)
			{
				while(p[j] != s[i]&&j>0)
				{
					j = pmt[j - 1];
				}
				if (p[j] == s[i])
				{
					j++;
				}
				if (j == pl)
				{
					ret = i + 1 - pl;
					break;
				}
			}
		}
		free(pmt);
		return ret;
	}

	int String::indexOf(const char* s) const
	{
		return pmt(m_str, s);
	}

	int String::indexOf(const String& s) const
	{
		return pmt(m_str, s.m_str);
	}

	String& String::remove(int i, int len)
	{
		if ((i >= 0) && (i < m_length))
		{
			int n = i;
			int m = i + len;
			while((n < m) && (m < m_length))
			{
				m_str[n++] = m_str[m++];
			}
			m_str[n] = '\0';
			m_length = n;
		}
		return *this;
	}

	String& String::remove(const char* s)
	{
		return remove(indexOf(s), s ? strlen(s) : 0);
	}

	String& String::remove(const String& s)
	{
		return remove(indexOf(s), s.length());
	}

	String& String::replace(const char* t, const char* s)
	{
		int index = indexOf(t);
		if (index >= 0)
		{
			remove(t);
			insert(index, s);
		}
		return *this;
	}

	String& String::replace(const String& t, const char* s)
	{
		return replace(t.m_str, s);
	}

	String& String::replace(const char* t, const String& s)
	{
		return replace(t, s.m_str);
	}

	String& String::replace(const String& t, const String& s)
	{
		return replace(t.m_str, s.m_str);
	}

	String String::operator - (const String& s) const
	{
		return String(*this).remove(s);
	}

	String String::operator - (const char* s) const
	{
		return String(*this).remove(s);
	}

	String& String::operator -= (const String& s)
	{
		return remove(s);
	}

	String& String::operator -= (const char* s)
	{
		return remove(s);
	}

	String String::sub(int i, int len) const
	{
		String ret;
		if ((i >= 0) && (i < m_length))
		{
			if (len < 0)len = 0;
			if (len+i > m_length )len = m_length - i;

			char* str = reinterpret_cast<char*>(malloc(len + 1));

			strncpy(str, m_str + i, len);
			str[len] = '\0';
			ret = str;
		}
		else
		{

		}
		return ret;
	}
}
