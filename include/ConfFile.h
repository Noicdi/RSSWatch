#ifndef RSSWATCH_INCLUDE_CONFFILE_
#define RSSWATCH_INCLUDE_CONFFILE_

#include <fstream>
#include <string>
#include <unordered_map>

class ConfFile
{
  public:
    using t_conf_file = std::ifstream;
    using t_conf_file_parameter = std::unordered_map<std::string, std::string>;
    using t_conf_file_section = std::unordered_map<std::string, t_conf_file_parameter>;

    explicit ConfFile(const std::string& conf_file_path);

    ~ConfFile();

    std::string getParameterString(const std::string& section,
                                   const std::string& parameter_key,
                                   const std::string& parameter_value_default);

    int getParameterInt(const std::string& section, const std::string& parameter_key, int parameter_value_default);

    bool getParameterBool(const std::string& section, const std::string& parameter_key, bool parameter_value_default);

  private:
    void readParameter();

    static bool isSection(const std::string& str);

    static bool isComment(const std::string& str);

    static void eraseComment(std::string& str);

    t_conf_file conf_file_;
    t_conf_file_section conf_file_section_;
};

#endif  // RSSWATCH_INCLUDE_CONFFILE_
