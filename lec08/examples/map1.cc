// map1.cc
#include<iostream>
#include<vector>
#include<map>
#include <utility>      // std::pair, std::make_pair
#include<string>

#include "Student.h"

int main() {

  // pair object to associate two different types of data
  std::pair< std::string, int> grade = std::make_pair("MQR", 24);

  // grades of a student stored in a vector
  std::vector< std::pair< std::string, int> > grades; //
  grades.push_back( std::make_pair("MQR", 26) );
  grades.push_back( std::make_pair("Phys Lab", 27) );
  grades.push_back( std::make_pair("Cond Matt", 23) );

  Student gino("Gino", 110998);


  // databases of grades of all students
  //    key: student     value: grades
  std::map<Student,  std::vector< std::pair< std::string, int> >  > exams;
  exams[gino] = grades;

  Student tina("Tina", 121001);
  grades.clear(); // delete all previous values in the vector
  grades.push_back( std::make_pair("MQR", 29) );
  grades.push_back( std::make_pair("Phys Lab", 28) );
  grades.push_back( std::make_pair("Cond Matt", 25) );

  exams[tina] = grades;

  // loop over entries in the map
  for(std::map<Student,  std::vector< std::pair< std::string, int> >  >::iterator it = exams.begin(); it != exams.end(); it++ ) {

    // print out student data
    std::cout << "Student name: " << (it->first).name() << "\t id: " << (it->first).id() << std::endl;

    // loop over list of exams 
    for(std::vector< std::pair< std::string, int> >::iterator vit = (it->second).begin(); vit != (it->second).end(); vit++) {

      // print name of each exams and relative grade
      std::cout << "\t Subject: " << vit->first << "\t grade: " << vit->second << std::endl;

    } // end: loop over grades

  } // end: loop over students
  
  return 0;

}
