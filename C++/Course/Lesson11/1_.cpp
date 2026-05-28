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
void sort_template(T a[], int n)
{
    sort(a, a + n);
}

int main()
{
    int numbers[] = {5, 2, 9, 1, 7};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    sort_template(numbers, count);

    float scores[] = {3.5f, 1.2f, 4.8f, 2.1f};
    int scoreCount = sizeof(scores) / sizeof(scores[0]);
    sort_template(scores, scoreCount);

    Student students[] = {
        {"Alice", 20},
        {"Bob", 19},
        {"Alice", 18}};
    int studentCount = sizeof(students) / sizeof(students[0]);
    sort_template(students, studentCount);

    return 0;
}
