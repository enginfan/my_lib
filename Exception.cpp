#include "Exception.h"
#include <cstdlib>
#include <cstring>
// test
using namespace std;
namespace mylib {
void Exception::init(const char *massage, const char *file, int line) {
  m_massage = (massage ? strdup(massage) : NULL);//防止massage的生命周期过短
  if (file != NULL) {
    char sl[16] = {0};
    _itoa(line, sl, 10);
    m_location = static_cast<char *>(malloc(strlen(file) + strlen(sl) + 2));
    m_location = strcpy(m_location, file);
    m_location = strcat(m_location, ":");
    m_location = strcat(m_location, sl);
  } else {
    m_location = NULL;
  }
}
Exception::Exception(const char *massage) { init(massage, NULL, 0); }
Exception::Exception(const char *file, int line) { init(NULL, file, line); }
Exception::Exception(const char *massage, const char *file, int line) {
  init(massage, file, line);
}
Exception::Exception(const Exception &e) {
  m_massage = strdup(e.m_massage);//保证都指向一片独立的堆空间
  m_location = strdup(e.m_location);
}
Exception &Exception::operator=(const Exception *e) {
  if (this != e) {
    free(m_massage);
    free(m_location);
    m_massage = strdup(e->m_location);
    m_location = strdup(e->m_massage);
  }
  return *this;
}
const char *Exception::massage() const { return m_massage; }
const char *Exception::location() const { return m_location; }
Exception::~Exception() {
  free(m_massage);
  free(m_location);
}
} // namespace mylib
