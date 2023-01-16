void data_transfer(const unsigned char pt[16], const unsigned char skey[32], unsigned char ct[16]){}

#include <time.h>
#include <stdio.h>
int main(){
    const unsigned char pt[16] = {
        0x00U,0x01U,0x02U,0x03U,0x04U,0x05U,0x06U,0x07U,
        0x08U,0x09U,0x0aU,0x0bU,0x0cU,0x0dU,0x0eU,0x0fU
        };
    const unsigned char skey[32] = {
        0xffU,0xeeU,0xddU,0xccU,0xbbU,0xaaU,0x99U,0x88U,
        0x77U,0x66U,0x55U,0x44U,0x33U,0x22U,0x11U,0x00U,
        0xf0U,0xe0U,0xd0U,0xc0U,0xb0U,0xa0U,0x90U,0x80U,
        0x70U,0x60U,0x50U,0x40U,0x30U,0x20U,0x10U,0x00U
        };
    unsigned char ct[16];
    struct timespec start_time, end_time;
    long long sec, nsec, d_sec, time_ave;
    unsigned int NUM_OF_LOOPS = 1<<17;
    int i = 0;
    
    // -----start-----
    clock_gettime(CLOCK_REALTIME, &start_time);
    while (i < NUM_OF_LOOPS){
        data_transfer(pt,skey,ct);
        i++;
    }
    clock_gettime(CLOCK_REALTIME, &end_time);
    // ----- end -----
    sec = end_time.tv_sec - start_time.tv_sec;
    nsec = end_time.tv_nsec - start_time.tv_nsec;
    d_sec = sec*1000*1000*1000 + nsec;
    time_ave = d_sec / NUM_OF_LOOPS;
    printf("%lld\n", time_ave);
    
    return 0;
}