#include <exception>
#include <string>

class Exception : public std::exception
{
public:
  explicit Exception(std::string msg_): _msg(std::move(msg_)) {}

  const char *what() const noexcept override
  {
    return _msg.c_str();
  }

private:
  std::string _msg;
};

//#define ASSERT(condition, msg) do { if(!condition) throw Exception(msg); } while(0);

//#define ASSERT(condition, expression)                    \
//        do {                                             \
//        if (!condition) throw Exception(expression);\
//        } while (0);
