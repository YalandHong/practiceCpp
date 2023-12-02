#include <atomic>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <iostream>
using namespace std;

atomic<__uint128_t> my_data;

static_assert(
    sizeof(void*) == sizeof(uint64_t), "ptr size");

void setData(void* root_ptr, int root_level)
{
    __uint128_t encoded = (__uint128_t)root_ptr;
    encoded <<= 64;
    encoded |= (__uint128_t)root_level;

    my_data.store(encoded);
}

void getData(void** root_ptr, int* root_level)
{
    __uint128_t encoded = my_data.load();
    uint64_t high = (uint64_t)(encoded >> 64);

    *root_level = (int)encoded;
    *root_ptr = (void*)high;
}

int main()
{
    void* ptr = (void*)main;
    int x;
    cin >> x;

    setData(ptr, x);
    printf("%p %d\n", ptr, x);

    void* outp = nullptr;
    int y = -1;
    getData(&outp, &y);
    printf("%p %d\n", outp, y);
    return 0;
}
