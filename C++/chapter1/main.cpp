#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// The above declaration allows all elements in the std namespace to be accessed in an unqualified manner (without the std:: prefix).
// a namespace is just a collection of related functions and properties

// C++ Primer given courtesy of https://cplusplus.com/doc/tutorial/


// In C++, identifiers can only be used in expressions once they have been declared. For example, some variable x cannot be used before being declared with a statement, such as:
//  `int x;`

// The same applies to functions. Functions cannot be called before they are declared. That is why, in all the previous examples of functions, the functions were always defined before the main function, which is the function from where the other functions were called. If main were defined before the other functions, this would break the rule that functions shall be declared before being used, and thus would not compile.

// The prototype of a function can be declared without actually defining the function completely, giving just enough details to allow the types involved in a function call to be known. Naturally, the function shall be defined somewhere else, like later in the code. But at least, once declared like this, it can already be called.

int addition(int a, int b);
void thisJustPrintsHi(void);
void multiplyByTwo (int& a, int& b, int& c);
inline string concatenate (const string& a, const string& b);
long recursiveFactorial(long a);



// line comment
/* block comment
 C++ supports two ways of commenting code:
 The first of them, known as line comment, discards everything from where the pair of slash signs are found up to the end of that same line.
 The second one, known as block comment, discards everything between the asterisk fowardslashes
 */
int main()
{
  // A simple C++ statement is each of the individual instructions of a program, like the variable declarations and expressions seen in previous sections. They always end with a semicolon (;), and are executed in the same order in which they appear in a program.
  // "explicit qualification of std" - this is a direct reference to the c-standard library function `cout` using it's namespace `std::`
  std::cout << "I'm a C++ program";
  // "using declaration" - this is an indirect reference to the c-standard library function `cout`, we can do this because the usind declaration handles it for us
  cout << "Hello World!";

  // a bit on variables https://cplusplus.com/doc/tutorial/variables/
  // initialization format: `type identifier = initial_value;`
  int variable_a = 10;
  float variable_b = 20.76;
  // constructor initialization format: `type identifier (initial_value);`
  int x (55);
  cout << x;
  //  uniform initialization format: `type identifier {initial_value};`
  int y {98};
  cout << y;

  // type deduction
  int foo = 0;
  auto bar = foo; // the same as: int bar = foo;

  int fizz = 0;
  decltype(fizz) buzz;  // the same as: int bar; 

  string mystring;
  mystring = "This is the initial string content";
  cout << mystring << endl;
  mystring = "This is a different string content";
  cout << mystring << endl;
  // Note: inserting the endl manipulator ends the line (printing a newline character and flushing the stream).

  // Constants; https://cplusplus.com/doc/tutorial/constants/
  const double pi = 3.1415926;
  const char tab = '\t';
  int i;
  float f = 3.14;
  // Operators https://cplusplus.com/doc/tutorial/operators/
  i = int (f); // (int) f; also works

  // I/o https://cplusplus.com/doc/tutorial/basic_io/
  // For formatted output operations, cout is used together with the insertion operator, which is written as << 
  // The << operator inserts the data that follows it into the stream that precedes it
  cout << i;


  // Multiple insertion operations (<<) may be chained in a single statement:
  cout << "This " << " is a " << "single C++ statement";

  // Chaining insertions is especially useful to mix literals and variables in a single statement:
  int age = 29;
  string zipcode = "34568";
  // To insert a line break, a new-line character shall be inserted at the exact position the line should be broken. In C++, a new-line character can be specified as \n (i.e., a backslash character followed by a lowercase n). For example:
  cout << "I am " << age << " years old.\n My zipcode is " << zipcode << endl;

  // Alternatively, the endl manipulator can also be used to break lines. For example:
  cout << "First sentence." << endl;
  cout << "Second sentence." << endl;


  // The endl manipulator produces a newline character, exactly as the insertion of '\n' does; 
  //  but it also has an additional behavior: 
  //    the stream's buffer (if any) is flushed, 
  //    which means that the output is requested to be physically written to the device,
  //  if it wasn't already.
  // This affects mainly fully buffered streams,
  //  and cout is (generally) not a fully buffered stream. 
  // Still, it is generally a good idea to use endl only when flushing the stream would be a feature
  //  and '\n' when it would not. 
  // Bear in mind that a flushing operation incurs a certain overhead,
  //  and on some devices it may produce a delay.

  // input
  int newNumber, a, b;
  cout << "Please enter an integer value: ";
  cin >> newNumber;
  cout << "The value you entered is " << newNumber;
  cout << " and its double is " << newNumber*2 << ".\n";

  // Extractions on cin can also be chained to request more than one datum in a single statement:
  // cin >> a >> b; 
  // This is equivalent to:
  // cin >> a;
  // cin >> b;
  // cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating the value being extracted, and thus extracting a string means to always extract a single word, not a phrase or an entire sentence
  // To get an entire line from cin, there exists a function, called getline, that takes the stream (cin) as first argument, and the string variable as second. For example:


  string mystr = "";
  cout << "What's your name? " << endl;
  getline (cin, mystr);
  cout << "Hello " << mystr << ".\n";
  cout << "What is your favorite game team? ";
  getline (cin, mystr);
  cout << "I like " << mystr << " too!\n";
  // Using string streams to convert strings to ints

  float price=0;
  int quantity=0;
  // In this example, we acquire numeric values from the standard input indirectly: Instead of extracting numeric values directly from cin, we get lines from it into a string object (mystr), and then we extract the values from this string into the variables price and quantity. Once these are numerical values, arithmetic operations can be performed on them, such as multiplying them to obtain a total price

  cout << "Enter price for it: ";
  getline (cin,mystr);
  stringstream(mystr) >> price;
  cout << "Enter quantity: ";
  getline (cin,mystr);
  stringstream(mystr) >> quantity;
  cout << "Total price: " << price*quantity << endl;

  // programs are not limited to a linear sequence of statements. During its process, a program may repeat segments of code, or take decisions and bifurcate. For that purpose, C++ provides flow control statements that serve to specify what has to be done by our program, when, and under which circumstances.
  // if statements:
  // if (condition) statement

  // If you want to include more than a single statement to be executed when the condition is fulfilled, these statements shall be enclosed in braces ({}), forming a block:

  if ( price >= 20 ) {
    cout << "wow that's a lot";
    int counter = 0;
    while(counter < price ) {
      cout << "Why would you charge so much?\n charge something else next time: ";
      counter++;
    }
  }


// for loop
// for (initialization; condition; increase) statement;
// Jump statements
for(int i =0; i < price; i++) {
  if (i==10)
    {
      cout << "max thanks reached aborted!";
      break;
    }
  if(i==3) continue;
  cout << i+1 << ". thank you\n";
}
// Range-based for loop
// The for-loop has another syntax, which is used exclusively with ranges:

// for ( declaration : range ) statement;

string madeupString = "Hello!";
for (char c : madeupString)
  {
    switch(c) {
      case 'H':
      case 'e':
        cout << "[" << c << "]";
        break;
      case 'l':
        cout << "{" << c << "}";
        break;
      case 'o':
        cout << "{" << c << "}";
        break;
      default:
        cout << "{" << c << "}";
        cout << '\n';
    }
  }
  cout << "time to use functions" << '\n';
  int price_plus_quantity = addition(price, quantity);
  cout << price_plus_quantity << endl;
  cout << "add 1: " << addition(price_plus_quantity,1) << endl;
  thisJustPrintsHi();
  int p1,p2,p3;
  p1=0;
  p2=35;
  p3=-22;
  multiplyByTwo(p1,p2,p3);
  cout << "p1: " << p1 << "p2:" << p2 << "p3" << p3;

  cout << concatenate("reallylongstringa","notactuallythatlongnowthatIthinkaboutitstringb") << endl;
  return 0;
}
int addition(int a, int b) {
  // Calling a function with parameters taken by value causes copies of the values to be made. This is a relatively inexpensive operation for fundamental types such as int, but if the parameter is of a large compound type, it may result on certain overhead. 
  return a + b;
}

void thisJustPrintsHi(void) {
  cout << "HI!";
}
// In certain cases, though, it may be useful to access an external variable from within a function. To do that, arguments can be passed by reference, instead of by value. For example, the function duplicate in this code duplicates the value of its three arguments, causing the variables used as arguments to actually be modified by the call
// To gain access to its arguments, the function declares its parameters as references. In C++, references are indicated with an ampersand (&) following the parameter type, as in the parameters taken by duplicate in the example above.
void multiplyByTwo (int& a, int& b, int& c)
{
  // https://cplusplus.com/doc/tutorial/functions/
  // When a variable is passed by reference, what is passed is no longer a copy, but the variable itself, the variable identified by the function parameter, becomes associated with the argument passed to the function, and any modification on their corresponding local variables within the function are reflected in the variables passed as arguments in the call.

  a*=2;
  b*=2;
  c*=2;
}

inline string concatenate (const string& a, const string& b)
  //  the inline specifier does not change at all the behavior of a function, but is merely used to suggest the compiler that the code generated by the function body shall be inserted at each point the function is called, instead of being invoked with a regular function call
  // Calling a function generally causes a certain overhead (stacking arguments, jumps, etc...), and thus for very short functions, it may be more efficient to simply insert the code of the function where it is called, instead of performing the process of formally calling a function.
{
  // Arguments by reference do not require a copy. The function operates directly on (aliases of) the strings passed as arguments, and, at most, it might mean the transfer of certain pointers to the function. In this regard, the version of concatenate taking references is more efficient than the version taking values, since it does not need to copy expensive-to-copy strings.
  // The solution is for the function to guarantee that its reference parameters are not going to be modified by this function. This can be done by qualifying the parameters as constant:
  // By qualifying them as const, the function is forbidden to modify the values of neither a nor b, but can actually access their values as references (aliases of the arguments), without having to make actual copies of the strings.

  return a+b;
}


// A recursive function is one that simply calls itself. Recursion therefore is the act of functions calling themselves
// Some pretty cool properties of recursive functions:
// 1. By definition, any function written recursively could be rewritten as a while loop.
// 2. Recursive functions will run infinitely if the exit condition is never reached
// long recursiveFactorial(long a)
// {
// if (a > 1)
//    return (a * factorial (a-1));
//   else
//    return 1;
// }