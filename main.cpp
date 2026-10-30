// 3. main.cpp파일에 테스트 코드를 작성합니다. 다음을 확인하여 테스트 코드를 완성해보세요. 파일명 명시하고 코드를 작성하세요. 
// 3-1. 전처리지시자를 넣으세요. 
// 3-2. main을 작성합니다. 
// 3-2-1. student형 객체3개를 선언하고 원하는 값으로 초기화합니다. 
// 3-2-2. studentRoster형을 가리키는 포인터변수를 선언하고 원하는 값으로 초기화하여 동적으로 할당합니다.  
// 3-2-3. studentRoster형을 가리키는 포인터변수에서 addStudent멤버함수를 호출하는데 인자를 3-2-1에서 선언한 객체를 넣습니다. 즉, addStudent멤버함수를 3번 호출합니다. 
// 3-2-4. studentRoster형을 가리키는 포인터변수에서 print멤버함수를 호출합니다. 
// 3-2-5. studentRoster형을 가리키는 포인터변수에서 동적으로 할당한 메모리를 해제합니다. 
// 4. 컴파일한 후 실행했을 때 예상되는 터미널창을 작성하세요. 
#include "student.Roster.h"

int main()
{
    using namespace ywchoi2649052;
    student s1{"kim", 1234567, 100};
    student s2{"lee", 2345678, 90};
    student s3{"park", 3456789, 80};

    studentRoster* srPtr{ new studentRoster{"C++ Programming"}};
    srPtr->addStudent(s1);
    srPtr->addStudent(s2);
    srPtr->addStudent(s3);
    srPtr->print();
    
    delete srPtr;

    return 0;
}

