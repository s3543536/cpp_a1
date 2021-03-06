//by Angel English s3543536
#ifndef VECTWRAP
#define VECTWRAP

#include "edit_distance.h"
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include <algorithm>

extern const char* DELIMS;
extern bool optimise_with_map;

class vector_wrapper {
public:
	std::vector<std::string> load_dict(std::string file_name);
	std::vector<std::string> load_text(std::string file_name);
	std::map<std::string, int> count_words(std::vector<std::string> dict, std::vector<std::string> text);
	std::map<std::string, std::string> check_words(std::vector<std::string> dict, std::map<std::string, int> w_counts);
private:
	std::string closest_match(std::vector<std::string> dict, std::string word);
};

#endif
