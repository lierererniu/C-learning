//
// Created by 53110 on 2022/3/8.
//
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Person {
public:
    Person(string name, int age, int height) {
        this->m_name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_name;
    int m_Age;
    int m_Height;
};


void test01() {
    list<Person> L;
    //׼������
    Person p1("����", 35, 175);
    Person p2("�ܲ�", 45, 180);
    Person p3("��Ȩ", 40, 170);
    Person p4("����", 25, 190);
    Person p5("�ŷ�", 35, 160);
    Person p6("����", 35, 200);
    //��������
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (auto &it: L) {
        cout << "������" << it.m_name << " ";
        cout << "���䣺" << it.m_Age << " ";
        cout << "��ߣ�" << it.m_Height << " " << endl;
    }
    //����
    cout << "-------------------------------" << endl;
    cout << "�����" << endl;
    L.sort([=](Person &v1, Person &v2) -> bool {
        if (v1.m_Age == v2.m_Age) {
            return v1.m_Height > v2.m_Height;
        } else {
            return v1.m_Age < v2.m_Age;
        }
    });
    for (auto &it: L) {
        cout << "������" << it.m_name << " ";
        cout << "���䣺" << it.m_Age << " ";
        cout << "��ߣ�" << it.m_Height << " " << endl;
    }
}

int main() {
    test01();
    return 0;
}