#ifndef __MY_DATE__
#define __MY_DATE__

class date
{
public:
    date(int y = 0, int m = 0, int d = 0) 
        : year(y), month(m), day(d)
    {
    }

    bool operator > (date& d) const;
    bool operator < (date& d) const;
    bool operator == (date& d) const;
    
private:
    int year, month, day;
    friend std::ostream& operator << (std::ostream &os, date& d);
};

inline void print(date *p, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << p[i];
}

inline std::ostream& operator << (std::ostream &os, date& d)
{
    return os << d.year << '-' << d.month << '-' << d.day << std::endl;
}

inline bool date::operator > (date& d) const
{
    if (this->year > d.year)
        return true;
    else if (this->year < d.year)
        return false;
    else {
        if (this->month > d.month)
            return true;
        else if (this->month < d.month)
            return false;
        else {
            if (this->day > d.day)
                return true;
            else
                return false;
        }

    }
}

inline bool date::operator < (date& d) const
{
    return (*this) > d ? false : true;
}

inline bool date::operator == (date& d) const
{
    return (this->year == d.year) && (this->month == d.month) && (this->day == d.day);
}

inline date* CreatePoints(int n)
{
    date *rdates = new date[n];

    srand(time(NULL));
    for (int i = 0; i < n ; ++i) {
        rdates[i] = date(rand() % 2015 + 1, rand() % 12 + 1, rand() % 31 + 1);
    }
    
    return rdates;
}

inline void Sort(date *pd, int n)
{
    date td;
    bool flag = true;

    for (int i = 0; i < n; ++i) {
        if (flag) {
            flag = false;
            for (int j = i+1; j < n; ++j) {
                if (pd[i] > pd[j]) {
                    td = pd[i];
                    pd[i] = pd[j];
                    pd[j] = td;
                    flag = true;
                }
            }
        }
    }
}

#endif
