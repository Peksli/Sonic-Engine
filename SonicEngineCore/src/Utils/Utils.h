#pragma once

#include <vector>
#include <string>


namespace Sonic {
	// O(1) delete element in vector	
	template<typename T>
	T quickDelFromVector(std::vector<T>& r_vec, int idx);


	template<typename T>
	T addElementInSortedVector(std::vector<T>& vec, T element);


	template<typename IT>
	double evaluateRpn(IT begin, IT end);


	std::string eraseAllPunctuation(std::string& s);


	std::string getSubstrWithoutPunctuation(std::string& s);


	std::vector<std::pair<std::string, size_t>> getFrequencyWordVec(std::string& s);
}