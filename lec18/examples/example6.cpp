// example6.cpp
#include <iostream>
#include <string>
#include <map>

int main() {

  std::map<std::string, int> days;

  days[std::string("Jan")] = 31;
  days[std::string("Feb")] = 28;
  days[std::string("Mar")] = 31;
  days[std::string("Apr")] = 30;
  days[std::string("May")] = 31;
  days[std::string("Jun")] = 30;
  days[std::string("Jul")] = 31;
  days[std::string("Aug")] = 31;
  days[std::string("Sep")] = 30;
  days[std::string("Oct")] = 31;
  days[std::string("Nov")] = 30;
  days[std::string("Dec")] = 31;
  std::map<std::string, int>::const_iterator iter;

    for( iter = days.begin(); // first elemnt
         iter!= days.end();  // last element
         ++iter  // step
       ) {
      std::cout << "key iter->first: " << iter->first
                << " value iter->second: " << iter->second
                << std::endl;
    }

    // lookup non-exisiting key
    std::string december("december");

    iter = days.find(december);

    if( iter != days.end() ) {
      std::cout << days["Dec"] << std::endl;
    } else {
       std::cout << "Bad key: " << december << std::endl;
    }

    std::string month;
    do {
      /* code */
      std::cout << "month? ";
      std::cin >> month;
      iter = days.find(month);
      if( iter != days.end() ) {
        std::cout << month << " has " << iter->second << " days" << std::endl;
      } else {
         std::cout << "Bad key: " << month << ". try again" << std::endl;
      }
    } while(true);


    return 0;
  }
