#include "QPerson.h"

QPerson::QPerson(QObject *parent) : QObject(parent)
{
    m_name = fName;
}

int QPerson::age(){ // return age
    return m_age;
}

void QPerson::setAge(int value){
    m_age = value;
    emit ageChanged(m_age);
}

void QPerson::incAge(){
    m_age++;
    emit ageChanged(m_age);
}
