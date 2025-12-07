

int fibonacci_rec(int n)
{

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}