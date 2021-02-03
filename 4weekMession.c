#include <stdio.h>
#include <cs50.h>
#include <string.h>

int* splitnumbers(int number, int* numbers)
{
    int count = 0;
    while(number > 0)
    {
        numbers[count] = number % 10;
        number /= 10;
        count ++;
    }
    return numbers;
}

int* sortnumber(int number, int* numbers)
{
    numbers = splitnumbers(number, numbers);
    int temp;
    for (int i=0; i < 5; i++)
    {
        for (int j=0; j < 5 - i - 1; j++ )
        {
            if (numbers[j] > numbers[j+1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    return numbers;
}

int main(void) {  
    int num1 = get_int("첫번째 숫자를 입력하세요: ");
    int num2 = get_int("두번째 숫자를 입력하세요: ");

    int numbers1[5];
    sortnumber(num1, numbers1);

    int numbers2[5];
    sortnumber(num2, numbers2);

    for(int i = 0; i < 5; i++)
    {
        if(numbers1[i] != numbers2[i])
        {
            printf("False\n");
            return 1;
        }
    }
    printf("true\n");
    return 0;
}
