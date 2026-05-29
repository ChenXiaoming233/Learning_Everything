#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int age;
};

bool operator<(const Student &a, const Student &b)
{
    if (a.name != b.name)
        return a.name < b.name;
    return a.age < b.age;
}

template <typename T>
void sort1(T a[], int n)
{
    sort(a, a + n);
}

int main()
{
    int nunbers[] = {5, 2, 9, 1, 7};
    int numbersCount = 5;
    sort1(nunbers, numbersCount);

    float scores[] = {3.5, 1.2, 4.8, 2.1};
    int scoresCount = 4;
    sort1(scores, scoresCount);

    Student students[] = {
        {"Alice", 20},
        {"Bob", 19},
        {"Alice", 18}};
    int studentCount = 3;
    sort1(students, studentCount);

    return 0;
}
