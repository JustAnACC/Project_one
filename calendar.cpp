#include "calendar.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

calendar::calendar()
{
    appointments = nullptr;
    holidays = nullptr;
    h_size = 0;
    file_path = nullptr;
}
calendar::calendar(const calendar& given)
{
    appointments = given.appointments;
    holidays = given.holidays; //to be fixed
    h_size = given.h_size;
    file_path = new char[strlen(given.file_path)+1];
    strcpy(file_path,given.file_path);
    file_write.open(given.file_path);
    file_read.open(given.file_path);
}
calendar& calendar::operator=(const calendar& given)
{
    if(this != &given)
    {
        appointments = given.appointments;
        holidays = given.holidays; //to be fixed
        h_size = given.h_size;
        delete[] file_path;
        file_path = new char[strlen(given.file_path)+1];
        strcpy(file_path,given.file_path);
        file_write.close();
        file_write.open(given.file_path);
        file_read.close();
        file_read.open(given.file_path);
    }
    return *this;
}
calendar::~calendar()
{
    delete appointments;
}

void calendar::book(tm date, tm start_time, tm end_time, char* name, char* note)
{
    node* use = appointments;
    while(use != nullptr)
    {
        /*if(appointments->date == date && ((appointments->start_time < start_time && appointments->end_time > start_time)||(appointments->start_time < end_time && appointments->end_time > end_time)||(appointments->start_time > start_time && appointments->end_time < end_time)))
        {
            add(date,start_time,end_time,name,note);
        }
        use = use->next;*/
    }
    use = nullptr;
}
void calendar::unbook(tm date, tm start_time, tm end_time)
{
    node* use = appointments;
    node* previous = nullptr;
    while(use != nullptr)
    {
        /*if(appointments->date == date && appointments->start_time == start_time && appointments->end_time == end_time)
        {
            if(previous == nullptr)
            {
                appointments = appointments.next;
            }
            else
            {

            }
        }
        use = use->next;*/
        if(previous == nullptr)
        {
            previous = appointments;
        }
        else
        {
            previous = previous->next;
        }

    }
    use = nullptr;
    previous = nullptr;
}
void calendar::agenda(tm date)
{
    node* use = appointments;
    while(use != nullptr)
    {
        /*if(appointments->date == date)
        {
            std::cout<<appointments->date<<":"<<appointments->start_time<<":"<<appointments->end_time<<" "<<appointments->name<<" "<<appointments->note<<std::endl;
        }
        use = use->next;*/
    }
    use = nullptr;
}
void calendar::change(tm date, tm start_time, char* option, char* new_value)
{
    node* use = appointments;
    while(use != nullptr)
    {
        /*if(appointments->date == date && appointments->start_time == start_time)
        {
            delete[] appointments->name;
            appoitments->name = new char[strlen(new_value)+1];
            strcpy(appointments->name,new_value);
        }
        use = use->next;*/
    }
    use = nullptr;
}
void calendar::find(char* given)
{
    //TO DO
}
void calendar::holiday(tm date)
{
    holidays[h_size] = &date;
    ++h_size;
}
void calendar::busydays(tm date_from, tm date_to)
{
    //TO DO
}
tm calendar::findslot(tm date, unsigned int hours)
{
    node* use = appointments;
    while(use != nullptr)
    {
        /*if(appointments->date == date && appointments->next != nullptr && appointments->end_time - appointments->next->start_time >= hours)
        {
            use = nullptr;
            return appointments->end_time;
        }
        use = use->next;*/
    }
    use = nullptr;
    return appointments->start_time; //
}
tm calendar::findslotwith(tm date, unsigned int hours, calendar given)
{
    node* use = appointments;
    while(use != nullptr)
    {
        /*if(appointments->date == date && appointments->next != nullptr && appointments->end_time - appointments->next->start_time >= hours && given->appointments->date == date && given->appointments->next != nullptr && given->appointments->end_time - given->appointments->next->start_time >= hours && appointments->end_time == given->appoiontments->end_time)
        {
            use = nullptr;
            return appointments->end_time;
        }
        use = use->next;*/
    }
    use = nullptr;
    return appointments->start_time; //
}
calendar& calendar::merge(calendar given)
{
    return *this; //
}
void calendar::save()
{
    //TO DO
}
void calendar::saveas()
{
    //TO DO
}
void calendar::add(tm, tm, tm, char*, char*)
{
    //Dobavqne v hronologichen red
}
