//by Angel English s3543536
#ifndef MAPWRAP
#define MAPWRAP

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

class map_wrapper {
public:
	std::map<std::string, int> load_dict(std::string file_name);
	std::map<std::string, int> load_text(std::string file_name);
	std::map<std::string, int> count_words(std::map<std::string, int> dict, std::map<std::string, int> text);
	std::map<std::string, std::string> check_words(std::map<std::string, int> dict, std::map<std::string, int> w_counts);
private:
	std::string closest_match(std::map<std::string, int> dict, std::string word);
};

#endif
