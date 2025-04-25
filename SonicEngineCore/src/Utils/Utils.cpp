#include <iostream>
#include <cassert>
#include <stack>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

#include "Managers/LogManager/LogManager.h"
#include "Utils/Utils.h"


// Some advices 
/*
	1) Use hints if u want to insert some element in map like this:
		auto insert_it {std::end(my_map)};
		insert_it = my_map.insert(insert_it, {some_el, 1}); -> here some_el key must be < then el key in insert_it
		-> if u want to make an insert O(1)

	2)use try_emplace if u r not sure about dublicates in data structure

	3)If u want to effectively change keys in map, u can use something like this:
		auto node_1 {my_map.extract(3)}; -> 3 is the key
		auto node_2 {my_map.extract(8)};

		-> now u can do something like this:
		std::swap(node_1.key(), node_2.key())
		-> NOTE: normally u can not change keys, but extract is exception

	4) Let constructor deduce the types of templates:
		std::pair my_pair{"some_str", 3};

	5) if u have a large set of one type data, u can use for example this to handle this data:
		std::set<std::string> s;

		std::istream_iterator begin {std::cin};
		std::istream_iterator end;

		std::copy(begin, end, std::inserter(s, s.end()));
*/


namespace Sonic
{
	// O(1) delete element in vector
	template<typename T>
	T quickDelFromVector(std::vector<T>& r_vec, int idx) {
		if (idx < r_vec.size() && idx >= 0) {
			r_vec[idx] = std::move(r_vec.back());
			r_vec.pop_back();
		}
		else {
			SONIC_ERROR("Can not use index: {0}", idx);
			throw std::invalid_argument();
		}

		return r_vec[idx];
	}


	template<typename T>
	T addElementInSortedVector(std::vector<T>& vec, T element) {
		assert(true == std::is_sorted(vec.begin(), vec.end()));
		const auto insert_pos_it{ std::lower_bound(vec.begin(), vec.end(), element) };
		vec.insert(insert_pos_it, element);
		return element;
	}


	template<typename IT>
	double evaluateRpn(IT begin, IT end) {
		std::stack<double> val_stack;

		std::map<std::string, double(*)(double, double)> mapOperations
		{
			{"+", [](double a, double b) -> double {return a + b; }},
			{"-", [](double a, double b) -> double {return a - b; }},
			{"*", [](double a, double b) -> double {return a * b; }},
			{"/", [](double a, double b) -> double {return a / b; }},
			{"%", [](double a, double b) -> double {return std::fmod(a, b); }}
		};

		auto getAndDel{ [&]() -> double {
			double val {val_stack.top()};
			val_stack.pop();
			return val;
		} };

		for (; begin != end; begin++) {
			std::stringstream ss;
			if (double val; ss >> val) {
				val_stack.push(val);
			}
			else {
				auto r{ getAndDel() };
				auto l{ getAndDel() };
				auto operationFunc{ mapOperations.at(*begin) };
				val_stack.push(operationFunc(l, r));
			}
		}

		return getAndDel();
	}

	std::string eraseAllPunctuation(std::string& s) {
		std::string forbidden_punctuation{ ",.;:!?" };
		s.erase(
			std::remove_if(s.begin(), s.end(),
				[&forbidden_punctuation](char current_symbol) {
					return forbidden_punctuation.find(current_symbol) != std::string::npos;
				}
			), s.end());

		return s;
	}


	std::string getSubstrWithoutPunctuation(std::string& s) {
		std::string forbidden_punctuation{ ",.;:!?" };
		const auto start_idx{ s.find_first_not_of(forbidden_punctuation) };
		const auto end_idx{ s.find_last_not_of(forbidden_punctuation) };

		return s.substr(start_idx, end_idx - start_idx + 1);
	}


	std::vector<std::pair<std::string, size_t>> getFrequencyWordVec(std::string& s) {
		std::map<std::string, size_t> map_word_count;
		std::istringstream iss{ s };
		std::string str;
		const auto& insert_it_hint{ map_word_count.end() };

		while (iss >> str) {
			auto no_puncuation_str{ getSubstrWithoutPunctuation(str) };
			auto it_element = map_word_count.find(no_puncuation_str);
			if (it_element != map_word_count.end()) {
				++(it_element->second);
			}
			else {
				map_word_count.insert(insert_it_hint, { no_puncuation_str, 1 });
			}
		}

		std::vector<std::pair<std::string, size_t>> vec_words_count;
		vec_words_count.reserve(map_word_count.size());
		std::move(map_word_count.begin(), map_word_count.end(), std::back_inserter(vec_words_count));
		std::sort(vec_words_count.begin(), vec_words_count.end(),
			[](const auto& a, const auto& b)
			{
				return a.second > b.second;
			});

		SONIC_INFO("Result frequency word table: ");
		for (const auto& m_pair : vec_words_count)
			SONIC_INFO("{0}->{1}", m_pair.first, m_pair.second);

		return vec_words_count;
	}
}