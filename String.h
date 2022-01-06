#pragma once
#ifndef STRING_H
#define STRING_H

#include "Object.h"

namespace mylib
{
	class String : public Object
	{
	protected:
		char* m_str;
		int m_length;
		void init(const char* s);
	public:
		String();
		String(char c);
		String(const char* s);
		String(const String& s);
		int length()const;
		const char* str()const;//与传统c进行互操作的
		
        char& operator [] (int i);
        char operator [] (int i) const;

        bool operator == (const String& s) const;
        bool operator == (const char* s) const;
        bool operator != (const String& s) const;
        bool operator != (const char* s) const;
        bool operator > (const String& s) const;
        bool operator > (const char* s) const;
        bool operator < (const String& s) const;
        bool operator < (const char* s) const;
        bool operator >= (const String& s) const;
        bool operator >= (const char* s) const;
        bool operator <= (const String& s) const;
        bool operator <= (const char* s) const;

        String operator + (const String& s) const;
        String operator + (const char* s) const;
        String& operator += (const String& s);
        String& operator += (const char* s);

       /* String operator - (const String& s) const;
        String operator - (const char* s) const;
        String& operator -= (const String& s);
        String& operator -= (const char* s);*/

        String& operator = (const String& s);
        String& operator = (const char* s);
        String& operator = (char c);

		~String();
	};


}
#endif
