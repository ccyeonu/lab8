#pragma once
#include <string>
#include <iostream>

// 1. student.h파일에 student class를 인라인으로 구현하려고 합니다. 다음을 확인하여 위 코드를 변경하여 student.h파일을 완성해보세요. 
// 1-1. 헤더가드, 전처리지시자를 넣으세요.
// 1-2. 본인이름학번의 네임스페이스안에 student class를 정의하세요.
// 1-3. testId와 testScore 함수에서 잘못된 부분이 있으면 수정해보세요. 
// 1-4. testGrade 함수정의를 없애고 calGrade 함수를 private 멤버함수로 구현합니다. calGrade함수는 score값에따라 grade를 할당: 90점이상이면 'A', 80점이상이면 'B", 70점 이상이면 'C', 60점 이상이면 'D', 그 외는 'F' 
// 1-5. 생성자의 매개변수를 3개로 변경하고, grade에 값을 초기화시키는 부분을 삭제, testGrade 함수 호출 대신 calGrade함수를 호출합니다. 
// 1-6. input함수에서 grade를 입력하는 부분을 삭제하고 calGrade함수를 호출합니다. 
// 1-7. 입력연산자오버로딩에서도 grade를 입력하는 부분을 삭제하고 calGrade함수를 호출합니다. 
// 1-8. setGrade 함수에 testGrade함수 호출을 삭제합니다. 
// 1-9. 전위증가연산자, 후위증가연산자를 this를 이용해서 구현하세요. 리턴형식도 참조가 필요하면 참조로 리턴하게 변경하세요. calGrade함수도 필요하면 호출하세요.
// 1-10. 복합할당연산자 +=를 구현하세요. 매개변수는 int, this를 이용하세요. score에 매개변수를 더하고 score가 100보다 커지면 score에 100을 할당하세요. 변경된 score값에 따라 grade도 변경하세요. 
namespace ywchoi2649052
{
    class student {
        std::string name{};
        int id{};
        int score{};
        char grade{};	
        
        void testId(){
            if (id < 1000000 || id > 9999999)
            {
                std::cout << "Invalid ID\n";
                std::exit(1);
            }    
        }

        void testScore(){
            if (score < 0 || score > 100)
            {
                std::cout << "Invalid score\n";
                std::exit(1);
            }    
        }

        void calGrade()
        {
            if (score >= 90) grade = 'A';
            else if (score >= 80) grade = 'B';
            else if (score >= 70) grade = 'C';
            else if (score >= 60) grade = 'D';
            else grade = 'F';
        }

    public:

        student(const std::string& n = "no name yet", int d = 1234567, int s = 0) 
        : name{n}, id{d}, score{s}{
            testId(); testScore(); calGrade();
        }

        void input(){
            std::cout << "Enter name: "; std::getline(std::cin >> std::ws, name);
            std::cout << "Enter id: ";   std::cin >> id; testId();
            std::cout << "Enter score: ";std::cin >> score; testScore();
            calGrade();
        }

        friend std::istream& operator>>(std::istream& is, student& s){
            std::cout << "Enter name: "; std::getline(is >> std::ws, s.name);
            std::cout << "Enter id: ";	 is >> s.id; s.testId();
            std::cout << "Enter score: ";is >> s.score; s.testScore();
            s.calGrade();
            return is;
        }

        void setName(const std::string& n){name = n;}
        void setId(int d){id = d; testId();}
        void setScore(int s){score = s; testScore();}
        void setGrade(char g){grade = g;}
        void print() const {
            std::cout << name << "(" << id << "):" << score << "(" << grade << ")\n";
        }

        friend std::ostream& operator<<(std::ostream& os, const student& s) {
            os << s.name << "(" << s.id << "):" << s.score << "(" << s.grade << ")\n";
            return os;
        }

        const std::string& getName() const {return name;}
        int getId() const {return id;}
        int getScore() const {return score;}
        char getGrade() const{return grade;}
        student& operator++(){++score; calGrade(); return *this}
        student operator++(int)
        { 
            student temp{*this};
            ++(*this);
            return temp; 
        }
        student& operator+=(int s)
        {
            score += s; 
            if(score > 100) score = 100;
            calGrade();
            return *this;
        }

        friend bool operator==(const student& s1, const student& s2) { return s1.id == s2.id;}
        friend int operator+(const student& s1, const student& s2) { return s1.score + s2.score;}

    };

}