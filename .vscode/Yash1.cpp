#include<iostream>
using namespace std;

class Student_1; // Forward declaration

class Student_2
{
    private:
        int roll_no;
        int marks[3]; // Fixed typo: changed 'mark' to 'marks'
    public:
        void get_data();
        int get_rno(){ return roll_no; }
        float get_avg();
};

void Student_2 :: get_data()
{
    cout<<"\n Enter Roll number :";
    cin>>roll_no;
    cout<<"\n Enter marks in three subjects :";
    for(int i=0;i<3;i++)
        cin>>marks[i];
}

float Student_2 ::get_avg()
{
    int total = 0;
    for(int i=0;i<3;i++)
        total += marks[i]; // Fixed typo: changed 'mark' to 'marks'
    return (float)total/3;
}

class Student_1
{
    private:
        int rno;
        float avg;
        char grade;
    public:
        Student_1()
        { 
            rno = 0; 
            avg = 0; 
            grade = ' '; // Fixed typo: changed '' to ' '
        }
        
        Student_1(Student_2 S)
        { 
            rno = S.get_rno();
            avg = S.get_avg();
            if(avg>=60)
                grade = 'A';
            else if(avg>=50 && avg<60)
                grade = 'B';
            else if(avg>=40 && avg<50) // Fixed logical error: changed '>' to '>='
                grade = 'C';
            else 
                grade = 'D';
        }
        
        void show_data()
        {
            cout<<"\n ROLL NUMBER :"<<rno;
            cout<<"\n AVERAGE :"<<avg;
            cout<<"\n GRADE :"<<grade;
        }
};

int main() // Fixed: Changed main() to int main()
{
    Student_2 Source_Stud;
    Source_Stud.get_data();
    Student_1 Dest_Stud(Source_Stud); // Fixed: Direct initialization
    Dest_Stud.show_data();
    return 0; // Added return statement
}
