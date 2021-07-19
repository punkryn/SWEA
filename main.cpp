#include <iostream>

#define BASEBALL (0x1)			// 0b0001
#define CONSTELLATION (0x2)		// 0b0010
#define CALCULATOR (0x4)		// 0b0100

struct PEOPLE {
	int status;

	PEOPLE() {
		status = 0;
	}

	PEOPLE(int _status) {
		status = _status;
	}
};

int main() {
	int tmp = 30;
    int flag;

    flag = tmp & 1;
    printf("%d", flag);
    int check = 1;
    for(int i = 0; i < 4; i++){
        if(flag == 0){
            printf("xx\n");
        }
        check = check << 1;
    }

    if(flag == 0){
        printf("123");
    }

	return 0;
}