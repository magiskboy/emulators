#include "ConfigReader.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

ConfigReader::ConfigReader(std::string filename, char sep) {
  this->sep = sep;
  std::ifstream fp(filename);

  for (std::string line; std::getline(fp, line);) {
    std::stringstream ss(line);
    std::string key, value;
    std::getline(ss, key, sep);
    std::getline(ss, value, sep);
    this->data.insert(std::pair<std::string, std::string>(key, value));
  }
}

ConfigReader::~ConfigReader() {}

std::string ConfigReader::getConfig(std::string name) {
  if (this->data.count(name) == 0)
    return "";
  return this->data[name];
}

uint32_t ConfigReader::setConfig(std::string name, std::string value) {
  return 0;
}

uint32_t ConfigReader::toFile(std::string filename) {
  std::ofstream fp(filename.c_str());

  for (auto it = this->data.begin(); it != this->data.end(); ++it) {
    fp << it->first << this->sep << it->second << std::endl;
  }

  fp.close();

  return 0;
}
