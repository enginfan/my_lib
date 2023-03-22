#ifndef EXCEPTION_H
#define EXCEPTION_H
namespace mylib {
// 异常的类型可以是自定义类型
// 对于类类型异常的匹配依旧是自上至下严格匹配
// 赋值兼容性原则在异常匹配中依然适用
    // 在一定条件下，不同类型的数据之间可以进行类型转换，
    // 如可以将整型数据赋给双精度型变量。
    // 在赋值之前，先把整型数据转换成双精度型数据，然后再把它赋给双精度型变量。
    // 这种不同类型数据之间的自动转换和赋值，称为赋值兼容。
    // 在基类和派生类对象之间也存有赋值兼容关系，
    // 基类和派生类对象之间的赋值兼容规则是指在需要基类对象的任何地方，
    // 都可以使用其子类对象来代替。
// 一般而言 匹配子类异常的catch要放在上部 匹配父类异常的catch放在下部

//尽量使用异常处理机制分离正常逻辑和异常逻辑



#define THROW_EXCEPTION(e, m, f, line) (throw e(m, f, line))
class Exception {
protected:
  char *m_massage;
  char *m_location;
  //使用辅助函数来完成初始化动作因为构造函数逻辑是差不多的
  void init(const char *massage, const char *file, int line);

public:
  Exception(const char *massage);
  Exception(const char *file, int line);
  Exception(const char *massage, const char *file, int line);
  Exception(const Exception &e);
  Exception &operator=(const Exception *e);
  // 具体的两个功能接口
  virtual const char *massage() const;  // 错误信息
  virtual const char *location() const; // 行号
  virtual ~Exception()=0;//顶层父类的析构函数必须提供实现，就算是抽象类也要提供
};
class ArithmeticException : public Exception {
public:
  ArithmeticException() : Exception(nullptr,nullptr,0) {}
  ArithmeticException(const char *massage) : Exception(massage) {}
  ArithmeticException(const char *file, int line) : Exception(file, line) {}
  ArithmeticException(const char *massage, const char *file, int line)
      : Exception(massage, file, line) {}
  ArithmeticException(const ArithmeticException &e) : Exception(e) {}
  ArithmeticException& operator=(const ArithmeticException *e) {
    Exception ::operator=(e);
    return *this;
  }
};
class IndexOutOfBoundsException : public Exception {
public:
  IndexOutOfBoundsException() : Exception(0){};
  IndexOutOfBoundsException(const char* massage) : Exception(massage) {}
  IndexOutOfBoundsException(const char* file, int line) : Exception(file, line) {}
  IndexOutOfBoundsException(const char* massage, const char* file, int line)
    : Exception(massage, file, line) {}
  IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e) {}
  IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException* e) {
    Exception ::operator=(e);
    return *this;
  }
};

class NullPointerException : public Exception {
public:
  NullPointerException() : Exception(nullptr, nullptr, 0) {}
  NullPointerException(const char* massage) : Exception(massage) {}
  NullPointerException(const char* file, int line) : Exception(file, line) {}
  NullPointerException(const char* massage, const char* file, int line)
    : Exception(massage, file, line) {}
  NullPointerException(const NullPointerException& e) : Exception(e) {}
  NullPointerException& operator=(const NullPointerException* e) {
    Exception ::operator=(e);
    return *this;
  }
};

class NoEnoughMemoryException : public Exception {
public:
  NoEnoughMemoryException() : Exception(nullptr, nullptr, 0) {}
  NoEnoughMemoryException(const char* massage) : Exception(massage) {}
  NoEnoughMemoryException(const char* file, int line) : Exception(file, line) {}
  NoEnoughMemoryException(const char* massage, const char* file, int line)
    : Exception(massage, file, line) {}
  NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) {}
  NoEnoughMemoryException& operator=(const NoEnoughMemoryException* e) {
    Exception ::operator=(e);
    return *this;
  }
};

class InvalidParameterException : public Exception {
public:
  InvalidParameterException() : Exception(nullptr, nullptr, 0) {}
  InvalidParameterException(const char* massage) : Exception(massage) {}
  InvalidParameterException(const char* file, int line) : Exception(file, line) {}
  InvalidParameterException(const char* massage, const char* file, int line)
    : Exception(massage, file, line) {}
  InvalidParameterException(const InvalidParameterException& e) : Exception(e) {}
  InvalidParameterException& operator=(const InvalidParameterException* e) {
    Exception ::operator=(e);
    return *this;
  }
};

}; // namespace mylib
#endif
