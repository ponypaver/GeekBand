#ifndef _PROGRAMMER_H_
#define _PROGRAMMER_H_

struct Programmer
{
    Programmer(const int id, const std::string name)
     : Id(id), Name(name)
    { }

    void Print() const
    {
        std::cout << "[" << Id << "]:" << Name << std::endl;
    }

    int Id;
    std::string Name;
};

struct ProgrammerIdGreater 
{
    //ProgrammerIdGreater(
    const bool operator() (const Programmer& p1, const Programmer& p2)
    {
        return (p1.Id > p2.Id);
    }
};

struct ProgrammerNameComparer
{
    const bool operator() (const Programmer& p1, const Programmer& p2)
    {
        return (p1.Name < p2.Name);
    }
};

#endif
