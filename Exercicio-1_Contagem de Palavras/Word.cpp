#include "Word.hpp"
#include <string>

Word::Word () {
	this->word = "";
	this->count = 0;
}

Word::Word (string palavra) {
	this->word = palavra;
	this->count = 0;
}

void Word::incrementFreq () {
	count += 1;
}