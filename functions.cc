#include "functions.hpp"

bool CheckForValidChars( std::string word ) {
  std::string valid_letters = "'aeioupkhlmnw";
  bool is_valid;
  for ( int i = 0; i < word.size(); ++i ) {
    char current_char = word.at( i );
    if ( current_char == ' ' ||
         valid_letters.find( tolower( current_char ) ) != std::string::npos ) {
      is_valid = true;
    } else {
      is_valid = false;
      return is_valid;
    }
  }
  return is_valid;
}

std::string WordToPronunciation(
    std::vector<std::string> vect_spaces_handled ) {
  std::string pronunciation;
  std::string consonants = "pkhlmn";
  for ( std::string word : vect_spaces_handled ) {
    char last_char = ( word.at( word.size() - 1 ) );
    char current_char;
    char next_char;
    last_char = tolower( last_char );
    for ( int i = 0; i < word.size() - 1; ++i ) {
      current_char = word.at( i );
      next_char = word.at( i + 1 );
      current_char = tolower( current_char );
      next_char = tolower( next_char );
      switch ( current_char ) {
      case 'a': {
        if ( consonants.find( next_char ) != std::string::npos ) {
          pronunciation = pronunciation + "ah";
        } else {
          if ( next_char == 'o' || next_char == 'u' ) {
            pronunciation = pronunciation + "ow";
            i = i + 1;
          } else if ( next_char == 'i' || next_char == 'e' ) {
            pronunciation = pronunciation + "eye";
            i = i + 1;
          } else {
            pronunciation = pronunciation + "ah";
          }
        }
        if ( i < word.size() - 1 ) {
          if ( next_char == '\'' ) {
            continue;
          } else {
            pronunciation = pronunciation + "-";
          }
        }
        break;
      }
      case 'e': {
        if ( consonants.find( next_char ) != std::string::npos ) {
          pronunciation = pronunciation + "eh";
        } else {
          if ( next_char == 'u' ) {
            pronunciation = pronunciation + "eh-oo";
            i++;
          } else if ( next_char == 'i' ) {
            pronunciation = pronunciation + "ay";
            i++;
          } else {
            pronunciation = pronunciation + "eh";
          }
        }
        if ( i < word.size() - 1 ) {
          if ( next_char == '\'' ) {
            continue;
          } else {
            pronunciation = pronunciation + "-";
          }
        }
        break;
      }
      case 'i': {
        if ( consonants.find( next_char ) != std::string::npos ) {
          pronunciation = pronunciation + "ee";
        } else {
          if ( next_char == 'u' ) {
            pronunciation = pronunciation + "ew";
            i++;
          } else {
            pronunciation = pronunciation + "ee";
          }
        }
        if ( i < word.size() - 1 ) {
          if ( next_char == '\'' ) {
            continue;
          } else {
            pronunciation = pronunciation + "-";
          }
        }
        break;
      }
      case 'o': {
        if ( consonants.find( next_char ) != std::string::npos ) {
          pronunciation = pronunciation + "oh";
        } else {
          if ( next_char == 'i' ) {
            pronunciation = pronunciation + "oy";
            i++;
          } else if ( next_char == 'u' ) {
            pronunciation = pronunciation + "ow";
            i++;
          } else {
            pronunciation = pronunciation + "oh";
          }
        }
        if ( i < word.size() - 1 ) {
          if ( next_char == '\'' ) {
            continue;
          } else {
            pronunciation = pronunciation + "-";
          }
        }
        break;
      }
      case 'u': {
        if ( consonants.find( next_char ) != std::string::npos ) {
          pronunciation = pronunciation + "oo";
        } else {
          if ( next_char == 'i' ) {
            pronunciation = pronunciation + "ooey";
            i++;
          } else {
            pronunciation = pronunciation + "oo";
          }
        }
        if ( i < word.size() - 1 ) {
          if ( next_char == '\'' ) {
            continue;
          } else {
            pronunciation = pronunciation + "-";
          }
        }
        break;
      }
      case 'w': {
        if ( i == 0 ) {
          pronunciation = pronunciation + "w";
        } else {
          char previous_char = word.at( i - 1 );
          if ( i > 0 && previous_char == 'a' ) {
            pronunciation = pronunciation + "w";
          }
          if ( i > 0 && previous_char == 'i' ) {
            pronunciation = pronunciation + "v";
          }
          if ( i > 0 && previous_char == 'e' ) {
            pronunciation = pronunciation + "v";
          }
          if ( i > 0 && previous_char == 'u' ) {
            pronunciation = pronunciation + "w";
          }
          if ( i > 0 && previous_char == 'o' ) {
            pronunciation = pronunciation + "w";
          }
        }
        break;
      }
      default: {
        pronunciation = pronunciation + current_char;
        break;
      }
      }
    }
    if ( last_char == 'a' ) {
      pronunciation = pronunciation + "ah";
    }
    if ( last_char == 'e' ) {
      pronunciation = pronunciation + "eh";
    }
    if ( last_char == 'i' ) {
      pronunciation = pronunciation + "ee";
    }
    if ( last_char == 'o' ) {
      pronunciation = pronunciation + "oh";
    }
    if ( last_char == 'u' ) {
      pronunciation = pronunciation + "oo";
    }
  }
  return pronunciation;
}

std::vector<std::string> HandleSpaces( std::string word ) {
  std::string current_field = "";
  std::vector<std::string> handle_spaces;
  for ( int i = 0; i < word.size(); i++ ) {
    char current_char = word.at( i );
    if ( current_char != ' ' ) {
      current_field = current_field + current_char;
    }
    if ( current_char == ' ' || i == word.size() - 1 ) {
      handle_spaces.push_back( current_field );
      current_field = " ";
    }
  }
  return handle_spaces;
}