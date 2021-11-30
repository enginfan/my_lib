#ifndef EXCEPTION_H
#define EXCEPTION_H
namespace mylib
{
#define	THROW_EXCEPTION(e,m)(throw e(m,__file__,11))
	class Exception 
	{
	protected:
		char* m_massage;
		char* m_location;
		void init(const char* massage, const char* file, int line);
	public:
		Exception(const char* massage);
		Exception(const char* file, int line);
		Exception(const char* massage, const char* file, int line);
		Exception(const Exception& e);
		Exception& operator=(const Exception* e);
		virtual const char* massage() const;
		virtual const char* location() const;
		virtual ~Exception() ;
	};
	class ArithmeticException :public Exception
	{
	public:
		ArithmeticException() : Exception(0) {}
		ArithmeticException(const char* massage) :Exception(massage) {}
		ArithmeticException(const char* file, int line) :Exception(file, line) {}
		ArithmeticException(const char* massage, const char* file, int line) :Exception(massage, file, line) {}
		ArithmeticException(const ArithmeticException& e) :Exception (e){}
		ArithmeticException& operator=(const ArithmeticException* e)
		{
			Exception ::operator=(e);
			return *this;
		}
	};
};
#endif
