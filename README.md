# Algoritmos-e-Estrutura-de-Dados
Coleção de problemas, soluções e implementação de algumas estruturas de dados usando C++

Problema 1 ----------------------------------------------------------------------------------------------------------------

Escreva um programa para contar a frequência de palavras em um texto. Seu programa deve usar a função main abaixo para ler a entrada padrão, e imprimir resultados:

int main() {

  WordCounter *wc = new WordCounter(100);
  string s;
  cin >> s;
  while (s != ".") {
    wc->addWord(s);
    cin >> s;
  }
  wc->print();

  return 0;
}

Para facilitar seu trabalho, a implementação da classe WordCounter segue abaixo. Para terminar esse exercício, você precisa completar os arquivos WordCounter.hpp e WordCounter.cpp. O construtor já está implementado.  Você deve implementar os métodos que estão faltando (addWord(), print() e ~WordCounter()). A saída do problema corresponde a lista de palavras e suas frequências. As frequências e as palavras devem ser separadas por um único espaço em branco (" "). Além disso, as palavras devem ser apresentadas em ordem alfabética.

Note que a classe WordCounter utiliza a classe Word, que também já está implementada para você. O principal objetivo desse exercício é observar a comunicação entre objetos de diferentes classes. Você pode incluir novos métodos e atributos nas classes WordCounter e Word se julgar necessário.

#ifndef WORDCOUNT

#define WORDCOUNT



#include <map>

#include <vector>

#include <iostream>

#include <string>

#include "Word.hpp"

using namespace std;



class WordCounter {

public:

	Word *words;

	int size = 0;



	WordCounter(int num_words);

	~WordCounter();

	void addWord(string w);

	void print() const;

};

#endif


Alguns exemplos de uso podem ser vistos logo abaixo:

$ cat t0.txt
uma frase outra frase mais uma frase .
$ ./a.out < t0.txt 
frase 3
mais 1
outra 1
uma 2

$ cat t1.txt
a a a b c a b b c a a b a a b c .
$ ./a.out < t2.txt 
a 8
b 5
c 3

$ cat t2.txt
1 2 3 4 2 1 4 3 2 1 .
$ ./a.out < t2.txt 
1 3
2 3
3 2
4 2

Atenção: você deve enviar os arquivos main.cpp, WordCounter.hpp, WordCounter.cpp, Word.hpp e Word.cpp.

Problema 2 ---------------------------------------------------------------------------------------------------------

Neste exercício você deverá completar as classes List e Node. A classe List representa uma lista encadeada de inteiros. Cada elo dessa lista é uma instância da classe Node:

class Node {
  private:
    int _data;
    Node * _next;
  public:
    Node(int data, Node* next);
    void setData(int data);
    void setNext(Node *next);
    /** Retorna o dado armazenado no nó. 
       @retorna um inteiro.
     */
    int getData() const;
    /** Retorna o próximo nó.
     */
    Node* getNext() const;
};

Parte da implementação da classe list é dada abaixo:

class List {
  public:
    List();

    /** Essa função insere um elemento no começo da lista.
     */
    void insert(int value);
    /** Essa função remove o primeiro nó da lista, e retorna o dado armazenado nele.
       @retorna um inteiro armazenado no primeiro nó da lista.
     */
    int remove();
    /** Esse método indica se a lista está vazia.
       @retorna verdadeiro se a lista está vazia, e falso caso contrário.
     */
    int isEmpty();
    /** Informa o número de elementos da lista.
       @retorna um inteiro n, onde n é o número de nó da lista.
     */
    unsigned size() const;
    /** Retorna o elemento do meio da lista.
       Se a lista possui 2*n ou 2*n + 1 elementos, então o elemento do meio é
       o que está no índice n, assumindo que o primeiro índice é 0.
       @retorna o elemento do meio da lista.
     */
    int middle() const;
    /** Retorna o último elemento da lista.
       @retorna o inteiro armazenado no último nó da lista.
     */
    int last() const;
    /** Esse método move o primeiro nó da lista para última posição.
       Em outras palavras, rotate() + last() == head.
     */
    void rotate();
  private:
    Node *head; /// Ponteiro para o primeiro elemento da lista.
};

Você deverá completar todas as funções que possuem declaração mais não possuem corpo. Fique à vontade para criar funções auxiliares (e privadas) e atributos dentro das classes List e Node. Tenha em mente que o principal objetivo desse exercício é aplicar o princípio de encapsulamento. Você deve enviar os arquivos .cpp e .hpp para as classes List e Node e o arquivo main.cpp. Para testar sua implementação, utilize a função main abaixo:

int main(int argc, char** argv) {
  int input;
  std::cin >> input;
  List *list = new List();
  while (input != 0) {
    list->insert(input);
    std::cin >> input;
  }
  std::cout << "s:" << list->size() << ", ";
  std::cout << "m:" << list->middle() << ", ";
  std::cout << "l:" << list->last() << ", ";
  std::cout << "r:" << list->remove() << ", ";
  std::cout << "m:" << list->middle() << ", ";
  std::cout << "l:" << list->last() << ", ";
  list->rotate();
  std::cout << "m:" << list->middle() << ", ";
  std::cout << "l:" << list->last() << std::endl;
  return 0;
}

Alguns exemplos de uso podem ser vistos logo abaixo:

$ cat t0.txt
2 3 5 7 11 0
$ ./a.out < t0.txt
s:5, m:5, l:2, r:11, m:3, l:2, m:2, l:7

$ cat t1.txt
2 3 5 7 11 13 17 19 23 29 31 37 0
$ ./a.out < t1.txt
s:12, m:13, l:2, r:37, m:13, l:2, m:11, l:31

$ cat t2.txt
1 2 3 4 5 6 7 8 9 0
$ ./a.out < t2.txt 
s:9, m:5, l:1, r:9, m:4, l:1, m:3, l:8

Problema 3 ----------------------------------------------------------------------------------------------------------------

Neste exercício você irá implementar uma função genérica <T>GetMaxDefault(T a, T b, T c). Essa função recebe três argumentos, e retorna o maior entre os dois primeiros, ou o terceiro argumento, caso não exista um maior entre os dois primeiros. A função opera sobre tipos que reconhecem uma ordem total ou parcial.  Uma ordem, estabelecida sobre um conjunto, é dita total caso, dados dois elementos diferentes do conjunto, sempre for possível definir o maior deles. A ordem é dita parcial quando isso não for possível sempre. Por exemplo, o conjunto dos números inteiros define uma ordem total: dados dois números diferentes, sempre há um maior. Por outro lado, um conjunto potência, ordenado por inclusão, define uma ordem parcial. Se um subconjunto A contiver um subconjunto B, então A é dito maior que B, e de modo análogo, se um subconjunto B contiver um subconjunto A, então B é dito maior que A. Porém, é possível que nem A esteja em B, nem B esteja em A. Nesse caso, a ordem entre A e B não é definida. Quando a ordem parcial entre os dois primeiros elements, a e b, não estiver definida, sua função GetMaxDefault(a, b, c) deve retornar o terceiro elemento, c. Para lhe ajudar, a declaração de GetMaxDefault é dada abaixo:

template <class T>
T GetMaxDefault (T a, T b, T dflt) {
  // TODO: implement the code that is missing here.
}

A função GetMaxDefault deve operar sobre tipos que reconheçam o operador de comparação "maior que ou igual" (>=). Esse operador está definido para todos os tipos primitivos da linguagem C++. Porém, ele não é definido para tipos compostos como classes e structs. Nesse exercício, você deverá implementar esse operador para dois tipos, a saber: Interval e BitSet. Parte da implementação de Interval pode ser vista abaixo. Note que um intervalo I1 somente é maior que outro intervalo I2 se I1 contém I2 inteiramente. Por exemplo, [1, 5] é maior que [2, 4], porém [1, 5] não é maior que [3, 6], pois o primeiro interval não contém o segundo:

struct Interval {
  Interval(int left, int right): _l(left), _r(right) {}
  const int _l;
  const int _r;
  friend std::ostream & operator<<(std::ostream& os, const Interval& i) {
    os << '(' << i._l << ", " << i._r << ')';
    return os;
  }
  /**
   * \brief compares two intervals to see if the first is greater than the
   * second. An interval (a1, a2) is greater than or equal to another interval
   * (b1, b2) if a1 <= b1 and a2 >= b2.
   */
  // TODO: implement the operator >=
};

O segundo tipo que deve ser implementado é um conjunto de bits. Esse conjunto representa elementos como índices em um mapa de bits. Cada conjunto tem capacidade para armazenar os elementos de 1 até 32. Existem 2^32 conjuntos possíveis com esses elementos. Cada conjunto é definido pela representação binária de um número inteiro. Por exemplo, o número três, em binário, é escrito assim: 0...0011. Esse número representa o conjunto formado pelos números 1 e 2 (o primeiro e o segundo bits ativos). Similarmente, o número 10 possui a seguinte representação binária: 0...01010. Esse número representa o conjunto {2, 4}, pois o segundo e o quarto bits estão ativos. Abaixo, é dada parte da implementação de BitSet:

struct BitSet {
  BitSet(unsigned value): _set(value) {}
  const unsigned _set;
  friend std::ostream & operator<<(std::ostream& os, const BitSet& i) {
    const int limit = sizeof(unsigned) * 8;
    os << '<';
    for (int aux = 0; aux < limit; aux++) {
      unsigned mask = 1 << aux;
      if (i._set & mask) {
        os << "|";
      } else {
        os << "-";
      }
    }
    os << '>';
    return os;
  }
  /**
   * \brief compares two bit sets. A bit set b1 is greater than or equal to
   * another bit set b2 if b1 contains all the bits in b2.
   */
  // TODO: implement the operador >=
  }
};

Note que tanto BitSet quanto Interval possuem a implementação do operador de streaming (<<). Assim, é possível imprimir valores desses tipos diretamente via std::cout ou std::cerr, por exemplo. Você deverá testar seu código com a função main abaixo. Essa função lê bit sets (via número inteiros positivos que os representam) ou intervalos da entrada padrão. O primeiro caracter de cada linha indica o tipo que deverá ser lido:

#include <iostream>
#include "GetMax.h"
BitSet* readBitSet() {
  unsigned set;
  std::cin >> set;
  return new BitSet(set);
}
Interval* readInterval() {
  int left, right;
  std::cin >> left >> right;
  return new Interval(left, right);
}
void testBitSet() {
  BitSet *b1 = readBitSet();
  BitSet *b2 = readBitSet();
  BitSet *dflt = new BitSet(0);
  std::cout << GetMaxDefault(*b1, *b2, *dflt) << std::endl;
  delete b1;
  delete b2;
}
void testInterval() {
  Interval *i1 = readInterval();
  Interval *i2 = readInterval();
  Interval *dflt = new Interval(0, 0);
  std::cout << GetMaxDefault(*i1, *i2, *dflt) << std::endl;
  delete i1;
  delete i2;
}
int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'i': testInterval();
                break;
      case 'b': testBitSet();
                break;
      default: std::cerr << "Invalid type\n";
    }
  }
  return 0;
}

Abaixo são mostrados alguns testes. Use-os como exemplo. Eles são parte do conjunto de testes que será usado para corrigir esse exercício.

$> X=0; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
i 2 20 3 15
i 2 4 3 5
i -1 1 0 0
***
(2, 20)
(0, 0)
(-1, 1)


$> X=1; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
b 7 3
b 6 3
b 15 7
b 12 8
***
<|||----------------------------->
<-------------------------------->
<||||---------------------------->
<--||---------------------------->


$> X=2; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
i 2 20 3 15
b 52428 34952
i 2 4 3 5
b 34952 33928
***
(2, 20)
<--||--||--||--||---------------->
(0, 0)
<-------------------------------->


$> X=3; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
i 1 3 1 2
***
(1, 3)


$> X=4; cat t$X.txt ; echo "***"; ./a.out < t$X.txt
b 24 24
b 28 24
b 24 28
***
<---||--------------------------->
<--|||--------------------------->
<--|||--------------------------->

Problema 4 -----------------------------------------------------------------------------------------------------------

Neste exercício você deverá implementar quatro operadores sobre a class Point, cuja declaração pode ser vista logo abaixo:

class Point {
  public:
    Point(double xx = 0, double yy = 0): x(xx), y(yy) {}
    double getX() const { return x; }
    double getY() const { return y; }
  private:
    double x;
    double y;
}

Os quatro operadores que precisam ser implementados são:

O operador de leitura de stream <<
O operador de escrita de stream >>
O operador de adição +
O operador de atribuição com adição +=

A declaração de tais operadores pode ser vista logo abaixo:

class Point {
  public:
    ...
    friend std::ostream & operator << (std::ostream &out, const Point &c);
    friend std::istream & operator >> (std::istream &in,  Point &c);
    Point operator + (const Point &p);
    Point& operator += (const Point &p);
    ...
};

Use a função main abaixo para testar sua implementação:

#include <vector>
#include <iostream>
#include "Point.h"
void readPoints(std::vector<Point> &vec) {
  Point p;
  while (std::cin >> p) {
    vec.push_back(p);
  }
}
void printPoints(std::vector<Point> &vec) {
  for (Point p: vec) {
    std::cout << p << " ";
  }
  std::cout << std::endl;
}
Point sumAssPoints(std::vector<Point> &vec) {
  Point pSum;
  for (Point p: vec) {
    pSum += p;
  }
  return pSum;
}
Point sumBinPoints(std::vector<Point> &vec) {
  Point pSum;
  for (Point p: vec) {
    pSum = pSum + p;
  }
  return pSum;
}
int main() {
  std::vector<Point> vec;
  char testCase;
  std::cin >> testCase;
  readPoints(vec);
  if (testCase == 'a') {
    std::cout << "Sum = " << sumAssPoints(vec) << std::endl;
  } else if (testCase == 'b') {
    std::cout << "Sum = " << sumBinPoints(vec) << std::endl;
  }
  printPoints(vec);
}

Abaixo são mostrados alguns testes que você pode usar como exemplo:

input
a
2.0 3.1
-1.0 4.0
-1.5 -2.3
2.5 -1.2
output
Sum = (2, 3.6)
(2, 3.1) (-1, 4) (-1.5, -2.3) (2.5, -1.2)

input
b
1.0 3.0
-2.0 -1.0
output
Sum = (-1, 2)
(1, 3) (-2, -1)

input
p
2 3
-2 4
1 5.5
-3 -1
output
(2, 3) (-2, 4) (1, 5.5) (-3, -1)

Problema 5 ----------------------------------------------------------------------------------------------------

Neste exercício você deverá implementar um arranjo circular. Um arranjo circular é uma estrutura de dados com capacidade finita, e duas operações, add e get. A primeira operação adiciona um elemento ao arranjo, e a segunda retorna o mais antigo elemento inserido nele. Use a declaração abaixo para entender como funciona essa estrutura de dados:

#ifndef RING_ARRAY_H
#define RING_ARRAY_H

/**
 * \brief this class represents a ring array, that is, a circular array. The
 * array has a fixed capacity, and it is possible to insert elements in it
 * until it becomes full. Any attempt to insert more elements in a filled array
 * will abort the program.
 */
template <class T, unsigned N> class RingArray {
  public:
    RingArray(): _first(0), _last(0) {}
    /**
     * \brief This method adds a new value into the array. If the array is full,     * then this method stops the program. After inserting an element in the
     * array, the number of elements stored there increases by one.
     * \param value the element that must be inserted.
     */
    void add(T value);

    /**
     * \brief This method returns the oldest element stored in the array. After
     * returning an element, that element is removed from the array. Thus, the
     * number of elements in the array decreases by one. If we try to retrieve
     * an element from an empty array, then this method aborts the program.
     */
    T get();

    /**
     * This method is true if the array contains N-1 elements.
     * \return true if the array contains N-1 elements.
     */
    bool isFull() const;

    /**
     * This method is true if the array contains zero elements.
     * \return true if the array is empty.
     */
    bool isEmpty() const;

  private:
    unsigned _first; ///< The index of the oldest element in the array.
    unsigned _last; ///< The index of the next empty spot in the array.
    T buf[N]; ///< The buffer that stores the data in the array.
};

#endif

Para testar seu programa, utilize o arquivo de testes abaixo. Note que a parte de leitura de dados já está definida. Tudo o que você precisa fazer é prover implementações para os métodos da classe RingArray. Lembre-se que sua implementação precisa tratar situações de erro. Você pode usar a função fer_assert, que está implementada para você. Caso prefira usar outra função, não imprima mensagens de erro na saída de erro (err), ou o sistema de avaliação não vai conseguir capturá-las:

#include <iostream>
#include "RingArray.h"
void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}
template <class T, unsigned N> void RingArray<T, N>::add(T value) {
  // TODO: implement this method.
}
template <class T, unsigned N> T RingArray<T, N>::get() {
  // TODO: implement this method.
}
template <class T, unsigned N> bool RingArray<T, N>::isFull() const {
  // TODO: implement this method.
}
template <class T, unsigned N> bool RingArray<T, N>::isEmpty() const {
  // TODO: implement this method.
}
template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}
template <class T>
void test_add_or_get() {
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}
int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}

Abaixo são mostrados alguns exemplos de testes. Seu programa deve produzir as mesmas saídas que esses exemplos. Não se preocupe em ler a entrada, pois isso já é feito pelo programa de testes:

$ X=0; echo "s o mar e ana, mariana" > t$X.txt ; ./a.out < t$X.txt
o
mar
e
ana,
mariana


$> X=1; echo "d 1.0 2.3 2.1 -23.5" > t$X.txt ; ./a.out < t$X.txt
1
2.3
2.1
-23.5


$> X=2; echo "s a b c d e f g h" > t$X.txt ; ./a.out < t$X.txt
Erro: anel cheio.


$> X=3; echo "D + 1.0 + 2.0 + 3.0 + 4.0 - + 5.0 + 6.0 + 7.0 - - - - - + 8.0 - -" > t$X.txt ; ./a.out < t$X.txt
1
2
3
4
5
6
7
8


$> X=4; echo "D + 1.0 - -" > t$X.txt ; ./a.out < t$X.txt
1
Erro: anel vazio.

Problema 6 ----------------------------------------------------------------------------------------------------

Neste exercício aprenderemos sobre mais um padrão de projetos: a Cadeia de Responsabilidade, ou Chain of Responsibility (CR), como originalmente chamado. Uma CR é um padrão bem parecido com o Decorator, que já vimos em um exercício anterior. Porém, em vez de todos os objetos da cadeia realizarem uma ação sobre o dado, na CR, somente um objeto perfaz tal ação.

Neste exercício, nós implementaremos um pequeno interpretador de instruções. Esse interpretador manipula uma máquina virtual de pilha. Essa máquina virtual é como um computador, porém, toda a memória que ela usa é uma pilha. As instruções permitem manipular os dados no topo da pilha. Nossa máquina reconhecerá somente cinco instruções:

pop: remove o dado no topo da pilha.
push n: coloca o valor 'n' no topo da pilha.
add: adiciona os dois valores no topo da pilha, remove-os, e coloca o valor resultante no topo da pilha.
mul: multiplica os dois valores no topo da pilha, remove-os, e coloca o valor resultante no topo da pilha.
print: imprime na saída padrão o valor no topo da pilha.

Para testar seu programa, utilize a função de teste abaixo:

#include <stack>
#include <iostream>
#include "Handler.h"
Instruction* readNextInstruction() {
  std::string msg;
  if (std::cin >> msg) {
    int value = 0;
    if (msg == "push") {
      std::cin >> value;
    }
    return new Instruction(msg, value);
  }
  return NULL;
}
int main() {
  std::stack<int> *stack = new std::stack<int>();
  Handler *handler = new HandlerAdd(NULL, stack);
  handler = new HandlerMul(handler, stack);
  handler = new HandlerPop(handler, stack);
  handler = new HandlerPrint(handler, stack);
  handler = new HandlerPush(handler, stack);
  Instruction *inst;
  while ((inst = readNextInstruction())) {
    handler->handle(inst);
    delete inst;
  }
  delete stack;
  delete handler;
  return 0;
}

Sua tarefa, neste exercício, será completar a implementação dos "Manipuladores de Instrução" (handlers). Um modelo descrevendo a estrutura de manipuladores pode ser vista abaixo:

![alt text](https://github.com/ViniciusCarvalhoDev/Algoritmos-e-Estrutura-de-Dados/blob/main/ChainOfResponsibility.png?raw=true)

As declarações de todas as funções já estão feitas para você. Você terá tão somente que implementar as funções handle de cada manipulador. A título de exemplo, abaixo pode ser vista a implementação da função handle da classe HandlerAdd:

void HandlerAdd::handle(Instruction *inst) {
  if (inst->msg.compare("add") == 0) {
    fer_assert(_stack->size() >= 2, "Erro: poucos argumentos na pilha.");
    const int v1 = _stack->top();
    _stack->pop();
    const int v2 = _stack->top();
    _stack->pop();
    const int vv = v1 + v2;
    _stack->push(vv);
  } else {
    fer_assert(_next != NULL, "Erro: comando desconhecido.");
    _next->handle(inst);
  }
}

Note que estamos realizando o tratamento de erro com a função fer_assert. Essa função é mostrada logo abaixo:

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

Você pode usar qualquer outra função para realizar o tratamento de erro. Contudo, você deve imprimir mensagens de erro na saída padrão, não na saída de erro, para que a correção automática possa funcionar. Caso um erro aconteça, seu programa deve imprimir uma mensagem, e então interromper o programa. Os dois tipos de mensagem de erro possíveis são (Lembre-se de imprimir um ponto no final da mensagem de erro):

Erro: poucos argumentos na pilha. Essa mensagem é disparada quando a pilha não contém argumentos suficientes para a realização de alguma operação.
Erro: comando desconhecido. Essa mensagem é disparada quando não existe nenhum manipulador para tratar um determinado tipo de instrução.

A declaração dos manipuladores e da classe de instrução está disponível em um dos arquivos que fazem parte do trabalho: Handler.h. Abaixo são dados alguns testes. Procure usá-los como exemplo para entender o funcionamento da máquina de pilha:


=== input ===
push 13
push 29
add
print
pop
=== output ===
42

=== input ===
push 2
push 2
mul
print
push 2
mul
print
push 2
mul
print
push 2
mul
print
=== output ===
4
8
16
32

=== input ===
push 2
push 3
push 4
push 5
mul
print
mul
print
mul
print
=== output ===
20
60
120

=== input ===
push 2
print
push 3
print
pop
add
=== output ===
2
3
Erro: poucos argumentos na pilha.

=== input ===
push 2
print
push 3
print
add
print
=== output ===
2
3
5

Problema 7 -------------------------------------------------------------------------------------------------------------------------------------

Implemente no arquivo Stack.cpp a classe Stack (pilha de números inteiros) declarada no arquivo Stack.h.
Sua implementação deve passar em todos os testes definidos no arquivo Main.cpp.
