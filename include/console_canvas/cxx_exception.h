// cxx_exception.h

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>

namespace ctm {

class exception : public std::exception
{
public:
    explicit exception(const std::string& s) noexcept : m_what(s) {}
    const char* what() const noexcept override {
        return m_what.c_str();
    }
private:
    std::string m_what;
};

} // namespace ctm

#endif // _EXCEPTION_H_
