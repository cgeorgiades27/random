/*
    Build: g++ -std=c++11 -o g.x g_int.cpp
 */

#include <iostream>
#include <list>
#include <string>
#include <map>
#include <utility>
#include <fstream>

typedef std::pair<std::string, std::string>    Pair;
std::list<std::pair<std::string, std::string>> teachers;
std::list<std::pair<std::string, std::string>> students;
std::list<std::pair<std::string, std::string>> pairs;

int main(int argc, char *argv[])
{
    // begin 
    if (argc < 3)
    {
        std::cerr
            << "*** Argument error!\n"
            << "Format = <students_file> <teachers_file>\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream stu, tea;
    stu.open(argv[1]);
    tea.open(argv[2]);

    if (!stu.is_open() || !tea.is_open())
    {
        std::cerr << "*** unable to open " << argv[1];
        exit(EXIT_FAILURE);
    }

    char line[90];
    char name[44], subject[44];

    while (stu.getline(line, 90))
    {
        sscanf(line, "%[^,],%s", name, subject);
        Pair p(name, subject);
        students.push_back(p);
    }

    while (tea.getline(line, 90))
    {
        sscanf(line, "%[^,],%s", name, subject);
        Pair p(name, subject);
        teachers.push_back(p);
    }

    // print students
    std::cout << "Students:\n";
    for (std::list<Pair>::iterator i = students.begin(); i != students.end(); ++i)
        std::cout << (*i).first << ", " << (*i).second << '\n';

    // print teachers
    std::cout << "Teachers:\n";
    for (std::list<Pair>::iterator i = teachers.begin(); i != teachers.end(); ++i)
        std::cout << (*i).first << ", " << (*i).second << '\n';

    for (std::list<Pair>::iterator i = teachers.begin(); i != teachers.end(); ++i)
    {
        for (std::list<Pair>::iterator j = students.begin(); j != students.end(); ++j)
        {
            if ((*i).second == (*j).second)
            {
                Pair p((*j).first, (*i).first);
                pairs.push_back(p);
            }
        }
    }

    // print matches
    for (std::list<Pair>::iterator i = pairs.begin(); i != pairs.end(); ++i)
        std::cout << "match: " << (*i).first << " and " << (*i).second << '\n';

    return 0;
}
