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
        void save_node_in_file()
        {
            std::ofstream file("calendar.dat", std::ios::binary | std::ios::app);
            if (!file)
            {
                std::cout << "Bad File!\n";
                file.close();
                return;
            }
            file.write((const char*)&date, sizeof(tm));
            file.write((const char*)&start_time, sizeof(tm));
            file.write((const char*)&end_time, sizeof(tm));
            file.write((const char*)next, sizeof(node*));
            file.write((const char*)strlen(name),sizeof(int));
            file.write(name, strlen(name));
            file.write((const char*)strlen(note), sizeof(int));
            file.write(note, strlen(note));
            file.close();
        }
        void read_node_in_file() {
            std::ifstream file("calendar.dat", std::ios::binary);
            if (!file)
            {
                std::cout << "Bad File!\n";
                file.close();
                return;
            }
            file.read((char*)&date, sizeof(tm));
            file.read((char*)&start_time, sizeof(tm));
            file.read((char*)&end_time, sizeof(tm));
            file.read((char*)&next, sizeof(node*));
            int name_length = 0;
            file.read((char*)&name_length, sizeof(int));
            delete[] name;
            this->name = new char[name_length + 1];
            file.read(this->name, name_length);
            int note_length = 0;
            file.read((char*)&note_length, sizeof(int));
            delete[] note;
            this->note = new char[note_length + 1];
            file.read(this->note, note_length);
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

    void load();
    void save();
    void close();

    void add(tm, tm, tm, char*, char*);

    void set_path(char*);
};
#endif // _CALENDAR_
