#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
using namespace std;
int main () {
  int myints[] = {1,2,3,4,5,6};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    for(int i = 0; i < 6; i++){
        cout << myints[i] << ' ';
    }
    cout << '\n';
  } while ( std::next_permutation(myints,myints+6) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}