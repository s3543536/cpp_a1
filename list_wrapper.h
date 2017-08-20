#ifndef LISTWRAP
#define LISTWRAP

#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <string>
#include <list>
#include <map>
#include <iostream>
#include <fstream>

extern const char* DELIMS;
extern bool optimise_with_map;

class list_wrapper {
public:
	std::list<std::string> load_dict(std::string file_name);
	std::list<std::string> load_text(std::string file_name);
	std::map<std::string, int> count_words(std::list<std::string> dict, std::list<std::string> text);
	std::map<std::string, std::string> check_words(std::list<std::string> dict, std::map<std::string, int> w_counts);
private:
	std::string closest_match(std::list<std::string> dict, std::string word);
};

#endif
