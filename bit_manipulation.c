#include <stdio.h>
#include <stdbool.h>

void number_sign(int a)
{
    int sign = (a > 0) - (a < 0);

    if (sign == 1)
    {
        printf("positive\n");
    }
    else if (sign == -1)
    {
        printf("negative\n");
    }
    else
    {
        printf("zero\n");
    }
}

void check_opp_sign(int a, int b)
{
    bool ret = 0;
    ret = ((a ^ b) < 0);

    if (ret)
    {
        printf("opp\n");
    }
    else
    {
        printf("same\n");
    }
}

void power_of_two(int a)
{
    int flag = ((a != 0) && !(a & (a - 1)));

    if (flag == 1)
    {
        printf("power of 2\n");
    }
    else
    {
        printf("not a power of 2\n");
    }
}

void setBit(unsigned char number, int position)
{
    printf("before setting: 0x%x\n", number);
    number |= (1 << position);

    printf("after setting the bit %d: 0x%x\n", position, number);
}

void unsetBit(int number, int position)
{
    printf("before unsetting: 0x%x\n", number);

    number &= ~(1 << position);

    printf("after unsetting: 0x%x\n", number);
}

void ifSet(int a, int position){
    int bit = (a >> position) & 1;
    if (bit == 1)
    {
        printf("set");
    }
    else
    {
        printf("unset");
    }
}



int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    number_sign(a);

    check_opp_sign(a, b);

    power_of_two(a);

    unsetBit(a, b);

    setBit(a, b);
}