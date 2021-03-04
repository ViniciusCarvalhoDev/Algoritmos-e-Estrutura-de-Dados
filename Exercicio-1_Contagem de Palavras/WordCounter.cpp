#include <iostream>
#include <string>
#include "WordCounter.hpp"
#include "Word.hpp"
#include <algorithm> 

using namespace std;

    
WordCounter::WordCounter(int num_words){

	words = new Word[num_words];
	this->size = 0;
}

 int WordCounter::countWord(string palavra){
    int i;
    int quantidade_de_aparicoes = 0;
    
    for(i = 0; i < this->size; i++){
        if(this->words[i].word == palavra){
            quantidade_de_aparicoes++;        
        }
    }
    
    return quantidade_de_aparicoes;
}

void WordCounter::addWord(string w){
    
        this->words[size] = Word(w);
        this->words[size].incrementFreq();
        this->size++;
   
}

void WordCounter::print(){
    int i,j;
 
    std::vector<string> myvector;
    
    for(i = 0; i < size; i++){
        
        string palavra = words[i].word;
        int quantidade = countWord(palavra);
        words[i].count = quantidade;
        myvector.push_back(words[i].word + " " + to_string(words[i].count));
    }
    
    std::sort (myvector.begin(), myvector.begin()+size);
    
    vector<string>::iterator ip; 
  
    ip = std::unique(myvector.begin(), myvector.begin() + size); 
    
    myvector.resize(std::distance(myvector.begin(), ip)); 
    
    for(i = 0; i < myvector.size(); i++){
        std::cout << myvector.at(i)  << std::endl;
    }
}

WordCounter::~WordCounter(){
}
