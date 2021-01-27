#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int MAX = 10;
int front = 0;
int rear = 0;
int count = 0;
int queue[MAX];


void insert()
{
    if(count == MAX){
        printf("큐가 꽉 찼습니다.\n");
    } else {
        int data = get_int("삽입할 값: ");
        queue[rear] = data;
        rear = (rear + 1) % 10;
        count++;
    }

}

void deletePop(){
    if(count == 0){
        printf("큐가 비어있습니다.\n");
    } else {
        int delData = queue[front];
        queue[front] = 0;
        printf("큐에서 삭제됨: %i\n", delData);
        front = (front + 1) % 10;
        count--;
    }
}

void display(){
    int maxIndexNum = front + count;
    printf("큐 : ");
    for(int i = front; i < maxIndexNum; i++){
        int index = i % MAX;
        printf("%i ", queue[index]);
    }
    printf("\n");
}

int main(void)
{
    bool check = true;
    while(check){
        printf("1. 삽입\n2. 삭제\n3. 조회\n4. 종료\n");
        int input = get_int("입력: ");
        switch (input){
            case 1:
                insert();
                break;
            case 2:
                deletePop();
                break;
            case 3:
                display();
                break;
            case 4:
                check = false;
                break;
            default:
                printf("잘못된 키를 누르셨습니다.\n");
                break;
        }
    }
}
