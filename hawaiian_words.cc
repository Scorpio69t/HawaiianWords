#include <iostream>
#include <string>

#include "functions.hpp"

int main( int argc, char** argv ) {
  if ( argc != 2 ) {
    std::cout << "Invalid number of arguments" << std::endl;
    return 1;
  }
  std::string hawaiian_word = argv[1];
  bool is_valid = CheckForValidChars( hawaiian_word );
  if ( is_valid == false ) {
    std::cout << hawaiian_word
              << " contains a character not a part of the Hawaiian language."
              << std::endl;
    return 1;
  }
  if ( is_valid == true ) {
    std::vector<std::string> vect_to_handle_spaces =
        HandleSpaces( hawaiian_word );
    std::cout << WordToPronunciation( vect_to_handle_spaces ) << std::endl;
  }
}