#ifndef CONFIGREADER_HPP
#define CONFIGREADER_HPP

#include <map>
#include <ostream>
#include <sys/types.h>

class ConfigReader {
public:
  ConfigReader(std::string filename, char sep = '=');
  ~ConfigReader();

  std::string getConfig(std::string name);
  u_int32_t setConfig(std::string name, std::string value);
  uint32_t toFile(std::string filename);

private:
  std::map<std::string, std::string> data;
  char sep;
};

#endif
