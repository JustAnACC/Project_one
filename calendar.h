#ifndef _CALENDAR_
#define _CALENDAR_
#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>

class calendar
{
public:
    struct node
    {
        tm date;
        tm start_time;
        tm end_time;
        char* name;
        char* note;
        node* next;

        node()
        {
            name = nullptr;
            note = nullptr;
            next = nullptr;
        }
        node(const node& given)
        {
            date = given.date;
            start_time = given.start_time;
            end_time = given.end_time;
            name = new char[strlen(given.name)+1];
            strcpy(name,given.name);
            note = new char[strlen(given.note)+1];
            strcpy(note,given.note);
            next = given.next;
        }
        node& operator=(const node& given)
        {
            if(this != &given)
            {
                date = given.date;
                start_time = given.start_time;
                end_time = given.end_time;
                delete[] name;
                name = new char[strlen(given.name)+1];
                strcpy(name,given.name);
                delete[] note;
                note = new char[strlen(given.note)+1];
                strcpy(note,given.note);
                next = given.next;
            }
            return *this;
        }
        ~node()
        {
            delete[] name;
            delete[] note;
            delete next;
        }
    };
private:
    node* appointments;
    tm** holidays;
    unsigned int h_size;
    char* file_path;
    std::ofstream file_write;
    std::ifstream file_read;
public:
    calendar();
    calendar(const calendar&);
    calendar& operator=(const calendar&);
    ~calendar();

    void book(tm, tm, tm, char*, char*);
    void unbook(tm, tm, tm);
    void agenda(tm);
    void change(tm, tm, char*, char*);
    void find(char*);
    void holiday(tm);
    void busydays(tm, tm);
    tm findslot(tm, unsigned int);
    tm findslotwith(tm , unsigned int, calendar);
    calendar& merge(calendar);

    void save();
    void saveas();

    void add(tm, tm, tm, char*, char*);
};
#endif // _CALENDAR_
