#include <stdio.h>
#include <cs50.h>
#include <string.h>

string days[7] = {"월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일"};
string menus[7] = {"청국장","비빔밥","된장찌개","칼국수","냉면","소불고기","오삼불고기"};

int getday();

int main(void)
{
    int index = getday();
    printf("%s:%s\n", days[index], menus[index]);
}

int getday(void)
{
    int index = -1;
    bool check = true;
    while(check){
        string day = get_string("요일을 입력하세요:");
        for(int i = 0; i< sizeof(days) / sizeof(days[0]); i++){
            int j = strcmp(day, days[i]);
            if(j == 0) {
                index = i;
                check = false;
            }
        }
        if(index == -1) {
            printf("잘못된 요일을 입력하셨습니다.\n");
            continue;
        }
    }
    return index;
}

