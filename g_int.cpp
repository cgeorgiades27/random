#include <iostream>
#include <list>
#include <string>
#include <map>
#include <utility>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cerr << "*** Argument error!\n";
        exit(EXIT_FAILURE);
    }
    
    typedef std::pair<std::string,std::string> Pair;
    std::list<std::pair<std::string,std::string> > teachers;
    std::list<std::pair<std::string,std::string> > students;
    std::list<std::pair<std::string,std::string> > pairs;
    std::ifstream stu, tea;
    stu.open(argv[1]);
    tea.open(argv[2]);

    if (!stu.is_open())
    {
        std::cerr << "*** unable to open " << argv[1];
        exit(EXIT_FAILURE);
    }

    char line[90];
    std::string name, subject;

    while (stu.getline(line,90))
    {
        sscanf(line,"%s,%s",name,subject);
        if (students.)
    }

    
    Pair a("Dr. J","Math");
    Pair b("Dr. M","English");
    Pair c("Dr. P","Proctology");
    Pair d("Dr. G","Zoology");
    Pair e("Jimmy","Math");
    Pair f("Little Timmy","English");
    Pair g("Peeniss","Proctology");
    Pair h("Gary","Zoology");
    Pair i("John","Math");

    teachers.push_back(a);
    teachers.push_back(b);
    teachers.push_back(c);
    teachers.push_back(d);
    students.push_back(e);
    students.push_back(f);
    students.push_back(g);
    students.push_back(h);
    students.push_back(i);

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

    for (std::list<Pair>::iterator i = pairs.begin(); i != pairs.end(); ++i)
        std::cout << "match: " << (*i).first << " and " << (*i).second << '\n';
    
    return 0;
}

