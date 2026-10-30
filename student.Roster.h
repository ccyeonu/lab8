// 2. studentRoster.h파일에 studentRoster class를 인라인으로 구현하려고 합니다. 다음을 확인하여 studentRoster.h파일을 완성해보세요. 파일명 명시하고 코드를 작성하세요. 
// 2-1. 헤더가드, 전처리지시자를 넣으세요.
// 2-2. 상수 max(maxStudent)를 30으로 선언합니다. 
// 2-3. 본인이름학번의 네임스페이스안에 studentRoster class를 정의하세요.
// 2-4. 멤버변수는 3개: std::string형의 courseName, student형의 max개의 std::array형 studentArray, int형의 n(numOfStudent)
// 2-5. 생성자: 매개변수 1개, courseName 초기화, n(numOfStudent)은 0으로 초기화
// 2-6. addStudent멤버함수(매개변수는 const student&형): n(numOfStudent)이 max(maxStudent)보다 크거나 같으면 프로그램종료, studentArray의 n(numOfStudent)인덱스변수에 매개변수 할당, n(numOfStudent)값은 +1
// 2-7. print멤버함수: 표준스트림으로 courseName와 studentArray를 출력, 이때 studentArray는 student형 n(numOfStudent)개 출력해야 합니다.
// 2-8. getCourseName, setCourseName 함수를 참조를 이용하여 정의하세요.  
// 2-9. const 멤버함수가 필요한 경우 const 멤버함수로 정의하세요. 

#pragma once
#include "student.h"
#include <array>

const int max{30};

namespace ywchoi2649052
{
    class studentRoster
    {
        std::string courseName;
        std::array<student, max> studentArray;
        int n;
    public:
        studentRoster(const std::string& c = "no course name yet")
        :courseName{c}, n{0}
        {}

        void addStudent(const student& s)
        {
            if (n >= max) 
            {
                std::cout << "in studentRoster:addStudent error, over max\n";
                std::exit(1);
            }
            studentArray[n] = s; 
            n += 1;
        }

        void print() const
        {
            std::cout << courseName << ": \n";
            for(int i = 0; i < n; i++)
                std::cout << studentArray[i];
            std::cout << std::endl;
        }

        const std::string& getCourseName(){return courseName;}
        void setCourseName(const std::string& c){courseName = c;}
        
    };
}

